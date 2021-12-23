#include "rnsscpi.h"

using namespace std;
RnSSCPI::RnSSCPI()
{

}

QString RnSSCPI::SetFrequency(QString value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::GHz)
    {
        if(value.toDouble() * pow(10, 9) <= MAX_FREQ && value.toDouble() >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение частоты.";
    }
    else if(unit == units::MHz)
    {
        if(value.toDouble() * pow(10, 6) <= MAX_FREQ && value.toDouble() >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение частоты.";
    }
    else if(unit == units::kHz)
    {
        if(value.toDouble() * 1000 <= MAX_FREQ && value.toDouble() >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение частоты.";
    }
    else if(unit == units::Hz)
    {
        if(value.toDouble() <= MAX_FREQ && value.toDouble() >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение частоты.";
    }
    else
    {
        // Временное решение
        command = "Не верно указаны едины измерения. Cм. пространство имен units";
    }
    return command;
}

QString RnSSCPI::SetFrequency(double value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::GHz)
    {
        if(value * pow(10, 9) <= MAX_FREQ && value >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение частоты.";
    }
    else if(unit == units::MHz)
    {
        if(value * pow(10, 6) <= MAX_FREQ && value >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение частоты.";
    }
    else if(unit == units::kHz)
    {
        if(value * 1000 <= MAX_FREQ && value >= 0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение частоты.";
    }
    else if(unit == units::Hz)
    {
        if(value <= MAX_FREQ && value >=0)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение частоты.";
    }
    else
    {
        command = "Не верно указаны едины измерения. Cм. пространство имен units";
    }
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
