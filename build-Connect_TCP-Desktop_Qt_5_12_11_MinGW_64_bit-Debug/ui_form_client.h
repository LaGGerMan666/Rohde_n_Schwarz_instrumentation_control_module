/********************************************************************************
** Form generated from reading UI file 'form_client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_CLIENT_H
#define UI_FORM_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Client
{
public:
    QGridLayout *gridLayout;
    QTextEdit *te_Log;
    QLineEdit *le_Command;
    QPushButton *pb_Send;
    QPushButton *pb_Connection;
    QPushButton *pb_Disconnect;

    void setupUi(QWidget *Form_Client)
    {
        if (Form_Client->objectName().isEmpty())
            Form_Client->setObjectName(QString::fromUtf8("Form_Client"));
        Form_Client->resize(400, 462);
        gridLayout = new QGridLayout(Form_Client);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        te_Log = new QTextEdit(Form_Client);
        te_Log->setObjectName(QString::fromUtf8("te_Log"));

        gridLayout->addWidget(te_Log, 0, 0, 1, 2);

        le_Command = new QLineEdit(Form_Client);
        le_Command->setObjectName(QString::fromUtf8("le_Command"));

        gridLayout->addWidget(le_Command, 1, 0, 1, 1);

        pb_Send = new QPushButton(Form_Client);
        pb_Send->setObjectName(QString::fromUtf8("pb_Send"));

        gridLayout->addWidget(pb_Send, 1, 1, 1, 1);

        pb_Connection = new QPushButton(Form_Client);
        pb_Connection->setObjectName(QString::fromUtf8("pb_Connection"));

        gridLayout->addWidget(pb_Connection, 2, 0, 1, 2);

        pb_Disconnect = new QPushButton(Form_Client);
        pb_Disconnect->setObjectName(QString::fromUtf8("pb_Disconnect"));

        gridLayout->addWidget(pb_Disconnect, 3, 0, 1, 2);


        retranslateUi(Form_Client);

        QMetaObject::connectSlotsByName(Form_Client);
    } // setupUi

    void retranslateUi(QWidget *Form_Client)
    {
        Form_Client->setWindowTitle(QApplication::translate("Form_Client", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        pb_Send->setText(QApplication::translate("Form_Client", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        pb_Connection->setText(QApplication::translate("Form_Client", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        pb_Disconnect->setText(QApplication::translate("Form_Client", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_Client: public Ui_Form_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_CLIENT_H
