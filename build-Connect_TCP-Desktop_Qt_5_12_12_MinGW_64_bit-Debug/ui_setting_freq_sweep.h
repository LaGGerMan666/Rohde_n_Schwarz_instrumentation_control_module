/********************************************************************************
** Form generated from reading UI file 'setting_freq_sweep.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_FREQ_SWEEP_H
#define UI_SETTING_FREQ_SWEEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Setting_Freq_Sweep
{
public:
    QPushButton *pb_StartFreqSweep;
    QLineEdit *le_StartFreq;
    QLabel *label;
    QComboBox *cb_UninsStartFreq;
    QLabel *label_2;
    QLineEdit *le_StopFreq;
    QComboBox *cb_UnitsStopFreq;
    QComboBox *cb_TriggerSource;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *cb_SweepFreqMode;
    QLineEdit *le_SpanFreq;
    QLabel *label_5;
    QLineEdit *le_CenterFreq;
    QLabel *label_6;
    QComboBox *cb_UnitsRange;
    QComboBox *cb_UninsCenter;
    QLabel *label_7;
    QComboBox *cb_SweepSpacing;
    QLabel *label_8;
    QComboBox *cb_SweepShape;
    QLabel *label_9;
    QLineEdit *le_StepSweep;
    QComboBox *cb_UnitsLinStep;
    QLabel *label_10;
    QLineEdit *le_SweepPoints;
    QLabel *label_11;
    QLineEdit *le_SweepDwell;
    QComboBox *cb_UnitsSweepDwell;

    void setupUi(QDialog *Setting_Freq_Sweep)
    {
        if (Setting_Freq_Sweep->objectName().isEmpty())
            Setting_Freq_Sweep->setObjectName(QString::fromUtf8("Setting_Freq_Sweep"));
        Setting_Freq_Sweep->resize(402, 278);
        pb_StartFreqSweep = new QPushButton(Setting_Freq_Sweep);
        pb_StartFreqSweep->setObjectName(QString::fromUtf8("pb_StartFreqSweep"));
        pb_StartFreqSweep->setGeometry(QRect(210, 250, 181, 21));
        le_StartFreq = new QLineEdit(Setting_Freq_Sweep);
        le_StartFreq->setObjectName(QString::fromUtf8("le_StartFreq"));
        le_StartFreq->setGeometry(QRect(10, 120, 113, 21));
        le_StartFreq->setLayoutDirection(Qt::LeftToRight);
        le_StartFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(Setting_Freq_Sweep);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 111, 16));
        cb_UninsStartFreq = new QComboBox(Setting_Freq_Sweep);
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->setObjectName(QString::fromUtf8("cb_UninsStartFreq"));
        cb_UninsStartFreq->setGeometry(QRect(130, 120, 61, 22));
        label_2 = new QLabel(Setting_Freq_Sweep);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 101, 16));
        le_StopFreq = new QLineEdit(Setting_Freq_Sweep);
        le_StopFreq->setObjectName(QString::fromUtf8("le_StopFreq"));
        le_StopFreq->setGeometry(QRect(10, 170, 113, 21));
        le_StopFreq->setLayoutDirection(Qt::LeftToRight);
        le_StopFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UnitsStopFreq = new QComboBox(Setting_Freq_Sweep);
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->setObjectName(QString::fromUtf8("cb_UnitsStopFreq"));
        cb_UnitsStopFreq->setGeometry(QRect(130, 170, 61, 22));
        cb_TriggerSource = new QComboBox(Setting_Freq_Sweep);
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->setObjectName(QString::fromUtf8("cb_TriggerSource"));
        cb_TriggerSource->setGeometry(QRect(10, 20, 161, 22));
        label_3 = new QLabel(Setting_Freq_Sweep);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 151, 16));
        label_4 = new QLabel(Setting_Freq_Sweep);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 151, 16));
        cb_SweepFreqMode = new QComboBox(Setting_Freq_Sweep);
        cb_SweepFreqMode->addItem(QString());
        cb_SweepFreqMode->addItem(QString());
        cb_SweepFreqMode->addItem(QString());
        cb_SweepFreqMode->setObjectName(QString::fromUtf8("cb_SweepFreqMode"));
        cb_SweepFreqMode->setGeometry(QRect(10, 70, 161, 22));
        le_SpanFreq = new QLineEdit(Setting_Freq_Sweep);
        le_SpanFreq->setObjectName(QString::fromUtf8("le_SpanFreq"));
        le_SpanFreq->setGeometry(QRect(210, 120, 113, 21));
        le_SpanFreq->setLayoutDirection(Qt::LeftToRight);
        le_SpanFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(Setting_Freq_Sweep);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 100, 61, 16));
        le_CenterFreq = new QLineEdit(Setting_Freq_Sweep);
        le_CenterFreq->setObjectName(QString::fromUtf8("le_CenterFreq"));
        le_CenterFreq->setGeometry(QRect(210, 170, 113, 21));
        le_CenterFreq->setLayoutDirection(Qt::LeftToRight);
        le_CenterFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(Setting_Freq_Sweep);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 150, 47, 13));
        cb_UnitsRange = new QComboBox(Setting_Freq_Sweep);
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->setObjectName(QString::fromUtf8("cb_UnitsRange"));
        cb_UnitsRange->setGeometry(QRect(330, 120, 61, 22));
        cb_UninsCenter = new QComboBox(Setting_Freq_Sweep);
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->setObjectName(QString::fromUtf8("cb_UninsCenter"));
        cb_UninsCenter->setGeometry(QRect(330, 170, 61, 22));
        label_7 = new QLabel(Setting_Freq_Sweep);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 0, 201, 16));
        cb_SweepSpacing = new QComboBox(Setting_Freq_Sweep);
        cb_SweepSpacing->addItem(QString());
        cb_SweepSpacing->addItem(QString());
        cb_SweepSpacing->setObjectName(QString::fromUtf8("cb_SweepSpacing"));
        cb_SweepSpacing->setGeometry(QRect(190, 20, 201, 22));
        label_8 = new QLabel(Setting_Freq_Sweep);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 50, 81, 16));
        cb_SweepShape = new QComboBox(Setting_Freq_Sweep);
        cb_SweepShape->addItem(QString());
        cb_SweepShape->addItem(QString());
        cb_SweepShape->setObjectName(QString::fromUtf8("cb_SweepShape"));
        cb_SweepShape->setGeometry(QRect(190, 70, 201, 22));
        label_9 = new QLabel(Setting_Freq_Sweep);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 200, 81, 16));
        le_StepSweep = new QLineEdit(Setting_Freq_Sweep);
        le_StepSweep->setObjectName(QString::fromUtf8("le_StepSweep"));
        le_StepSweep->setGeometry(QRect(10, 220, 81, 21));
        le_StepSweep->setLayoutDirection(Qt::LeftToRight);
        le_StepSweep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UnitsLinStep = new QComboBox(Setting_Freq_Sweep);
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->setObjectName(QString::fromUtf8("cb_UnitsLinStep"));
        cb_UnitsLinStep->setGeometry(QRect(100, 220, 61, 22));
        label_10 = new QLabel(Setting_Freq_Sweep);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 200, 101, 16));
        le_SweepPoints = new QLineEdit(Setting_Freq_Sweep);
        le_SweepPoints->setObjectName(QString::fromUtf8("le_SweepPoints"));
        le_SweepPoints->setGeometry(QRect(170, 220, 101, 21));
        le_SweepPoints->setLayoutDirection(Qt::LeftToRight);
        le_SweepPoints->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(Setting_Freq_Sweep);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(280, 200, 91, 16));
        le_SweepDwell = new QLineEdit(Setting_Freq_Sweep);
        le_SweepDwell->setObjectName(QString::fromUtf8("le_SweepDwell"));
        le_SweepDwell->setGeometry(QRect(280, 220, 51, 21));
        le_SweepDwell->setLayoutDirection(Qt::LeftToRight);
        le_SweepDwell->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UnitsSweepDwell = new QComboBox(Setting_Freq_Sweep);
        cb_UnitsSweepDwell->addItem(QString());
        cb_UnitsSweepDwell->addItem(QString());
        cb_UnitsSweepDwell->addItem(QString());
        cb_UnitsSweepDwell->setObjectName(QString::fromUtf8("cb_UnitsSweepDwell"));
        cb_UnitsSweepDwell->setGeometry(QRect(340, 220, 51, 22));

        retranslateUi(Setting_Freq_Sweep);

        QMetaObject::connectSlotsByName(Setting_Freq_Sweep);
    } // setupUi

    void retranslateUi(QDialog *Setting_Freq_Sweep)
    {
        Setting_Freq_Sweep->setWindowTitle(QApplication::translate("Setting_Freq_Sweep", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270 \320\277\320\276 \321\207\320\260\321\201\321\202\320\276\321\202\320\265", nullptr));
        pb_StartFreqSweep->setText(QApplication::translate("Setting_Freq_Sweep", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        label->setText(QApplication::translate("Setting_Freq_Sweep", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\207\320\260\321\201\321\202\320\276\321\202\320\260:", nullptr));
        cb_UninsStartFreq->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "GHz", nullptr));
        cb_UninsStartFreq->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "MHz", nullptr));
        cb_UninsStartFreq->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "kHz", nullptr));
        cb_UninsStartFreq->setItemText(3, QApplication::translate("Setting_Freq_Sweep", "Hz", nullptr));

        label_2->setText(QApplication::translate("Setting_Freq_Sweep", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\207\320\260\321\201\321\202\320\276\321\202\320\260:", nullptr));
        cb_UnitsStopFreq->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "GHz", nullptr));
        cb_UnitsStopFreq->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "MHz", nullptr));
        cb_UnitsStopFreq->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "kHz", nullptr));
        cb_UnitsStopFreq->setItemText(3, QApplication::translate("Setting_Freq_Sweep", "Hz", nullptr));

        cb_TriggerSource->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "Auto", nullptr));
        cb_TriggerSource->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "Immediate", nullptr));
        cb_TriggerSource->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "Single", nullptr));
        cb_TriggerSource->setItemText(3, QApplication::translate("Setting_Freq_Sweep", "Bus", nullptr));
        cb_TriggerSource->setItemText(4, QApplication::translate("Setting_Freq_Sweep", "External", nullptr));
        cb_TriggerSource->setItemText(5, QApplication::translate("Setting_Freq_Sweep", "Eauto", nullptr));

        label_3->setText(QApplication::translate("Setting_Freq_Sweep", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \320\267\320\260\320\277\321\203\321\201\320\272\320\260 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270:", nullptr));
        label_4->setText(QApplication::translate("Setting_Freq_Sweep", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270 \320\277\320\276 \321\207\320\260\321\201\321\202\320\276\321\202\320\265:", nullptr));
        cb_SweepFreqMode->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "Auto", nullptr));
        cb_SweepFreqMode->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "Manual", nullptr));
        cb_SweepFreqMode->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "Step", nullptr));

        label_5->setText(QApplication::translate("Setting_Freq_Sweep", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275:", nullptr));
        label_6->setText(QApplication::translate("Setting_Freq_Sweep", "\320\246\320\265\320\275\321\202\321\200:", nullptr));
        cb_UnitsRange->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "GHz", nullptr));
        cb_UnitsRange->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "MHz", nullptr));
        cb_UnitsRange->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "kHz", nullptr));
        cb_UnitsRange->setItemText(3, QApplication::translate("Setting_Freq_Sweep", "Hz", nullptr));

        cb_UninsCenter->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "GHz", nullptr));
        cb_UninsCenter->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "MHz", nullptr));
        cb_UninsCenter->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "kHz", nullptr));
        cb_UninsCenter->setItemText(3, QApplication::translate("Setting_Freq_Sweep", "Hz", nullptr));

        label_7->setText(QApplication::translate("Setting_Freq_Sweep", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\321\201\321\207\320\265\321\202\320\260 \321\207\320\260\321\201\321\202\320\276\321\202\320\275\321\213\321\205 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\276\320\262:", nullptr));
        cb_SweepSpacing->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "Linear", nullptr));
        cb_SweepSpacing->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "Logarithmic", nullptr));

        label_8->setText(QApplication::translate("Setting_Freq_Sweep", "\320\244\320\276\321\200\320\274\320\260 \321\201\320\270\320\263\320\275\320\260\320\273\320\260:", nullptr));
        cb_SweepShape->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "Sawtooth", nullptr));
        cb_SweepShape->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "Triangle", nullptr));

        label_9->setText(QApplication::translate("Setting_Freq_Sweep", "\320\250\320\260\320\263 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270:", nullptr));
        cb_UnitsLinStep->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "GHz", nullptr));
        cb_UnitsLinStep->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "MHz", nullptr));
        cb_UnitsLinStep->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "kHz", nullptr));
        cb_UnitsLinStep->setItemText(3, QApplication::translate("Setting_Freq_Sweep", "Hz", nullptr));

        label_10->setText(QApplication::translate("Setting_Freq_Sweep", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\210\320\260\320\263\320\276\320\262:", nullptr));
        label_11->setText(QApplication::translate("Setting_Freq_Sweep", "\320\222\321\200\320\265\320\274\321\217 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270:", nullptr));
        cb_UnitsSweepDwell->setItemText(0, QApplication::translate("Setting_Freq_Sweep", "s", nullptr));
        cb_UnitsSweepDwell->setItemText(1, QApplication::translate("Setting_Freq_Sweep", "ms", nullptr));
        cb_UnitsSweepDwell->setItemText(2, QApplication::translate("Setting_Freq_Sweep", "us", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Setting_Freq_Sweep: public Ui_Setting_Freq_Sweep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_FREQ_SWEEP_H
