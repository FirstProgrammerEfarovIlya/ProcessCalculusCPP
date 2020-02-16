/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *graphic_widget;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spb_ctests;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spb_d;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spb_count;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *bt_explore;
    QPushButton *bt_explore_th;
    QPushButton *bt_cancel_th;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 729);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphic_widget = new QCustomPlot(centralwidget);
        graphic_widget->setObjectName(QString::fromUtf8("graphic_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphic_widget->sizePolicy().hasHeightForWidth());
        graphic_widget->setSizePolicy(sizePolicy);
        graphic_widget->setMinimumSize(QSize(781, 411));

        gridLayout->addWidget(graphic_widget, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spb_ctests = new QSpinBox(centralwidget);
        spb_ctests->setObjectName(QString::fromUtf8("spb_ctests"));
        spb_ctests->setMinimumSize(QSize(91, 28));
        spb_ctests->setMaximumSize(QSize(91, 28));
        spb_ctests->setMinimum(1);
        spb_ctests->setMaximum(1000000);
        spb_ctests->setValue(1);

        horizontalLayout_3->addWidget(spb_ctests);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spb_d = new QSpinBox(centralwidget);
        spb_d->setObjectName(QString::fromUtf8("spb_d"));
        spb_d->setMinimumSize(QSize(91, 28));
        spb_d->setMaximumSize(QSize(91, 28));
        spb_d->setMinimum(1);
        spb_d->setMaximum(1000000);
        spb_d->setValue(1);

        horizontalLayout_2->addWidget(spb_d);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spb_count = new QSpinBox(centralwidget);
        spb_count->setObjectName(QString::fromUtf8("spb_count"));
        spb_count->setMinimumSize(QSize(91, 28));
        spb_count->setMaximumSize(QSize(91, 28));
        spb_count->setMinimum(10);
        spb_count->setMaximum(1000000);

        horizontalLayout->addWidget(spb_count);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        bt_explore = new QPushButton(centralwidget);
        bt_explore->setObjectName(QString::fromUtf8("bt_explore"));
        bt_explore->setMinimumSize(QSize(131, 27));
        bt_explore->setMaximumSize(QSize(131, 27));

        horizontalLayout_5->addWidget(bt_explore);

        bt_explore_th = new QPushButton(centralwidget);
        bt_explore_th->setObjectName(QString::fromUtf8("bt_explore_th"));
        bt_explore_th->setMinimumSize(QSize(121, 27));
        bt_explore_th->setMaximumSize(QSize(121, 27));

        horizontalLayout_5->addWidget(bt_explore_th);

        bt_cancel_th = new QPushButton(centralwidget);
        bt_cancel_th->setObjectName(QString::fromUtf8("bt_cancel_th"));
        bt_cancel_th->setMinimumSize(QSize(81, 27));
        bt_cancel_th->setMaximumSize(QSize(81, 27));

        horizontalLayout_5->addWidget(bt_cancel_th);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\276\320\272", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\273-\320\262\320\276 \321\202\320\265\321\201\321\202\320\276\320\262 \320\275\320\260 \321\210\320\260\320\263\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\274\320\260\320\272\321\201. \320\272\320\276\320\273-\320\262\320\276", nullptr));
        bt_explore->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\321\214 \320\267\320\264\320\265\321\201\321\214", nullptr));
        bt_explore_th->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\321\214", nullptr));
        bt_cancel_th->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
