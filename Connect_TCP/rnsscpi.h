#ifndef RNSSCPI_H
#define RNSSCPI_H
#include <QString>

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
        QString SetFrequency(QString value, QString unit, int sour_hw = 1);
        QString SetFrequency(double value, QString unit, int sour_hw = 1);
        QString SetPower(QString value, QString unit, int sour_hw = 1);
        QString SetPower(double value, QString unit, int sour_hw = 1);
        QString SetLevel(QString value, QString unit, int sour_hw = 1);
        QString SetLevel(double value, QString unit, int sour_hw = 1);

};

#endif // RNSSCPI_H
