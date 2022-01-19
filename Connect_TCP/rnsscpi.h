#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <QString>
#include <QStringList>
#include <math.h>
#include <QRegExp>
#include <QVariant>
#define MAX_FREQ 12750000000
#define MIN_FREQ 100
#define MIN_CENTER_FREQ 300000
#define MAX_POW_DBM 30
#define MIN_POW_DBM -145
#define MIN_POW_V 12.57/pow(10,9)
#define MAX_POW_V 7.071
#define MIN_SRATE 50
#define MAX_SRATE 300000000

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

class RnSSCPI
{
    public:


    private:
        QString response_From_Device;

        // Стандартные конфигурации устройства и их сокращенные названия для команд
        QString standard_sheet[25][2] = {{"PHASE1 C4FM", "APCOPH1C4"},
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
                                         {"USER", "USER"}};

        // Типы модуляции и их сокращенные названия для команд
        QString mod_type_sheet[35][2] = {{"ASK", "ASK"},
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
                                         {"USER", "USER"}};

        QString trigger_for_sweeps_values[6] = {"AUTO", "IMMediate", "SINGle", "BUS", "EXTernal", "EAUTo"};
        QString sweep_freq_mode_values[3] = {"AUTO", "MANual", "STEP"};
        QString sweep_spacing_values[2] = {"LINear", "LOGarithmic"};
        QString sweep_shape_values[2] = {"SAWTooth", "TRIangle"};
        QString freq_mode_values[5] = {"CW", "FIXed", "SWEep", "LIST", "COMBined"};

    public:
        RnSSCPI();
        void ListenToDevice(QString answer);
        QString Get_Last_Response();                                                                                        // Последний запрос
        QString Send_Request_IDN();                                                                                         // Идентификация устройства
        QString Send_Request_Error();                                                                                       // Запрос стека ошибок
        QString Send_Request_Frequency(int sour_hw = 1);                                                                    // Запрос значения частоты
        QString Send_Request_FrequencyMode(int sour_hw = 1);                                                                // Запрос частотного режима для генерации выходного ВЧ-сигнала.
        QString Send_Request_Level(int sour_hw = 1);                                                                        // Запрос значение уровня
        QString Send_Request_PEP(int sour_hw = 1);                                                                          // Запрос значения PEP
        QString Send_Request_Standard(int sour_hw = 1);                                                                     // Запрос названия стандартного режима
        QString Send_Request_ModType(int sour_hw = 1);                                                                      // Запрос типа модуляции
        QString Send_Request_SymbolRate(int sour_hw = 1);                                                                   // Запрос скорости передачи символов
        QString Send_Request_TriggerForSweeps(int trig_hw = 1);                                                             // Запрос вида триггера для разверток
        QString Send_Request_SweepFreqMode(int sour_hw);                                                                    // Запрос циклического режима для развертки по частоте
        QString Send_Request_FreqSpan(int sour_hw = 1);                                                                     // Запрос диапазона частотной развертки
        QString Send_Request_FreqCenter(int sour_hw = 1);                                                                   // Запрос центральной частоты развертки
        QString Send_Request_FreqStart(int sour_hw = 1);                                                                    // Запрос начальной частоты развертки
        QString Send_Request_FreqStop(int sour_hw = 1);                                                                     // Запрос конечную частоту развертки
        QString Send_Request_SweepSpacing(int sour_hw = 1);                                                                 // Запрос режима расчета частотных интервалов
        QString Send_Request_SweepShape(int sour_hw = 1);                                                                   // Запрос установленной формы сигнала для последовательности развертки частоты
        QString Send_Request_SweepRetrace(int sour_hw = 1);                                                                 // Запрос активности изменения начальной частоты в ожидании следующего триггера
        QString Send_Request_SweepStepLinear(int sour_hw = 1);                                                              // Запрос ширины шага для линейной развертки
        QString Send_Request_SweepStepLogarithmic(int sour_hw = 1);                                                         // Запрос логарифмически определяемой ширины шага для развертки по частоте
        QString Send_Request_SweepPoints(int sour_hw = 1);                                                                  // Запрос количества шагов в пределах диапазона развертки
        QString Send_Request_SweepFreqDwell(int sour_hw = 1);                                                               // Запрос времени задержки для шага развертки по частоте
        QString Send_Request_SweepFreqRun(int sour_hw = 1);                                                                 // Запрос текущего состояния развертки
        void Response_Handling(QString answer);                                                                             // Обработчик ответов от устройства (удаление \n из строки)
        QString SetFrequency(QString value, int unit = 3, int sour_hw = 1);                                                 // Установка частоты через строку
        QString SetFrequency(double value, int unit = 3, int sour_hw = 1);                                                  // Установка частоты через число
        QString SetFrequencyMode(QVariant value, int sour_hw = 1);                                                          // Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
        QString SetPower(QString value, int unit = 0, int sour_hw = 1);                                                     // Установка значения мощности через строку
        QString SetPower(double value, int unit = 0, int sour_hw = 1);                                                      // Установка значения мощности через число
        QString SetLevel(QString value, int unit = 0, int sour_hw = 1);                                                     // Установка значения уровка через строку
        QString SetLevel(double value, int unit = 0, int sour_hw = 1);                                                      // Установка значения уровня через число
        QString SetAccordingToStandard(QString name_of_the_standard, int sour_hw = 1);                                      // Установка стандартных режимов по названию
        QString SetAccordingToStandard(int standard_number, int sour_hw = 1);                                               // Установка стандартных режимов по номеру
        QString SetModulationType(QString type, int sour_hw = 1);                                                           // Установка типа модуляции по названию
        QString SetModulationType(int num_type, int sour_hw = 1);                                                           // Установка типа модуляции по номеру
        QString SetSymbolRate(QString value, int unit = 3, int sour_hw = 1);                                                // Установка скорости передачи символов
        QString SetSymbolRate(double value, int unit = 3, int sour_hw = 1);                                                 // Установка скорости передачи символов
        QString SetBasebandState(bool value, int sour_hw = 1);                                                              // Метод активации Baseband
        QString Preset();                                                                                                   // Сброс настроек устройства
        QString SetTriggerForSweeps(QString value, int trig_hw = 1);                                                        // Выбор триггера для разверток
        QString SetSweepFreqMode(QString value, int sour_hw = 1);                                                           // Установка циклического режима для развертки по частоте
        QString SetFreqSpan(QString value, int unit = 3, int sour_hw = 1);                                                  // Установка диапазона частотной развертки через строку
        QString SetFreqSpan(double value, int unit = 3, int sour_hw = 1);                                                   // Установка диапазона частотной развертки через число
        QString SetFreqCenter(QString value, int unit = 3, int sour_hw = 1);                                                // Установка центральной частоты развертки через строку
        QString SetFreqCenter(double value, int unit = 3, int sour_hw = 1);                                                 // Установка центральной частоты развертки через число
        QString SetFreqStart(QString value, int unit = 3, int sour_hw = 1);                                                 // Установка начальной частоты развертки через строку
        QString SetFreqStart(double value, int unit = 3, int sour_hw = 1);                                                  // Установка начальной частоты развертки через число
        QString SetFreqStop(QString value, int unit = 3, int sour_hw = 1);                                                  // Установка конечной частоты развертки через строку
        QString SetFreqStop(double value, int unit = 3, int sour_hw = 1);                                                   // Установка конечной частоты развертки через число
        QString SetSweepSpacing(QString value, int sour_hw = 1);                                                            // Установка режима расчета частотных интервалов
        QString SetSweepShape(QString value, int sour_hw = 1);                                                              // Установка формы сигнала для последовательности развертки частоты
        QString SetSweepRetrace(bool value, int sour_hw = 1);                                                               // Активировать изменение начальной частоты в ожидании следующего триггера
        QString SetSweepResetAll(int sour_hw = 1);                                                                          // Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())
        QString SetSweepStepLinear(QString value, double freq_Start, double freq_Stop, int unit = 3, int sour_hw = 1);      // Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START) через строку
        QString SetSweepStepLinear(double value, double freq_Start, double freq_Stop, int unit = 3, int sour_hw = 1);       // Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START) через число
        QString SetSweepStepLogarithmic(QVariant value, int sour_hw = 1);                                                   // Установка логарифмически определяемой ширины шага для развертки по частоте (Задается в %(PCT))
        QString SetSweepPoints(QVariant value, int sour_hw = 1);                                                            // Установка количества шагов в пределах диапазона развертки
        QString SetSweepFreqDwell(QVariant value, QString unint = "s", int sour_hw = 1);                                    // Установка времени задержки для шага развертки по частоте
        QString SweepFreqExecute(int sour_hw = 1);                                                                          // Выполнение однократной развертки
};

#endif // RNSSCPI_H
