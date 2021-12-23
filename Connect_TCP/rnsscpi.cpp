#include "rnsscpi.h"

RnSSCPI::RnSSCPI()
{

}

QString RnSSCPI::SetFrequency(QString value, QString unit, int sour_hw)
{
    QString command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit;
    return command;
}

QString RnSSCPI::SetFrequency(double value, QString unit, int sour_hw)
{
    QString command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit;
    return command;
}

QString RnSSCPI::SetPower(QString value, QString unit, int sour_hw)
{
    QString command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit;
    return command;
}

QString RnSSCPI::SetPower(double value, QString unit, int sour_hw)
{
    QString command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit;
    return command;
}

QString RnSSCPI::SetLevel(QString value, QString unit, int sour_hw)
{
    QString command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit;
    return command;
}

QString RnSSCPI::SetLevel(double value, QString unit, int sour_hw)
{
    QString command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit;
    return command;
}
