#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <string>
#include <math.h>
#include <regex>
#include <array>

/**
 * @def MAX_FREQ
 * @brief Максимальное значение частоты.
 */
#define MAX_FREQ 12.75 * pow(10,9)

/**
 * @def MIN_FREQ
 * @brief Минимальное значение частоты.
 */
#define MIN_FREQ 100 * pow(10,3)

/**
 * @def MIN_CENTER_FREQ
 * @brief Минимальное значение центральной частоты.
 */
#define MIN_CENTER_FREQ 300000

/**
 * @def MAX_POW_DBM
 * @brief Максимальное значение мощности, имеряемое в dBm.
 */
#define MAX_POW_DBM 30

/**
 * @def MIN_POW_DBM
 * @brief Минимальное значение мощности, имеряемое в dBm.
 */
#define MIN_POW_DBM -145

/**
 * @def MIN_POW_V
 * @brief Минимальное значение мощности, измеряемое в V.
 */
#define MIN_POW_V 12.57/pow(10,9)

/**
 * @def MAX_POW_V
 * @brief Максимальное значение мощности, измеряемое в V.
 */
#define MAX_POW_V 7.071

/**
 * @def MIN_SRATE
 * @brief Минимальное значение символьной скорости.
 */
#define MIN_SRATE 50

/**
 * @def MAX_SRATE
 * @brief Максимальное значение символьной скорости.
 */
#define MAX_SRATE 300000000

using namespace std;

/**
 * @brief Класс, содержащий методы управления аппаратурой Rohde&Schwarz.
 */
class RnSSCPI
{
    public:
        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки стандартных настроек APCO.
         * @static
         */
        static array<string, 8> standard_sheet_apco;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки стандартных настроек.
         * @static
         */
        static array<string, 16> standard_sheet;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки типа модуляции PSK.
         * @static
         */
        static array<string, 12> mod_type_sheet_PSK;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки типа модуляции QAM.
         * @static
         */
        static array<string, 11> mod_type_sheet_QAM;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки типа модуляции FSK.
         * @static
         */
        static array<string, 8> mod_type_sheet_FSK;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки типа модуляции APSK.
         * @static
         */
        static array<string, 2> mod_type_sheet_APSK;

        //  Массивы команд для частотной развертки
        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки триггера частотной развертки.
         * @static
         */
        static array<string, 6> trigger_for_sweeps_values;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки режима частотной развертки.
         * @static
         */
        static array<string, 3> sweep_freq_mode_values;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки режима шага частотной развертки.
         * @static
         */
        static array<string, 2> sweep_spacing_values;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки типа сигнала частотной развертки.
         * @static
         */
        static array<string, 2> sweep_shape_values;

        /**
         * @brief Статический массив, содержащий сокращенные названия для команд установки частотного режима.
         * @static
         */
        static array<string, 5> freq_mode_values;

        /**
         * @brief Перечисление единиц измерения частоты.
         */
        enum unitsFreq {
            eGHz,
            eMHz,
            ekHz,
            eHZ
        };

        /**
         * @brief Перечисление единиц измерения мощности и уровня.
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
         * @brief Перечисление единиц измерения времени.
         */
        enum unitsTime{
            s,
            ms,
            us
        };

        /**
         * @brief Перечисление возможных ошибок.
         */
        enum errors{
            No_error,
            Value_out_of_range,
            Wrong_unit_of_measure,
            Invalid_type_number,
            Element_not_found
        };

    public:
        /**
         * @brief конструктор класса RnSSCPI.
         * @class
         */
        RnSSCPI();

        /**
         * @brief Сброс настроек устройства к предустановленным.
         * @param request_buffer  - ссылка на переменную, которая будет хранить сформированную команду.
         * @static
         */
        static void Preset(string &request_buffer) noexcept;
        /*--------------------------------- Поиск параметров -----------------------------------*/
        /**
         * @brief Поиск значения стандартной настройки APSO по номеру в массиве {@link standard_sheet_apco}.
         * @param device_response - ответ от устройства после запроса текущей стандарной настройки {@link request_Standard}.
         * @param number_standard - возвразаемый номер найденного элемента массива {@link standard_sheet_apco}.
         * @return Eсли элемент найден метод возваращает No_error из {@link errors}, в противном случае Element_not_found из {@link errors}.
         * @static
         */
        static int search_StandardAPCO(string &device_response, int &number_standard);

        /**
         * @brief Поиск значения стандартной настройки по номеру в массиве {@link standard_sheet}.
         * @param device_response - ответ от устройства после запроса текущей стандарной настройки {@link request_Standard}.
         * @param number_standard возвразаемый номер найденного элемента массива {@link standard_sheet}.
         * @return Eсли элемент найден метод возваращает No_error из {@link errors}, в противном случае Element_not_found из {@link errors}.
         * @static
         */
        static int search_Standard(string &device_response, int &number_standard);

        /**
         * @brief Поиск значения типа модуляции PSK по номеру в массиве {@link mod_type_sheet_PSK}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_PSK}.
         * @return Eсли элемент найден метод возваращает No_error из {@link errors}, в противном случае Element_not_found из {@link errors}.
         * @static
         */
        static int search_ModPSK(string &device_response, int &number_mod);

        /**
         * @brief Поиск значения типа модуляции QAM по номеру в массиве {@link mod_type_sheet_QAM}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_QAM}.
         * @return Eсли элемент найден метод возваращает No_error из {@link errors}, в противном случае Element_not_found из {@link errors}.
         * @static
         */
        static int search_ModQAM(string &device_response, int &number_mod);

        /**
         * @brief Поиск значения типа модуляции FSK по номеру в массиве {@link mod_type_sheet_FSK}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_FSK}.
         * @return Eсли элемент найден метод возваращает No_error из {@link errors}, в противном случае Element_not_found из {@link errors}.
         * @static
         */
        static int search_ModFSK(string &device_response, int &number_mod);

        /**
         * @brief Поиск значения типа модуляции APSK по номеру в массиве {@link mod_type_sheet_APSK}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_APSK}.
         * @return Eсли элемент найден метод возваращает No_error из {@link errors}, в противном случае Element_not_found из {@link errors}.
         * @static
         */
        static int search_Mod_APSK(string &device_response, int &number_mod);
        /*------------------------------------------------------------------------------------------------------*/

        /*------------------------------------------ Основные запросы ------------------------------------------*/
        /**
         * @brief Идентификация устройства.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @static
         */
        static void request_IDN(string &request_buffer) noexcept;

        /**
         * @brief Запрос последней ошибки из стека.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @static
         */
        static void request_LastError(string &request_buffer) noexcept;

        /**
         * @brief Запрос значения частоты.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_Frequency(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос значение уровня.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_Level(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос значения PEP
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_PEP(string &request_buffer, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*--------------------------------------- Запросы модуляции --------------------------------------------*/
        /**
         * @brief Запрос названия стандартного режима.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_Standard(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос типа модуляции.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_ModType(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос скорости передачи символов.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SymbolRate(string &request_buffer, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*--------------------------------- Запросы для частотной развертки ------------------------------------*/
        /**
         * @brief Запрос режима триггера для разверток.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param trig_hw - номер триггера (по умолчанию 1).
         * @static
         */
        static void request_TriggerForSweeps(string &request_buffer, int trig_hw = 1);

        /**
         * @brief Запрос режима для развертки по частоте.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepFreqMod(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос диапазона частотной развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_FreqSpan(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос центральной частоты развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_FreqCenter(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос начальной частоты развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_FreqStart(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос конечной частоты развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_FreqStop(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос режима расчета частотных интервалов.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepSpacing(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос установленной формы сигнала для последовательности развертки частоты.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepShape(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос активности изменения начальной частоты в ожидании следующего триггера.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepRetrace(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос ширины шага для линейной развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepStepLinear(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос логарифмически определяемой ширины шага для развертки по частоте.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepStepLog(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос количества шагов в пределах диапазона развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepPoints(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос частотного режима для генерации выходного ВЧ-сигнала.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_FrequencyMode(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос времени задержки для шага развертки по частоте.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepFreqDwell(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос текущего состояния развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_SweepFreqRun(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Сброс всех активных разверток в начальную точку (альтернатива {@link set_SweepRetrace}).
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void sweepResetAll(string &request_buffer, int sour_hw = 1) noexcept;
        /*------------------------------------------------------------------------------------------------------*/

        /*----------------------------------------- Основные настройки -----------------------------------------*/
        // Установка частоты через число
        /**
         * @brief Метод, позволяющий установить частоту.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемой частоты.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой частоты {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_Frequency(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        // Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
        /**
         * @brief Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - номер режима, соответствующий возможным номерам из массива {@link freq_mode_values}
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_FrequencyMode(string &request_buffer, int value, int &err, int sour_hw = 1);

        /**
         * @brief Метод, позволяющий установить мощность.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемой мощности.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой мощности {@link unitsPower} (по умолчанию 0).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_Power(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1) ;

        /**
         * @brief Метод, позволяющий установить уровень.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемого уровня.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемого уровня {@link unitsPower} (по умолчанию 0).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_Level(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1);

        /**
         * @brief Метод активации Baseband.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - переменная для активации/деактивации Baseband.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_BasebandState(string &request_buffer, bool value, int sour_hw = 1) noexcept;
        /*------------------------------------------------------------------------------------------------------*/

        /*-------------------------------------- Настройки модуляции -------------------------------------------*/
        /**
         * @brief Установка стандартных режимов.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param standard_number - номер стандартного режима, соответствующий номеру массива {@link standard_sheet} или {@link standard_sheet_apco}.
         * @param isAPCO - переменая, которая определяет относится ли устанавливаемый номер стандартного режима к подгруппе режимов APCO {@link standard_sheet_apco}.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_AccordingToStandard(string &request_buffer, int standard_number, bool isAPCO, int &err, int sour_hw = 1);

        /**
         * @brief Установка типа модуляции.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param num_type - переменная, хранящая значение типа устанавливаемой модуляции (PSK, QAM, FSK, APSK).
         * @param num_subtype - переменная, хранящая значение подтипа устанавливаемой модуляции который должен относиться к одному из массивов:
         * {@link mod_type_sheet_PSK}, {@link mod_type_sheet_QAM}, {@link mod_type_sheet_FSK}, {@link mod_type_sheet_APSK},
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_ModulationType(string &request_buffer, int num_type, int num_subtype, int &err, int sour_hw = 1);

        /**
         * @brief Установка скорости передачи символов. Задавать необходимо в единицах измерения Hz(sym/s можно не указывать), kHz(kSym/s), MHz(MSym/s).
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемой скорости передачи символов.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой скорости {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SymbolRate(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*----------------------------------- Настройки частотной развертки ------------------------------------*/
        /**
         * @brief Установка режима триггера для разверток.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - номер режима, соответствующий номеру из массива режимов триггера для разверток {@link trigger_for_sweeps_values}.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param trig_hw - номер триггера (по умолчанию 1).
         */
        static void set_TriggerForSweeps(string &request_buffer, int value, int &err, int trig_hw = 1);

        /**
         * @brief Установка циклического режима для развертки по частоте.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - номер режима, соответствующий номеру из массива режимов развертки по частоте {@link sweep_freq_mode_values}.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepFreqMode(string &request_buffer, int value, int &err, int sour_hw = 1);

        /**
         * @brief Установка диапазона частотной развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемого диапазона.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемого диапазона частотной развертки {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_FreqSpan(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        /**
         * @brief Установка центральной частоты развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемой центральной частоты.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой центральной частоты {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_FreqCenter(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        /**
         * @brief Установка начальной частоты развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемой начальной частоты развертки.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой начальной частоты развертки {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_FreqStart(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        /**
         * @brief Установка конечной частоты развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение устанавливаемой конечной частоты развертки.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой конечной частоты развертки {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_FreqStop(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        /*-------------- Установка диапазона чатот развертки -------------------------*/
        /**
         * @brief Установка начальной и конечной частот одновременно с учетом граничных значений.
         * @param start_freq_buffer - ссылка на переменную, которая будет хранить сформированную команду установки начальной частоты.
         * @param stop_freq_buffer - ссылка на переменную, которая будет хранить сформированную команду установки конечной частоты.
         * @param start_freq - значение начальной частоты.
         * @param stop_freq - значение конечной частоты.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемых конечной и начальной частот развертки {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_freqSweepRange(string &start_freq_buffer, string &stop_freq_buffer, double start_freq, double stop_freq, int &err, int unit = 3, int sour_hw = 1);
        /*----------------------------------------------------------------------------*/

        /**
         * @brief Установка режима расчета частотных интервалов.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - номер режима, соответствующий номеру из массива режимов расчета частотных интервалов {@link sweep_spacing_values}.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepSpacing(string &request_buffer, int value, int &err, int sour_hw = 1);

        /**
         * @brief Установка формы сигнала для развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - номер режима, соответствующий номеру из массива форм сигналов {@link sweep_shape_values}.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepShape(string &request_buffer, int value, int &err, int sour_hw = 1);

        /**
         * @brief Активировация/деактивация изменения начальной частоты в ожидании следующего триггера
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - переменная активации/деактивации изменения начальной частоты.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepRetrace(string &request_buffer, bool value, int sour_hw = 1) noexcept;

        /**
         * @brief Установка линейно определяемой ширины шага для развертки по частоте (значения от 0.01Гц до значения STOP - START).
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение ширины шага для линейного режима.
         * @param freq_start - ответ от устройства после запроса текущего значения начальной частоты {@link request_FreqStart}.
         * @param freq_stop - ответ от устройства после запроса текущего значения конечной частоты {@link request_FreqStop}.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой ширины шага для линейно развертки {@link unitsFreq} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepStepLinear(string &request_buffer, double value, double freq_start, double freq_stop, int &err, int unit = 3, int sour_hw = 1);

        /**
         * @brief Установка логарифмически определяемой ширины шага для развертки по частоте.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение ширины шага для логарифмического режима (Задается в %(PCT)).
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepStepLogarithmic(string &request_buffer, double value, int &err, int sour_hw = 1);

        /**
         * @brief Установка количества шагов в пределах диапазона развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение количества шагов.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepPoints(string &request_buffer, int value, int &err, int sour_hw = 1);

        /**
         * @brief Установка времени задержки для шага развертки по частоте.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param value - значение задержки шага.
         * @param err - ссылка на переменную, которая будет храненить номер ошибки {@link errors}.
         * @param unit - значение единицы измерения устанавливаемой задержки шага {@link unitsTime} (по умолчанию 3).
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void set_SweepFreqDwell(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1);

        /**
         * @brief Запуск развертки.
         * @param request_buffer - ссылка на переменную, которая будет хранить сформированную команду.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void sweepFreqExecute(string &request_buffer, int sour_hw = 1) noexcept;
        /*------------------------------------------------------------------------------------------------------*/
};

#endif // RNSSCPI_H
