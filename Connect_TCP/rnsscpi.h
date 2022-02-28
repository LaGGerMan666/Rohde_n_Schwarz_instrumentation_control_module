#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <string>
#include <math.h>
#include <QRegExp>
#include <regex>
#include <QVariant>
#include <array>

#define MAX_FREQ 12.75 * pow(10,9)
#define MIN_FREQ 100 * pow(10,3)
#define MIN_CENTER_FREQ 300000
#define MAX_POW_DBM 30
#define MIN_POW_DBM -145
#define MIN_POW_V 12.57/pow(10,9)
#define MAX_POW_V 7.071
#define MIN_SRATE 50

/**
 * @def MAX_SRATE
 * @brief ...
 */
#define MAX_SRATE 300000000

using namespace std;

enum unitsFreq {
    eGHz,
    eMHz,
    ekHz,
    eHZ

};

/**
 * @brief Перечисление единиц мощности
 */
enum unitsPower{
    edBM,
    edBUV,
    eV,
    emV,
    euV,
    enV
};

/**
 * @brief The unitsTime enum
 */
enum unitsTime{
    s,
    ms,
    us
};

enum error{
    No_error,
    Value_out_of_range,
    Wrong_unit_of_measure,
    Invalid_type_number,
    Element_not_found
};

// Стандартные конфигурации устройства и их сокращенные названия для команд
static const array<string, 8> standard_sheet_apco = {"APCOPH1C4", "APCOPH1CQ", "APCOPH2HC", "APCOPH2HDQ", "APCOPH2HD8PSKW", "APCOPH2HD8PSKN", "APCOPH1L", "APCOPH1W"};
static const array<string, 16> standard_sheet = {"BLU", "CFOR", "CREV", "CWBP", "DECT", "ETC", "GSM", "GSME", "NADC", "PDC", "PHS", "TDSC", "TETR", "TFTS", "W3GP", "WORL"};

// Типы модуляции и их сокращенные названия для команд
static const array<string, 12> mod_type_sheet_PSK = {"BPSK", "QPSK", "QPSK45", "QEDG", "AQPS", "OQPS", "P4QP", "P2DB", "P4DQ", "P8D8", "PSK8", "P8ED"};
static const array<string, 11> mod_type_sheet_QAM = {"QAM16", "QAM16ED", "QAM32", "QAM32ED", "QAM64", "QAM128", "QAM256", "QAM512", "QAM1024", "QAM2048", "QAM4096"};
static const array<string, 8> mod_type_sheet_FSK = {"MSK", "FSK2", "FSK4", "FSK8", "FSK16", "FSK32", "FSK64", "FSKV"};
static const array<string, 2> mod_type_sheet_APSK = {"APSK16", "APSK32"};

//  Массивы команд для частотной развертки
static const array<string, 6> trigger_for_sweeps_values = {"AUTO", "IMMediate", "SINGle", "BUS", "EXTernal", "EAUTo"};
static const array<string, 3> sweep_freq_mode_values = {"AUTO", "MANual", "STEP"};
static const array<string, 2> sweep_spacing_values = {"LINear", "LOGarithmic"};
static const array<string, 2> sweep_shape_values = {"SAWTooth", "TRIangle"};
static const array<string, 5> freq_mode_values = {"CW", "FIXed", "SWEep", "LIST", "COMBined"};

/**
 * @brief The RnSSCPI class
 */
class RnSSCPI
{
    private:


    public:
        RnSSCPI();
        /**
         * @brief Response_Handling
         * @param answer - Ответ для ...
         */
        void Response_Handling(string answer);                                                                             // Обработчик ответов от устройства (удаление \n из строки)
        static void Preset(string &request_buffer) noexcept;                                                                                                   // Сброс настроек устройства
        int Search_StandardAPCO(string response);
        static void search_StandardAPCO(string &device_response, int &number_standard, int &err);
        int Search_Standard(string response);
        static void search_Standard(string &device_response, int &number_standard, int &err);
        int Search_ModPSK(string response);
        static void search_ModPSK(string &device_response, int &number_mod, int &err);
        int Search_ModQAM(string response);
        static void search_ModQAM(string &device_response, int &number_mod, int &err);
        int Search_ModFSK(string response);
        static void search_ModFSK(string &device_response, int &number_mod, int &err);
        int Search_ModAPSK(string response);
        static void search_Mod_APSK(string &device_response, int &number_mod, int &err);

        // Основные запросы
        string Send_Request_IDN() const;                                                                                      // Идентификация устройства
        static void request_IDN(string &request_buffer) noexcept;
        string Send_Request_Error() noexcept;                                                                                       // Запрос стека ошибок
        static void request_LastError(string &request_buffer) noexcept;
        string Send_Request_Frequency(int sour_hw = 1);                                                                    // Запрос значения частоты
        static void request_Frequency(string &request_buffer, int sour_hw = 1);
        string Send_Request_Level(int sour_hw = 1);                                                                        // Запрос значение уровня
        static void request_Level(string &request_buffer, int sour_hw = 1);
        string Send_Request_PEP(int sour_hw = 1);                                                                          // Запрос значения PEP
        static void request_PEP(string &request_buffer, int sour_hw = 1);

        // Запросы модуляция
        string Send_Request_Standard(int sour_hw = 1);                                                                     // Запрос названия стандартного режима
        static void request_Standard(string &request_buffer, int sour_hw = 1);
        string Send_Request_ModType(int sour_hw = 1);                                                                      // Запрос типа модуляции
        static void request_ModType(string &request_buffer, int sour_hw = 1);
        string Send_Request_SymbolRate(int sour_hw = 1);                                                                   // Запрос скорости передачи символов
        static void request_SymbolRate(string &request_buffer, int sour_hw = 1);

        // Запросы частотная развертка
        string Send_Request_TriggerForSweeps(int trig_hw = 1);                                                             // Запрос вида триггера для разверток
        static void request_TriggerForSweeps(string &request_buffer, int trig_hw = 1);
        string Send_Request_SweepFreqMode(int sour_hw = 1);                                                                // Запрос циклического режима для развертки по частоте
        static void request_SweepFreqMod(string &request_buffer, int sour_hw = 1);
        string Send_Request_FreqSpan(int sour_hw = 1);                                                                     // Запрос диапазона частотной развертки
        static void request_FreqSpan(string &request_buffer, int sour_hw = 1);
        string Send_Request_FreqCenter(int sour_hw = 1);                                                                   // Запрос центральной частоты развертки
        static void request_FreqCenter(string &request_buffer, int sour_hw = 1);
        string Send_Request_FreqStart(int sour_hw = 1);                                                                    // Запрос начальной частоты развертки
        static void request_FreqStart(string &request_buffer, int sour_hw = 1);
        string Send_Request_FreqStop(int sour_hw = 1);                                                                     // Запрос конечную частоту развертки
        static void request_FreqStop(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepSpacing(int sour_hw = 1);                                                                 // Запрос режима расчета частотных интервалов
        static void request_SweepSpacing(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepShape(int sour_hw = 1);                                                                   // Запрос установленной формы сигнала для последовательности развертки частоты
        static void request_SweepShape(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepRetrace(int sour_hw = 1);                                                                 // Запрос активности изменения начальной частоты в ожидании следующего триггера
        static void request_SweepRetrace(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepStepLinear(int sour_hw = 1);                                                              // Запрос ширины шага для линейной развертки
        static void request_SweepStepLinear(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepStepLogarithmic(int sour_hw = 1);                                                         // Запрос логарифмически определяемой ширины шага для развертки по частоте
        static void request_SweepStepLog(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepPoints(int sour_hw = 1);                                                                  // Запрос количества шагов в пределах диапазона развертки
        static void request_SweepPoints(string &request_buffer, int sour_hw = 1);
        string Send_Request_FrequencyMode(int sour_hw = 1);                                                                // Запрос частотного режима для генерации выходного ВЧ-сигнала.
        static void request_FrequencyMode(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepFreqDwell(int sour_hw = 1);                                                               // Запрос времени задержки для шага развертки по частоте
        static void request_SweepFreqDwell(string &request_buffer, int sour_hw = 1);
        string Send_Request_SweepFreqRun(int sour_hw = 1);                                                                 // Запрос текущего состояния развертки
        static void request_SweepFreqRun(string &request_buffer, int sour_hw = 1);
        static void sweepResetAll(string &request_buffer, int sour_hw = 1) noexcept;

        // Основные настройки
        string SetFrequency(double value, int unit = 3, int sour_hw = 1);                                                  // Установка частоты через число
        static void set_Frequency(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        string SetFrequencyMode(int value, int sour_hw = 1);                                                               // Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
        static void set_FrequencyMode(string &request_buffer, int value, int &err, int sour_hw = 1);
        string SetPower(double value, int unit = 0, int sour_hw = 1);                                                      // Установка мощности
        static void set_Power(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1) ;
        string SetLevel(double value, int unit = 0, int sour_hw = 1);                                                      // Установка уровня
        static void set_Level(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1);
        string SetBasebandState(bool value, int sour_hw = 1);                                                              // Метод активации Baseband
        static void set_BasebandState(string &request_buffer, bool value, int sour_hw = 1) noexcept;

        // Настройки модуляции
        string SetAccordingToStandard(int value, int isAPCO, int sour_hw = 1);                                                         // Установка стандартных режимов
        static void set_AccordingToStandard(string &request_buffer, int standard_number, bool isAPCO, int &err, int sour_hw = 1);
        string SetModulationType(int num_subtype, int num_type, int sour_hw = 1);                                                           // Установка типа модуляции
        static void set_ModulationType(string &request_buffer, int num_type, int num_subtype, int &err, int sour_hw = 1);
        string SetSymbolRate(double value, int unit = 3, int sour_hw = 1);                                                 // Установка скорости передачи символов
        static void set_SymbolRate(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        // Настройки частотной развертки
        string SetTriggerForSweeps(int value, int trig_hw = 1);                                                            // Выбор триггера для разверток
        static void set_TriggerForSweeps(string &request_buffer, int value, int &err, int trig_hw = 1);
        string SetSweepFreqMode(int value, int sour_hw = 1);                                                               // Установка циклического режима для развертки по частоте
        static void set_SweepFreqMode(string &request_buffer, int value, int &err, int sour_hw = 1);
        string SetFreqSpan(double value, int unit = 3, int sour_hw = 1);                                                   // Установка диапазона частотной развертки
        static void set_FreqSpan(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        string SetFreqCenter(double value, int unit = 3, int sour_hw = 1);                                                 // Установка центральной частоты развертки
        static void set_FreqCenter(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        string SetFreqStart(double value, int unit = 3, int sour_hw = 1);                                                  // Установка начальной частоты развертки
        static void set_FreqStart(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        string SetFreqStop(double value, int unit = 3, int sour_hw = 1);                                                   // Установка конечной частоты развертки
        static void set_FreqStop(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        /*------------------------------ Установка диапазона чатот развертки ---------------------------------------*/
        static void set_freqSweepRange(string &start_freq_buffer, string &stop_freq_buffer, double start_freq, double stop_freq, int &err, int unit = 3, int sour_hw = 1);
        /*----------------------------------------------------------------------------------------------------------*/

        string SetSweepSpacing(int value, int sour_hw = 1);                                                                // Установка режима расчета частотных интервалов
        static void set_SweepSpacing(string &request_buffer, int value, int &err, int sour_hw = 1);
        string SetSweepShape(int value, int sour_hw = 1);                                                                  // Установка формы сигнала для последовательности развертки частоты
        static void set_Sweephape(string &request_buffer, int value, int &err, int sour_hw = 1);
        string SetSweepRetrace(bool value, int sour_hw = 1);                                                               // Активировать изменение начальной частоты в ожидании следующего триггера
        static void set_SweepRetrace(string &request_buffer, bool value, int sour_hw = 1) noexcept;
        string SetSweepResetAll(int sour_hw = 1);                                                                          // Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())

        string SetSweepStepLinear(double value, double freq_Start, double freq_Stop, int unit = 3, int sour_hw = 1);       // Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START)
        static void set_SweepStepLinear(string &request_buffer, double value, double freq_start, double freq_stop, int &err, int unit = 3, int sour_hw = 1);
        string SetSweepStepLogarithmic(double value, int sour_hw = 1);                                                     // Установка логарифмически определяемой ширины шага для развертки по частоте (Задается в %(PCT))
        static void set_SweepStepLogarithmic(string &request_buffer, double value, int &err, int sour_hw = 1);
        string SetSweepPoints(int value, int sour_hw = 1);                                                                 // Установка количества шагов в пределах диапазона развертки
        static void set_SweepPoints(string &request_buffer, int value, int &err, int sour_hw = 1);
        string SetSweepFreqDwell(double value, int unit = 0, int sour_hw = 1);                                             // Установка времени задержки для шага развертки по частоте
        static void set_SweepFreqDwell(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1);
        string SweepFreqExecute(int sour_hw = 1);                                                                          // Выполнение однократной развертки
        static void sweepFreqExecute(string &request_buffer, int sour_hw = 1) noexcept;
};

#endif // RNSSCPI_H
