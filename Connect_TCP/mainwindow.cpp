#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    SMW200A = new RnSSCPI();
    set_FreqSweep = new Setting_Freq_Sweep;


    // Активность виджетов главного окна
    ui->te_Log->setReadOnly(true);
    ui->pb_Disconnect->setEnabled(false);
    ui->le_Command->setEnabled(false);
    ui->pb_Send->setEnabled(false);
    ui->le_Frequency->setEnabled(false);
    ui->le_Level->setEnabled(false);
    ui->le_PEP->setEnabled(false);
    ui->cb_FrequencyUnits->setEnabled(false);
    ui->cb_LevelUnits->setEnabled(false);
    ui->cb_PEPUnits_2->setEnabled(false);
    ui->statusbar->showMessage("Состояние: отключено.");
    set_FreqSweep->setModal(true);
    ui->action_FreqSweep->setEnabled(false);
    ui->tw_Settings->setEnabled(false);

    // Настрокйки List widget
    ui->lw_AccordingToStandard->addItem("Phase1 C4FM");
    ui->lw_AccordingToStandard->addItem("Phase1 CQPSK");
    ui->lw_AccordingToStandard->addItem("Phase2 H-CPM");
    ui->lw_AccordingToStandard->addItem("Phase2 H-DQPSK");
    ui->lw_AccordingToStandard->addItem("Phase2 H-D8PSK Wide");
    ui->lw_AccordingToStandard->addItem("Phase2 H-D8PSK Narrow");
    ui->lw_AccordingToStandard->addItem("Phase1 LSM");
    ui->lw_AccordingToStandard->addItem("Phase1 WCQPSK");


    // Настройка заполнения полей ввода
    QRegExp correctFrequence("^(\\d+(\\.\\d+)?)$");
    QRegExp correctPepAndLevel("^(-?\\d{1,4}(\\.\\d{1,3})?)$");
    ui->le_Frequency->setValidator(new QRegExpValidator(correctFrequence, this));
    ui->le_PEP->setValidator(new QRegExpValidator(correctPepAndLevel, this));
    ui->le_Level->setValidator(new QRegExpValidator(correctPepAndLevel, this));

    // Настройки заполнения полей для частотной развертки
    QRegExp correctDouble("^(\\d+(\\.\\d+)?)$");
    QRegExp correctInt("^\\d+$");
    ui->le_StartFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_StopFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_SpanFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_CenterFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_StepSweep->setValidator(new QRegExpValidator(correctDouble));
    ui->le_SweepDwell->setValidator(new QRegExpValidator(correctDouble));
    ui->le_SweepPoints->setValidator(new QRegExpValidator(correctInt));

    // Настройка заполнения поля Symbol Rate
    ui->le_SymbolRate->setValidator(new QRegExpValidator(correctDouble));

    // Начальные единицы измерения для частотной развертки
    ui->cb_UnitsLinStep->setCurrentIndex(1);
    ui->cb_UninsCenter->setCurrentIndex(1);
    ui->cb_UninsStartFreq->setCurrentIndex(1);
    ui->cb_UnitsStopFreq->setCurrentIndex(1);
    ui->cb_UnitsRange->setCurrentIndex(1);

    // Описание взаимодействия сигналов и слотов
    connect(tcpSocket, &QTcpSocket::connected, this, &MainWindow::slotConnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::slotDisconnected);
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
    connect(this, &MainWindow::signalSendToServer, this, &MainWindow::slotSendToServer);
    connect(set_FreqSweep, &Setting_Freq_Sweep::sign_RunFreqSweep, this, &MainWindow::slotRunFreqSweep);
    connect(this, &MainWindow::signalGetData, set_FreqSweep, &Setting_Freq_Sweep::slotGetData);
    connect(this, &MainWindow::signalGetSweepData, this, &MainWindow::slotGetSweepData);
    connect(this, &MainWindow::signalGetModData, this, &MainWindow::slotGetModData);

    log_commands = new QFile(QDir::currentPath() + "/log_commands.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Обработка пролистывания лога предыдущих команд
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString widget = QApplication::focusWidget()->objectName();
    QStringList commands;
    QRegExp regExp("\\s-\\s(.+)\\n$");
    if(event->key() == Qt::Key_Up && widget == "le_Command")
    {
        try
        {
            if(!log_commands->open(QIODevice::ReadOnly | QFile::Text))
            {
               throw std::exception();
            }
            else
            {
                commands.clear();
                while (!log_commands->atEnd())
                {
                    regExp.indexIn(log_commands->readLine());
                    commands << regExp.cap(1);
                }

                if(countPressBut < commands.count())
                {
                    countPressBut++;
                    ui->le_Command->setText(commands.at(commands.count() - countPressBut));
                }
            }
        }
        catch(std::exception &err)
        {
            QMessageBox::warning(this, "Ошибка чтения файла команд.", err.what(), QMessageBox::Ok);
        }
        log_commands->close();
    }
    else if(event->key() == Qt::Key_Down && widget == "le_Command")
    {
        try
        {
            if(!log_commands->open(QIODevice::ReadOnly | QFile::Text))
            {
                throw std::exception();
            }
            else
            {
                commands.clear();
                while (!log_commands->atEnd())
                {
                    regExp.indexIn(log_commands->readLine());
                    commands << regExp.cap(1);
                }

                if(countPressBut > 1)
                {
                    countPressBut--;
                    ui->le_Command->setText(commands.at(commands.count() - countPressBut));
                }
                else if(countPressBut == 1){
                    countPressBut--;
                    ui->le_Command->clear();
                }
            }
        }
        catch (std::exception &err)
        {
            QMessageBox::warning(this, "Ошибка чтения файла команд.", err.what(), QMessageBox::Ok);
        }
        log_commands->close();
    }
    else if((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) && ui->pb_Connection->isEnabled())
    {
        on_pb_Connection_clicked();
    }
}

QString MainWindow::delSpace(QString command)
{
    QRegExp rE("^(.+)(\n)$");
    rE.indexIn(command);
    QString result = rE.cap(1);
    return result;
}

// Обновление стандартных настроек
void MainWindow::UpdateStandart(QString response)
{
    /* ----------------------------------------- Требуется проверка на устройстве ----------------------------------------- */
    if(SMW200A->Search_StandardAPCO(delSpace(response).toStdString()) != -1)
    {
        ui->cb_AccordingToStandard->setCurrentIndex(0);
        ui->lw_AccordingToStandard->setCurrentRow(SMW200A->Search_StandardAPCO(delSpace(response).toStdString()));
    }
    else if(SMW200A->Search_Standard(delSpace(response).toStdString()) != -1)
    {
        ui->cb_AccordingToStandard->setCurrentIndex(SMW200A->Search_Standard(delSpace(response).toStdString()) + 1);
    }
    else if(delSpace(response) == "USER")
    {
        ui->cb_AccordingToStandard->setCurrentIndex(17);
    }

    /* -------------------------------------------------------------------------------------------------------------------- */

//    if(delSpace(response) == "APCOPH1C4")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(0);
//        }
//        else if(delSpace(response) == "APCOPH1CQ")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(1);
//        }
//        else if(delSpace(response) == "APCOPH2HC")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(2);
//        }
//        else if(delSpace(response) == "APCOPH2HDQ")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(3);
//        }
//        else if(delSpace(response) == "APCOPH2HD8PSKW")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(4);
//        }
//        else if(delSpace(response) == "APCOPH2HD8PSKN")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(5);
//        }
//        else if(delSpace(response) == "APCOPH1L")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(6);
//        }
//        else if(delSpace(response) == "APCOPH1W")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(0);
//            ui->lw_AccordingToStandard->setCurrentRow(7);
//        }
//        else if(delSpace(response) == "BLU")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(1);
//        }
//        else if(delSpace(response) == "CFOR")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(2);
//        }
//        else if(delSpace(response) == "CREV")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(3);
//        }
//        else if(delSpace(response) == "CWBP")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(4);
//        }
//        else if(delSpace(response) == "DECT")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(5);
//        }
//        else if(delSpace(response) == "ETC")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(6);
//        }
//        else if(delSpace(response) == "GSM")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(7);
//        }
//        else if(delSpace(response) == "GSME")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(8);
//        }
//        else if(delSpace(response) == "NADC")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(9);
//        }
//        else if(delSpace(response) == "PDC")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(10);
//        }
//        else if(delSpace(response) == "PHS")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(11);
//        }
//        else if(delSpace(response) == "TDSC")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(12);
//        }
//        else if(delSpace(response) == "TETR")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(13);
//        }
//        else if(delSpace(response) == "TFTS")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(14);
//        }
//        else if(delSpace(response) == "W3GP")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(15);
//        }
//        else if(delSpace(response) == "WORL")
//        {
//            ui->cb_AccordingToStandard->setCurrentIndex(16);
//        }
//        else ui->cb_AccordingToStandard->setCurrentIndex(17);

}

// Обновление режима модуляции
void MainWindow::UpdateModulation(QString response)
{
    if(delSpace(response) == "ASK")
    {
        ui->cb_ModType->setCurrentIndex(0);
        ui->lw_ModType->clear();
    }
    else if(SMW200A->Search_ModPSK(delSpace(response).toStdString()) != -1)
    {
        ui->cb_ModType->setCurrentIndex(1);
        ui->lw_ModType->setCurrentRow(SMW200A->Search_ModPSK(delSpace(response).toStdString()));
    }
    else if(SMW200A->Search_ModQAM(delSpace(response).toStdString()) != -1)
    {
        ui->cb_ModType->setCurrentIndex(2);
        ui->lw_ModType->setCurrentRow(SMW200A->Search_ModQAM(delSpace(response).toStdString()));
    }
    else if(SMW200A->Search_ModFSK(delSpace(response).toStdString()) != -1)
    {
        ui->cb_ModType->setCurrentIndex(3);
        ui->lw_ModType->setCurrentRow(SMW200A->Search_ModFSK(delSpace(response).toStdString()));
    }
    else if(SMW200A->Search_ModAPSK(delSpace(response).toStdString()) != -1)
    {
        ui->cb_ModType->setCurrentIndex(4);
        ui->lw_ModType->setCurrentRow(SMW200A->Search_ModAPSK(delSpace(response).toStdString()));
    }
    else if(delSpace(response) == "USER")
    {
        ui->cb_ModType->setCurrentIndex(5);
    }

//    if(delSpace(response) == "ASK")
//    {
//        ui->cb_ModType->setCurrentIndex(0);
//        ui->lw_ModType->clear();
//    }
//    else if(delSpace(response) == "BPSK")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(0);
//    }
//    else if(delSpace(response) == "QPSK")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(1);
//    }
//    else if(delSpace(response) == "QPSK45")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(2);
//    }
//    else if(delSpace(response) == "QEDG")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(3);
//    }
//    else if(delSpace(response) == "AQPS")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(4);
//    }
//    else if(delSpace(response) == "OQPS")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(5);
//    }
//    else if(delSpace(response) == "P4QP")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(6);
//    }
//    else if(delSpace(response) == "P2DB")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(7);
//    }
//    else if(delSpace(response) == "P4DQ")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(8);
//    }
//    else if(delSpace(response) == "P8D8")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(9);
//    }
//    else if(delSpace(response) == "PSK8")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(10);
//    }
//    else if(delSpace(response) == "P8ED")
//    {
//        ui->cb_ModType->setCurrentIndex(1);
//        ui->lw_ModType->setCurrentRow(11);
//    }
//    else if(delSpace(response) == "QAM16")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(0);
//    }
//    else if(delSpace(response) == "QAM16ED")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(1);
//    }
//    else if(delSpace(response) == "QAM32")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(2);
//    }
//    else if(delSpace(response) == "QAM32ED")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(3);
//    }
//    else if(delSpace(response) == "QAM64")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(4);
//    }
//    else if(delSpace(response) == "QAM128")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(5);
//    }
//    else if(delSpace(response) == "QAM256")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(6);
//    }
//    else if(delSpace(response) == "QAM512")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(7);
//    }
//    else if(delSpace(response) == "QAM1024")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(8);
//    }
//    else if(delSpace(response) == "QAM2048")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(9);
//    }
//    else if(delSpace(response) == "QAM4096")
//    {
//        ui->cb_ModType->setCurrentIndex(2);
//        ui->lw_ModType->setCurrentRow(10);
//    }
//    else if(delSpace(response) == "MSK")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(0);
//    }
//    else if(delSpace(response) == "FSK2")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(1);
//    }
//    else if(delSpace(response) == "FSK4")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(2);
//    }
//    else if(delSpace(response) == "FSK8")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(3);
//    }
//    else if(delSpace(response) == "FSK16")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(4);
//    }
//    else if(delSpace(response) == "FSK32")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(5);
//    }
//    else if(delSpace(response) == "FSK64")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(6);
//    }
//    else if(delSpace(response) == "FSKV")
//    {
//        ui->cb_ModType->setCurrentIndex(3);
//        ui->lw_ModType->setCurrentRow(7);
//    }
//    else if(delSpace(response) == "APSK16")
//    {
//        ui->cb_ModType->setCurrentIndex(4);
//        ui->lw_ModType->setCurrentRow(0);
//    }
//    else if(delSpace(response) == "APSK32")
//    {
//        ui->cb_ModType->setCurrentIndex(4);
//        ui->lw_ModType->setCurrentRow(1);
//    }
//    else if(delSpace(response) == "USER")
//    {
//        ui->lw_ModType->setCurrentRow(5);
//    }
}

// Обновление Symbol Rate
void MainWindow::UpdateSymbolRate(QString response)
{
    double symbrate = 0;
    if(ui->cb_UnitsSymRate->currentIndex() == 0)
    {
        symbrate = delSpace(response).toDouble() * pow(10, -6);
    }
    else if(ui->cb_UnitsSymRate->currentIndex() == 1)
    {
        symbrate = delSpace(response).toDouble() * pow(10, -3);
    }
    else symbrate = delSpace(response).toDouble();
    ui->le_SymbolRate->setText(QString::number(symbrate, 'g', 10));
}

/* ------------------------------- My slots -------------------------------- */

// Прием сообщения от устройства
void MainWindow::slotReadyRead()
{
    if (tcpSocket->bytesAvailable())
    {
        response_From_Device = tcpSocket->readAll();
        ui->te_Log->append(QTime::currentTime().toString() + " -  Ответ от устройства: " + response_From_Device );
    }
}

// Отправка команды на устройство
void MainWindow::slotSendToServer(string command)
{
    QRegExp regExp("\\?");
    regExp.indexIn(QString::fromStdString(command));
    QString isRequest = regExp.cap(0);
    QByteArray arrBlock = command.c_str();
    tcpSocket->write(arrBlock);
    if(!isRequest.isEmpty())
    {
        bool check = tcpSocket->waitForReadyRead(1000);
        if(!check) slotSendToServer(SMW200A->Send_Request_Error());
    }
    else
    {
        tcpSocket->waitForBytesWritten();
        slotSendToServer(SMW200A->Send_Request_Error());
    }
    log_commands->close();
}

// Вывод ошибки при подключении к устройству
void MainWindow::slotError(QAbstractSocket::SocketError error)
{
    QString strError = QTime::currentTime().toString() + " -  ";
    bool isDisconnected = false;
    switch (error)
    {
        case QAbstractSocket::ConnectionRefusedError:
            strError += "В соединении было отказано.";
            isDisconnected = true;
        break;
        case QAbstractSocket::RemoteHostClosedError:
            strError += "Удаленный хост закрыт.";
            isDisconnected = true;
        break;
        case QAbstractSocket::HostNotFoundError:
            strError += "Хост не найден.";
            isDisconnected = true;
        break;
        case QAbstractSocket::SocketAccessError:
            strError += "Операция сокета завершилась неудачно т.к. нет необходимых привилегий.";
        break;
        case QAbstractSocket::SocketResourceError:
            strError += "В системе закончились ресурсы.";
        break;
        case QAbstractSocket::SocketTimeoutError:
            strError += "Истекло время ожидания оперции сокета.";
        break;
        case QAbstractSocket::DatagramTooLargeError:
            strError += "Размер дейтаграммы превысил предел операционной системы.";
        break;
        case QAbstractSocket::NetworkError:
            strError += "Произошла ошибка сети. Проверьте подключение сетевого кабеля.";
            isDisconnected = true;
        break;
        case QAbstractSocket::AddressInUseError:
            strError += "Адрес уже используется и был установлен как эксклюзивный.";
            isDisconnected = true;
        break;
        case QAbstractSocket::SocketAddressNotAvailableError:
            strError += "Адрес не принадлежит хосту.";
            isDisconnected = true;
        break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            strError += "Запрошенная операция не поддерживается локальной операционной системой.";
        break;
        case QAbstractSocket::SslHandshakeFailedError:
            strError += "Подтверждение связи SSL/TLS не удалось. Соединение закрыто.";
        break;
        case QAbstractSocket::UnfinishedSocketOperationError:
            strError += "Операция еще не завершена. Выполняется в фоновом режиме";
        break;
        case QAbstractSocket::OperationError:
            strError += "Была предпринята попытка выполнения операции, когда сокет находился в недопустимом состоянии.";
        break;
        case QAbstractSocket::TemporaryError:
            strError += "Произошла временная ошибка.";
        break;
        case QAbstractSocket::UnknownSocketError:
            strError += "Произошла неопознанная ошибка.";
        break;
//        case QAbstractSocket::ProxyAuthenticationRequiredError:
//            strError += "Прокси требует аутентификации.";
//        break;
//        case QAbstractSocket::ProxyConnectionRefusedError:
//            strError += "Не удалось связаться с прокси-сервером.";
//        break;
//        case QAbstractSocket::ProxyConnectionClosedError:
//            strError += "Соединение с прокси-сервером было неожиданно закрыто.";
//        break;
//        case QAbstractSocket::ProxyConnectionTimeoutError:
//            strError += "Время ожидания к прокси-серверу истекло или прокси-сервер перестал отвечать на этапе проверки подлинности.";
//        break;
//        case QAbstractSocket::ProxyNotFoundError:
//            strError += "Адрес прокси не найден";
//        break;
//        case QAbstractSocket::ProxyProtocolError:
//            strError += "Соединение с прокси-сервером не удалось. Ответ от прокси-сервера не был прочитан.";
//        break;
//        case QAbstractSocket::SslInternalError:
//            strError += "Используемая библиотека SSL сообщила о внутренней ошибке.";
//        break;
//        case QAbstractSocket::SslInvalidUserDataError:
//            strError += "Были предоставлены неверные данные (сертификат, ключ, шифр и т.д.)";
//        break;
        default:
            strError += QString(tcpSocket->errorString());
    }
    if(isDisconnected)
    {
        // Активность виджетов главного окна
        ui->te_Log->append(strError);
        ui->le_Command->clear();
        ui->le_Command->setEnabled(false);
        ui->pb_Connection->setEnabled(true);
        ui->pb_Disconnect->setEnabled(false);
        ui->pb_Send->setEnabled(false);
        ui->le_Frequency->setEnabled(false);
        ui->le_Level->setEnabled(false);
        ui->le_PEP->setEnabled(false);
        ui->cb_FrequencyUnits->setEnabled(false);
        ui->cb_LevelUnits->setEnabled(false);
        ui->cb_PEPUnits_2->setEnabled(false);
        ui->action_FreqSweep->setEnabled(false);
        ui->tw_Settings->setEnabled(false);
        ui->statusbar->showMessage("Состояние: отключено.");
    }
}

// Уведомление о подключении к устройству
void MainWindow::slotConnected()
{
    ui->te_Log->append(QTime::currentTime().toString() + " -  Соединение с SMW200A установлено.\n");

    // Активность виджетов главного окна
    ui->pb_Send->setEnabled(true);
    ui->pb_Connection->setEnabled(false);
    ui->pb_Disconnect->setEnabled(true);
    ui->le_Command->setEnabled(true);
    ui->le_Frequency->setEnabled(true);
    ui->le_Level->setEnabled(true);
    ui->le_PEP->setEnabled(true);
    ui->cb_FrequencyUnits->setEnabled(true);
    ui->cb_LevelUnits->setEnabled(true);
    ui->cb_PEPUnits_2->setEnabled(true);
    ui->action_FreqSweep->setEnabled(true);
    ui->tw_Settings->setEnabled(true);
    ui->le_Command->setFocus();
    slotSendToServer(SMW200A->Send_Request_IDN());
    slotSendToServer(SMW200A->Send_Request_Error());
    ui->statusbar->showMessage("Состояние: подключено.");

    // Подгрузка текущей частоты
    slotSendToServer(SMW200A->Send_Request_Frequency());
    double result = 0;
    switch(ui->cb_FrequencyUnits->currentIndex())
    {
        case 0: // GHz
           result = response_From_Device.toDouble() / 1000000000;
           ui->le_Frequency->setText(QString::number(result));
        break;

        case 1: // MHz
           result = response_From_Device.toDouble() / 1000000;
           ui->le_Frequency->setText(QString::number(result));
        break;

        case 2: // kHz
            result = response_From_Device.toDouble() / 1000;
            ui->le_Frequency->setText(QString::number(result));
        break;

        case 3: // Hz
            ui->le_Frequency->setText(response_From_Device);
        break;
    }

    // Подгрузка текущего значения PEP
    slotSendToServer(SMW200A->Send_Request_PEP());
    double val_PEP = delSpace(response_From_Device).toDouble();
    ui->le_PEP->setText(QString::number(val_PEP));

    // Подгрузка текущего значения Level
    slotSendToServer(SMW200A->Send_Request_Level());
    double val_Level = delSpace(response_From_Device).toDouble();
    ui->le_Level->setText(QString::number(val_Level));

    // Подгрузка текущих настроек в TabWidget
    switch(ui->tw_Settings->currentIndex())
    {
        case 0:
            emit signalGetModData();
        break;

        case 1:
            emit signalGetSweepData();
        break;

        case 2:

        break;
    }
}

void MainWindow::slotDisconnected()
{
    ui->te_Log->append(QTime::currentTime().toString() + " -  Соединение прервано.");
    ui->le_Command->clear();

    // Активность виджетов главного окна
    ui->le_Command->setEnabled(false);
    ui->pb_Connection->setEnabled(true);
    ui->pb_Disconnect->setEnabled(false);
    ui->pb_Send->setEnabled(false);
    ui->le_Frequency->setEnabled(false);
    ui->le_Level->setEnabled(false);
    ui->le_PEP->setEnabled(false);
    ui->cb_FrequencyUnits->setEnabled(false);
    ui->cb_LevelUnits->setEnabled(false);
    ui->cb_PEPUnits_2->setEnabled(false);
    ui->action_FreqSweep->setEnabled(false);
    ui->tw_Settings->setEnabled(false);
    ui->statusbar->showMessage("Состояние: отключено.");
}

void MainWindow::slotRunFreqSweep(QStringList data)
{
    slotSendToServer(SMW200A->SetTriggerForSweeps(data.at(0).toInt()));                                                     // Установка триггера для развертки
    slotSendToServer(SMW200A->SetSweepFreqMode(data.at(1).toInt()));                                                        // Установка циклического режима для развертки по частоте
    slotSendToServer(SMW200A->SetSweepSpacing(data.at(2).toInt()));                                                         // Установка режима расчета частотных интервалов
    slotSendToServer(SMW200A->SetSweepShape(data.at(3).toInt()));                                                           // Установка формы сигнала для последовательности развертки частоты
    slotSendToServer(SMW200A->SetFreqStart(data.at(4).toDouble(), data.at(5).toInt()));                                     // Установка начальной частоты развертки
    slotSendToServer(SMW200A->SetFreqStop(data.at(6).toDouble(), data.at(7).toInt()));                                      // Установка конечной частоты развертки
    slotSendToServer(SMW200A->SetSweepRetrace(true));                                                                       // Активация изменения начальной частоты в ожидании следующего триггера
//    slotSendToServer(SMW200A->SetSweepResetAll());                                                                          // Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())
//    slotSendToServer(SMW200A->SetFreqSpan(data.at(8).toDouble(), data.at(9).toInt()));                                      // Установка диапазона частотной развертки
//    slotSendToServer(SMW200A->SetFreqCenter(data.at(10).toDouble(), data.at(11).toInt()));                                  // Установка центральной частоты развертки
    slotSendToServer(SMW200A->SetSweepStepLinear(data.at(12).toDouble(),data.at(4).toDouble(), data.at(6).toDouble()));     // Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START)
    slotSendToServer(SMW200A->SetSweepStepLogarithmic(data.at(12).toDouble()));                                             // Установка логарифмически определяемой ширины шага для развертки по частоте (Задается в %(PCT))
    slotSendToServer(SMW200A->SetSweepPoints(data.at(14).toInt()));                                                         // Установка количества шагов в пределах диапазона развертки
    slotSendToServer(SMW200A->SetSweepFreqDwell(data.at(15).toDouble(), data.at(16).toInt()));                              // Установка времени задержки для шага развертки по частоте
    slotSendToServer(SMW200A->SetFrequencyMode(2));                                                                         // Установка частотного режима Sweep.
    slotSendToServer(SMW200A->SweepFreqExecute());                                                                          // Запуск развертки
}

// Текущие данные для частотной развертки
void MainWindow::slotGetSweepData()
{
    slotSendToServer(SMW200A->Send_Request_TriggerForSweeps());
    if(delSpace(response_From_Device) == "AUTO")
    {
        ui->cb_TriggerSource->setCurrentIndex(0);
    }
    else if(delSpace(response_From_Device) == "IMM")
    {
        ui->cb_TriggerSource->setCurrentIndex(1);
    }
    else if(delSpace(response_From_Device) == "SING")
    {
        ui->cb_TriggerSource->setCurrentIndex(2);
    }
    else if(delSpace(response_From_Device) == "BUS")
    {
        ui->cb_TriggerSource->setCurrentIndex(3);
    }
    else if(delSpace(response_From_Device) == "EXT")
    {
        ui->cb_TriggerSource->setCurrentIndex(4);
    }
    else ui->cb_TriggerSource->setCurrentIndex(5);


    // Режим развертки по частоте
    slotSendToServer(SMW200A->Send_Request_SweepFreqMode());
    if(delSpace(response_From_Device) == "AUTO")
    {
        ui->cb_SweepFreqMode->setCurrentIndex(0);
    }
    else if(delSpace(response_From_Device) == "MAN")
    {
        ui->cb_SweepFreqMode->setCurrentIndex(1);
    }
    else ui->cb_SweepFreqMode->setCurrentIndex(2);


    //Режим расчета частотных интервалов
    slotSendToServer(SMW200A->Send_Request_SweepSpacing());
    if(delSpace(response_From_Device) == "LIN")
    {
        ui->cb_SweepSpacing->setCurrentIndex(0);
    }
    else ui->cb_SweepSpacing->setCurrentIndex(1);


    // Форма сигнала
    slotSendToServer(SMW200A->Send_Request_SweepShape());
    if(delSpace(response_From_Device) == "SAWT")
    {
        ui->cb_SweepShape->setCurrentIndex(0);
    }
    else ui->cb_SweepShape->setCurrentIndex(1);


    // Текущая начальная частота
    slotSendToServer(SMW200A->Send_Request_FreqStart());
    double translate_Freq = 0;
    switch (ui->cb_UninsStartFreq->currentIndex())
    {
        case 0:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = delSpace(response_From_Device).toDouble();
        break;
    }
    ui->le_StartFreq->setText(QString::number(translate_Freq,'g', 10));

    // Текущая конечная частота
    slotSendToServer(SMW200A->Send_Request_FreqStop());
    switch (ui->cb_UnitsStopFreq->currentIndex())
    {
        case 0:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = delSpace(response_From_Device).toDouble();
        break;
    }
    ui->le_StopFreq->setText(QString::number(translate_Freq,'g', 10));


    // Текущий диапазон
    slotSendToServer(SMW200A->Send_Request_FreqSpan());
    switch (ui->cb_UnitsRange->currentIndex())
    {
        case 0:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = delSpace(response_From_Device).toDouble();
        break;
    }
    ui->le_SpanFreq->setText(QString::number(translate_Freq,'g', 10));

    // Текущая центральная частота
    slotSendToServer(SMW200A->Send_Request_FreqCenter());
    switch (ui->cb_UninsCenter->currentIndex())
    {
        case 0:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = delSpace(response_From_Device).toDouble();
        break;
    }
    ui->le_CenterFreq->setText(QString::number(translate_Freq,'g', 10));


    // Текущий тип шага и его значение (Линейный или Логарифмический)
    if(ui->cb_SweepSpacing->currentText() == "Linear")
    {
        slotSendToServer(SMW200A->Send_Request_SweepStepLinear());
        switch (ui->cb_UnitsLinStep->currentIndex())
        {
            case 0:
                translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 9);
            break;

            case 1:
                translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 6);
            break;

            case 2:
                translate_Freq = delSpace(response_From_Device).toDouble() / pow(10, 3);
            break;

            case 3:
                translate_Freq = delSpace(response_From_Device).toDouble();
            break;
        }
        ui->le_StepSweep->setText(QString::number(translate_Freq,'g', 10));
    }
    else
    {
        slotSendToServer(SMW200A->Send_Request_SweepStepLogarithmic());
        ui->le_StepSweep->setText(delSpace(response_From_Device));
    }

    // Текущее количество точек
    slotSendToServer(SMW200A->Send_Request_SweepPoints());
    ui->le_SweepPoints->setText(delSpace(response_From_Device));

    // Текущее время задержки
    slotSendToServer(SMW200A->Send_Request_SweepFreqDwell());
    ui->le_SweepDwell->setText(delSpace(response_From_Device));
}

// Текущие данные для настроек модуляции
void MainWindow::slotGetModData()
{
    // Текущий стандарт
    slotSendToServer(SMW200A->Send_Request_Standard());
    UpdateStandart(response_From_Device);

    slotSendToServer(SMW200A->Send_Request_ModType());
    UpdateModulation(response_From_Device);

    slotSendToServer(SMW200A->Send_Request_SymbolRate());
    UpdateSymbolRate(response_From_Device);

}
/* ---------------------------- My slots end ----------------------------- */

/* ----------------------------- Push buttons -----------------------------*/

// Кнопка для отправки команды
void MainWindow::on_pb_Send_clicked()
{
    QRegExp regExp("^(\\s+)$");
    regExp.indexIn(ui->le_Command->text());
    QString isPressSpace = regExp.cap(0);
    bool isEmpty = ui->le_Command->displayText().isEmpty();
    if(!isEmpty && isPressSpace.isEmpty())
    {
        ui->te_Log->append(QTime::currentTime().toString() + " -  Отправлена команда: " + ui->le_Command->text());
        if(!log_commands->open(QIODevice::Append | QFile::Text))
        {
            QMessageBox::critical(this, "Ошибка!", "Не удалось открыть файл.", QMessageBox::Ok);
        }
        else
        {
            QTextStream out(log_commands);
            out << QDateTime::currentDateTime().toString() << " - " << ui->le_Command->text() << endl;
        }
        emit signalSendToServer(ui->le_Command->text().toStdString() + "\n");
    }
    ui->le_Command->clear();
    countPressBut = 0;
}

// Кнопка подключения к устройству
void MainWindow::on_pb_Connection_clicked()
{
    tcpSocket->connectToHost(SMW_ADDRESS, SMW_PORT);
    ui->te_Log->append("Ожидание подключения ...");
    ui->pb_Connection->setEnabled(false);
}

// Кнопка отключения от устройства
void MainWindow::on_pb_Disconnect_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->waitForDisconnected();
}

// Отправка команды при нажатии на Enter при фокусе на le_Command
void MainWindow::on_le_Command_returnPressed()
{
    QRegExp regExp("^(\\s+)$");
    regExp.indexIn(ui->le_Command->text());
    QString isPressSpace = regExp.cap(0);
    bool isEmpty = ui->le_Command->displayText().isEmpty();
    if(!isEmpty && isPressSpace.isEmpty())
    {
        ui->te_Log->append(QTime::currentTime().toString() + " -  Отправлена команда: " + ui->le_Command->text());
        if(!log_commands->open(QIODevice::Append | QFile::Text))
        {
            QMessageBox::critical(this, "Ошибка!", "Не удалось открыть файл.", QMessageBox::Ok);
        }
        else
        {
            QTextStream out(log_commands);
            out << QDateTime::currentDateTime().toString() << " - " << ui->le_Command->text() << endl;
        }
        emit signalSendToServer(ui->le_Command->text().toStdString() + "\n");
    }
    ui->le_Command->clear();
    countPressBut = 0;
}

// Кнопка запуска частотной развертки
void MainWindow::on_pb_StartFreqSweep_clicked()
{
    QStringList sweep_options;
    sweep_options.append(QString::number(ui->cb_TriggerSource->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepFreqMode->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepSpacing->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepShape->currentIndex()));

    double translate_Freq = 0;
    switch (ui->cb_UninsStartFreq->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_StartFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_StartFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_StartFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_StartFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UnitsStopFreq->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_StopFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_StopFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_StopFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_StopFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UnitsRange->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_SpanFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_SpanFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_SpanFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_SpanFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UninsCenter->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_CenterFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_CenterFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_CenterFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_CenterFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UnitsLinStep->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_StepSweep->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_StepSweep->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_StepSweep->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_StepSweep->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    sweep_options.append(ui->le_SweepPoints->text());
    sweep_options.append(ui->le_SweepDwell->text());
    sweep_options.append(QString::number(ui->cb_UnitsSweepDwell->currentIndex()));
    slotRunFreqSweep(sweep_options);
    sweep_options.clear();
}

// Кнопка останова частотной развертки
void MainWindow::on_pb_StopFreqSweep_clicked()
{
    slotSendToServer(SMW200A->SetFrequencyMode(0));
}

// Кнопка сбороcа частотной развертки в начальное значение
void MainWindow::on_pb_ResetFreqSweep_clicked()
{
    slotSendToServer(SMW200A->SetFrequency(ui->le_StartFreq->text().toDouble(), ui->cb_UninsStartFreq->currentIndex()));
}
/* -------------------------- Push buttons end --------------------------- */

// Установка Frequency. При смене фокуса или при нажатии на Enter отправляются данные на устройство.
void MainWindow::on_le_Frequency_editingFinished()
{
    string command = SMW200A->SetFrequency(ui->le_Frequency->text().toDouble(), ui->cb_FrequencyUnits->currentIndex());
    ui->te_Log->append(QTime::currentTime().toString() + " -  Установлено значение Frequency : " + QString::fromStdString(command));
    emit signalSendToServer(command);
}

// Установка PEP. При смене фокуса или при нажатии на Enter отправляются данные на устройство.
void MainWindow::on_le_PEP_editingFinished()
{
    string command = SMW200A->SetPower(ui->le_PEP->text().toDouble(), ui->cb_PEPUnits_2->currentIndex());
    ui->te_Log->append(QTime::currentTime().toString() + " -  Установлено значение PEP : " + QString::fromStdString(command));
    emit signalSendToServer(command);
    slotSendToServer(SMW200A->Send_Request_Level());
    double val_Level = delSpace(response_From_Device).toDouble();
    ui->le_Level->setText(QString::number(val_Level));
}

// Установка Level. При смене фокуса или при нажатии на Enter отправляются данные на устройство.
void MainWindow::on_le_Level_editingFinished()
{
    string command = SMW200A->SetLevel(ui->le_Level->text().toDouble(), ui->cb_LevelUnits->currentIndex());
    ui->te_Log->append(QTime::currentTime().toString() + " -  Установлено значение Level : " + QString::fromStdString(command));
    emit signalSendToServer(command);
    slotSendToServer(SMW200A->Send_Request_PEP());
    double val_PEP = delSpace(response_From_Device).toDouble();
    ui->le_PEP->setText(QString::number(val_PEP, 'g', 4));
}

// Настройка единиц измерения частоты при переключении
void MainWindow::on_cb_FrequencyUnits_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "GHz")
    {

    }
    else if(arg1 == "MHz")
    {

    }
    else if (arg1 == "kHz")
    {

    }
    else
    {

    }
}


// Action для вызова настроек развертки по частоте
void MainWindow::on_action_FreqSweep_triggered()
{
    QStringList data;
    slotSendToServer(SMW200A->Send_Request_TriggerForSweeps());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepFreqMode());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepSpacing());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepShape());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_FreqStart());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_FreqStop());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_FreqSpan());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_FreqCenter());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepStepLinear());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepStepLogarithmic());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepPoints());
    data.append(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_SweepFreqDwell());
    data.append(delSpace(response_From_Device));

    emit signalGetData(data);
    data.clear();
    set_FreqSweep->exec();
}


// Загрузка текущих данных при переключении вкладок
void MainWindow::on_tw_Settings_tabBarClicked(int index)
{
    switch(index)
    {
        case 0:
            emit signalGetModData();
        break;

        case 1:
            emit signalGetSweepData();
        break;

        case 2:

        break;
    }

}

// Переключения режима расчета частотных интервалов
void MainWindow::on_cb_SweepSpacing_currentIndexChanged(const QString &arg1)
{
    arg1 == "Linear" ? ui->cb_UnitsLinStep->setEnabled(true) : ui->cb_UnitsLinStep->setEnabled(false);
}

// Переключение страндартных настроек
void MainWindow::on_cb_AccordingToStandard_currentIndexChanged(int index)
{
    int newIndex = index - 1;

    if(newIndex == -1)
    {
        ui->lw_AccordingToStandard->setEnabled(true);
    }
    else if(newIndex != 16)
    {
        ui->lw_AccordingToStandard->setCurrentRow(-1);
        ui->lw_AccordingToStandard->setEnabled(false);
        slotSendToServer(SMW200A->SetAccordingToStandard(newIndex, 0));
        slotSendToServer(SMW200A->Send_Request_ModType());
        UpdateModulation(response_From_Device);
        slotSendToServer(SMW200A->Send_Request_SymbolRate());
        UpdateSymbolRate(response_From_Device);
    }
    else ui->lw_AccordingToStandard->setEnabled(false);
}
void MainWindow::on_lw_AccordingToStandard_currentRowChanged(int currentRow)
{
    slotSendToServer(SMW200A->SetAccordingToStandard(currentRow, 1));
    slotSendToServer(SMW200A->Send_Request_ModType());
    UpdateModulation(response_From_Device);
    slotSendToServer(SMW200A->Send_Request_SymbolRate());
    UpdateSymbolRate(response_From_Device);
}

// Переключение настроек модуляции
void MainWindow::on_cb_ModType_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->lw_ModType->setEnabled(false);
    }
    else ui->lw_ModType->setEnabled(true);
    switch(index)
    {
        case 0:
            ui->lw_ModType->clear();
            slotSendToServer(SMW200A->SetModulationType(0, ui->cb_ModType->currentIndex())); // Для установки типа ASK первым параметром указываем любое целочисленное число
            slotSendToServer(SMW200A->Send_Request_Standard());
            UpdateStandart(response_From_Device);
            slotSendToServer(SMW200A->Send_Request_SymbolRate());
            UpdateSymbolRate(response_From_Device);
        break;

        case 1:
            ui->lw_ModType->clear();
            ui->lw_ModType->addItem("BPSK");
            ui->lw_ModType->addItem("QPSK");
            ui->lw_ModType->addItem("QPSK 45 Offset");
            ui->lw_ModType->addItem("QPSK EDGE");
            ui->lw_ModType->addItem("AQPSK");
            ui->lw_ModType->addItem("OQPSK");
            ui->lw_ModType->addItem("PI/4-QPSK");
            ui->lw_ModType->addItem("PI/2-DBPSK");
            ui->lw_ModType->addItem("PI/4-DQPSK");
            ui->lw_ModType->addItem("PI/8-D8PSK");
            ui->lw_ModType->addItem("8PSK");
            ui->lw_ModType->addItem("8PSK EDGE");
        break;

        case 2:
            ui->lw_ModType->clear();
            ui->lw_ModType->addItem("16QAM");
            ui->lw_ModType->addItem("16QAM EDGE");
            ui->lw_ModType->addItem("32QAM");
            ui->lw_ModType->addItem("32QAM EDGE");
            ui->lw_ModType->addItem("64QAM");
            ui->lw_ModType->addItem("128QAM");
            ui->lw_ModType->addItem("256QAM");
            ui->lw_ModType->addItem("512QAM");
            ui->lw_ModType->addItem("1024QAM");
            ui->lw_ModType->addItem("2048QAM");
            ui->lw_ModType->addItem("4096QAM");
        break;

        case 3:
            ui->lw_ModType->clear();
            ui->lw_ModType->addItem("MSK");
            ui->lw_ModType->addItem("2FSK");
            ui->lw_ModType->addItem("4FSK");
            ui->lw_ModType->addItem("8FSK");
            ui->lw_ModType->addItem("16FSK");
            ui->lw_ModType->addItem("32FSK");
            ui->lw_ModType->addItem("64FSK");
            ui->lw_ModType->addItem("Variable FSK");
        break;

        case 4:
            ui->lw_ModType->clear();
            ui->lw_ModType->addItem("16APSK");
            ui->lw_ModType->addItem("32APSK");
        break;

        case 5:
            ui->lw_ModType->clear();
            ui->lw_ModType->setEnabled(false);
        break;
    }
}
void MainWindow::on_lw_ModType_currentRowChanged(int currentRow)
{
    int current_type = ui->cb_ModType->currentIndex();
    slotSendToServer(SMW200A->SetModulationType(currentRow, current_type));
    slotSendToServer(SMW200A->Send_Request_Standard());
    UpdateStandart(response_From_Device);
    slotSendToServer(SMW200A->Send_Request_SymbolRate());
    UpdateSymbolRate(response_From_Device);

}
