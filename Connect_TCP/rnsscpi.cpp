#include "rnsscpi.h"

// Стандартные конфигурации устройства и их сокращенные названия для команд
std::array<std::string, 8> RnSSCPI::standard_sheet_apco = {"APCOPH1C4", "APCOPH1CQ", "APCOPH2HC", "APCOPH2HDQ", "APCOPH2HD8PSKW", "APCOPH2HD8PSKN", "APCOPH1L", "APCOPH1W"};
std::array<string, 16> RnSSCPI::standard_sheet = {"BLU", "CFOR", "CREV", "CWBP", "DECT", "ETC", "GSM", "GSME", "NADC", "PDC", "PHS", "TDSC", "TETR", "TFTS", "W3GP", "WORL"};

// Типы модуляции и их сокращенные названия для команд
std::array<string, 12> RnSSCPI::mod_type_sheet_PSK = {"BPSK", "QPSK", "QPSK45", "QEDG", "AQPS", "OQPS", "P4QP", "P2DB", "P4DQ", "P8D8", "PSK8", "P8ED"};
std::array<string, 11> RnSSCPI::mod_type_sheet_QAM = {"QAM16", "QAM16ED", "QAM32", "QAM32ED", "QAM64", "QAM128", "QAM256", "QAM512", "QAM1024", "QAM2048", "QAM4096"};
std::array<string, 8> RnSSCPI::mod_type_sheet_FSK = {"MSK", "FSK2", "FSK4", "FSK8", "FSK16", "FSK32", "FSK64", "FSKV"};
std::array<string, 2> RnSSCPI::mod_type_sheet_APSK = {"APSK16", "APSK32"};

//  Массивы команд для частотной развертки
std::array<string, 6> RnSSCPI::trigger_for_sweeps_values = {"AUTO", "IMMediate", "SINGle", "BUS", "EXTernal", "EAUTo"};
std::array<string, 3> RnSSCPI::sweep_freq_mode_values = {"AUTO", "MANual", "STEP"};
std::array<string, 2> RnSSCPI::sweep_spacing_values = {"LINear", "LOGarithmic"};
std::array<string, 2> RnSSCPI::sweep_shape_values = {"SAWTooth", "TRIangle"};
std::array<string, 5> RnSSCPI::freq_mode_values = {"CW", "FIXed", "SWEep", "LIST", "COMBined"};

RnSSCPI::RnSSCPI()
{

}

// Сброс настроек устройства
void RnSSCPI::Preset(string &request_buffer) noexcept
{
    request_buffer = "SYSTem:PRESet\n";
}

void RnSSCPI::request_IDN(string &request_buffer) noexcept
{
    request_buffer = "*IDN?\n";
}

void RnSSCPI::request_LastError(string &request_buffer) noexcept
{
    request_buffer = "SYSTem:ERRor?\n";
}

void RnSSCPI::request_Frequency(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CW?\n";;
}

void RnSSCPI::request_FrequencyMode(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:MODE?\n";
}

void RnSSCPI::request_Level(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:LEVel:IMMediate:AMPLitude?\n";
}

void RnSSCPI::request_PEP(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":POWer:PEP?\n";
}

void RnSSCPI::request_Standard(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard?\n";
}

void RnSSCPI::request_ModType(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:FORMat?\n";
}

void RnSSCPI::request_SymbolRate(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:SRATe?\n";
}

void RnSSCPI::request_TriggerForSweeps(string &request_buffer, int trig_hw)
{
    request_buffer = "TRIGger" + to_string(trig_hw) + ":FSWeep:SOURce?\n";
}

void RnSSCPI::request_SweepFreqMod(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:MODE?\n";
}

void RnSSCPI::request_FreqSpan(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:SPAN?\n";
}

void RnSSCPI::request_FreqCenter(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:CENTer?\n";
}

void RnSSCPI::request_FreqStart(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STARt?\n";
}

void RnSSCPI::request_FreqStop(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":FREQuency:STOP?\n";
}

void RnSSCPI::request_SweepSpacing(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SPACing?\n";
}

void RnSSCPI::request_SweepShape(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:SHAPe?\n";
}

void RnSSCPI::request_SweepStepLinear(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LINear?\n";
}

void RnSSCPI::request_SweepStepLog(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:STEP:LOGarithmic?\n";
}

void RnSSCPI::request_SweepPoints(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:POINts?\n";
}

void RnSSCPI::request_SweepFreqDwell(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:DWELl?\n";
}

void RnSSCPI::request_SweepFreqRun(string &request_buffer, int sour_hw)
{
    request_buffer = "SOURce" + to_string(sour_hw) + "SWEep:FREQuency:RUNNing?\n";
}

// Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())
void RnSSCPI::sweepResetAll(string &request_buffer, int sour_hw) noexcept
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:RESet:ALL\n";
}

// Установка частоты
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
            request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STANdard " + standard_sheet_apco.at(standard_number) + "\n";
        }
        else err = error::Value_out_of_range;
    }
}

// Установка типа модуляции
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
void RnSSCPI::set_BasebandState(string &request_buffer, bool value, int sour_hw) noexcept
{
    if(value)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STATe ON\n";
    }
    else request_buffer = "SOURce" + to_string(sour_hw) + ":BB:DM:STATe OFF\n";
}


int RnSSCPI::search_StandardAPCO(string &device_response, int &number_standard)
{
    int count = sizeof(standard_sheet_apco)/sizeof(standard_sheet_apco[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == standard_sheet_apco.at(i))
        {
            number_standard = i;
            return error::No_error;
            break;
        }
    }
    return error::Element_not_found;
}


int RnSSCPI::search_Standard(string &device_response, int &number_standard)
{
    int count = sizeof(standard_sheet)/sizeof(standard_sheet[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == standard_sheet.at(i))
        {
            number_standard = i;
            return error::No_error;
            break;
        }
    }
    return error::Element_not_found;
}


int RnSSCPI::search_ModPSK(string &device_response, int &number_mod)
{
    int count = sizeof(mod_type_sheet_PSK)/sizeof(mod_type_sheet_PSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_PSK.at(i))
        {
            number_mod = i;
            return error::No_error;
            break;
        }
    }
    return error::Element_not_found;
}


int RnSSCPI::search_ModQAM(string &device_response, int &number_mod)
{
    int count = sizeof(mod_type_sheet_QAM)/sizeof(mod_type_sheet_QAM[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_QAM.at(i))
        {
            number_mod = i;
            return error::No_error;
            break;
        }
    }
    return error::Element_not_found;
}


int RnSSCPI::search_ModFSK(string &device_response, int &number_mod)
{
    int count = sizeof(mod_type_sheet_FSK)/sizeof(mod_type_sheet_FSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_FSK.at(i))
        {
            number_mod = i;
            return error::No_error;
            break;
        }
    }
    return error::Element_not_found;
}


int RnSSCPI::search_Mod_APSK(string &device_response, int &number_mod)
{
    int count = sizeof(mod_type_sheet_APSK)/sizeof(mod_type_sheet_APSK[0]);
    for(int i = 0; i < count; i++)
    {
        if(device_response == mod_type_sheet_APSK.at(i))
        {
            number_mod = i;
            return error::No_error;
            break;
        }
    }
    return error::Element_not_found;
}

// Выбор триггера для разверток
void RnSSCPI::set_TriggerForSweeps(string &request_buffer, int value, int &err, int trig_hw)
{
    err = error::No_error;
    int count_value = sizeof(trigger_for_sweeps_values)/sizeof(trigger_for_sweeps_values[0]);
    if(value >= 0 && value <= count_value - 1)
    {
        request_buffer = "TRIGger" + to_string(trig_hw) + ":FSWeep:SOURce " + trigger_for_sweeps_values.at(value) + "\n";
    }
    else err = error::Value_out_of_range;
}

// Установка циклического режима для развертки по частоте
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
void RnSSCPI::set_SweepShape(string &request_buffer, int value, int &err, int sour_hw)
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
void RnSSCPI::set_SweepRetrace(string &request_buffer, bool value, int sour_hw) noexcept
{
    if(value)
    {
        request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace ON\n";
    }
    else request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:RETRace OFF\n";
}

// Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START) через строку
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
void RnSSCPI::sweepFreqExecute(string &request_buffer, int sour_hw) noexcept
{
    request_buffer = "SOURce" + to_string(sour_hw) + ":SWEep:FREQuency:EXECute\n";
}
