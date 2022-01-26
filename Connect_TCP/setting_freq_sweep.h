#ifndef SETTING_FREQ_SWEEP_H
#define SETTING_FREQ_SWEEP_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QRegExp>
#include <QStringList>
#include <cmath>

using namespace std;

namespace Ui {
class Setting_Freq_Sweep;
}

class Setting_Freq_Sweep : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_Freq_Sweep(QWidget *parent = nullptr);
    ~Setting_Freq_Sweep();

signals:
    void sign_RunFreqSweep(QStringList);

public slots:
    void slotGetData(QStringList data);

private slots:

    void on_pb_StartFreqSweep_clicked();

    void on_cb_SweepSpacing_currentIndexChanged(const QString &arg1);



private:
    QStringList sweep_options;

private:
    Ui::Setting_Freq_Sweep *ui;
};

#endif // SETTING_FREQ_SWEEP_H
