#ifndef RNSSCPI_H
#define RNSSCPI_H
#include <QString>

namespace units {
    const QString GHz = "GHz";
    const QString MHz = "MHz";
    const QString kHz = "kHz";
    const QString Hz = "Hz";
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
        QString SetFrequency(QString value, QString unit);
        QString SetFrequency(double value, QString unit);
        QString SetPower(QString value, QString unit);
        QString SetPower(double value, QString unit);
        QString SetLevel(QString value, QString unit);
        QString SetLevel(double value, QString unit);
};

#endif // RNSSCPI_H
