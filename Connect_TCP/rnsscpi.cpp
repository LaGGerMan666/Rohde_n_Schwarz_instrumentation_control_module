#include "rnsscpi.h"

RnSSCPI::RnSSCPI()
{

}

string RnSSCPI::Get_Last_Response()
{
    string result;
    !response_From_Device.empty() ? result = response_From_Device :  result = "Ответа от устройства еще не было";
    response_From_Device.clear();
    return result;
}

string RnSSCPI::Send_Request_IDN()
{
    return "*IDN?\n";
}

string RnSSCPI::Send_Request_Error()
{
    return "SYSTem:ERRor?\n";
}

string RnSSCPI::Send_Request_Frequency(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:CW?\n";
}

string RnSSCPI::Send_Request_FrequencyMode(int sour_hw)
{
    return  "SOURce" + to_string(sour_hw) + ":FREQuency:MODE?\n";
}

string RnSSCPI::Send_Request_Level(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude?\n";
}

string RnSSCPI::Send_Request_PEP(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":POWer:PEP?\n";
}

string RnSSCPI::Send_Request_Standard(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard?\n";
}

string RnSSCPI::Send_Request_ModType(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat?\n";
}

string RnSSCPI::Send_Request_SymbolRate(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe?\n";
}

string RnSSCPI::Send_Request_TriggerForSweeps(int trig_hw)
{
    return "TRIGger" + to_string(trig_hw) + ":FSWeep:SOURce?\n";
}

string RnSSCPI::Send_Request_SweepFreqMode(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:MODE?\n";
}

string RnSSCPI::Send_Request_FreqSpan(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN?\n";
}

string RnSSCPI::Send_Request_FreqCenter(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer?\n";
}

string RnSSCPI::Send_Request_FreqStart(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:STARt?\n";
}

string RnSSCPI::Send_Request_FreqStop(int sour_hw)
{
    return "SOURce" + to_string(sour_hw)+ ":FREQuency:STOP?\n";
}

string RnSSCPI::Send_Request_SweepSpacing(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SPACing?\n";
}

string RnSSCPI::Send_Request_SweepShape(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SHAPe?\n";
}

string RnSSCPI::Send_Request_SweepRetrace(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace?\n";
}

string RnSSCPI::Send_Request_SweepStepLinear(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear?\n";
}

string RnSSCPI::Send_Request_SweepStepLogarithmic(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LOGarithmic?\n";
}

string RnSSCPI::Send_Request_SweepPoints(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:POINts?\n";
}

string RnSSCPI::Send_Request_SweepFreqDwell(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl?\n";
}

string RnSSCPI::Send_Request_SweepFreqRun(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RUNNing?\n";
}

void RnSSCPI::Response_Handling(string answer)
{


    if (*answer.end() == '\n')
    {
        response_From_Device = answer.erase(answer.size()-1, 1);
    }

//    Возможно где нибудь пригодится QRegExp checkNoError("^(0,\"No error\")\\n$");
//    regex searchNewLine("^(.+)\\n$");
//    "^.+(?=\\n)"
//    regex searchNullTerm("\\n$");
//    string delNullTerm = "";
//    if(!answer.empty())
//    {
//        bool found = regex_match(answer.cbegin(), answer.cend(), searchNullTerm);
//        if(found)
//        {
//            response_From_Device = regex_replace(answer, searchNullTerm, delNullTerm);
//        }
//    }
}

// Установка частоты
string RnSSCPI::SetFrequency(double value, int unit, int sour_hw)
{
    string command;
    switch(unit)
    {
        case unitsFreq::eGHz:
            if(value * pow(10, 9) <= MAX_FREQ && value * pow(10, 9) >= MIN_FREQ)
            {
                command = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " GHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) <= MAX_FREQ && value * pow(10, 6) >= MIN_FREQ)
            {
                command = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " MHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::ekHz:
            if(value * 1000 <= MAX_FREQ && value * 1000 >= MIN_FREQ)
            {
                command = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " kHz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        case unitsFreq::eHZ:
            if(value <= MAX_FREQ && value >= MIN_FREQ)
            {
               command = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " Hz" + "\n";
            }
            else command = "Получено недопустимое значение FREQuency.";
        break;

        default:
            command = "";
    }
    return command;
}

// Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
// 0 ="CW", 1 = "FIXed", 2 = "SWEep", 3 = "LIST", 4 = "COMBined"
string RnSSCPI::SetFrequencyMode(int value, int sour_hw)
{
    int count_values = sizeof(freq_mode_values)/sizeof(freq_mode_values[0]);
    string command = "";
    if(value >= 0 && value <= count_values - 1)
    {
        command = "SOURce" + to_string(sour_hw) + ":FREQuency:MODE " + freq_mode_values[value] + "\n";
    }
    return  command;
}

// Установка мощности
string RnSSCPI::SetPower(double value, int unit, int sour_hw)
{
    string command;
    switch(unit)
    {
        case unitsPower::edBM:
            if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " dBm" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MIN_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " v" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " mV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " uV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " nV" + "\n";
            }
            else command = "Получено недопустимое значение POWer.";
        break;

        default:
            command = "";
    }
    return command;
}

// Установка уровня
string RnSSCPI::SetLevel(double value, int unit, int sour_hw)
{
    string command;
    switch (unit)
    {
        case unitsPower::edBM:
            if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + to_string(value) + " dBm" + "\n";
            }
            else command = "Получено недопустимое значение LEVel";
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MAX_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + to_string(value) + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel";
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + to_string(value) + " V" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + to_string(value) + " mV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + to_string(value) + " uV" + "\n";
            }
            else command = "Получено недопустимое значени LEVel.";
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLiteude " + to_string(value) + " nV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        default:
            command = "";
    }
    return command;
}

// Установка стандартных режимов
string RnSSCPI::SetAccordingToStandard(int standard_number, int sour_hw)
{
    int count_StandardSheet = (sizeof(standard_sheet)/sizeof(standard_sheet[0][0]))/2;
    if(standard_number >= 0 && standard_number <= count_StandardSheet - 1)
    {
        return "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard " + standard_sheet[standard_number][1] + "\n";
    }
    else return "";
}

// Установка типа модуляции
string RnSSCPI::SetModulationType(int num_type, int sour_hw)
{
    int count_modType = (sizeof(mod_type_sheet)/sizeof(mod_type_sheet[0][0]))/2;
    if(num_type >= 0 && num_type <= count_modType - 1)
    {
        return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet[num_type][1] + "\n";
    }
    else return "";
}

// Установка скорости передачи символов
// Задавать в единицах измерения Hz(sym/s можно не указывать), kHz(kSym/s), MHz(MSym/s)
string RnSSCPI::SetSymbolRate(double value, int unit, int sour_hw)
{
    bool err_unit = false;
    string current_unit = "";
    double translate_value = 0;
    switch (unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value * pow(10,3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value * pow(10,6);
            current_unit = "MHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= MIN_SRATE && translate_value <= MAX_SRATE)
        {
            return "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe " + to_string(value) + current_unit + "\n";
        }
    }
    return "";
}

// Метод активации Baseband
string RnSSCPI::SetBasebandState(bool value, int sour_hw)
{
    if(value)
    {
        return "SOURce" + to_string(sour_hw) + ":BB:DM:STATe ON\n";
    }
    else return "SOURce" + to_string(sour_hw) + ":BB:DM:STATe OFF\n";
}

// Сброс настроек устройства
string RnSSCPI::Preset()
{
    return "SYSTem:PRESet\n";
}

// Выбор триггера для разверток
string RnSSCPI::SetTriggerForSweeps(int value, int trig_hw)
{
    string command = "";
    int count_values = (sizeof(trigger_for_sweeps_values)/sizeof(trigger_for_sweeps_values[0]));
    if(value >= 0 && value <= count_values - 1)
    {
        command = "TRIGger" + to_string(trig_hw) + ":FSWeep:SOURce " + trigger_for_sweeps_values[value] + "\n";
    }
    return command;
}

// Установка циклического режима для развертки по частоте
string RnSSCPI::SetSweepFreqMode(int value, int sour_hw)
{
    string command = "";
    int count_mode = sizeof(sweep_freq_mode_values)/sizeof(sweep_freq_mode_values[0]);
    if(value >= 0 && value <= count_mode - 1)
    {
        command = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:MODE " + sweep_freq_mode_values[value] + "\n";
    }
    return command;
}

// Установка диапазона частотной развертки
string RnSSCPI::SetFreqSpan(double value, int unit, int sour_hw)
{
    string current_unit = "";
    //double translate_value = 0; // потом нужно будет для проверки граничных значений
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            //translate_value = value * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            //translate_value = value * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            //translate_value = value * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        return "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN " + to_string(value) + current_unit + "\n";
    }
    return "";
}

// Установка центральной частоты развертки через число
string RnSSCPI::SetFreqCenter(double value, int unit, int sour_hw)
{
    string current_unit = "";
    double translate_value = 0;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translate_value = value * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer " + to_string(value) + current_unit + "\n";
        }
    }
    return "";
}

// Установка начальной частоты развертки
string RnSSCPI::SetFreqStart(double value, int unit, int sour_hw)
{
    string current_unit = "";
    double translate_value = 0;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translate_value = value * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(value) + current_unit + "\n";
        }
    }
    return "";
}

// Установка конечной частоты развертки
string RnSSCPI::SetFreqStop(double value, int unit, int sour_hw)
{
    string current_unit = "";
    double translate_value = 0;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translate_value = value * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= MIN_CENTER_FREQ)
        {
            return "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(value) + current_unit + "\n";
        }
    }
    return "";
}

// Установка режима расчета частотных интервалов
string RnSSCPI::SetSweepSpacing(int value, int sour_hw)
{
    string command = "";
    int count_spacing = sizeof(sweep_spacing_values) / sizeof(sweep_spacing_values[0]);
    if(value >= 0 && value <= count_spacing - 1)
    {
        command = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SPACing " + sweep_spacing_values[value] + "\n";
    }
    return command;
}

// Установка формы сигнала для последовательности развертки частоты
string RnSSCPI::SetSweepShape(int value, int sour_hw)
{
    string command = "";
    int count_shape = sizeof(sweep_shape_values) / sizeof(sweep_shape_values[0]);
    if(value >= 0 && value <= count_shape)
    {
        command = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SHAPe " + sweep_shape_values[value] + "\n";
    }
    return command;
}

// Активировать изменение начальной частоты в ожидании следующего триггера
string RnSSCPI::SetSweepRetrace(bool value, int sour_hw)
{
    if(value)
    {
        return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace ON\n";
    }
    else return "";
}

// Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())
string RnSSCPI::SetSweepResetAll(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:RESet:ALL\n";
}

// Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START) через строку
string RnSSCPI::SetSweepStepLinear(double value, double freq_Start, double freq_Stop, int unit, int sour_hw)
{
    string current_unit = "";
    double translate_value = 0;
    bool err_unit = false;
    switch(unit)
    {
        case unitsFreq::eHZ:
            current_unit = "Hz";
        break;

        case unitsFreq::ekHz:
            translate_value = value * pow(10, 3);
            current_unit = "kHz";
        break;

        case unitsFreq::eMHz:
            translate_value = value * pow(10, 6);
            current_unit = "MHz";
        break;

        case unitsFreq::eGHz:
            translate_value = value * pow(10, 9);
            current_unit = "GHz";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        if(translate_value >= 0.01 && translate_value <= (freq_Stop - freq_Start))
        {
            return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear " + to_string(value) + current_unit + "\n";
        }
    }
    return "";
}

// Установка логарифмически определяемой ширины шага для развертки по частоте (Задается в %(PCT))
string RnSSCPI::SetSweepStepLogarithmic(double value, int sour_hw)
{
    if(value >= 0.01 && value <= 100)
    {
        return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LOGarithmic " + to_string(value) + "PCT\n";
    }
    return "";
}

// Установка количества шагов в пределах диапазона развертки
string RnSSCPI::SetSweepPoints(int value, int sour_hw)
{
    if(value >= 2)
    {
        return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:POINts " + to_string(value) + "\n";
    }
    return "";
}

// Установка времени задержки для шага развертки по частоте
string RnSSCPI::SetSweepFreqDwell(double value, int unit, int sour_hw)
{
    string command = "";
    string currentUnit = "";
    bool err_unit = false;
    switch(unit)
    {
        case unitsTime::s:
            currentUnit = "s";
        break;

        case unitsTime::ms:
            currentUnit = "ms";
        break;

        case unitsTime::us:
            currentUnit = "us";
        break;

        default:
            err_unit = true;
    }
    if(!err_unit)
    {
        command =  "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl " + to_string(value) + currentUnit + "\n";
    }
    return command;
}

// Выполнение однократной развертки
string RnSSCPI::SweepFreqExecute(int sour_hw)
{
    // Реализовать проверку на готовность всех параметров развертки
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:EXECute\n";
}
