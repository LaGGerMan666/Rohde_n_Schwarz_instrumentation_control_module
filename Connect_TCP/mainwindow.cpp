#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    SMW200A = new RnSSCPI();

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
    ui->mdiArea->setEnabled(false);
    ui->statusbar->showMessage("Состояние: отключено.");

    // Настройка условия заполнения полей ввода
    QRegExp correctFrequence("^(\\d+(\\.\\d+)?)$");
    QRegExp correctPepAndLevel("^(-?\\d{1,4}(\\.\\d{1,3})?)$");
    ui->le_Frequency->setValidator(new QRegExpValidator(correctFrequence, this));
    ui->le_PEP->setValidator(new QRegExpValidator(correctPepAndLevel, this));
    ui->le_Level->setValidator(new QRegExpValidator(correctPepAndLevel, this));

    // Работа с MdiArea и MdiSubWindow

    myFirstSubWin = new QMdiSubWindow();
    myFirstSubWin->setWindowTitle("BaseBand");
    myFirstSubWin->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    ui->mdiArea->addSubWindow(myFirstSubWin);
    QList<QMdiSubWindow*> subWinList;
    subWinList = ui->mdiArea->subWindowList();
    myFirstSubWin->resize(105, 100);


    QCheckBox *ch = new QCheckBox();
    QVBoxLayout *vbox = new QVBoxLayout(ui->mdiArea);
    vbox->addWidget(myFirstSubWin);
    myFirstSubWin->show();
    ch->setObjectName("check");
    myFirstSubWin->setWidget(ch);

    // Описание взаимодействия сигналов и слотов
    connect(tcpSocket, &QTcpSocket::connected, this, &MainWindow::slotConnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::slotDisconnected);
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
    connect(this, &MainWindow::signalSendToServer, this, &MainWindow::slotSendToServer);

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
        if(log_commands->exists() && log_commands->open(QIODevice::ReadOnly | QFile::Text))
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
        else
        {
            QMessageBox::warning(this, "Ошибка!", "Не удалось прочитать лог последних команд", QMessageBox::Ok);
        }
        log_commands->close();
    }
    else if(event->key() == Qt::Key_Down && widget == "le_Command")
    {
        if(log_commands->exists() && log_commands->open(QIODevice::ReadOnly | QFile::Text))
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
        else
        {
            QMessageBox::warning(this, "Ошибка!", "Не удалось прочитать лог последних команд", QMessageBox::Ok);
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

/* ----------------------------- My slots ----------------------------- */

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
void MainWindow::slotSendToServer(QString command)
{
    QRegExp regExp("\\?");
    regExp.indexIn(command);
    QString isRequest = regExp.cap(0);
    //command += "\n";
    QByteArray arrBlock = command.toStdString().c_str();
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
//            break;
//        case QAbstractSocket::ProxyConnectionRefusedError:
//            strError += "Не удалось связаться с прокси-сервером.";
//            break;
//        case QAbstractSocket::ProxyConnectionClosedError:
//            strError += "Соединение с прокси-сервером было неожиданно закрыто.";
//            break;
//        case QAbstractSocket::ProxyConnectionTimeoutError:
//            strError += "Время ожидания к прокси-серверу истекло или прокси-сервер перестал отвечать на этапе проверки подлинности.";
//            break;
//        case QAbstractSocket::ProxyNotFoundError:
//            strError += "Адрес прокси не найден";
//            break;
//        case QAbstractSocket::ProxyProtocolError:
//            strError += "Соединение с прокси-сервером не удалось. Ответ от прокси-сервера не был прочитан.";
//            break;
//        case QAbstractSocket::SslInternalError:
//            strError += "Используемая библиотека SSL сообщила о внутренней ошибке.";
//            break;
//        case QAbstractSocket::SslInvalidUserDataError:
//            strError += "Были предоставлены неверные данные (сертификат, ключ, шифр и т.д.)";
//            break;


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
        ui->mdiArea->setEnabled(false);
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
    ui->mdiArea->setEnabled(true);
    ui->le_Command->setFocus();

    slotSendToServer(SMW200A->Send_Request_IDN());
    slotSendToServer(SMW200A->Send_Request_Error());
    ui->statusbar->showMessage("Состояние: подключено.");

    slotSendToServer(SMW200A->Send_Request_Frequency());
    double result;
    switch(ui->cb_FrequencyUnits->currentIndex())
    {
        case 0: // GHz
           result = response_From_Device.toDouble() /1000000000;
           ui->le_Frequency->setText(QString::number(result));
        break;

        case 1: // MHz
           result = response_From_Device.toDouble() /1000000;
           ui->le_Frequency->setText(QString::number(result));
        break;

        case 2: // kHz
            result = response_From_Device.toDouble() /1000;
            ui->le_Frequency->setText(QString::number(result));
        break;

        case 3: // Hz
            ui->le_Frequency->setText(response_From_Device);
        break;
    }
    slotSendToServer(SMW200A->Send_Request_PEP());
    ui->le_PEP->setText(delSpace(response_From_Device));

    slotSendToServer(SMW200A->Send_Request_Level());
    ui->le_Level->setText(delSpace(response_From_Device));


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
    ui->mdiArea->setEnabled(false);
    ui->statusbar->showMessage("Состояние: отключено.");
}


/* ----------------------------- Push buttons -----------------------------*/

// Кнопка для отправки команды (реализовано через "connect")
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
        emit signalSendToServer(ui->le_Command->text() + "\n");
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
        emit signalSendToServer(ui->le_Command->text() + "\n");
    }
    ui->le_Command->clear();
    countPressBut = 0;
}

// Установка Frequency. При смене фокуса или при нажатии на Enter отправляются данные на устройство.
void MainWindow::on_le_Frequency_editingFinished()
{
    QString command = SMW200A->SetFrequency(ui->le_Frequency->text(), ui->cb_FrequencyUnits->currentIndex());
    ui->te_Log->append(QTime::currentTime().toString() + " -  Установлено значение Frequency : " + command);
    emit signalSendToServer(command);
}

// Установка PEP. При смене фокуса или при нажатии на Enter отправляются данные на устройство.
void MainWindow::on_le_PEP_editingFinished()
{
    QString command = SMW200A->SetPower(ui->le_PEP->text(), ui->cb_PEPUnits_2->currentIndex());
    ui->te_Log->append(QTime::currentTime().toString() + " -  Установлено значение PEP : " + command);
    emit signalSendToServer(command);
    slotSendToServer(SMW200A->Send_Request_Level());
    ui->le_Level->setText(delSpace(response_From_Device));
}

// Установка Level. При смене фокуса или при нажатии на Enter отправляются данные на устройство.
void MainWindow::on_le_Level_editingFinished()
{
    QString command = SMW200A->SetLevel(ui->le_Level->text(), ui->cb_LevelUnits->currentIndex());
    ui->te_Log->append(QTime::currentTime().toString() + " -  Установлено значение Level : " + command);
    emit signalSendToServer(command);
    slotSendToServer(SMW200A->Send_Request_PEP());
    ui->le_PEP->setText(delSpace(response_From_Device));
}

// Настройка единиц измерения частоты при переключении
void MainWindow::on_cb_FrequencyUnits_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "GHz")
    {
//        ui->le_Frequency->setInputMask("9.999999999999");
    }
    else if(arg1 == "MHz")
    {
//        ui->le_Frequency->setInputMask("9999.999999999");
    }
    else if (arg1 == "kHz")
    {
//        ui->le_Frequency->setInputMask("9999999.999999");
    }
    else
    {
//        ui->le_Frequency->setInputMask("9999999999.999");
    }
}







