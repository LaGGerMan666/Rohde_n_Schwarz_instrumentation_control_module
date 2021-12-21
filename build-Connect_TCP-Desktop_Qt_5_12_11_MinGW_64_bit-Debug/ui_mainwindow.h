/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QFrame *frame_Consol;
    QGridLayout *gridLayout_3;
    QTextEdit *te_Log;
    QLineEdit *le_Command;
    QPushButton *pb_Send;
    QPushButton *pb_Connection;
    QPushButton *pb_Disconnect;
    QFrame *frame_MainArea;
    QGridLayout *gridLayout_4;
    QFrame *frame_Frequency;
    QGridLayout *gridLayout;
    QComboBox *cb_FrequencyUnits;
    QLineEdit *le_Frequency;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_PepLevel;
    QGridLayout *gridLayout_2;
    QComboBox *cb_LevelUnits;
    QLineEdit *le_PEP;
    QLineEdit *le_Level;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *cb_PEPUnits_2;
    QSpacerItem *horizontalSpacer;
    QMdiArea *mdiArea;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Setup;
    QMenu *menu_Reference;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 610);
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

        pb_Disconnect = new QPushButton(frame_Consol);
        pb_Disconnect->setObjectName(QString::fromUtf8("pb_Disconnect"));

        gridLayout_3->addWidget(pb_Disconnect, 3, 0, 1, 2);


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
        frame_Frequency->setFrameShape(QFrame::StyledPanel);
        frame_Frequency->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_Frequency);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cb_FrequencyUnits = new QComboBox(frame_Frequency);
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->addItem(QString());
        cb_FrequencyUnits->setObjectName(QString::fromUtf8("cb_FrequencyUnits"));
        cb_FrequencyUnits->setMinimumSize(QSize(51, 0));
        cb_FrequencyUnits->setMaximumSize(QSize(51, 16777215));

        gridLayout->addWidget(cb_FrequencyUnits, 2, 1, 1, 1);

        le_Frequency = new QLineEdit(frame_Frequency);
        le_Frequency->setObjectName(QString::fromUtf8("le_Frequency"));
        le_Frequency->setMaximumSize(QSize(16777215, 16777215));
        le_Frequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(le_Frequency, 2, 0, 1, 1);

        label = new QLabel(frame_Frequency);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        gridLayout_4->addWidget(frame_Frequency, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        frame_PepLevel = new QFrame(frame_MainArea);
        frame_PepLevel->setObjectName(QString::fromUtf8("frame_PepLevel"));
        frame_PepLevel->setFrameShape(QFrame::StyledPanel);
        frame_PepLevel->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_PepLevel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        cb_LevelUnits = new QComboBox(frame_PepLevel);
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->addItem(QString());
        cb_LevelUnits->setObjectName(QString::fromUtf8("cb_LevelUnits"));
        cb_LevelUnits->setMinimumSize(QSize(51, 0));
        cb_LevelUnits->setMaximumSize(QSize(51, 16777215));

        gridLayout_2->addWidget(cb_LevelUnits, 1, 4, 1, 1);

        le_PEP = new QLineEdit(frame_PepLevel);
        le_PEP->setObjectName(QString::fromUtf8("le_PEP"));
        le_PEP->setMaximumSize(QSize(16777215, 16777215));
        le_PEP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(le_PEP, 1, 0, 1, 1);

        le_Level = new QLineEdit(frame_PepLevel);
        le_Level->setObjectName(QString::fromUtf8("le_Level"));
        le_Level->setMaximumSize(QSize(16777215, 16777215));
        le_Level->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(le_Level, 1, 3, 1, 1);

        label_3 = new QLabel(frame_PepLevel);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        label_2 = new QLabel(frame_PepLevel);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        cb_PEPUnits_2 = new QComboBox(frame_PepLevel);
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->addItem(QString());
        cb_PEPUnits_2->setObjectName(QString::fromUtf8("cb_PEPUnits_2"));
        cb_PEPUnits_2->setMinimumSize(QSize(51, 0));
        cb_PEPUnits_2->setMaximumSize(QSize(51, 16777215));

        gridLayout_2->addWidget(cb_PEPUnits_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);


        gridLayout_4->addWidget(frame_PepLevel, 0, 2, 1, 1);

        mdiArea = new QMdiArea(frame_MainArea);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_4->addWidget(mdiArea, 1, 0, 1, 3);


        gridLayout_5->addWidget(frame_MainArea, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 20));
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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        pb_Send->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        pb_Connection->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        pb_Disconnect->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\321\200\320\262\320\260\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        cb_FrequencyUnits->setItemText(0, QApplication::translate("MainWindow", "GHz", nullptr));
        cb_FrequencyUnits->setItemText(1, QApplication::translate("MainWindow", "MHz", nullptr));
        cb_FrequencyUnits->setItemText(2, QApplication::translate("MainWindow", "kHz", nullptr));
        cb_FrequencyUnits->setItemText(3, QApplication::translate("MainWindow", "Hz", nullptr));

        label->setText(QApplication::translate("MainWindow", "Frequency", nullptr));
        cb_LevelUnits->setItemText(0, QApplication::translate("MainWindow", "dBm", nullptr));
        cb_LevelUnits->setItemText(1, QApplication::translate("MainWindow", "dB\302\265V", nullptr));
        cb_LevelUnits->setItemText(2, QApplication::translate("MainWindow", "nV", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "Level", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "PEP", nullptr));
        cb_PEPUnits_2->setItemText(0, QApplication::translate("MainWindow", "dBm", nullptr));
        cb_PEPUnits_2->setItemText(1, QApplication::translate("MainWindow", "dB\302\265V", nullptr));
        cb_PEPUnits_2->setItemText(2, QApplication::translate("MainWindow", "nV", nullptr));

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
