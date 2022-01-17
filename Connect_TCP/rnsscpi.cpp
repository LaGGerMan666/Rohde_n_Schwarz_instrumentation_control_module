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
    return "*IDN?\n";
}

QString RnSSCPI::Send_Request_Error()
{
    return "SYSTem:ERRor?\n";
}

QString RnSSCPI::Send_Request_Frequency(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":FREQuency:CW?\n";
}

QString RnSSCPI::Send_Request_Level(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude?\n";
}

QString RnSSCPI::Send_Request_PEP(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":POWer:PEP?\n";
}

QString RnSSCPI::Send_Request_Standard(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":BB:DM:STANdard?\n";
}

QString RnSSCPI::Send_Request_ModType(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":BB:DM:FORMat?\n";
}

QString RnSSCPI::Send_Request_SymbolRate(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":BB:DM:SRATe?\n";
}

QString RnSSCPI::Send_Request_TriggerForSweeps(int trig_hw)
{
    return "TRIGger" + QString::number(trig_hw) + ":FSWeep:SOURce?\n";
}

QString RnSSCPI::Send_SweepFreqMode(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":SWEep:FREQuensy:MODE?\n";
}

QString RnSSCPI::Send_FreqSpan(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":FREQuency:SPAN?\n";
}

QString RnSSCPI::Send_FreqCenter(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":FREQuency:CENTer?\n";
}

QString RnSSCPI::Send_FreqStart(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":FREQuency:STARt?\n";
}

QString RnSSCPI::Send_FreqStop(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw)+ ":FREQuency:STOP?\n";
}

QString RnSSCPI::Send_SweepSpacing(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":SWEep:FREQuency:SPACing?\n";
}

QString RnSSCPI::Send_SweepShape(int sour_hw)
{
    return "SOURce" + QString::number(sour_hw) + ":SWEep:FREQuency:SHAPe?\n";
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
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " GHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) <= MAX_FREQ && value * pow(10, 6) >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " MHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::ekHz:
            if(value * 1000 <= MAX_FREQ && value * 1000 >= MIN_FREQ)
            {
                command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " kHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::eHZ:
            if(value <= MAX_FREQ && value >= MIN_FREQ)
            {
               command = "SOURce" + QString::number(sour_hw) + ":FREQuency:CW " + QString::number(value) + " Hz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
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
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::edBUV:
            if(value.toDouble() - 108.75 <= MAX_POW_DBM && value.toDouble() - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::eV:
            if(value.toDouble() <= MAX_POW_V && value.toDouble() >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " V" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::emV:
            if(value.toDouble() * pow(10, -3) <= MAX_POW_V && value.toDouble() * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " mV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::euV:
            if(value.toDouble() * pow(10, -6) <= MAX_POW_V && value.toDouble() * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " uV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::enV:
            if(value.toDouble() * pow(10, -9) <= MAX_POW_V && value.toDouble() * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + value + " nV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
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
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MIN_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " v" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " mV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " uV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + QString::number(sour_hw) + ":POWer:POWer " + QString::number(value) + " nV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
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
            else command = "Получено недопустимое значение LEVel.";
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

// Установка стандартных режимов по названию или номеру
QString RnSSCPI::SetAccordingToStandard(QString name_of_the_standard, int sour_hw)
{
    QString command;
    int count_StandardSheet = (sizeof(standard_sheet)/sizeof(standard_sheet[0][0]))/2;
    for(int i = 0; i < count_StandardSheet; i++)
    {
        if(name_of_the_standard.toUpper() == standard_sheet[i][0])
        {
            command = "SOURce" + QString::number(sour_hw) + ":BB:DM:STANdard " + standard_sheet[i][1] + "\n";
            break;
        }
        else command = "";
    }
    return command;
}
QString RnSSCPI::SetAccordingToStandard(int standard_number, int sour_hw)
{
    int count_StandardSheet = (sizeof(standard_sheet)/sizeof(standard_sheet[0][0]))/2;
    if(standard_number >= 0 && standard_number <= count_StandardSheet)
    {
        return "SOURce" + QString::number(sour_hw) + ":BB:DM:STANdard " + standard_sheet[standard_number][1] + "\n";
    }
    else return "";
}

// Установка типа модуляции по названию или номеру
QString RnSSCPI::SetModulationType(QString type, int sour_hw)
{
    QString command;
    int count_modType = (sizeof(mod_type_sheet)/sizeof(mod_type_sheet[0][0]))/2;
    for(int i = 0; i < count_modType; i++)
    {
        if(type.toUpper() == mod_type_sheet[i][0])
        {
            command = "SOURce" + QString::number(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet[i][1] + "\n";
            break;
        }
        else command = "";
    }
    return command;
}
QString RnSSCPI::SetModulationType(int num_type, int sour_hw)
{
    int count_modType = (sizeof(mod_type_sheet)/sizeof(mod_type_sheet[0][0]))/2;
    if(num_type >= 0 && num_type <= count_modType)
    {
        return "SOURce" + QString::number(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet[num_type][1] + "\n";
    }
    else return "";
}

// Установка скорости передачи символов
// Задавать в единицах измерения Hz(sym/s можно не указывать), kHz(kSym/s), MHz(MSym/s)
QString RnSSCPI::SetSymbolRate(QString value, int unit, int sour_hw)
{
    double translated_value;
    QString current_unit;
    bool err_unit = false;
    switch (unit)
    {
        case unitsFreq::eHZ:
            translated_value = value.toDouble();
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translated_value = value.toDouble() * pow(10,3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translated_value = value.toDouble() * pow(10,6);
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translated_value >= MIN_SRATE && translated_value <= MAX_SRATE)
        {
            return "SOURce" + QString::number(sour_hw) + ":BB:DM:SRATe " + QString::number(translated_value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}
QString RnSSCPI::SetSymbolRate(double value, int unit, int sour_hw)
{
    bool err_unit = false;
    QString current_unit;
    switch (unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            value *= pow(10,3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            value *= pow(10,6);
            current_unit = "MHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(value >= MIN_SRATE && value <= MAX_SRATE)
        {
            return "SOURce" + QString::number(sour_hw) + ":BB:DM:SRATe " + QString::number(value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";

}

// Метод активации Baseband
QString RnSSCPI::SetBasebandState(bool value, int sour_hw)
{
    if(value)
    {
        return "SOURce" + QString::number(sour_hw) + ":BB:DM:STATe ON\n";
    }
    else return "SOURce" + QString::number(sour_hw) + ":BB:DM:STATe OFF\n";
}

// Сброс настроек устройства
QString RnSSCPI::SetPreset()
{
    return "SYSTem:PRESet\n";
}

// Выбор триггера для разверток
QString RnSSCPI::SetTriggerForSweeps(QString value, int trig_hw)
{
    QString command;
    int count_values = (sizeof(trigger_for_sweeps_values)/sizeof(trigger_for_sweeps_values[0]));
    for(int i = 0; i < count_values; i++)
    {
        if(value.toUpper() == trigger_for_sweeps_values[i].toUpper())
        {
            command = "TRIGger" + QString::number(trig_hw) + ":FSWeep:SOURce " + value + "\n";
            break;
        }
        else command = "";
    }
    return command;
}

// Установка циклического режима для развертки по частоте
QString RnSSCPI::SetSweepFreqMode(QString value, int sour_hw)
{
    QString command;
    int count_mode = sizeof(sweep_freq_mode_values)/sizeof(sweep_freq_mode_values[0]);
    for(int i = 0; i < count_mode; i++)
    {
        if(value.toUpper() == sweep_freq_mode_values[i].toUpper())
        {
            command = "SOURce" + QString::number(sour_hw) + ":SWEep:FREQuency:MODE " + value + "\n";
            break;
        }
        else command = "";
    }
    return command;
}

// Установка диапазона частотной развертки
QString RnSSCPI::SetFreqSpan(QString value, int unit, int sour_hw)
{
    double translated_value;
    QString current_unit;
    bool err_unit = false;
    switch (unit)
    {
        case unitsFreq::eHZ:
            translated_value = value.toDouble();
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translated_value = value.toDouble() * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translated_value = value.toDouble() * pow(10, 6);
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        return "SOURce" + QString::number(sour_hw) + ":FREQuency:SPAN " + QString::number(translated_value) + current_unit + "\n";
    }
    else return "";
}
QString RnSSCPI::SetFreqSpan(double value, int unit, int sour_hw)
{
    QString current_unit;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            value *= pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            value *= pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            value *= pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        return "SOURce" + QString::number(sour_hw) + ":FREQuency:SPAN " + QString::number(value) + current_unit + "\n";
    }
    else return "";
}

// Установка центральной частоты развертки через число
QString RnSSCPI::SetFreqCenter(QString value, int unit, int sour_hw)
{
    QString current_unit;
    double translated_value;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            translated_value = value.toDouble();
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translated_value = value.toDouble() * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translated_value = value.toDouble() * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translated_value = value.toDouble() * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translated_value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + QString::number(sour_hw) + ":FREQuency:CENTer " + QString::number(translated_value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}
QString RnSSCPI::SetFreqCenter(double value, int unit, int sour_hw)
{
    QString current_unit;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            value *= pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            value *= pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            value *= pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + QString::number(sour_hw) + ":FREQuency:CENTer " + QString::number(value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}

// Установка начальной частоты развертки
QString RnSSCPI::SetFreqStart(QString value, int unit, int sour_hw)
{
    QString current_unit;
    double translate_value;
    bool err_unit = false;
    switch (unit)
    {
        case unitsFreq::eHZ:
            translate_value = value.toDouble();
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value.toDouble() * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value.toDouble() * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translate_value = value.toDouble() * pow(10, 9);
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + QString::number(sour_hw) + ":FREQuency:STARt " + QString::number(translate_value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}
QString RnSSCPI::SetFreqStart(double value, int unit, int sour_hw)
{
    QString current_unit;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            value *= pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            value *= pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            value *= pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + QString::number(sour_hw) + ":FREQuency:STARt " + QString::number(value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}

// Установка конечной частоты развертки
QString RnSSCPI::SetFreqStop(QString value, int unit, int sour_hw)
{
    QString current_unit;
    double translate_value;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            translate_value = value.toDouble();
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value.toDouble() * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value.toDouble() * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translate_value = value.toDouble() * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + QString::number(sour_hw) + ":FREQuency:STOP " + QString::number(translate_value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}
QString RnSSCPI::SetFreqStop(double value, int unit, int sour_hw)
{
    QString current_unit;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            value *= pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            value *= pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            value *= pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + QString::number(sour_hw) + ":FREQuency:STOP " + QString::number(value) + current_unit + "\n";
        }
        else return "";
    }
    else return "";
}

// Установка режима расчета частотных интервалов
QString RnSSCPI::SetSweepSpacing(QString value, int sour_hw)
{
    QString command;
    int count_spacing = sizeof(sweep_spacing_values) / sizeof(sweep_spacing_values[0]);
    for(int i = 0; i < count_spacing; i++)
    {
        if(value.toUpper() == sweep_spacing_values[i].toUpper())
        {
            command = "SOURce" + QString::number(sour_hw) + ":SWEep:FREQuency:SPACing " + value + "\n";
            break;
        }
        else command = "";
    }
    return command;
}

// Установка формы сигнала для последовательности развертки частоты
QString RnSSCPI::SetSweepShape(QString value, int sour_hw)
{
    QString command;
    int count_shape = sizeof(sweep_shape_values) / sizeof(sweep_shape_values[0]);
    for(int i = 0; i < count_shape; i++)
    {
        if(value.toUpper() == sweep_shape_values[i].toUpper())
        {
            command = "SOURce" + QString::number(sour_hw) + ":SWEep:FREQuency:SHAPe " + value + "\n";
            break;
        }
        else command = "";
    }
    return command;
}


