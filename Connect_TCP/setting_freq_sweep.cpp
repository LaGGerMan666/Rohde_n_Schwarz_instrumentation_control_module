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
    // Источник запуска развертки
    if(data.at(0) == "AUTO")
    {
        ui->cb_TriggerSource->setCurrentIndex(0);
    }
    else if(data.at(0) == "IMM")
    {
        ui->cb_TriggerSource->setCurrentIndex(1);
    }
    else if(data.at(0) == "SING")
    {
        ui->cb_TriggerSource->setCurrentIndex(2);
    }
    else if(data.at(0) == "BUS")
    {
        ui->cb_TriggerSource->setCurrentIndex(3);
    }
    else if(data.at(0) == "EXT")
    {
        ui->cb_TriggerSource->setCurrentIndex(4);
    }
    else ui->cb_TriggerSource->setCurrentIndex(5);

    // Режим развертки по частоте
    if(data.at(1) == "AUTO")
    {
        ui->cb_SweepFreqMode->setCurrentIndex(0);
    }
    else if(data.at(1) == "MAN")
    {
        ui->cb_SweepFreqMode->setCurrentIndex(1);
    }
    else ui->cb_SweepFreqMode->setCurrentIndex(2);

    //Режим расчета частотных интервалов
    if(data.at(2) == "LIN")
    {
        ui->cb_SweepSpacing->setCurrentIndex(0);
    }
    else ui->cb_SweepSpacing->setCurrentIndex(1);

    // Форма сигнала
    if(data.at(3) == "SAWT")
    {
        ui->cb_SweepShape->setCurrentIndex(0);
    }
    else ui->cb_SweepShape->setCurrentIndex(1);


    double translate_Freq = 0;
    switch (ui->cb_UninsStartFreq->currentIndex())
    {
        case 0:
            translate_Freq = data.at(4).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = data.at(4).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = data.at(4).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = data.at(4).toDouble();
        break;
    }
    ui->le_StartFreq->setText(QString::number(translate_Freq,'g', 10));          // Текущая начальная частота

    switch (ui->cb_UnitsStopFreq->currentIndex())
    {
        case 0:
            translate_Freq = data.at(5).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = data.at(5).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = data.at(5).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = data.at(5).toDouble();
        break;
    }
    ui->le_StopFreq->setText(QString::number(translate_Freq,'g', 10));           // Текущая конечная частота

    switch (ui->cb_UnitsRange->currentIndex())
    {
        case 0:
            translate_Freq = data.at(6).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = data.at(6).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = data.at(6).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = data.at(6).toDouble();
        break;
    }
    ui->le_SpanFreq->setText(QString::number(translate_Freq,'g', 10));           // Текущий диапазон

    switch (ui->cb_UninsCenter->currentIndex())
    {
        case 0:
            translate_Freq = data.at(7).toDouble() / pow(10, 9);
        break;

        case 1:
            translate_Freq = data.at(7).toDouble() / pow(10, 6);
        break;

        case 2:
            translate_Freq = data.at(7).toDouble() / pow(10, 3);
        break;

        case 3:
            translate_Freq = data.at(7).toDouble();
        break;
    }
    ui->le_CenterFreq->setText(QString::number(translate_Freq,'g', 10));         // Текущая средняя частота



    if(ui->cb_SweepSpacing->currentText() == "Linear")
    {
        switch (ui->cb_UnitsLinStep->currentIndex())
        {
            case 0:
                translate_Freq = data.at(8).toDouble() / pow(10, 9);
            break;

            case 1:
                translate_Freq = data.at(8).toDouble() / pow(10, 6);
            break;

            case 2:
                translate_Freq = data.at(8).toDouble() / pow(10, 3);
            break;

            case 3:
                translate_Freq = data.at(8).toDouble();
            break;
        }
        ui->le_StepSweep->setText(QString::number(translate_Freq,'g', 10));          // Текущий шаг (линейный)
    }
    else ui->le_StepSweep->setText(data.at(9));         // Текущий шаг (логарифмический)



    ui->le_SweepPoints->setText(data.at(10));        // Текущее количество точек
    ui->le_SweepDwell->setText(data.at(11));        // Теущее время задержки

}

void Setting_Freq_Sweep::on_pb_StartFreqSweep_clicked()
{
    sweep_options.append(QString::number(ui->cb_TriggerSource->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepFreqMode->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepSpacing->currentIndex()));
    sweep_options.append(QString::number(ui->cb_SweepShape->currentIndex()));

    double translate_Freq = 0;
    switch (ui->cb_UninsStartFreq->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_StartFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_StartFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_StartFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_StartFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UnitsStopFreq->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_StopFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_StopFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_StopFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_StopFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UnitsRange->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_SpanFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_SpanFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_SpanFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_SpanFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UninsCenter->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_CenterFreq->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_CenterFreq->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_CenterFreq->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_CenterFreq->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));

    switch (ui->cb_UnitsLinStep->currentIndex())
    {
        case 0:
            translate_Freq = ui->le_StepSweep->text().toDouble() * pow(10, 9);
        break;

        case 1:
            translate_Freq = ui->le_StepSweep->text().toDouble() * pow(10, 6);
        break;

        case 2:
            translate_Freq = ui->le_StepSweep->text().toDouble() * pow(10, 3);
        break;

        case 3:
            translate_Freq = ui->le_StepSweep->text().toDouble();
        break;
    }
    sweep_options.append(QString::number(translate_Freq));
    sweep_options.append(QString::number(3));


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

