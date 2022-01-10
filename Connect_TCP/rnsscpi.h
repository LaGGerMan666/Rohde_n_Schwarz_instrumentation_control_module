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

Phase1 C4FM
Phase1 CQPSK
Phase2 H-CPM
Phase2 H-DQPSK
Phase2 H-D8PSK Wide
Phase2 H-D8PSK Narrow
Phase1 LSM
Phase1 WCQPSK
Bluetooth
CDMA2000 Forward
CDMA2000 Reverse
CW in Baseband
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
Worldspace

*/

class RnSSCPI
{
    public:


    private:
        QString response_From_Device;
        // Команды стандартов устройства
        QStringList standard_sheet = {"APCOPH1C4",
                                      "APCOPH1CQ",
                                      "APCOPH2HC",
                                      "APCOPH2HDQ",
                                      "APCOPH2HD8PSKW",
                                      "APCOPH2HD8PSKN",
                                      "APCOPH1L",
                                      "APCOPH1W",
                                      "BLU",
                                      "CFOR",
                                      "CREV",
                                      "CWBP",
                                      "DECT",
                                      "ETC",
                                      "GSM",
                                      "GSME",
                                      "NADC",
                                      "PDC",
                                      "PHS",
                                      "TDSC",
                                      "TETR",
                                      "TFTS",
                                      "W3GP",
                                      "WORL"};

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
};

#endif // RNSSCPI_H
