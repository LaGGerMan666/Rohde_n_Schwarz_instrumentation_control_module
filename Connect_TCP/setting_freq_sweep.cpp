#include "setting_freq_sweep.h"
#include "ui_setting_freq_sweep.h"

Setting_Freq_Sweep::Setting_Freq_Sweep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_Freq_Sweep)
{
    ui->setupUi(this);

    // Валидация полей ввода
    // В будущем переписать регулярки для меньшего количества симолов, а пока так
    QRegExp correctDouble("^(\\d+(\\.\\d+)?)$");
    QRegExp correctInt("^\\d+$");
    ui->le_StartFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_StopFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_SpanFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_CenterFreq->setValidator(new QRegExpValidator(correctDouble));
    ui->le_StepSweep->setValidator(new QRegExpValidator(correctDouble));
    ui->le_SweepDwell->setValidator(new QRegExpValidator(correctDouble));
    ui->le_SweepPoints->setValidator(new QRegExpValidator(correctInt));

    // Начальные значения полей
    ui->le_StartFreq->setText("0");
    ui->le_StopFreq->setText("0");
    ui->le_CenterFreq->setText("0");
    ui->le_SpanFreq->setText("0");
    ui->le_StepSweep->setText("1");
    ui->le_SweepDwell->setText("1");
    ui->le_SweepPoints->setText("0");
    ui->cb_UnitsLinStep->setCurrentIndex(3);
    ui->cb_UninsCenter->setCurrentIndex(3);
    ui->cb_UninsStartFreq->setCurrentIndex(3);
    ui->cb_UnitsStopFreq->setCurrentIndex(3);
    ui->cb_UnitsRange->setCurrentIndex(3);


}

Setting_Freq_Sweep::~Setting_Freq_Sweep()
{
    delete ui;
}

void Setting_Freq_Sweep::slotGetData(QStringList data)
{
    ui->le_StartFreq->setText(data.at(4));
    ui->le_StopFreq->setText(data.at(5));
    ui->le_SpanFreq->setText(data.at(6));
    ui->le_CenterFreq->setText(data.at(7));
    ui->le_StepSweep->setText(data.at(8));
    ui->le_SweepPoints->setText(data.at(9));
    ui->le_SweepDwell->setText(data.at(10));

}

void Setting_Freq_Sweep::on_pb_StartFreqSweep_clicked()
{
    sweep_options.append(QString::number(ui->cb_TriggerSource->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepFreqMode->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepSpacing->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepShape->currentIndex()));
    sweep_options.append(ui->le_StartFreq->text());
    sweep_options.append(QString::number(ui->cb_UninsStartFreq->currentIndex()));
    sweep_options.append(ui->le_StopFreq->text());
    sweep_options.append(QString::number(ui->cb_UnitsStopFreq->currentIndex()));
    sweep_options.append(ui->le_SpanFreq->text());
    sweep_options.append(QString::number(ui->cb_UnitsRange->currentIndex()));
    sweep_options.append(ui->le_CenterFreq->text());
    sweep_options.append(QString::number(ui->cb_UninsCenter->currentIndex()));
    sweep_options.append(ui->le_StepSweep->text());
    sweep_options.append(QString::number(ui->cb_UnitsLinStep->currentIndex()));
    sweep_options.append(ui->le_SweepPoints->text());
    sweep_options.append(ui->le_SweepDwell->text());
    sweep_options.append(QString::number(ui->cb_UnitsSweepDwell->currentIndex()));
    emit sign_RunFreqSweep(sweep_options);
    sweep_options.clear();
}


void Setting_Freq_Sweep::on_cb_SweepSpacing_currentIndexChanged(const QString &arg1)
{
    arg1 == "Linear" ? ui->cb_UnitsLinStep->setEnabled(true) : ui->cb_UnitsLinStep->setEnabled(false);
}

