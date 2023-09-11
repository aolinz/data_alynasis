/********************************************************************************
** Form generated from reading UI file 'data.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_H
#define UI_DATA_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imageviewer.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_data
{
public:
    QAction *actionshow_parameter;
    QAction *actionwarning_message;
    QAction *savedata;
    QAction *actionrun;
    QAction *actionrun_2;
    QAction *actionshuipingxianshi;
    QAction *actionlat_lon;
    QAction *actiondata_back;
    QAction *actionclose_udp;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_15;
    QVBoxLayout *verticalLayout_2;
    QLabel *par_lb;
    QTableWidget *parameter;
    QGridLayout *gridLayout;
    QWidget *widget_big;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_14;
    QWidget *widget_map;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *w1_lab;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *w1_change;
    QPushButton *w1_close;
    QQuickWidget *w1_qml;
    QWidget *widget_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *w2_label;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *w2_change;
    QPushButton *w2_close;
    QCustomPlot *w2_plt;
    QWidget *widget_3;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *w3_lab;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *w3_change;
    QPushButton *w3_close;
    ImageViewer *w3_gmt;
    QGridLayout *gridLayout_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *w4_lab;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *w4_change;
    QPushButton *w4_close;
    QCustomPlot *w4_plt;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *message;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *save;
    QMenu *run;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *data)
    {
        if (data->objectName().isEmpty())
            data->setObjectName(QString::fromUtf8("data"));
        data->resize(1021, 714);
        data->setStyleSheet(QString::fromUtf8(""));
        actionshow_parameter = new QAction(data);
        actionshow_parameter->setObjectName(QString::fromUtf8("actionshow_parameter"));
        actionwarning_message = new QAction(data);
        actionwarning_message->setObjectName(QString::fromUtf8("actionwarning_message"));
        savedata = new QAction(data);
        savedata->setObjectName(QString::fromUtf8("savedata"));
        actionrun = new QAction(data);
        actionrun->setObjectName(QString::fromUtf8("actionrun"));
        actionrun_2 = new QAction(data);
        actionrun_2->setObjectName(QString::fromUtf8("actionrun_2"));
        actionshuipingxianshi = new QAction(data);
        actionshuipingxianshi->setObjectName(QString::fromUtf8("actionshuipingxianshi"));
        actionlat_lon = new QAction(data);
        actionlat_lon->setObjectName(QString::fromUtf8("actionlat_lon"));
        actiondata_back = new QAction(data);
        actiondata_back->setObjectName(QString::fromUtf8("actiondata_back"));
        actionclose_udp = new QAction(data);
        actionclose_udp->setObjectName(QString::fromUtf8("actionclose_udp"));
        centralWidget = new QWidget(data);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(0);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, -1, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        par_lb = new QLabel(centralWidget);
        par_lb->setObjectName(QString::fromUtf8("par_lb"));
        par_lb->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(par_lb);

        parameter = new QTableWidget(centralWidget);
        parameter->setObjectName(QString::fromUtf8("parameter"));

        verticalLayout_2->addWidget(parameter);


        gridLayout_15->addLayout(verticalLayout_2, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, -1, 0);
        widget_big = new QWidget(centralWidget);
        widget_big->setObjectName(QString::fromUtf8("widget_big"));
        widget_big->setMouseTracking(true);
        widget_big->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);\n"
"border:1px solid gray"));
        gridLayout_16 = new QGridLayout(widget_big);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, -1, -1, -1);
        widget_map = new QWidget(widget_big);
        widget_map->setObjectName(QString::fromUtf8("widget_map"));
        widget_map->setMouseTracking(true);
        widget_map->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"background-color:rgb(255, 255, 255);"));
        gridLayout_5 = new QGridLayout(widget_map);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        w1_lab = new QLabel(widget_map);
        w1_lab->setObjectName(QString::fromUtf8("w1_lab"));
        w1_lab->setMaximumSize(QSize(16777215, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        w1_lab->setFont(font);
        w1_lab->setMouseTracking(true);
        w1_lab->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(w1_lab);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        w1_change = new QPushButton(widget_map);
        w1_change->setObjectName(QString::fromUtf8("w1_change"));
        w1_change->setMaximumSize(QSize(31, 31));
        w1_change->setMouseTracking(true);

        horizontalLayout_3->addWidget(w1_change);

        w1_close = new QPushButton(widget_map);
        w1_close->setObjectName(QString::fromUtf8("w1_close"));
        w1_close->setMaximumSize(QSize(31, 31));
        w1_close->setMouseTracking(true);

        horizontalLayout_3->addWidget(w1_close);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);

        gridLayout_5->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        w1_qml = new QQuickWidget(widget_map);
        w1_qml->setObjectName(QString::fromUtf8("w1_qml"));
        w1_qml->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_5->addWidget(w1_qml, 1, 0, 1, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 20);
        gridLayout_5->setRowMinimumHeight(0, 1);
        gridLayout_5->setRowMinimumHeight(1, 20);

        gridLayout_14->addWidget(widget_map, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_big);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMouseTracking(true);
        widget_2->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"background-color:rgb(255, 255, 255);"));
        gridLayout_6 = new QGridLayout(widget_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        w2_label = new QLabel(widget_2);
        w2_label->setObjectName(QString::fromUtf8("w2_label"));
        w2_label->setMaximumSize(QSize(16777215, 31));
        w2_label->setFont(font);
        w2_label->setMouseTracking(true);
        w2_label->setTextFormat(Qt::AutoText);

        horizontalLayout_4->addWidget(w2_label);

        horizontalSpacer_4 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        w2_change = new QPushButton(widget_2);
        w2_change->setObjectName(QString::fromUtf8("w2_change"));
        w2_change->setMaximumSize(QSize(31, 31));
        w2_change->setMouseTracking(true);

        horizontalLayout_4->addWidget(w2_change);

        w2_close = new QPushButton(widget_2);
        w2_close->setObjectName(QString::fromUtf8("w2_close"));
        w2_close->setMaximumSize(QSize(31, 31));
        w2_close->setMouseTracking(true);

        horizontalLayout_4->addWidget(w2_close);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);

        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        w2_plt = new QCustomPlot(widget_2);
        w2_plt->setObjectName(QString::fromUtf8("w2_plt"));

        gridLayout_7->addWidget(w2_plt, 1, 0, 1, 1);

        gridLayout_7->setRowStretch(0, 1);
        gridLayout_7->setRowStretch(1, 25);

        gridLayout_6->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_14->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(widget_big);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMouseTracking(true);
        widget_3->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"background-color:rgb(255, 255, 255);"));
        gridLayout_8 = new QGridLayout(widget_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        w3_lab = new QLabel(widget_3);
        w3_lab->setObjectName(QString::fromUtf8("w3_lab"));
        w3_lab->setMaximumSize(QSize(16777215, 31));
        w3_lab->setFont(font);
        w3_lab->setMouseTracking(true);
        w3_lab->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(w3_lab);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        w3_change = new QPushButton(widget_3);
        w3_change->setObjectName(QString::fromUtf8("w3_change"));
        w3_change->setMaximumSize(QSize(31, 31));
        w3_change->setMouseTracking(true);

        horizontalLayout_5->addWidget(w3_change);

        w3_close = new QPushButton(widget_3);
        w3_close->setObjectName(QString::fromUtf8("w3_close"));
        w3_close->setMaximumSize(QSize(31, 31));
        w3_close->setMouseTracking(true);

        horizontalLayout_5->addWidget(w3_close);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);

        gridLayout_9->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        w3_gmt = new ImageViewer(widget_3);
        w3_gmt->setObjectName(QString::fromUtf8("w3_gmt"));
        gridLayout_2 = new QGridLayout(w3_gmt);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_9->addWidget(w3_gmt, 1, 0, 1, 1);

        gridLayout_9->setRowStretch(0, 1);
        gridLayout_9->setRowStretch(1, 25);

        gridLayout_8->addLayout(gridLayout_9, 0, 0, 1, 1);


        gridLayout_14->addWidget(widget_3, 1, 0, 1, 1);

        widget_4 = new QWidget(widget_big);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMouseTracking(true);
        widget_4->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"background-color:rgb(255, 255, 255);"));
        gridLayout_12 = new QGridLayout(widget_4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(3, 3, 3, 3);
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        w4_lab = new QLabel(widget_4);
        w4_lab->setObjectName(QString::fromUtf8("w4_lab"));
        w4_lab->setMaximumSize(QSize(16777215, 31));
        w4_lab->setFont(font);
        w4_lab->setMouseTracking(true);
        w4_lab->setTextFormat(Qt::AutoText);

        horizontalLayout_7->addWidget(w4_lab);

        horizontalSpacer_7 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        w4_change = new QPushButton(widget_4);
        w4_change->setObjectName(QString::fromUtf8("w4_change"));
        w4_change->setMaximumSize(QSize(31, 31));
        w4_change->setMouseTracking(true);

        horizontalLayout_7->addWidget(w4_change);

        w4_close = new QPushButton(widget_4);
        w4_close->setObjectName(QString::fromUtf8("w4_close"));
        w4_close->setMaximumSize(QSize(31, 31));
        w4_close->setMouseTracking(true);

        horizontalLayout_7->addWidget(w4_close);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(2, 1);
        horizontalLayout_7->setStretch(3, 1);

        gridLayout_13->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        w4_plt = new QCustomPlot(widget_4);
        w4_plt->setObjectName(QString::fromUtf8("w4_plt"));

        gridLayout_13->addWidget(w4_plt, 1, 0, 1, 1);

        gridLayout_13->setRowStretch(0, 1);
        gridLayout_13->setRowStretch(1, 20);

        gridLayout_12->addLayout(gridLayout_13, 0, 0, 1, 1);


        gridLayout_14->addWidget(widget_4, 1, 1, 1, 1);

        gridLayout_14->setRowStretch(0, 1);
        gridLayout_14->setRowStretch(1, 1);
        gridLayout_14->setColumnStretch(0, 1);
        gridLayout_14->setColumnStretch(1, 1);
        gridLayout_14->setColumnMinimumWidth(0, 1);
        gridLayout_14->setColumnMinimumWidth(1, 1);
        gridLayout_14->setRowMinimumHeight(0, 1);
        gridLayout_14->setRowMinimumHeight(1, 1);

        gridLayout_16->addLayout(gridLayout_14, 0, 0, 1, 1);


        gridLayout->addWidget(widget_big, 0, 0, 1, 1);


        gridLayout_15->addLayout(gridLayout, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        message = new QTableWidget(centralWidget);
        message->setObjectName(QString::fromUtf8("message"));

        verticalLayout->addWidget(message);


        gridLayout_15->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout_15->setColumnStretch(0, 1);
        gridLayout_15->setColumnStretch(1, 3);
        gridLayout_15->setColumnStretch(2, 1);

        gridLayout_3->addLayout(gridLayout_15, 0, 0, 1, 1);

        data->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(data);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1021, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        save = new QMenu(menuBar);
        save->setObjectName(QString::fromUtf8("save"));
        run = new QMenu(menuBar);
        run->setObjectName(QString::fromUtf8("run"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        data->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(save->menuAction());
        menuBar->addAction(run->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionshow_parameter);
        menu->addAction(actionwarning_message);
        save->addAction(actionshuipingxianshi);
        save->addAction(actionclose_udp);
        run->addAction(savedata);
        menu_2->addAction(actionlat_lon);
        menu_3->addAction(actiondata_back);

        retranslateUi(data);

        QMetaObject::connectSlotsByName(data);
    } // setupUi

    void retranslateUi(QMainWindow *data)
    {
        data->setWindowTitle(QApplication::translate("data", "data_analyse", nullptr));
        actionshow_parameter->setText(QApplication::translate("data", "show_parameter", nullptr));
        actionwarning_message->setText(QApplication::translate("data", "warning_message", nullptr));
        savedata->setText(QApplication::translate("data", "savedata", nullptr));
#ifndef QT_NO_TOOLTIP
        savedata->setToolTip(QApplication::translate("data", "savedata", nullptr));
#endif // QT_NO_TOOLTIP
        actionrun->setText(QApplication::translate("data", "run_shuiping", nullptr));
        actionrun_2->setText(QApplication::translate("data", "run_chuizhi", nullptr));
        actionshuipingxianshi->setText(QApplication::translate("data", "open_udp", nullptr));
        actionlat_lon->setText(QApplication::translate("data", "lat_lon", nullptr));
        actiondata_back->setText(QApplication::translate("data", "data_back", nullptr));
        actionclose_udp->setText(QApplication::translate("data", "close_udp", nullptr));
        par_lb->setText(QApplication::translate("data", "\345\217\202\346\225\260\346\230\276\347\244\272", nullptr));
        w1_lab->setText(QApplication::translate("data", "\345\234\260\345\233\276", nullptr));
        w1_change->setText(QApplication::translate("data", "\360\237\224\263", nullptr));
        w1_close->setText(QApplication::translate("data", "\342\235\214", nullptr));
        w2_label->setText(QApplication::translate("data", "\345\256\236\346\227\266\347\233\221\346\265\213", nullptr));
        w2_change->setText(QApplication::translate("data", "\360\237\224\263", nullptr));
        w2_close->setText(QApplication::translate("data", "\342\235\214", nullptr));
        w3_lab->setText(QApplication::translate("data", "\346\260\264\345\271\263\345\211\226\351\235\242\346\230\276\347\244\272", nullptr));
        w3_change->setText(QApplication::translate("data", "\360\237\224\263", nullptr));
        w3_close->setText(QApplication::translate("data", "\342\235\214", nullptr));
        w4_lab->setText(QApplication::translate("data", "\345\236\202\347\233\264\345\211\226\351\235\242", nullptr));
        w4_change->setText(QApplication::translate("data", "\360\237\224\263", nullptr));
        w4_close->setText(QApplication::translate("data", "\342\235\214", nullptr));
        label->setText(QApplication::translate("data", "\346\266\210\346\201\257\350\255\246\347\244\272", nullptr));
        menu->setTitle(QApplication::translate("data", "\346\230\276\347\244\272\344\277\241\346\201\257", nullptr));
        save->setTitle(QApplication::translate("data", "udp\346\225\260\346\215\256", nullptr));
        run->setTitle(QApplication::translate("data", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("data", "\346\260\264\345\271\263\345\211\226\351\235\242", nullptr));
        menu_3->setTitle(QApplication::translate("data", "\346\225\260\346\215\256\345\233\236\351\241\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class data: public Ui_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_H
