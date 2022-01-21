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
    ui->cb_UnitsLinStep->setCurrentIndex(1);
    ui->cb_UninsCenter->setCurrentIndex(1);
    ui->cb_UninsStartFreq->setCurrentIndex(1);
    ui->cb_UnitsStopFreq->setCurrentIndex(1);
    ui->cb_UnitsRange->setCurrentIndex(1);


}

Setting_Freq_Sweep::~Setting_Freq_Sweep()
{
    delete ui;
}

void Setting_Freq_Sweep::on_pb_StartFreqSweep_clicked()
{
    sweep_options.append(ui->cb_TriggerSource->currentText());
    sweep_options.append(ui->cb_SweepFreqMode->currentText());
    sweep_options.append(ui->cb_SweepSpacing->currentText());
    sweep_options.append(ui->cb_SweepShape->currentText());
    sweep_options.append(ui->le_StartFreq->text());
    sweep_options.append(ui->cb_UninsStartFreq->currentText());
    sweep_options.append(ui->le_StopFreq->text());
    sweep_options.append(ui->cb_UnitsStopFreq->currentText());
    sweep_options.append(ui->le_SpanFreq->text());
    sweep_options.append(ui->cb_UnitsRange->currentText());
    sweep_options.append(ui->le_CenterFreq->text());
    sweep_options.append(ui->cb_UninsCenter->currentText());
    sweep_options.append(ui->le_StepSweep->text());
    sweep_options.append(ui->cb_UnitsLinStep->currentText());
    sweep_options.append(ui->le_SweepPoints->text());
    sweep_options.append(ui->le_SweepDwell->text());
    sweep_options.append(ui->cb_UnitsSweepDwell->currentText());
    emit sign_RunFreqSweep(sweep_options);
}


void Setting_Freq_Sweep::on_cb_SweepSpacing_currentIndexChanged(const QString &arg1)
{
    arg1 == "Linear"? ui->cb_UnitsLinStep->setEnabled(true) : ui->cb_UnitsLinStep->setEnabled(false);
}

