#ifndef FORM_CLIENT_H
#define FORM_CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QMessageBox>
#include <QtNetwork>
#include <QTime>

namespace Ui {
class Form_Client;
}

class Form_Client : public QWidget
{
    Q_OBJECT

private:
    QTcpSocket *tcpSocket;
    quint16 nextBlockSize = 0; // Хранит длину следующего полученного блока от сокета
    quint16 SMW_PORT = 5025;

public:
    explicit Form_Client(QWidget *parent = nullptr);
    ~Form_Client();

private slots:
    void on_pb_Send_clicked();

    void on_pb_Connection_clicked();

    void on_pb_Disconnect_clicked();

    void slotReadyRead();

    void slotError();

    void slotSendToServer();

    void slotConnected();

private:
    Ui::Form_Client *ui;
};

#endif // FORM_CLIENT_H
