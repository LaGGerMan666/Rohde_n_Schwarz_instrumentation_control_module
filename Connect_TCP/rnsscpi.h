#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <string>
#include <math.h>
#include <QRegExp>
#include <regex>
#include <QVariant>
#include <array>
#define MAX_FREQ 12750000000
#define MIN_FREQ 100
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

/**
 * @brief The RnSSCPI class
 */
class RnSSCPI
{
    private:
//        string response_From_Device;

        // Стандартные конфигурации устройства и их сокращенные названия для команд
        array<string, 8> standard_sheet_apco = {"APCOPH1C4", "APCOPH1CQ", "APCOPH2HC", "APCOPH2HDQ", "APCOPH2HD8PSKW", "APCOPH2HD8PSKN", "APCOPH1L", "APCOPH1W"};
        array<string, 16> standard_sheet = {"BLU", "CFOR", "CREV", "CWBP", "DECT", "ETC", "GSM", "GSME", "NADC", "PDC", "PHS", "TDSC", "TETR", "TFTS", "W3GP", "WORL"};

        // Типы модуляции и их сокращенные названия для команд
        array<string, 12> mod_type_sheet_PSK = {"BPSK", "QPSK", "QPSK45", "QEDG", "AQPS", "OQPS", "P4QP", "P2DB", "P4DQ", "P8D8", "PSK8", "P8ED"};
        array<string, 11> mod_type_sheet_QAM = {"QAM16", "QAM16ED", "QAM32", "QAM32ED", "QAM64", "QAM128", "QAM256", "QAM512", "QAM1024", "QAM2048", "QAM4096"};
        array<string, 8> mod_type_sheet_FSK = {"MSK", "FSK2", "FSK4", "FSK8", "FSK16", "FSK32", "FSK64", "FSKV"};
        array<string, 2> mod_type_sheet_APSK = {"APSK16", "APSK32"};

        //  Массивы команд для частотной развертки
        array<string, 6> trigger_for_sweeps_values = {"AUTO", "IMMediate", "SINGle", "BUS", "EXTernal", "EAUTo"};
        array<string, 3> sweep_freq_mode_values = {"AUTO", "MANual", "STEP"};
        array<string, 2> sweep_spacing_values = {"LINear", "LOGarithmic"};
        array<string, 2> sweep_shape_values = {"SAWTooth", "TRIangle"};
        array<string, 5> freq_mode_values = {"CW", "FIXed", "SWEep", "LIST", "COMBined"};

    public:
        RnSSCPI();
        string Get_Last_Response();                                                                                        // Последний запрос

        /**
         * @brief Response_Handling
         * @param answer - Ответ для ...
         */
        void Response_Handling(string answer);                                                                             // Обработчик ответов от устройства (удаление \n из строки)
        string Preset();                                                                                                   // Сброс настроек устройства
        int Search_StandardAPCO(string response);
        int Search_Standard(string response);
        int Search_ModPSK(string response);
        int Search_ModQAM(string response);
        int Search_ModFSK(string response);
        int Search_ModAPSK(string response);

        // Основные запросы
        string Send_Request_IDN() const;                                                                                      // Идентификация устройства
        string Send_Request_Error() noexcept;                                                                                       // Запрос стека ошибок
        string Send_Request_Frequency(int sour_hw = 1);                                                                    // Запрос значения частоты
        string Send_Request_Level(int sour_hw = 1);                                                                        // Запрос значение уровня
        string Send_Request_PEP(int sour_hw = 1);                                                                          // Запрос значения PEP

        // Запросы модуляция
        string Send_Request_Standard(int sour_hw = 1);                                                                     // Запрос названия стандартного режима
        string Send_Request_ModType(int sour_hw = 1);                                                                      // Запрос типа модуляции
        string Send_Request_SymbolRate(int sour_hw = 1);                                                                   // Запрос скорости передачи символов

        // Запросы частотная развертка
        string Send_Request_TriggerForSweeps(int trig_hw = 1);                                                             // Запрос вида триггера для разверток
        string Send_Request_SweepFreqMode(int sour_hw = 1);                                                                // Запрос циклического режима для развертки по частоте
        string Send_Request_FreqSpan(int sour_hw = 1);                                                                     // Запрос диапазона частотной развертки
        string Send_Request_FreqCenter(int sour_hw = 1);                                                                   // Запрос центральной частоты развертки
        string Send_Request_FreqStart(int sour_hw = 1);                                                                    // Запрос начальной частоты развертки
        string Send_Request_FreqStop(int sour_hw = 1);                                                                     // Запрос конечную частоту развертки
        string Send_Request_SweepSpacing(int sour_hw = 1);                                                                 // Запрос режима расчета частотных интервалов
        string Send_Request_SweepShape(int sour_hw = 1);                                                                   // Запрос установленной формы сигнала для последовательности развертки частоты
        string Send_Request_SweepRetrace(int sour_hw = 1);                                                                 // Запрос активности изменения начальной частоты в ожидании следующего триггера
        string Send_Request_SweepStepLinear(int sour_hw = 1);                                                              // Запрос ширины шага для линейной развертки
        string Send_Request_SweepStepLogarithmic(int sour_hw = 1);                                                         // Запрос логарифмически определяемой ширины шага для развертки по частоте
        string Send_Request_SweepPoints(int sour_hw = 1);                                                                  // Запрос количества шагов в пределах диапазона развертки
        string Send_Request_FrequencyMode(int sour_hw = 1);                                                                // Запрос частотного режима для генерации выходного ВЧ-сигнала.
        string Send_Request_SweepFreqDwell(int sour_hw = 1);                                                               // Запрос времени задержки для шага развертки по частоте
        string Send_Request_SweepFreqRun(int sour_hw = 1);                                                                 // Запрос текущего состояния развертки

        // Основные настройки
        string SetFrequency(double value, int unit = 3, int sour_hw = 1);                                                  // Установка частоты через число
        string SetFrequencyMode(int value, int sour_hw = 1);                                                               // Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
        string SetPower(double value, int unit = 0, int sour_hw = 1);                                                      // Установка мощности
        string SetLevel(double value, int unit = 0, int sour_hw = 1);                                                      // Установка уровня
        string SetBasebandState(bool value, int sour_hw = 1);                                                              // Метод активации Baseband

        // Настройки модуляции
        string SetAccordingToStandard(int value, int isAPCO, int sour_hw = 1);                                                         // Установка стандартных режимов
        string SetModulationType(int num_subtype, int num_type, int sour_hw = 1);                                                           // Установка типа модуляции
        string SetSymbolRate(double value, int unit = 3, int sour_hw = 1);                                                 // Установка скорости передачи символов

        // Настройки частотной развертки
        string SetTriggerForSweeps(int value, int trig_hw = 1);                                                            // Выбор триггера для разверток
        string SetSweepFreqMode(int value, int sour_hw = 1);                                                               // Установка циклического режима для развертки по частоте
        string SetFreqSpan(double value, int unit = 3, int sour_hw = 1);                                                   // Установка диапазона частотной развертки
        string SetFreqCenter(double value, int unit = 3, int sour_hw = 1);                                                 // Установка центральной частоты развертки
        string SetFreqStart(double value, int unit = 3, int sour_hw = 1);                                                  // Установка начальной частоты развертки
        string SetFreqStop(double value, int unit = 3, int sour_hw = 1);                                                   // Установка конечной частоты развертки
        string SetSweepSpacing(int value, int sour_hw = 1);                                                                // Установка режима расчета частотных интервалов
        string SetSweepShape(int value, int sour_hw = 1);                                                                  // Установка формы сигнала для последовательности развертки частоты
        string SetSweepRetrace(bool value, int sour_hw = 1);                                                               // Активировать изменение начальной частоты в ожидании следующего триггера
        string SetSweepResetAll(int sour_hw = 1);                                                                          // Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())
        string SetSweepStepLinear(double value, double freq_Start, double freq_Stop, int unit = 3, int sour_hw = 1);       // Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START)
        string SetSweepStepLogarithmic(double value, int sour_hw = 1);                                                     // Установка логарифмически определяемой ширины шага для развертки по частоте (Задается в %(PCT))
        string SetSweepPoints(int value, int sour_hw = 1);                                                                 // Установка количества шагов в пределах диапазона развертки
        string SetSweepFreqDwell(double value, int unit = 0, int sour_hw = 1);                                             // Установка времени задержки для шага развертки по частоте
        string SweepFreqExecute(int sour_hw = 1);                                                                          // Выполнение однократной развертки
};

#endif // RNSSCPI_H
