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
         * {No_error}
         */
        enum error{
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
         * @param request_buffer  - ссылка на переменную для хранения сформированной команды.
         * @static
         */
        static void Preset(string &request_buffer) noexcept;
        /*--------------------------------- Поиск параметров -----------------------------------*/
        /**
         * @brief Поиск значения стандартной настройки APSO по номеру в массиве {@link standard_sheet_apco}.
         * @param device_response - ответ от устройства после запроса текущей стандарной настройки.
         * @param number_standard - возвразаемый номер найденного элемента массива {@link standard_sheet_apco}.
         * @return Eсли элемент найден метод возваращает {@link No_error}, в противном случае {@link Element_not_found}.
         * @static
         */
        static int search_StandardAPCO(string &device_response, int &number_standard);

        /**
         * @brief Поиск значения стандартной настройки по номеру в массиве {@link standard_sheet}.
         * @param device_response - ответ от устройства после запроса текущей стандарной настройки.
         * @param number_standard возвразаемый номер найденного элемента массива {@link standard_sheet}.
         * @return Eсли элемент найден метод возваращает {@link No_error}, в противном случае {@link Element_not_found}.
         * @static
         */
        static int search_Standard(string &device_response, int &number_standard);

        /**
         * @brief Поиск значения типа модуляции PSK по номеру в массиве {@link mod_type_sheet_PSK}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_PSK}.
         * @return Eсли элемент найден метод возваращает {@link No_error}, в противном случае {@link Element_not_found}.
         * @static
         */
        static int search_ModPSK(string &device_response, int &number_mod);

        /**
         * @brief Поиск значения типа модуляции QAM по номеру в массиве {@link mod_type_sheet_QAM}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_QAM}.
         * @return Eсли элемент найден метод возваращает {@link No_error}, в противном случае {@link Element_not_found}.
         * @static
         */
        static int search_ModQAM(string &device_response, int &number_mod);

        /**
         * @brief Поиск значения типа модуляции FSK по номеру в массиве {@link mod_type_sheet_FSK}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_FSK}.
         * @return Eсли элемент найден метод возваращает {@link No_error}, в противном случае {@link Element_not_found}.
         * @static
         */
        static int search_ModFSK(string &device_response, int &number_mod);

        /**
         * @brief Поиск значения типа модуляции APSK по номеру в массиве {@link mod_type_sheet_APSK}.
         * @param device_response - ответ от устройства после запроса типа модуляции {@link request_ModType}.
         * @param number_mod - возвразаемый номер найденного элемента массива {@link mod_type_sheet_APSK}.
         * @return Eсли элемент найден метод возваращает {@link No_error}, в противном случае {@link Element_not_found}.
         * @static
         */
        static int search_Mod_APSK(string &device_response, int &number_mod);
        /*------------------------------------------------------------------------------------------------------*/

        /*------------------------------------------ Основные запросы ------------------------------------------*/
        /**
         * @brief Идентификация устройства.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @static
         */
        static void request_IDN(string &request_buffer) noexcept;

        /**
         * @brief Запрос последней ошибки из стека.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @static
         */
        static void request_LastError(string &request_buffer) noexcept;

        /**
         * @brief Запрос значения частотыю.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_Frequency(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос значение уровня.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_Level(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос значения PEP
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         * @static
         */
        static void request_PEP(string &request_buffer, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*--------------------------------------- Запросы модуляции --------------------------------------------*/
        /**
         * @brief Запрос названия стандартного режима.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_Standard(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос типа модуляции.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_ModType(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос скорости передачи символов.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SymbolRate(string &request_buffer, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*--------------------------------- Запросы для частотной развертки ------------------------------------*/
        /**
         * @brief Запрос режима триггера для разверток
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param trig_hw - номер триггера (по умолчанию 1).
         */
        static void request_TriggerForSweeps(string &request_buffer, int trig_hw = 1);

        /**
         * @brief Запрос режима для развертки по частоте
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepFreqMod(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос диапазона частотной развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_FreqSpan(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос центральной частоты развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_FreqCenter(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос начальной частоты развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_FreqStart(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос конечную частоту развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_FreqStop(string &request_buffer, int sour_hw = 1);

        // Запрос режима расчета частотных интервалов
        /**
         * @brief Запрос режима расчета частотных интервалов
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepSpacing(string &request_buffer, int sour_hw = 1);

        // Запрос установленной формы сигнала для последовательности развертки частоты
        /**
         * @brief Запрос установленной формы сигнала для последовательности развертки частоты
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepShape(string &request_buffer, int sour_hw = 1);

        // Запрос активности изменения начальной частоты в ожидании следующего триггера
        /**
         * @brief Запрос активности изменения начальной частоты в ожидании следующего триггера
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepRetrace(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос ширины шага для линейной развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepStepLinear(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос логарифмически определяемой ширины шага для развертки по частоте
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepStepLog(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос количества шагов в пределах диапазона развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepPoints(string &request_buffer, int sour_hw = 1);

        /**
         * @brief Запрос частотного режима для генерации выходного ВЧ-сигнала.
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_FrequencyMode(string &request_buffer, int sour_hw = 1);

        // Запрос времени задержки для шага развертки по частоте
        /**
         * @brief Запрос времени задержки для шага развертки по частоте
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepFreqDwell(string &request_buffer, int sour_hw = 1);

        // Запрос текущего состояния развертки
        /**
         * @brief Запрос текущего состояния развертки
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void request_SweepFreqRun(string &request_buffer, int sour_hw = 1);

        // Сброс всех активных разверток в начальную точку (альтернатива SetSweepRetrace())
        /**
         * @brief Сброс всех активных разверток в начальную точку (альтернатива {@link set_SweepRetrace})
         * @param request_buffer - ссылка на переменную для хранения сформированной команды.
         * @param sour_hw - номер источника (по умолчанию 1).
         */
        static void sweepResetAll(string &request_buffer, int sour_hw = 1) noexcept;
        /*------------------------------------------------------------------------------------------------------*/

        /*----------------------------------------- Основные настройки -----------------------------------------*/
        // Установка частоты через число
        static void set_Frequency(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        // Устанавливает частотный режим для генерации выходного ВЧ-сигнала.
        static void set_FrequencyMode(string &request_buffer, int value, int &err, int sour_hw = 1);

        // Установка мощности
        static void set_Power(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1) ;

        // Установка уровня
        static void set_Level(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1);

        // Метод активации Baseband
        static void set_BasebandState(string &request_buffer, bool value, int sour_hw = 1) noexcept;
        /*------------------------------------------------------------------------------------------------------*/

        /*-------------------------------------- Настройки модуляции -------------------------------------------*/
        // Установка стандартных режимов
        static void set_AccordingToStandard(string &request_buffer, int standard_number, bool isAPCO, int &err, int sour_hw = 1);

        // Установка типа модуляции
        static void set_ModulationType(string &request_buffer, int num_type, int num_subtype, int &err, int sour_hw = 1);

        // Установка скорости передачи символов
        static void set_SymbolRate(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*----------------------------------- Настройки частотной развертки ------------------------------------*/
        // Выбор триггера для разверток
        static void set_TriggerForSweeps(string &request_buffer, int value, int &err, int trig_hw = 1);

        // Установка циклического режима для развертки по частоте
        static void set_SweepFreqMode(string &request_buffer, int value, int &err, int sour_hw = 1);

        // Установка диапазона частотной развертки
        static void set_FreqSpan(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        // Установка центральной частоты развертки
        static void set_FreqCenter(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        // Установка начальной частоты развертки
        static void set_FreqStart(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);

        // Установка конечной частоты развертки
        static void set_FreqStop(string &request_buffer, double value, int &err, int unit = 3, int sour_hw = 1);
        /*------------------------------------------------------------------------------------------------------*/

        /*-------------- Установка диапазона чатот развертки -------------------------*/
        static void set_freqSweepRange(string &start_freq_buffer, string &stop_freq_buffer, double start_freq, double stop_freq, int &err, int unit = 3, int sour_hw = 1);
        /*----------------------------------------------------------------------------*/

        // Установка режима расчета частотных интервалов
        static void set_SweepSpacing(string &request_buffer, int value, int &err, int sour_hw = 1);

        // Установка формы сигнала для последовательности развертки частоты
        static void set_SweepShape(string &request_buffer, int value, int &err, int sour_hw = 1);

        // Активировать изменение начальной частоты в ожидании следующего триггера
        static void set_SweepRetrace(string &request_buffer, bool value, int sour_hw = 1) noexcept;                                  

        // Установка ширины шага для линейной развертки (значения от 0.01Гц до значения STOP - START)
        static void set_SweepStepLinear(string &request_buffer, double value, double freq_start, double freq_stop, int &err, int unit = 3, int sour_hw = 1);

        // Установка логарифмически определяемой ширины шага для развертки по частоте (Задается в %(PCT))
        static void set_SweepStepLogarithmic(string &request_buffer, double value, int &err, int sour_hw = 1);

        // Установка количества шагов в пределах диапазона развертки
        static void set_SweepPoints(string &request_buffer, int value, int &err, int sour_hw = 1);

        // Установка времени задержки для шага развертки по частоте
        static void set_SweepFreqDwell(string &request_buffer, double value, int &err, int unit = 0, int sour_hw = 1);

        // Выполнение однократной развертки
        static void sweepFreqExecute(string &request_buffer, int sour_hw = 1) noexcept;
        /*------------------------------------------------------------------------------------------------------*/
};

#endif // RNSSCPI_H
