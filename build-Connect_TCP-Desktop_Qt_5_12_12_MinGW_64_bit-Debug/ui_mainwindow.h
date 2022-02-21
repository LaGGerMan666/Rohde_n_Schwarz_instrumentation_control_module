/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_FreqSweep;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QFrame *frame_Consol;
    QGridLayout *gridLayout_3;
    QPushButton *pb_Disconnect;
    QTextEdit *te_Log;
    QLineEdit *le_Command;
    QPushButton *pb_Send;
    QPushButton *pb_Connection;
    QFrame *frame_MainArea;
    QGridLayout *gridLayout_4;
    QFrame *frame_Frequency;
    QGridLayout *gridLayout;
    QLineEdit *le_Frequency;
    QComboBox *cb_FrequencyUnits;
    QLabel *label;
    QFrame *frame_PepLevel;
    QGridLayout *gridLayout_2;
    QLineEdit *le_PEP;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *le_Level;
    QComboBox *cb_LevelUnits;
    QComboBox *cb_PEPUnits_2;
    QLabel *label_2;
    QTabWidget *tw_Settings;
    QWidget *page_ModSet;
    QComboBox *cb_AccordingToStandard;
    QComboBox *cb_UnitsSymRate;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *le_SymbolRate;
    QComboBox *cb_ModType;
    QLabel *label_17;
    QListWidget *lw_AccordingToStandard;
    QListWidget *lw_ModType;
    QWidget *page_SweepSet;
    QLabel *label_11;
    QComboBox *cb_SweepShape;
    QComboBox *cb_TriggerSource;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *le_StepSweep;
    QComboBox *cb_SweepFreqMode;
    QComboBox *cb_UninsCenter;
    QLabel *label_7;
    QLineEdit *le_CenterFreq;
    QComboBox *cb_UnitsLinStep;
    QLabel *label_8;
    QLineEdit *le_SweepDwell;
    QComboBox *cb_UninsStartFreq;
    QLabel *label_10;
    QLineEdit *le_StopFreq;
    QLabel *label_5;
    QComboBox *cb_SweepSpacing;
    QLineEdit *le_SpanFreq;
    QComboBox *cb_UnitsRange;
    QLabel *label_9;
    QLabel *label_12;
    QComboBox *cb_UnitsSweepDwell;
    QLabel *label_13;
    QLineEdit *le_StartFreq;
    QComboBox *cb_UnitsStopFreq;
    QPushButton *pb_StartFreqSweep;
    QLineEdit *le_SweepPoints;
    QLabel *label_14;
    QPushButton *pb_StopFreqSweep;
    QPushButton *pb_ResetFreqSweep;
    QWidget *page_IqSet;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Setup;
    QMenu *menu_Reference;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(729, 592);
        MainWindow->setMinimumSize(QSize(729, 0));
        action_FreqSweep = new QAction(MainWindow);
        action_FreqSweep->setObjectName(QString::fromUtf8("action_FreqSweep"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(0);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_Consol = new QFrame(centralwidget);
        frame_Consol->setObjectName(QString::fromUtf8("frame_Consol"));
        frame_Consol->setMinimumSize(QSize(290, 550));
        frame_Consol->setMaximumSize(QSize(300, 16777215));
        frame_Consol->setFrameShape(QFrame::StyledPanel);
        frame_Consol->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_Consol);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setContentsMargins(4, -1, 4, 0);
        pb_Disconnect = new QPushButton(frame_Consol);
        pb_Disconnect->setObjectName(QString::fromUtf8("pb_Disconnect"));

        gridLayout_3->addWidget(pb_Disconnect, 3, 0, 1, 2);

        te_Log = new QTextEdit(frame_Consol);
        te_Log->setObjectName(QString::fromUtf8("te_Log"));

        gridLayout_3->addWidget(te_Log, 0, 0, 1, 2);

        le_Command = new QLineEdit(frame_Consol);
        le_Command->setObjectName(QString::fromUtf8("le_Command"));
        le_Command->setMaximumSize(QSize(16777215, 22));

        gridLayout_3->addWidget(le_Command, 1, 0, 1, 1);

        pb_Send = new QPushButton(frame_Consol);
        pb_Send->setObjectName(QString::fromUtf8("pb_Send"));
        pb_Send->setMaximumSize(QSize(16777215, 22));

        gridLayout_3->addWidget(pb_Send, 1, 1, 1, 1);

        pb_Connection = new QPushButton(frame_Consol);
        pb_Connection->setObjectName(QString::fromUtf8("pb_Connection"));

        gridLayout_3->addWidget(pb_Connection, 2, 0, 1, 2);


        gridLayout_5->addWidget(frame_Consol, 0, 0, 1, 1);

        frame_MainArea = new QFrame(centralwidget);
        frame_MainArea->setObjectName(QString::fromUtf8("frame_MainArea"));
        frame_MainArea->setFrameShape(QFrame::StyledPanel);
        frame_MainArea->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_MainArea);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(4, -1, 4, 0);
        frame_Frequency = new QFrame(frame_MainArea);
        frame_Frequency->setObjectName(QString::fromUtf8("frame_Frequency"));
        frame_Frequency->setMinimumSize(QSize(150, 0));
        frame_Frequency->setFrameShape(QFrame::StyledPanel);
        frame_Frequency->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_Frequency);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        le_Frequency = new QLineEdit(frame_Frequency);
        le_Frequency->setObjectName(QString::fromUtf8("le_Frequency"));
        le_Frequency->setMaximumSize(QSize(16777215, 16777215));
        le_Frequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(le_Frequency, 2, 0, 1, 1);

        cb_FrequencyUnits = new QComboBox(frame_Frequency);
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->setObjectName(QString::fromUtf8("cb_FrequencyUnits"));
        cb_FrequencyUnits->setMinimumSize(QSize(51, 0));
        cb_FrequencyUnits->setMaximumSize(QSize(51, 16777215));

        gridLayout->addWidget(cb_FrequencyUnits, 2, 1, 1, 1);

        label = new QLabel(frame_Frequency);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        gridLayout_4->addWidget(frame_Frequency, 0, 0, 1, 1);

        frame_PepLevel = new QFrame(frame_MainArea);
        frame_PepLevel->setObjectName(QString::fromUtf8("frame_PepLevel"));
        frame_PepLevel->setFrameShape(QFrame::StyledPanel);
        frame_PepLevel->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_PepLevel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        le_PEP = new QLineEdit(frame_PepLevel);
        le_PEP->setObjectName(QString::fromUtf8("le_PEP"));
        le_PEP->setMaximumSize(QSize(16777215, 16777215));
        le_PEP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(le_PEP, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        label_3 = new QLabel(frame_PepLevel);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        le_Level = new QLineEdit(frame_PepLevel);
        le_Level->setObjectName(QString::fromUtf8("le_Level"));
        le_Level->setMaximumSize(QSize(16777215, 16777215));
        le_Level->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(le_Level, 1, 3, 1, 1);

        cb_LevelUnits = new QComboBox(frame_PepLevel);
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->setObjectName(QString::fromUtf8("cb_LevelUnits"));
        cb_LevelUnits->setMinimumSize(QSize(51, 0));
        cb_LevelUnits->setMaximumSize(QSize(51, 16777215));

        gridLayout_2->addWidget(cb_LevelUnits, 1, 4, 1, 1);

        cb_PEPUnits_2 = new QComboBox(frame_PepLevel);
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->setObjectName(QString::fromUtf8("cb_PEPUnits_2"));
        cb_PEPUnits_2->setMinimumSize(QSize(51, 0));
        cb_PEPUnits_2->setMaximumSize(QSize(51, 16777215));

        gridLayout_2->addWidget(cb_PEPUnits_2, 1, 1, 1, 1);

        label_2 = new QLabel(frame_PepLevel);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_PepLevel, 0, 1, 1, 1);

        tw_Settings = new QTabWidget(frame_MainArea);
        tw_Settings->setObjectName(QString::fromUtf8("tw_Settings"));
        tw_Settings->setTabShape(QTabWidget::Rounded);
        page_ModSet = new QWidget();
        page_ModSet->setObjectName(QString::fromUtf8("page_ModSet"));
        cb_AccordingToStandard = new QComboBox(page_ModSet);
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->addItem(QString());
        cb_AccordingToStandard->setObjectName(QString::fromUtf8("cb_AccordingToStandard"));
        cb_AccordingToStandard->setGeometry(QRect(10, 70, 191, 22));
        cb_UnitsSymRate = new QComboBox(page_ModSet);
        cb_UnitsSymRate->addItem(QString());
        cb_UnitsSymRate->addItem(QString());
        cb_UnitsSymRate->addItem(QString());
        cb_UnitsSymRate->setObjectName(QString::fromUtf8("cb_UnitsSymRate"));
        cb_UnitsSymRate->setGeometry(QRect(110, 20, 72, 22));
        label_15 = new QLabel(page_ModSet);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 50, 161, 16));
        label_16 = new QLabel(page_ModSet);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 0, 61, 16));
        le_SymbolRate = new QLineEdit(page_ModSet);
        le_SymbolRate->setObjectName(QString::fromUtf8("le_SymbolRate"));
        le_SymbolRate->setGeometry(QRect(10, 20, 101, 21));
        le_SymbolRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_ModType = new QComboBox(page_ModSet);
        cb_ModType->addItem(QString());
        cb_ModType->addItem(QString());
        cb_ModType->addItem(QString());
        cb_ModType->addItem(QString());
        cb_ModType->addItem(QString());
        cb_ModType->addItem(QString());
        cb_ModType->setObjectName(QString::fromUtf8("cb_ModType"));
        cb_ModType->setGeometry(QRect(220, 70, 191, 22));
        label_17 = new QLabel(page_ModSet);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(220, 50, 81, 16));
        lw_AccordingToStandard = new QListWidget(page_ModSet);
        lw_AccordingToStandard->setObjectName(QString::fromUtf8("lw_AccordingToStandard"));
        lw_AccordingToStandard->setGeometry(QRect(10, 100, 191, 261));
        lw_ModType = new QListWidget(page_ModSet);
        lw_ModType->setObjectName(QString::fromUtf8("lw_ModType"));
        lw_ModType->setGeometry(QRect(220, 100, 191, 261));
        tw_Settings->addTab(page_ModSet, QString());
        page_SweepSet = new QWidget();
        page_SweepSet->setObjectName(QString::fromUtf8("page_SweepSet"));
        label_11 = new QLabel(page_SweepSet);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(280, 210, 91, 16));
        cb_SweepShape = new QComboBox(page_SweepSet);
        cb_SweepShape->addItem(QString());
        cb_SweepShape->addItem(QString());
        cb_SweepShape->setObjectName(QString::fromUtf8("cb_SweepShape"));
        cb_SweepShape->setGeometry(QRect(190, 80, 201, 22));
        cb_TriggerSource = new QComboBox(page_SweepSet);
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->addItem(QString());
        cb_TriggerSource->setObjectName(QString::fromUtf8("cb_TriggerSource"));
        cb_TriggerSource->setGeometry(QRect(10, 30, 161, 22));
        label_4 = new QLabel(page_SweepSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 101, 16));
        label_6 = new QLabel(page_SweepSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 160, 47, 13));
        le_StepSweep = new QLineEdit(page_SweepSet);
        le_StepSweep->setObjectName(QString::fromUtf8("le_StepSweep"));
        le_StepSweep->setGeometry(QRect(10, 230, 81, 21));
        le_StepSweep->setLayoutDirection(Qt::LeftToRight);
        le_StepSweep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_SweepFreqMode = new QComboBox(page_SweepSet);
        cb_SweepFreqMode->addItem(QString());
        cb_SweepFreqMode->addItem(QString());
        cb_SweepFreqMode->addItem(QString());
        cb_SweepFreqMode->setObjectName(QString::fromUtf8("cb_SweepFreqMode"));
        cb_SweepFreqMode->setGeometry(QRect(10, 80, 161, 22));
        cb_UninsCenter = new QComboBox(page_SweepSet);
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->addItem(QString());
        cb_UninsCenter->setObjectName(QString::fromUtf8("cb_UninsCenter"));
        cb_UninsCenter->setGeometry(QRect(330, 180, 61, 22));
        label_7 = new QLabel(page_SweepSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 10, 201, 16));
        le_CenterFreq = new QLineEdit(page_SweepSet);
        le_CenterFreq->setObjectName(QString::fromUtf8("le_CenterFreq"));
        le_CenterFreq->setGeometry(QRect(210, 180, 113, 21));
        le_CenterFreq->setLayoutDirection(Qt::LeftToRight);
        le_CenterFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UnitsLinStep = new QComboBox(page_SweepSet);
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->addItem(QString());
        cb_UnitsLinStep->setObjectName(QString::fromUtf8("cb_UnitsLinStep"));
        cb_UnitsLinStep->setGeometry(QRect(100, 230, 61, 22));
        label_8 = new QLabel(page_SweepSet);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 60, 81, 16));
        le_SweepDwell = new QLineEdit(page_SweepSet);
        le_SweepDwell->setObjectName(QString::fromUtf8("le_SweepDwell"));
        le_SweepDwell->setGeometry(QRect(280, 230, 51, 21));
        le_SweepDwell->setLayoutDirection(Qt::LeftToRight);
        le_SweepDwell->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UninsStartFreq = new QComboBox(page_SweepSet);
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->addItem(QString());
        cb_UninsStartFreq->setObjectName(QString::fromUtf8("cb_UninsStartFreq"));
        cb_UninsStartFreq->setGeometry(QRect(130, 130, 61, 22));
        label_10 = new QLabel(page_SweepSet);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 210, 101, 16));
        le_StopFreq = new QLineEdit(page_SweepSet);
        le_StopFreq->setObjectName(QString::fromUtf8("le_StopFreq"));
        le_StopFreq->setGeometry(QRect(10, 180, 113, 21));
        le_StopFreq->setLayoutDirection(Qt::LeftToRight);
        le_StopFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(page_SweepSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 151, 16));
        cb_SweepSpacing = new QComboBox(page_SweepSet);
        cb_SweepSpacing->addItem(QString());
        cb_SweepSpacing->addItem(QString());
        cb_SweepSpacing->setObjectName(QString::fromUtf8("cb_SweepSpacing"));
        cb_SweepSpacing->setGeometry(QRect(190, 30, 201, 22));
        le_SpanFreq = new QLineEdit(page_SweepSet);
        le_SpanFreq->setObjectName(QString::fromUtf8("le_SpanFreq"));
        le_SpanFreq->setGeometry(QRect(210, 130, 113, 21));
        le_SpanFreq->setLayoutDirection(Qt::LeftToRight);
        le_SpanFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UnitsRange = new QComboBox(page_SweepSet);
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->addItem(QString());
        cb_UnitsRange->setObjectName(QString::fromUtf8("cb_UnitsRange"));
        cb_UnitsRange->setGeometry(QRect(330, 130, 61, 22));
        label_9 = new QLabel(page_SweepSet);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 60, 151, 16));
        label_12 = new QLabel(page_SweepSet);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 210, 81, 16));
        cb_UnitsSweepDwell = new QComboBox(page_SweepSet);
        cb_UnitsSweepDwell->addItem(QString());
        cb_UnitsSweepDwell->addItem(QString());
        cb_UnitsSweepDwell->addItem(QString());
        cb_UnitsSweepDwell->setObjectName(QString::fromUtf8("cb_UnitsSweepDwell"));
        cb_UnitsSweepDwell->setGeometry(QRect(340, 230, 51, 22));
        label_13 = new QLabel(page_SweepSet);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 110, 111, 16));
        le_StartFreq = new QLineEdit(page_SweepSet);
        le_StartFreq->setObjectName(QString::fromUtf8("le_StartFreq"));
        le_StartFreq->setGeometry(QRect(10, 130, 113, 21));
        le_StartFreq->setLayoutDirection(Qt::LeftToRight);
        le_StartFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_UnitsStopFreq = new QComboBox(page_SweepSet);
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->addItem(QString());
        cb_UnitsStopFreq->setObjectName(QString::fromUtf8("cb_UnitsStopFreq"));
        cb_UnitsStopFreq->setGeometry(QRect(130, 180, 61, 22));
        pb_StartFreqSweep = new QPushButton(page_SweepSet);
        pb_StartFreqSweep->setObjectName(QString::fromUtf8("pb_StartFreqSweep"));
        pb_StartFreqSweep->setGeometry(QRect(10, 260, 121, 21));
        le_SweepPoints = new QLineEdit(page_SweepSet);
        le_SweepPoints->setObjectName(QString::fromUtf8("le_SweepPoints"));
        le_SweepPoints->setGeometry(QRect(170, 230, 101, 21));
        le_SweepPoints->setLayoutDirection(Qt::LeftToRight);
        le_SweepPoints->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(page_SweepSet);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(210, 110, 61, 16));
        pb_StopFreqSweep = new QPushButton(page_SweepSet);
        pb_StopFreqSweep->setObjectName(QString::fromUtf8("pb_StopFreqSweep"));
        pb_StopFreqSweep->setGeometry(QRect(140, 260, 121, 21));
        pb_ResetFreqSweep = new QPushButton(page_SweepSet);
        pb_ResetFreqSweep->setObjectName(QString::fromUtf8("pb_ResetFreqSweep"));
        pb_ResetFreqSweep->setGeometry(QRect(270, 260, 121, 21));
        tw_Settings->addTab(page_SweepSet, QString());
        page_IqSet = new QWidget();
        page_IqSet->setObjectName(QString::fromUtf8("page_IqSet"));
        tw_Settings->addTab(page_IqSet, QString());

        gridLayout_4->addWidget(tw_Settings, 1, 0, 1, 2);


        gridLayout_5->addWidget(frame_MainArea, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Setup = new QMenu(menuBar);
        menu_Setup->setObjectName(QString::fromUtf8("menu_Setup"));
        menu_Reference = new QMenu(menuBar);
        menu_Reference->setObjectName(QString::fromUtf8("menu_Reference"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Setup->menuAction());
        menuBar->addAction(menu_Reference->menuAction());
        menu_Setup->addAction(action_FreqSweep);

        retranslateUi(MainWindow);

        tw_Settings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SMW200A settings", nullptr));
        action_FreqSweep->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\260 \320\277\320\276 \321\207\320\260\321\201\321\202\320\276\321\202\320\265", nullptr));
        pb_Disconnect->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\321\200\320\262\320\260\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        pb_Send->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        pb_Connection->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        cb_FrequencyUnits->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_FrequencyUnits->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_FrequencyUnits->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_FrequencyUnits->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        label->setText(QApplication::translate("MainWindow", "Frequency", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Level", nullptr));
        cb_LevelUnits->setItemText(0, QApplication::translate("MainWindow", "dBM", nullptr));
        cb_LevelUnits->setItemText(1, QApplication::translate("MainWindow", "dBUV", nullptr));
        cb_LevelUnits->setItemText(2, QApplication::translate("MainWindow", "V", nullptr));
        cb_LevelUnits->setItemText(3, QApplication::translate("MainWindow", "mV", nullptr));
        cb_LevelUnits->setItemText(4, QApplication::translate("MainWindow", "uV", nullptr));
        cb_LevelUnits->setItemText(5, QApplication::translate("MainWindow", "nV", nullptr));

        cb_PEPUnits_2->setItemText(0, QApplication::translate("MainWindow", "dBM", nullptr));
        cb_PEPUnits_2->setItemText(1, QApplication::translate("MainWindow", "dBUV", nullptr));
        cb_PEPUnits_2->setItemText(2, QApplication::translate("MainWindow", "V", nullptr));
        cb_PEPUnits_2->setItemText(3, QApplication::translate("MainWindow", "mV", nullptr));
        cb_PEPUnits_2->setItemText(4, QApplication::translate("MainWindow", "uV", nullptr));
        cb_PEPUnits_2->setItemText(5, QApplication::translate("MainWindow", "nV", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "PEP", nullptr));
        cb_AccordingToStandard->setItemText(0, QApplication::translate("MainWindow", "APCO", nullptr));
        cb_AccordingToStandard->setItemText(1, QApplication::translate("MainWindow", "Bluetooth", nullptr));
        cb_AccordingToStandard->setItemText(2, QApplication::translate("MainWindow", "CDMA2000 Forward", nullptr));
        cb_AccordingToStandard->setItemText(3, QApplication::translate("MainWindow", "CDMA2000 Reverse", nullptr));
        cb_AccordingToStandard->setItemText(4, QApplication::translate("MainWindow", "CW in Baseband", nullptr));
        cb_AccordingToStandard->setItemText(5, QApplication::translate("MainWindow", "DECT", nullptr));
        cb_AccordingToStandard->setItemText(6, QApplication::translate("MainWindow", "ETC", nullptr));
        cb_AccordingToStandard->setItemText(7, QApplication::translate("MainWindow", "GSM", nullptr));
        cb_AccordingToStandard->setItemText(8, QApplication::translate("MainWindow", "GSM EDGE", nullptr));
        cb_AccordingToStandard->setItemText(9, QApplication::translate("MainWindow", "NADC", nullptr));
        cb_AccordingToStandard->setItemText(10, QApplication::translate("MainWindow", "PDC", nullptr));
        cb_AccordingToStandard->setItemText(11, QApplication::translate("MainWindow", "PHS", nullptr));
        cb_AccordingToStandard->setItemText(12, QApplication::translate("MainWindow", "TD-SCDMA", nullptr));
        cb_AccordingToStandard->setItemText(13, QApplication::translate("MainWindow", "TETRA", nullptr));
        cb_AccordingToStandard->setItemText(14, QApplication::translate("MainWindow", "TFTS", nullptr));
        cb_AccordingToStandard->setItemText(15, QApplication::translate("MainWindow", "WCDMA-3GPP", nullptr));
        cb_AccordingToStandard->setItemText(16, QApplication::translate("MainWindow", "Worldspace", nullptr));
        cb_AccordingToStandard->setItemText(17, QApplication::translate("MainWindow", "User", nullptr));

        cb_UnitsSymRate->setItemText(0, QApplication::translate("MainWindow", "Msym/s", nullptr));
        cb_UnitsSymRate->setItemText(1, QApplication::translate("MainWindow", "ksym/s", nullptr));
        cb_UnitsSymRate->setItemText(2, QApplication::translate("MainWindow", "sym/s", nullptr));

        label_15->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\275\320\260\320\261\320\276\321\200 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272:", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "C\320\272\320\276\321\200\320\276\321\201\321\202\321\214:", nullptr));
        cb_ModType->setItemText(0, QApplication::translate("MainWindow", "ASK", nullptr));
        cb_ModType->setItemText(1, QApplication::translate("MainWindow", "PSK", nullptr));
        cb_ModType->setItemText(2, QApplication::translate("MainWindow", "QAM", nullptr));
        cb_ModType->setItemText(3, QApplication::translate("MainWindow", "FSK", nullptr));
        cb_ModType->setItemText(4, QApplication::translate("MainWindow", "APSK", nullptr));
        cb_ModType->setItemText(5, QApplication::translate("MainWindow", "User", nullptr));

        label_17->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\274\320\276\320\264\321\203\320\273\321\217\321\206\320\270\320\270:", nullptr));
        tw_Settings->setTabText(tw_Settings->indexOf(page_ModSet), QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\274\320\276\320\264\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270:", nullptr));
        cb_SweepShape->setItemText(0, QApplication::translate("MainWindow", "Sawtooth", nullptr));
        cb_SweepShape->setItemText(1, QApplication::translate("MainWindow", "Triangle", nullptr));

        cb_TriggerSource->setItemText(0, QApplication::translate("MainWindow", "Auto", nullptr));
        cb_TriggerSource->setItemText(1, QApplication::translate("MainWindow", "Immediate", nullptr));
        cb_TriggerSource->setItemText(2, QApplication::translate("MainWindow", "Single", nullptr));
        cb_TriggerSource->setItemText(3, QApplication::translate("MainWindow", "Bus", nullptr));
        cb_TriggerSource->setItemText(4, QApplication::translate("MainWindow", "External", nullptr));
        cb_TriggerSource->setItemText(5, QApplication::translate("MainWindow", "Eauto", nullptr));

        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\207\320\260\321\201\321\202\320\276\321\202\320\260:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200:", nullptr));
        cb_SweepFreqMode->setItemText(0, QApplication::translate("MainWindow", "Auto", nullptr));
        cb_SweepFreqMode->setItemText(1, QApplication::translate("MainWindow", "Manual", nullptr));
        cb_SweepFreqMode->setItemText(2, QApplication::translate("MainWindow", "Step", nullptr));

        cb_UninsCenter->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_UninsCenter->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_UninsCenter->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_UninsCenter->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        label_7->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\321\201\321\207\320\265\321\202\320\260 \321\207\320\260\321\201\321\202\320\276\321\202\320\275\321\213\321\205 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\276\320\262:", nullptr));
        cb_UnitsLinStep->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_UnitsLinStep->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_UnitsLinStep->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_UnitsLinStep->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        label_8->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \321\201\320\270\320\263\320\275\320\260\320\273\320\260:", nullptr));
        cb_UninsStartFreq->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_UninsStartFreq->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_UninsStartFreq->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_UninsStartFreq->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        label_10->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\210\320\260\320\263\320\276\320\262:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \320\267\320\260\320\277\321\203\321\201\320\272\320\260 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270:", nullptr));
        cb_SweepSpacing->setItemText(0, QApplication::translate("MainWindow", "Linear", nullptr));
        cb_SweepSpacing->setItemText(1, QApplication::translate("MainWindow", "Logarithmic", nullptr));

        cb_UnitsRange->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_UnitsRange->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_UnitsRange->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_UnitsRange->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        label_9->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270 \320\277\320\276 \321\207\320\260\321\201\321\202\320\276\321\202\320\265:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270:", nullptr));
        cb_UnitsSweepDwell->setItemText(0, QApplication::translate("MainWindow", "s", nullptr));
        cb_UnitsSweepDwell->setItemText(1, QApplication::translate("MainWindow", "ms", nullptr));
        cb_UnitsSweepDwell->setItemText(2, QApplication::translate("MainWindow", "us", nullptr));

        label_13->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\207\320\260\321\201\321\202\320\276\321\202\320\260:", nullptr));
        cb_UnitsStopFreq->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_UnitsStopFreq->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_UnitsStopFreq->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_UnitsStopFreq->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        pb_StartFreqSweep->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275:", nullptr));
        pb_StopFreqSweep->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        pb_ResetFreqSweep->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        tw_Settings->setTabText(tw_Settings->indexOf(page_SweepSet), QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\272\320\271\320\270 \321\207\320\260\321\201\321\202\320\276\321\202\320\275\320\276\320\271 \321\200\320\260\320\267\320\262\320\265\321\200\321\202\320\272\320\270", nullptr));
        tw_Settings->setTabText(tw_Settings->indexOf(page_IqSet), QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\272\320\271\320\272\320\270 I/Q", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_Setup->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        menu_Reference->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
