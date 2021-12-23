#ifndef RNSSCPI_H
#define RNSSCPI_H

#include <QString>
#include <math.h>
#define MAX_FREQ 12750000000


// Это так, для себя. Не насмехайтесь(
namespace units {
    const QString GHz = "GHz";
    const QString MHz = "MHz";
    const QString kHz = "kHz";
    const QString Hz = "Hz";

    const QString dBM = "dBM";
    const QString dBUV = "dBUV";
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
        QString GetError();
        QString SetFrequency(QString value, QString unit = units::Hz, int sour_hw = 1);
        QString SetFrequency(double value, QString unit = units::Hz, int sour_hw = 1);
        QString SetPower(QString value, QString unit = units::dBM, int sour_hw = 1);
        QString SetPower(double value, QString unit = units::dBM, int sour_hw = 1);
        QString SetLevel(QString value, QString unit = units::dBM, int sour_hw = 1);
        QString SetLevel(double value, QString unit = units::dBM, int sour_hw = 1);
};

#endif // RNSSCPI_H
