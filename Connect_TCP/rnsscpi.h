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
#define MAX_SRATE 300000000

using namespace std;

enum unitsFreq {
    eGHz,
    eMHz,
    ekHz,
    eHZ

};
enum unitsPower{
    edBM,
    edBUV,
    eV,
    emV,
    euV,
    enV
};
enum unitsTime{
    s,
    ms,
    us
};

class RnSSCPI
{
    public:


    private:
        string response_From_Device;

        // Стандартные конфигурации устройства и их сокращенные названия для команд

        array<array<string, 2>, 25> standard_sheet = {{{"PHASE1 C4FM", "APCOPH1C4"},
                                                       {"PHASE1 CQPSK", "APCOPH1CQ"},
                                                       {"PHASE2 H-CPM", "APCOPH2HC"},
                                                       {"PHASE2 H-DQPSK", "APCOPH2HDQ"},
                                                       {"PHASE2 H-D8PSK WIDE", "APCOPH2HD8PSKW"},
                                                       {"PHASE2 H-D8PSK NARROW", "APCOPH2HD8PSKN"},
                                                       {"PHASE1 LSM", "APCOPH1L"},
                                                       {"PHASE1 WCQPSK", "APCOPH1W"},
                                                       {"BLUETOOTH", "BLU"},
                                                       {"CDMA2000 FORWARD", "CFOR"},
                                                       {"CDMA2000 REVERSE","CREV"},
                                                       {"CW IN BASEBAND", "CWBP"},
                                                       {"DECT", "DECT"},
                                                       {"ETC", "ETC"},
                                                       {"GSM", "GSM"},
                                                       {"GSM EDGE", "GSME"},
                                                       {"NADC", "NADC"},
                                                       {"PDC", "PDC"},
                                                       {"PHS", "PHS"},
                                                       {"TD-SCDMA", "TDSC"},
                                                       {"TETRA", "TETR"},
                                                       {"TFTS", "TFTS"},
                                                       {"WCDMA-3GPP", "W3GP"},
                                                       {"WORLDSPACE", "WORL"},
                                                       {"USER", "USER"}}};


        // Типы модуляции и их сокращенные названия для команд
        array<array<string, 2>, 35> mod_type_sheet = {{{"ASK", "ASK"},
                                                       {"BPSK", "BPSK"},
                                                       {"QPSK", "QPSK"},
                                                       {"QPSK 45 OFFSET", "QPSK45"},
                                                       {"QPSK EDGE", "QEDG"},
                                                       {"AQPSK", "AQPS"},
                                                       {"OQPSK", "OQPS"},
                                                       {"PI/4-QPSK", "P4QP"},
                                                       {"PI/2-DBPSK", "P2DB"},
                                                       {"PI/4-DQPSK", "P4DQ"},
                                                       {"PI/8-D8PSK", "P8D8"},
                                                       {"8PSK", "PSK8"},
                                                       {"8PSK EDGE", "P8ED"},
                                                       {"16QAM", "QAM16"},
                                                       {"16QAM EDGE", "QAM16ED"},
                                                       {"32QAM", "QAM32"},
                                                       {"32QAM EDGE", "QAM32ED"},
                                                       {"64QAM", "QAM64"},
                                                       {"128QAM", "QAM128"},
                                                       {"256QAM", "QAM256"},
                                                       {"512QAM", "QAM512"},
                                                       {"1024QAM", "QAM1024"},
                                                       {"2048QAM", "QAM2048"},
                                                       {"4096QAM", "QAM4096"},
                                                       {"MSK", "MSK"},
                                                       {"2FSK", "FSK2"},
                                                       {"4FSK", "FSK4"},
                                                       {"8FSK", "FSK8"},
                                                       {"16FSK", "FSK16"},
                                                       {"32FSK", "FSK32"},
                                                       {"64FSK", "FSK64"},
                                                       {"VARIABLE FSK", "FSKV"},
                                                       {"16APSK", "APSK16"},
                                                       {"32APSK", "APSK32"},
                                                       {"USER", "USER"}}};

        array<string, 6> trigger_for_sweeps_values = {"AUTO", "IMMediate", "SINGle", "BUS", "EXTernal", "EAUTo"};
        array<string, 3> sweep_freq_mode_values = {"AUTO", "MANual", "STEP"};
        array<string, 2> sweep_spacing_values = {"LINear", "LOGarithmic"};
        array<string, 2> sweep_shape_values = {"SAWTooth", "TRIangle"};
        array<string, 5> freq_mode_values = {"CW", "FIXed", "SWEep", "LIST", "COMBined"};

    public:
        RnSSCPI();
        string Get_Last_Response();                                                                                        // Последний запрос
        void Response_Handling(string answer);                                                                             // Обработчик ответов от устройства (удаление \n из строки)
        string Preset();                                                                                                   // Сброс настроек устройства

        // Основные запросы
        string Send_Request_IDN();                                                                                         // Идентификация устройства
        string Send_Request_Error();                                                                                       // Запрос стека ошибок
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
        string SetAccordingToStandard(int value, int sour_hw = 1);                                                         // Установка стандартных режимов
        string SetModulationType(int num_type, int sour_hw = 1);                                                           // Установка типа модуляции
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
