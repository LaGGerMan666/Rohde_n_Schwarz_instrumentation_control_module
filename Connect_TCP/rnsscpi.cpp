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
        if(value.toDouble() * pow(10, 9) <= MAX_FREQ && value.toDouble() * pow(10, 9) >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение FREQuency.";
    }
    else if(unit == units::MHz)
    {
        if(value.toDouble() * pow(10, 6) <= MAX_FREQ && value.toDouble() * pow(10, 6) >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение FREQuency.";
    }
    else if(unit == units::kHz)
    {
        if(value.toDouble() * 1000 <= MAX_FREQ && value.toDouble() * 1000 >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение FREQuency.";
    }
    else if(unit == units::Hz)
    {
        if(value.toDouble() <= MAX_FREQ && value.toDouble() >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение FREQuency.";
    }
    else command = "Не верно указаны едины измерения. Cмотри пространство имен units"; // Временное решение
    return command;
}

QString RnSSCPI::SetFrequency(double value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::GHz)
    {
        if(value * pow(10, 9) <= MAX_FREQ && value * pow(10, 9) >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение FREQuency.";
    }
    else if(unit == units::MHz)
    {
        if(value * pow(10, 6) <= MAX_FREQ && value * pow(10, 6) >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение FREQuency.";
    }
    else if(unit == units::kHz)
    {
        if(value * 1000 <= MAX_FREQ && value * 1000 >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение FREQuency.";
    }
    else if(unit == units::Hz)
    {
        if(value <= MAX_FREQ && value >= MIN_FREQ)
        {
            command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение FREQuency.";
    }
    else command = "Не верно указаны едины измерения. Cмотри пространство имен units";
    return command;
}

QString RnSSCPI::SetPower(QString value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::dBM)
    {
        if(value.toDouble() <= MAX_POW_DBM && value.toDouble() >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::dBUV)
    {
        if(value.toDouble() - 108.75 <= MAX_POW_DBM && value.toDouble() - 108.75 >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::V)
    {
        if(value.toDouble() <= MAX_POW_V && value.toDouble() >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";

    }
    else if(unit == units::mV)
    {
        if(value.toDouble() * pow(10, -3) <= MAX_POW_V && value.toDouble() * pow(10, -3) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";

    }
    else if(unit == units::uV)
    {
        if(value.toDouble() * pow(10, -6) <= MAX_POW_V && value.toDouble() * pow(10, -6) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::nV)
    {
        if(value.toDouble() * pow(10, -9) <= MAX_POW_V && value.toDouble() * pow(10, -9) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else command = "Неверно указаны единицы измерения. Cмотри пространство имен units";
    return command;
}

QString RnSSCPI::SetPower(double value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::dBM)
    {
        if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::dBUV)
    {
        if(value - 108.75 <= MIN_POW_DBM && value - 108.75 >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::V)
    {
        if(value <= MAX_POW_V && value >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::mV)
    {
        if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::uV)
    {
        if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else if(unit == units::nV)
    {
        if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение POWer.";
    }
    else command = "Неверно указаны единицы измерения. Cмотри пространство имен units";
    return command;
}

QString RnSSCPI::SetLevel(QString value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::dBM)
    {
        if(value.toDouble() <= MAX_POW_DBM && value.toDouble() >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit + "\n";
        }
        else command = "Получено недопустивое значение LEVel.";
    }
    else if(unit == units::dBUV)
    {
        if(value.toDouble() - 108.75 <= MAX_POW_DBM && value.toDouble() - 108.75 >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else if(unit == units::V)
    {
        if(value.toDouble() <= MAX_POW_V && value.toDouble() >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else if(unit == units::mV)
    {
        if(value.toDouble() * pow(10, -3) <= MAX_POW_V && value.toDouble() * pow(10, -3) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else if(unit == units::uV)
    {
        if(value.toDouble() * pow(10, -6) <= MAX_POW_V && value.toDouble() * pow(10, -6) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else if(unit == units::nV)
    {
        if(value.toDouble() * pow(10, -9) <= MAX_POW_V && value.toDouble() * pow(10, -9) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitede " + value + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else command = "Неверно указаны единицы измерения. Смотри простравнство имен units";

    return command;
}

QString RnSSCPI::SetLevel(double value, QString unit, int sour_hw)
{
    QString command;
    if(unit == units::dBM)
    {
        if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel";
    }
    else if(unit == units::dBUV)
    {
        if(value - 108.75 <= MAX_POW_DBM && value - 108.75 >= MIN_POW_DBM)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel";
    }
    else if(unit == units::V)
    {
        if(value <= MAX_POW_V && value >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else if(unit == units::mV)
    {
        if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else if(unit == units::uV)
    {
        if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустимое значени LEVel.";
    }
    else if(unit == units::nV)
    {
        if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
        {
            command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " " + unit + "\n";
        }
        else command = "Получено недопустимое значение LEVel.";
    }
    else command = "Неверно указаны единицы измерения. Смотри простравнство имен units";
    return command;
}
