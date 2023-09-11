/********************************************************************************
** Form generated from reading UI file 'ip.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IP_H
#define UI_IP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ip
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *port_port;
    QLabel *label_3;
    QLabel *ip_label;

    void setupUi(QDialog *ip)
    {
        if (ip->objectName().isEmpty())
            ip->setObjectName(QString::fromUtf8("ip"));
        ip->resize(290, 236);
        gridLayout_2 = new QGridLayout(ip);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ip);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(ip);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        port_port = new QLabel(ip);
        port_port->setObjectName(QString::fromUtf8("port_port"));
        QFont font;
        font.setPointSize(15);
        port_port->setFont(font);

        gridLayout->addWidget(port_port, 0, 1, 1, 1);

        label_3 = new QLabel(ip);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        ip_label = new QLabel(ip);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));
        ip_label->setFont(font);

        gridLayout->addWidget(ip_label, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 5);

        retranslateUi(ip);

        QMetaObject::connectSlotsByName(ip);
    } // setupUi

    void retranslateUi(QDialog *ip)
    {
        ip->setWindowTitle(QApplication::translate("ip", "PORT", nullptr));
        label->setText(QApplication::translate("ip", "port\351\205\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("ip", "port", nullptr));
        port_port->setText(QApplication::translate("ip", "38500", nullptr));
        label_3->setText(QApplication::translate("ip", "ip", nullptr));
        ip_label->setText(QApplication::translate("ip", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ip: public Ui_ip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IP_H
