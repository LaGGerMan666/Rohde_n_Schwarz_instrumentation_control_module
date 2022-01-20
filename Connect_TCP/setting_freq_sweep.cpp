#include "setting_freq_sweep.h"
#include "ui_setting_freq_sweep.h"

Setting_Freq_Sweep::Setting_Freq_Sweep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_Freq_Sweep)
{
    ui->setupUi(this);
}

Setting_Freq_Sweep::~Setting_Freq_Sweep()
{
    delete ui;
}
