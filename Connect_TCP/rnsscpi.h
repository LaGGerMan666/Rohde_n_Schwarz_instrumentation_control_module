#ifndef RNSSCPI_H
#define RNSSCPI_H
#include <QString>

class RnSSCPI
{



    private:
        bool isError;
        QString response_From_Device;


    public:
        RnSSCPI();
        void ListenToDevice(QString answer);
        QString SetFrequency(QString value, QString unit);
        QString SetFrequency(double value, QString unit);
};

#endif // RNSSCPI_H
