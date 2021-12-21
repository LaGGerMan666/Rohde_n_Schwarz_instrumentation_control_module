#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QMessageBox>
#include <QTime>

class Tcp_socket : public QObject
{
    Q_OBJECT
public:
    Tcp_socket(QTcpSocket *socket);

public:
    QString slotReadyRead();

private:
    void sendToServer(QString message);

private:
    QTcpSocket *tcpSocket;
};

#endif // TCP_SOCKET_H
