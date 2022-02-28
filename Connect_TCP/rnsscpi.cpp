#include "rnsscpi.h"

RnSSCPI::RnSSCPI()
{

}

// Сброс настроек устройства
void RnSSCPI::Preset(string &request_buffer) noexcept
{
    request_buffer = "SYSTem:PRESet\n";
}
//string RnSSCPI::Get_Last_Response()
//{
//    string result;
//    !response_From_Device.empty() ? result = response_From_Device :  result = "Ответа от устройства еще не было";
//    response_From_Device.clear();
//    return result;
//}

string RnSSCPI::Send_Request_IDN() const
{
    return "*IDN?\n";
}

void RnSSCPI::request_IDN(string &request_buffer) noexcept
{
    request_buffer = "*IDN?\n";
}

string RnSSCPI::Send_Request_Error() noexcept
{
    return "SYSTem:ERRor?\n";
}

void RnSSCPI::request_LastError(string &request_buffer) noexcept
{
    request_buffer = "SYSTem:ERRor?\n";
}

string RnSSCPI::Send_Request_Frequency(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:CW?\n";
}

void RnSSCPI::request_Frequency(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + "FREQuency:CW?\n";
}

string RnSSCPI::Send_Request_FrequencyMode(int sour_hw)
{
    return  "SOURce" + to_string(sour_hw) + ":FREQuency:MODE?\n";
}

void RnSSCPI::request_FrequencyMode(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:MODE?\n";
}

string RnSSCPI::Send_Request_Level(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude?\n";
}

void RnSSCPI::request_Level(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude?\n";
}

string RnSSCPI::Send_Request_PEP(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":POWer:PEP?\n";
}

void RnSSCPI::request_PEP(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:PEP?\n";
}

string RnSSCPI::Send_Request_Standard(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard?\n";
}

void RnSSCPI::request_Standard(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard?\n";
}

string RnSSCPI::Send_Request_ModType(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat?\n";
}

void RnSSCPI::request_ModType(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat?\n";
}

string RnSSCPI::Send_Request_SymbolRate(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe?\n";
}

void RnSSCPI::request_SymbolRate(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe?\n";
}

string RnSSCPI::Send_Request_TriggerForSweeps(int trig_hw)
{
    return "TRIGger" + to_string(trig_hw) + ":FSWeep:SOURce?\n";
}

void RnSSCPI::request_TriggerForSweeps(string &request_buffer, int trig_hw)
{
    request_buffer = "TRIGger" + to_string(trig_hw) + ":FSWeep:SOURce?\n";
}

string RnSSCPI::Send_Request_SweepFreqMode(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:MODE?\n";
}

void RnSSCPI::request_SweepFreqMod(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:MODE?\n";
}

string RnSSCPI::Send_Request_FreqSpan(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN?\n";
}

void RnSSCPI::request_FreqSpan(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN?\n";
}

string RnSSCPI::Send_Request_FreqCenter(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer?\n";
}

void RnSSCPI::request_FreqCenter(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer?\n";
}

string RnSSCPI::Send_Request_FreqStart(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":FREQuency:STARt?\n";
}

void RnSSCPI::request_FreqStart(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt?\n";
}

string RnSSCPI::Send_Request_FreqStop(int sour_hw)
{
    return "SOURce" + to_string(sour_hw)+ ":FREQuency:STOP?\n";
}

void RnSSCPI::request_FreqStop(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP?\n";
}

string RnSSCPI::Send_Request_SweepSpacing(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SPACing?\n";
}

void RnSSCPI::request_SweepSpacing(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuebcy:SPACing?\n";
}

string RnSSCPI::Send_Request_SweepShape(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SHAPe?\n";
}

void RnSSCPI::request_SweepShape(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SHAPe?\n";
}

string RnSSCPI::Send_Request_SweepRetrace(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace?\n";
}

string RnSSCPI::Send_Request_SweepStepLinear(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear?\n";
}

void RnSSCPI::request_SweepStepLinear(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear?\n";
}

string RnSSCPI::Send_Request_SweepStepLogarithmic(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LOGarithmic?\n";
}

void RnSSCPI::request_SweepStepLog(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LOGarithmic?\n";
}

string RnSSCPI::Send_Request_SweepPoints(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:POINts?\n";
}

void RnSSCPI::request_SweepPoints(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:POINts?\n";
}

string RnSSCPI::Send_Request_SweepFreqDwell(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl?\n";
}

void RnSSCPI::request_SweepFreqDwell(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl?\n";
}

string RnSSCPI::Send_Request_SweepFreqRun(int sour_hw)
{
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RUNNing?\n";
}

void RnSSCPI::request_SweepFreqRun(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + "SWEep:FREQuency:RUNNing?\n";
}

void RnSSCPI::sweepResetAll(string &request_buffer, int sour_hw) noexcept
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:RESet:ALL\n";
}

//void RnSSCPI::Response_Handling(string answer)
//{


//    if (*answer.end() == '\n')
//    {
//        response_From_Device = answer.erase(answer.size()-1, 1);
//    }

////    Возможно где нибудь пригодится QRegExp checkNoError("^(0,\"No error\")\\n$");
////    regex searchNewLine("^(.+)\\n$");
////    "^.+(?=\\n)"
////    regex searchNullTerm("\\n$");
////    string delNullTerm = "";
////    if(!answer.empty())
////    {
////        bool found = regex_match(answer.cbegin(), answer.cend(), searchNullTerm);
////        if(found)
////        {
////            response_From_Device = regex_replace(answer, searchNullTerm, delNullTerm);
////        }
////    }
//}

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

void RnSSCPI::set_Frequency(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsFreq::eGHz:
            if(value * pow(10, 9) <= MAX_FREQ && value * pow(10, 9) >= MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) <= MAX_FREQ && value * pow(10, 6) >= MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) <= MAX_FREQ && value * pow(10, 3) >= MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + " kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eHZ:
            if(value <= MAX_FREQ && value >= MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CW " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;

    }
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

void RnSSCPI::set_FrequencyMode(string &request_buffer, int value, int &err, int sour_hw)
{
    err = error::No_error;
    int count_values = sizeof(freq_mode_values)/sizeof(freq_mode_values[0]);
    if(value >= 0 && value <= count_values - 1)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:MODE " + freq_mode_values.at(value) + "\n";
    }
    else err = error::Value_out_of_range;
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

void RnSSCPI::set_Power(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsPower::edBM:
            if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " dBm\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MIN_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " dBUV\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " V\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " mV\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " uV\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_DBM)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:POWer " + to_string(value) + " nV\n";
            }
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
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
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " dBm" + "\n";
            }
            else command = "Получено недопустимое значение LEVel";
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MAX_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " dBUV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel";
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " V" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " mV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        case unitsPower::euV:
            if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " uV" + "\n";
            }
            else command = "Получено недопустимое значени LEVel.";
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                command = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " nV" + "\n";
            }
            else command = "Получено недопустимое значение LEVel.";
        break;

        default:
            command = "";
    }
    return command;
}

void RnSSCPI::set_Level(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsPower::edBM:
            if(value <= MAX_POW_DBM && value >= MIN_POW_DBM)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " dBm\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::edBUV:
            if(value - 108.75 <= MAX_POW_DBM && value - 108.75 >= MIN_POW_DBM)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " dBUV\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::eV:
            if(value <= MAX_POW_V && value >= MIN_POW_V)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " V\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::emV:
            if(value * pow(10, -3) <= MAX_POW_V && value * pow(10, -3) >= MIN_POW_V)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " mV\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsPower::euV:
             if(value * pow(10, -6) <= MAX_POW_V && value * pow(10, -6) >= MIN_POW_V)
             {
                 request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " uV\n";
             }
             else err = error::Value_out_of_range;
        break;

        case unitsPower::enV:
            if(value * pow(10, -9) <= MAX_POW_V && value * pow(10, -9) >= MIN_POW_V)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude " + to_string(value) + " nV\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
}

// Установка стандартных режимов
string RnSSCPI::SetAccordingToStandard(int standard_number, int isAPCO, int sour_hw)
{

    if(isAPCO == 0)
    {
        int count_StandardSheet = sizeof(standard_sheet)/sizeof(standard_sheet[0]);
        if(standard_number >= 0 && standard_number <= count_StandardSheet - 1)
        {
            return "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard " + standard_sheet[standard_number] + "\n";
        }
        else return "";
    }
    else
    {
        int count_StandardSheet_APCO = sizeof(standard_sheet_apco)/sizeof(standard_sheet_apco[0]);
        if(standard_number >= 0 && standard_number <= count_StandardSheet_APCO - 1)
        {
            return "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard " + standard_sheet_apco[standard_number] + "\n";
        }
        else return "";
    }

}

void RnSSCPI::set_AccordingToStandard(string &request_buffer, int standard_number, bool isAPCO, int &err, int sour_hw)
{
    err = error::No_error;
    if(!isAPCO)
    {
        int count_StandardSheet = sizeof(standard_sheet)/sizeof(standard_sheet[0]);
        if(standard_number >= 0 && standard_number <= count_StandardSheet - 1)
        {
            request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard " + standard_sheet.at(standard_number) + "\n";
        }
        else err = error::Value_out_of_range;
    }
    else
    {
        int count_StandardSheet_APCO = sizeof(standard_sheet_apco)/sizeof(standard_sheet_apco[0]);
        if(standard_number >= 0 && standard_number <= count_StandardSheet_APCO)
        {
            request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DMLSTANdard " + standard_sheet_apco.at(standard_number) + "\n";
        }
        else err = error::Value_out_of_range;
    }
}

// Установка типа модуляции
string RnSSCPI::SetModulationType(int num_subtype, int num_type, int sour_hw)
{
    int count_modType = 0;
    switch (num_type)
    {
        case 0: // ASK
            return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat ASK\n";
        break;

        case 1: // PSK
            count_modType = sizeof(mod_type_sheet_PSK)/sizeof(mod_type_sheet_PSK[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType - 1)
            {
                return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_PSK[num_subtype] + "\n";
            } else return "";
        break;

        case 2: // QAM
            count_modType = sizeof(mod_type_sheet_QAM)/sizeof(mod_type_sheet_QAM[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType - 1)
            {
                return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_QAM[num_subtype] + "\n";
            }else return "";
        break;

        case 3: // FSK
            count_modType = sizeof(mod_type_sheet_FSK)/sizeof(mod_type_sheet_FSK[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType - 1)
            {
                return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_FSK[num_subtype] + "\n";
            }else return "";
        break;

        case 4: // APSK
            count_modType = sizeof(mod_type_sheet_APSK)/sizeof(mod_type_sheet_APSK[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType - 1)
            {
                return "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_APSK[num_subtype] + "\n";
            }else return "";
        break;
        default:
            return "";
    }
}

void RnSSCPI::set_ModulationType(string &request_buffer, int num_type, int num_subtype, int &err, int sour_hw)
{
    err = error::No_error;
    int count_modType = 0;
    switch (num_type)
    {
        case 0: // ASK
            request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat ASK\n";
        break;

        case 1: // PSK
            count_modType = sizeof(mod_type_sheet_PSK)/sizeof(mod_type_sheet_PSK[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType - 1)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_PSK.at(num_subtype) + "\n";
            }
            else err = error::Value_out_of_range;
        break;

        case 2: // QAM
            count_modType = sizeof(mod_type_sheet_QAM)/sizeof(mod_type_sheet_QAM[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_QAM.at(num_subtype) + "\n";
            }
        break;

        case 3: // FSK
            count_modType = sizeof(mod_type_sheet_FSK)/sizeof(mod_type_sheet_FSK[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_FSK.at(num_subtype) + "\n";
            }
            else err = error::Value_out_of_range;
        break;

        case 4: // APSK
            count_modType = sizeof(mod_type_sheet_APSK)/sizeof(mod_type_sheet_APSK[0]);
            if(num_subtype >= 0 && num_subtype <= count_modType)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat " + mod_type_sheet_APSK.at(num_subtype) + "\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Invalid_type_number;
    }
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

void RnSSCPI::set_SymbolRate(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsFreq::eHZ:
            if(value >= MIN_SRATE && value <= MAX_SRATE)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) >= MIN_SRATE && value * pow(10, 3) <= MAX_SRATE)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe " + to_string(value) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) >= MIN_SRATE && value * pow(10, 6) <= MAX_SRATE)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe " + to_string(value) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
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

void RnSSCPI::set_BasebandState(string &request_buffer, bool value, int sour_hw) noexcept
{
    if(value)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STATe ON\n";
    }
    else request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STATe OFF\n";
}



int RnSSCPI::Search_StandardAPCO(string response)
{
    int number = -1;
    int count = sizeof(standard_sheet_apco)/sizeof(standard_sheet_apco[0]);
    for(int i = 0; i < count; i++)
    {
        if(response == standard_sheet_apco.at(i))
        {
            number = i;
            break;
        }
    }
    return number;
}

void RnSSCPI::search_StandardAPCO(string &device_response, int &number_standard, int &err)
{
    int count = sizeof(standard_sheet_apco)/sizeof(standard_sheet_apco[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == standard_sheet_apco.at(i))
        {
            number_standard = i;
            err = error::No_error;
            break;
        }
        else err = error::Element_not_found;
    }
}

int RnSSCPI::Search_Standard(string response)
{
    int number = -1;
    int count = sizeof(standard_sheet)/sizeof(standard_sheet[0]);
    for(int i = 0; i < count; i++)
    {
        if(response == standard_sheet.at(i))
        {
            number = i;
            break;
        }
    }
    return number;
}

void RnSSCPI::search_Standard(string &device_response, int &number_standard, int &err)
{
    int count = sizeof(standard_sheet)/sizeof(standard_sheet[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == standard_sheet.at(i))
        {
            number_standard = i;
            err = error::No_error;
            break;
        }
        else err = error::Element_not_found;
    }
}

int RnSSCPI::Search_ModPSK(string response)
{
    int number = -1;
    int count = sizeof(mod_type_sheet_PSK)/ sizeof(mod_type_sheet_PSK.at(0));
    for(int i = 0; i < count; i++)
    {
        if(response == mod_type_sheet_PSK.at(i))
        {
            number = i;
            break;
        }
    }
    return number;
}

void RnSSCPI::search_ModPSK(string &device_response, int &number_mod, int &err)
{
    int count = sizeof(mod_type_sheet_PSK)/sizeof(mod_type_sheet_PSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_PSK.at(i))
        {
            number_mod = i;
            err = error::No_error;
            break;
        }
        else err = error::Element_not_found;
    }
}

int RnSSCPI::Search_ModQAM(string response)
{
    int number = -1;
    int count = sizeof(mod_type_sheet_QAM)/sizeof(mod_type_sheet_QAM[0]);
    for(int i = 0; i < count; i++)
    {
        if(response == mod_type_sheet_QAM.at(i))
        {
            number = i;
            break;
        }
    }
    return number;
}

void RnSSCPI::search_ModQAM(string &device_response, int &number_mod, int &err)
{
    int count = sizeof(mod_type_sheet_QAM)/sizeof(mod_type_sheet_QAM[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_QAM.at(i))
        {
            number_mod = i;
            err = error::No_error;
            break;
        }
        else err = error::Element_not_found;
    }
}

int RnSSCPI::Search_ModFSK(string response)
{
    int number = -1;
    int count = sizeof(mod_type_sheet_FSK)/sizeof(mod_type_sheet_FSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(response == mod_type_sheet_FSK.at(i))
        {
            number = i;
            break;
        }
    }
    return number;
}

void RnSSCPI::search_ModFSK(string &device_response, int &number_mod, int &err)
{
    int count = sizeof(mod_type_sheet_FSK)/sizeof(mod_type_sheet_FSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_FSK.at(i))
        {
            number_mod = i;
            err = error::No_error;
            break;
        }
        else err = error::Element_not_found;
    }
}

int RnSSCPI::Search_ModAPSK(string response)
{
    int number = -1;
    int count = sizeof(mod_type_sheet_APSK)/sizeof(mod_type_sheet_APSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(response == mod_type_sheet_APSK.at(i))
        {
            number = i;
            break;
        }
    }
    return number;
}

void RnSSCPI::search_Mod_APSK(string &device_response, int &number_mod, int &err)
{
    int count = sizeof(mod_type_sheet_APSK)/sizeof(mod_type_sheet_APSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_APSK.at(i))
        {
            number_mod = i;
            err = error::No_error;
            break;
        }
        else err = error::Element_not_found;
    }
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

void RnSSCPI::set_TriggerForSweeps(string &request_buffer, int value, int &err, int trig_hw)
{
    err = error::No_error;
    int count_value = sizeof(trigger_for_sweeps_values)/sizeof(trigger_for_sweeps_values[0]);
    if(value >= 0 && value <= count_value - 1)
    {
        request_buffer = "SOURce" + to_string(trig_hw) + ":FSWeep:SOURce " + trigger_for_sweeps_values.at(value) + "\n";
    }
    else err = error::Value_out_of_range;
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

void RnSSCPI::set_SweepFreqMode(string &request_buffer, int value, int &err, int sour_hw)
{
    int count_mode = sizeof(sweep_freq_mode_values)/sizeof(sweep_freq_mode_values[0]);
    if(value >= 0 && value <= count_mode - 1)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:MODE " + sweep_freq_mode_values.at(value) + "\n";
    }
    else err = error::Value_out_of_range;
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

void RnSSCPI::set_FreqSpan(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsFreq::eHZ:
            if(value >= MAX_FREQ - MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) >= MAX_FREQ - MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN " + to_string(value) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) >= MAX_FREQ - MIN_FREQ)
            {
               request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN " + to_string(value) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eGHz:
            if(value * pow(10, 9) >= MAX_FREQ - MIN_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN " + to_string(value) + "GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }    
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

void RnSSCPI::set_FreqCenter(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsFreq::eHZ:
            if(value >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer " + to_string(value) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer " + to_string(value) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eGHz:
            if(value * pow(10, 9) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer " + to_string(value) + "GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
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

void RnSSCPI::set_FreqStart(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch(unit)
    {
        case unitsFreq::eHZ:
            if(value >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(value) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(value) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eGHz:
            if(value * pow(10, 9) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(value) + "GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
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
/*-------------------------------- Нужна нормальная проверка граничных значений ----------------------------------*/
void RnSSCPI::set_FreqStop(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch (unit)
    {
        case unitsFreq::eHZ:
            if(value >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(value) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(value) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eGHz:
            if(value * pow(10, 9) >= MIN_CENTER_FREQ)
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(value) + "GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
}

// Установка диапазона чатот развертки
void RnSSCPI::set_freqSweepRange(string &start_freq_buffer, string &stop_freq_buffer, double start_freq, double stop_freq, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch(unit)
    {
        case unitsFreq::eHZ:
            if(start_freq >= MIN_CENTER_FREQ && stop_freq > start_freq)
            {
                start_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(start_freq) + "Hz\n";
                stop_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(stop_freq) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(start_freq * pow(10, 3) >= MIN_CENTER_FREQ && stop_freq > start_freq)
            {
                start_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(start_freq) + "kHz\n";
                stop_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(stop_freq) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(start_freq * pow(10, 6) >= MIN_CENTER_FREQ && stop_freq > start_freq)
            {
                start_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(start_freq) + "MHz\n";
                stop_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(stop_freq) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eGHz:
            if(start_freq * pow(10, 9) >= MIN_CENTER_FREQ && stop_freq > start_freq)
            {
                start_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt " + to_string(start_freq) + "GHz\n";
                stop_freq_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP " + to_string(stop_freq) + "GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
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

void RnSSCPI::set_SweepSpacing(string &request_buffer, int value, int &err, int sour_hw)
{
    err = error::No_error;
    int count_spasing = sizeof(sweep_spacing_values) / sizeof(sweep_spacing_values[0]);
    if(value >= 0 && value <= count_spasing - 1)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SPACing " + sweep_spacing_values.at(value) + "\n";
    }
    else err = error::Invalid_type_number;
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

void RnSSCPI::set_Sweephape(string &request_buffer, int value, int &err, int sour_hw)
{
    err = error::No_error;
    int count_shape = sizeof(sweep_shape_values)/sizeof(sweep_shape_values[0]);
    if(value >= 0 && value <= count_shape - 1)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SHAPe " + sweep_shape_values.at(value) + "\n";
    }
    else err = error::Invalid_type_number;
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

void RnSSCPI::set_SweepRetrace(string &request_buffer, bool value, int sour_hw) noexcept
{
    if(value)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace ON\n";
    }
    else request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace OFF\n";
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

void RnSSCPI::set_SweepStepLinear(string &request_buffer, double value, double freq_start, double freq_stop, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch(unit)
    {
        case unitsFreq::eHZ:
            if(value >= 0.01 && value <= (freq_stop - freq_start))
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear " + to_string(value) + "Hz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::ekHz:
            if(value * pow(10, 3) >= 0.01 && value * pow(10, 3) <= (freq_stop - freq_start))
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear " + to_string(value) + "kHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eMHz:
            if(value * pow(10, 6) >= 0.01 && value * pow(10, 6) <= (freq_stop - freq_start))
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear " + to_string(value) + "MHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        case unitsFreq::eGHz:
            if(value * pow(10, 9) >= 0.01 && value * pow(10, 9) <= (freq_stop - freq_start))
            {
                request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear " + to_string(value) + "GHz\n";
            }
            else err = error::Value_out_of_range;
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
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

void RnSSCPI::set_SweepStepLogarithmic(string &request_buffer, double value, int &err, int sour_hw)
{
    err = error::No_error;
    if(value >= 0.01 && value <= 100)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LOGarithmic " + to_string(value) + "PCT\n";
    }
    else err = error::Value_out_of_range;
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

void RnSSCPI::set_SweepPoints(string &request_buffer, int value, int &err, int sour_hw)
{
    err = error::No_error;
    if(value >= 2)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:POINts " + to_string(value) + "\n";
    }
    else err = error::Value_out_of_range;
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

/*------------------------------ Разобраться с граничными значениями ---------------------------------------*/
void RnSSCPI::set_SweepFreqDwell(string &request_buffer, double value, int &err, int unit, int sour_hw)
{
    err = error::No_error;
    switch(unit)
    {
        case unitsTime::s:
            request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl " + to_string(value) + "s\n";
        break;

        case unitsTime::ms:
            request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl " + to_string(value) + "ms\n";
        break;

        case unitsTime::us:
            request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl " + to_string(value) + "us\n";
        break;

        default:
            err = error::Wrong_unit_of_measure;
    }
}

// Выполнение однократной развертки
string RnSSCPI::SweepFreqExecute(int sour_hw)
{
    // Реализовать проверку на готовность всех параметров развертки
    return "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:EXECute\n";
}

void RnSSCPI::sweepFreqExecute(string &request_buffer, int sour_hw) noexcept
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:EXECute\n";
}
