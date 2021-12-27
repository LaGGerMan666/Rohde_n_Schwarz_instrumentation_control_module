#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <QString>
#include <math.h>
#include <QRegExp>
#define MAX_FREQ 12750000000
#define MIN_FREQ 100
#define MAX_POW_DBM 30
#define MIN_POW_DBM -145
#define MIN_POW_V 12.57/pow(10,9)
#define MAX_POW_V 7.071


// Это так, для себя. Не насмехайтесь(
namespace units {
    const QString GHz = "GHz";
    const QString MHz = "MHz";
    const QString kHz = "kHz";
    const QString Hz = "Hz";

    const QString dBM = "dBM";
    const QString dBUV = "dBUV";
    const QString V = "V";
    const QString mV = "mV";
    const QString uV = "uV";
    const QString nV = "V";
}

class RnSSCPI
{
    public:


    private:
        bool isError;
        QString response_From_Device;

    public:
        RnSSCPI();
        void ListenToDevice(QString answer);
        QString Get_Last_Response();
        QString Send_Request_Error();
        void Response_Handling(QString answer);
        QString SetFrequency(QString value, QString unit = units::Hz, int sour_hw = 1);
        QString SetFrequency(double value, QString unit = units::Hz, int sour_hw = 1);
        QString SetPower(QString value, QString unit = units::dBM, int sour_hw = 1);
        QString SetPower(double value, QString unit = units::dBM, int sour_hw = 1);
        QString SetLevel(QString value, QString unit = units::dBM, int sour_hw = 1);
        QString SetLevel(double value, QString unit = units::dBM, int sour_hw = 1);
};

#endif // RNSSCPI_H
