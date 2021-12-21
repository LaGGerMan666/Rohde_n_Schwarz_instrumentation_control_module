#include "tcp_socket.h"

Tcp_socket::Tcp_socket(QTcpSocket *socket)
{
    tcpSocket = socket;

    connect(tcpSocket, &QTcpSocket::readyRead, this, &Tcp_socket::slotReadyRead);
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotConnectionError(QAbstractSocket::SocketError)));


}

QString Tcp_socket::slotReadyRead()
{
    QString answer;
    if(tcpSocket->bytesAvailable())
    {
        answer = tcpSocket->readAll();
        return answer;
    }
}

void Tcp_socket::sendToServer(QString message)
{
    QByteArray arrBlock = message.toStdString().c_str();
    tcpSocket->write(arrBlock);
}
