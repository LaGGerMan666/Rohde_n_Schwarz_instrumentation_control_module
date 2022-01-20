#ifndef SETTING_FREQ_SWEEP_H
#define SETTING_FREQ_SWEEP_H

#include <QDialog>

namespace Ui {
class Setting_Freq_Sweep;
}

class Setting_Freq_Sweep : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_Freq_Sweep(QWidget *parent = nullptr);
    ~Setting_Freq_Sweep();

private:
    Ui::Setting_Freq_Sweep *ui;
};

#endif // SETTING_FREQ_SWEEP_H
