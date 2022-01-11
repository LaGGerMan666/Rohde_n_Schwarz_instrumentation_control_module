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

/* Названия стандартов устройства

PHASE1 C4FM
PHASE1 CQPSK
PHASE2 H-CPM
PHASE2 H-DQPSK
PHASE2 H-D8PSK WIDE
PHASE2 H-D8PSK NARROW
PHASE1 LSM
PHASE1 WCQPSK
BLUETOOTH
CDMA2000 FORWARD
CDMA2000 REVERSE
CW IN BASEBAND
DECT
ETC
GSM
GSM EDGE
NADC
PDC
PHS
TD-SCDMA
TETRA
TFTS
WCDMA-3GPP
WORLDSPACE

*/

class RnSSCPI
{
    public:


    private:
        QString response_From_Device;
        // Команды стандартов устройства

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
                                      "WORLDSPACE", "WORL"};


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
        QString Set_AccordingToStandard(QString name_of_the_standard, int sour_hw = 1);
        QString Set_AccordingToStandard(int standard_number, int sour_hw = 1);
};

#endif // RNSSCPI_H
