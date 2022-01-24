#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QMessageBox>
#include <QTextStream>
#include <QKeyEvent>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QMdiArea>
#include <QMdiSubWindow>
#include "rnsscpi.h"
#include "setting_freq_sweep.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalSendToServer(string);

public:
    void keyPressEvent(QKeyEvent *event);
    QString delSpace(QString command);

private slots:
    void slotReadyRead();

    void slotError(QAbstractSocket::SocketError);

    void slotSendToServer(string);

    void slotConnected();

    void slotDisconnected();

    void slotRunFreqSweep(QStringList data);

    void on_pb_Send_clicked();

    void on_pb_Connection_clicked();

    void on_pb_Disconnect_clicked();

    void on_le_Command_returnPressed();

    void on_le_Frequency_editingFinished();

    void on_cb_FrequencyUnits_currentIndexChanged(const QString &arg1);

    void on_le_PEP_editingFinished();

    void on_le_Level_editingFinished();

    void on_action_FreqSweep_triggered();

private:
    QTcpSocket *tcpSocket;
    QString SMW_ADDRESS = "172.16.13.41"; //42
    quint16 SMW_PORT = 5025;
    QString response_From_Device;
    QFile *log_commands;
    int countPressBut = 0;
    QMdiSubWindow *myFirstSubWin;
    RnSSCPI *SMW200A;
    Setting_Freq_Sweep *set_FreqSweep;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
