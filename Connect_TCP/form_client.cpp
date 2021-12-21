#include "form_client.h"
#include "ui_form_client.h"

Form_Client::Form_Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Client)
{
    ui->setupUi(this);
    ui->te_Log->setReadOnly(true);
    ui->pb_Disconnect->setEnabled(false);
    ui->le_Command->setEnabled(false);
    ui->pb_Send->setEnabled(false);

    tcpSocket = new QTcpSocket(this);

    //А здесь все робит
    connect(tcpSocket, &QTcpSocket::connected, this, &Form_Client::slotConnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Form_Client::slotReadyRead);
    connect(ui->le_Command, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));
    connect(ui->pb_Send, SIGNAL(clicked()), this, SLOT(slotSendToServer()));

}

Form_Client::~Form_Client()
{
    delete ui;
}

// Отправка команды, но до этого еще далеко
void Form_Client::on_pb_Send_clicked()
{

}

// Установка соединения с сервером
void Form_Client::on_pb_Connection_clicked()
{
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("localhost", 2323);

    ui->pb_Connection->setEnabled(false);
    ui->pb_Disconnect->setEnabled(true);
    ui->le_Command->setEnabled(true);
    ui->pb_Send->setEnabled(true);
}

// Отключение от сервера
void Form_Client::on_pb_Disconnect_clicked()
{
    ui->pb_Connection->setEnabled(true);
    ui->pb_Disconnect->setEnabled(false);
    ui->le_Command->clear();
    ui->le_Command->setEnabled(false);
    ui->te_Log->clear();
    tcpSocket->disconnect();
}

void Form_Client::slotReadyRead()
{
    QString result;
    if (this->tcpSocket->bytesAvailable()) {
        result = tcpSocket->readAll();
    }

    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_12);
    while (true)
    {
        if(!nextBlockSize)
        {
            if(tcpSocket->bytesAvailable() < sizeof(quint16))
            {
                break;
            }
            in >> nextBlockSize;
        }
        if(tcpSocket->bytesAvailable() < nextBlockSize)
        {
            break;
        }

        QTime time;
        QString str;
        in >> time >> str;
        ui->te_Log->append(time.toString() + ":  " + result);
        nextBlockSize = 0;
    }
}

void Form_Client::slotError()
{
    QString strError = this->tcpSocket->errorString();
    ui->te_Log->append(strError);
}

void Form_Client::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << quint16(0) << QTime::currentTime() << ui->le_Command->text();
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    tcpSocket->write(arrBlock);
    ui->le_Command->clear();
}

void Form_Client::slotConnected()
{
    ui->te_Log->append("Получен сигнал connected ().");
}

