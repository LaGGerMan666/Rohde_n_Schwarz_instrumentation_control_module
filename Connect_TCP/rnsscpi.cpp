#include "rnsscpi.h"

using namespace std;
RnSSCPI::RnSSCPI()
{

}

QString RnSSCPI::Get_Last_Response()
{
    QString result;
    !response_From_Device.isEmpty() ? result = response_From_Device :  result = "Ответа от устройства еще не было";
    response_From_Device.clear();
    return result;
}

QString RnSSCPI::Send_Request_IDN()
{
    QString command = "*IDN?";
    return command + "\n";
}

QString RnSSCPI::Send_Request_Error()
{
    QString command = "SYSTem:ERRor?";
    return command + "\n";
}

QString RnSSCPI::Send_Request_Frequency()
{
    QString command = "SOURce:FREQuency:CW?";
    return command + "\n";
}

QString RnSSCPI::Send_Request_Level()
{
    QString command = "SOURce:POWer:LEVel:IMMediate:AMPLitude?";
    return command + "\n";
}

QString RnSSCPI::Send_Request_PEP()
{
    QString command = "SOURce:POWer:PEP?";
    return command + "\n";
}

void RnSSCPI::Response_Handling(QString answer)
{
    // Возможно где нибудь пригодится QRegExp checkNoError("^(0,\"No error\")\\n$");
    QRegExp searchNewLine("^(.+)\\n$");
    if(!answer.isEmpty())
    {
        searchNewLine.indexIn(answer);
        response_From_Device = searchNewLine.cap(1);
    }
}

QString RnSSCPI::SetFrequency(QString value, int unit, int sour_hw)
{
    QString command;
    switch(unit){
        case unitsFreq::eGHz:
            if(value.toDouble() * pow(10, 9) <= MAX_FREQ && value.toDouble() * pow(10, 9) >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " GHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::eMHz:
            if(value.toDouble() * pow(10, 6) <= MAX_FREQ && value.toDouble() * pow(10, 6) >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " MHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::ekHz:
            if(value.toDouble() * 1000 <= MAX_FREQ && value.toDouble() * 1000 >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " kHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::eHZ:
            if(value.toDouble() <= MAX_FREQ && value.toDouble() >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + value + " Hz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        default:
            command = "";
    }
    return command;
}

QString RnSSCPI::SetFrequency(double value, int unit, int sour_hw)
{
    QString command;
    switch(unit)
    {
        case unitsFreq::eGHz:
            if(value * pow(10, 9) <= MAX_FREQ && value * pow(10, 9) >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
            }
            else command = "Получено недопустивое значение FREQuency.";
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) <= MAX_FREQ && value * pow(10, 6) >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
            }
            else command = "Получено недопустивое значение FREQuency.";
        break;

        case unitsFreq::ekHz:
            if(value * 1000 <= MAX_FREQ && value * 1000 >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
            }
            else command = "Получено недопустивое значение FREQuency.";
        break;

        case unitsFreq::eHZ:
            if(value <= MAX_FREQ && value >= MIN_FREQ)
            {
               command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " " + unit + "\n";
            }
            else command = "Получено недопустивое значение FREQuency.";
        break;

        default:
            command = "";
    }
    return command;
}

QString RnSSCPI::SetPower(QString value, int unit, int sour_hw)
{
    QString command;
    switch(unit)
    {
        case unitsPower::edBM:
            if(value.toDouble() <= MAX_POW_DBM && value.toDouble() >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " dBm" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::edBUV:
            if(value.toDouble() - 108.75 <= MAX_POW_DBM && value.toDouble() - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " dBUV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::eV:
            if(value.toDouble() <= MAX_POW_V && value.toDouble() >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " V" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::emV:
            if(value.toDouble() * pow(10, -3) <= MAX_POW_V && value.toDouble() * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " mV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::euV:
            if(value.toDouble() * pow(10, -6) <= MAX_POW_V && value.toDouble() * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " uV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::enV:
            if(value.toDouble() * pow(10, -9) <= MAX_POW_V && value.toDouble() * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " nV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        default:
            command = "";
    }
    return command;
}

QString RnSSCPI::SetPower(double value, int unit, int sour_hw)
{
    QString command;
    switch(unit)
    {
        case unitsPower::edBM:
            if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " dBm" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MIN_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " dBUV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " v" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " mV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " uV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " nV" + "\n";
            }
            else command = "Получено недопустивое значение POWer.";
        break;

        default:
            command = "";
    }
    return command;
}

QString RnSSCPI::SetLevel(QString value, int unit, int sour_hw)
{
    QString command;
    switch(unit)
    {
        case unitsPower::edBM:
            if(value.toDouble() <= MAX_POW_DBM && value.toDouble() >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + value + " dBm" + "\n";
            }
            else command = "Получено недопустивое значение LEVel.";
        break;

        case unitsPower::edBUV:
            if(value.toDouble() - 108.75 <= MAX_POW_DBM && value.toDouble() - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + value + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::eV:
            if(value.toDouble() <= MAX_POW_V && value.toDouble() >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + value + " V" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::emV:
            if(value.toDouble() * pow(10, -3) <= MAX_POW_V && value.toDouble() * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + value + " mV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::euV:
            if(value.toDouble() * pow(10, -6) <= MAX_POW_V && value.toDouble() * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + value + " uV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::enV:
            if(value.toDouble() * pow(10, -9) <= MAX_POW_V && value.toDouble() * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + value + " nV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        default:
            command = "";
    }
    return command;
}

QString RnSSCPI::SetLevel(double value, int unit, int sour_hw)
{
    QString command;
    switch (unit)
    {
        case unitsPower::edBM:
            if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " dBm" + "\n";
            }
            else command = "Получено недопустимое значение LEVel";
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MAX_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel";
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " V" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " mV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " uV" + "\n";
            }
            else command = "Получено недопустимое значени LEVel.";
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + QString::number(value) + " nV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        default:
            command = "";
    }
    return command;
}
