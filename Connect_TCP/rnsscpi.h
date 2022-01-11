#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <QString>
#include <QStringList>
#include <math.h>
#include <QRegExp>
#define MAX_FREQ 12750000000
#define MIN_FREQ 100
#define MAX_POW_DBM 30
#define MIN_POW_DBM -145
#define MIN_POW_V 12.57/pow(10,9)
#define MAX_POW_V 7.071

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
        QStringList standard_sheet = {"PHASE1 C4FM", "APCOPH1C4",
                                      "PHASE1 CQPSK", "APCOPH1CQ",
                                      "PHASE2 H-CPM", "APCOPH2HC",
                                      "PHASE2 H-DQPSK", "APCOPH2HDQ",
                                      "PHASE2 H-D8PSK WIDE", "APCOPH2HD8PSKW",
                                      "PHASE2 H-D8PSK NARROW", "APCOPH2HD8PSKN",
                                      "PHASE1 LSM", "APCOPH1L",
                                      "PHASE1 WCQPSK", "APCOPH1W",
                                      "BLUETOOTH", "BLU",
                                      "CDMA2000 FORWARD", "CFOR",
                                      "CDMA2000 REVERSE","CREV",
                                      "CW IN BASEBAND", "CWBP",
                                      "DECT", "DECT",
                                      "ETC", "ETC",
                                      "GSM", "GSM",
                                      "GSM EDGE", "GSME",
                                      "NADC", "NADC",
                                      "PDC", "PDC",
                                      "PHS", "PHS",
                                      "TD-SCDMA", "TDSC",
                                      "TETRA", "TETR",
                                      "TFTS", "TFTS",
                                      "WCDMA-3GPP", "W3GP",
                                      "WORLDSPACE", "WORL"
                                      "USER", "USER"};

        // Типы модуляции и их сокращенные названия для команд
        QStringList mod_type_sheet = {"ASK", "ASK",
                                      "BPSK", "BPSK",
                                      "QPSK", "QPSK",
                                      "QPSK 45 OFFSET", "QPSK45",
                                      "QPSK EDGE", "QEDG",
                                      "AQPSK", "AQPS",
                                      "OQPSK", "OQPS",
                                      "PI/4-QPSK", "P4QP",
                                      "PI/2-DBPSK", "P2DB",
                                      "PI/4-DQPSK", "P4DQ",
                                      "PI/8-D8PSK", "P8D8",
                                      "8PSK", "PSK8",
                                      "8PSK EDGE", "P8ED",
                                      "16QAM", "QAM16",
                                      "16QAM EDGE", "QAM16ED",
                                      "32QAM", "QAM32",
                                      "32QAM EDGE", "QAM32ED",
                                      "64QAM", "QAM64",
                                      "128QAM", "QAM128",
                                      "256QAM", "QAM256",
                                      "512QAM", "QAM512",
                                      "1024QAM", "QAM1024",
                                      "2048QAM", "QAM2048",
                                      "4096QAM", "QAM4096",
                                      "MSK", "MSK",
                                      "2FSK", "FSK2",
                                      "4FSK", "FSK4",
                                      "8FSK", "FSK8",
                                      "16FSK", "FSK16",
                                      "32FSK", "FSK32",
                                      "64FSK", "FSK64",
                                      "VARIABLE FSK", "FSKV",
                                      "16APSK", "APSK16",
                                      "32APSK", "APSK32",
                                      "USER", "USER"};


    public:
        RnSSCPI();
        void ListenToDevice(QString answer);
        QString Get_Last_Response();
        QString Send_Request_IDN();
        QString Send_Request_Error();
        QString Send_Request_Frequency();
        QString Send_Request_Level();
        QString Send_Request_PEP();
        void Response_Handling(QString answer);
        QString SetFrequency(QString value, int unit = 3, int sour_hw = 1);
        QString SetFrequency(double value, int unit = 3, int sour_hw = 1);
        QString SetPower(QString value, int unit = 0, int sour_hw = 1);
        QString SetPower(double value, int unit = 0, int sour_hw = 1);
        QString SetLevel(QString value, int unit = 0, int sour_hw = 1);
        QString SetLevel(double value, int unit = 0, int sour_hw = 1);
        QString SetAccordingToStandard(QString name_of_the_standard, int sour_hw = 1);
        QString SetAccordingToStandard(int standard_number, int sour_hw = 1);
        QString SetModulationType(QString type, int sour_hw = 1);
        QString SetModulationType(int num_type, int sour_hw = 1);
};

#endif // RNSSCPI_H
