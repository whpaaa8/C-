/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    CustomView *graphicsView;
    QWidget *Graph;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *d_in1;
    QLineEdit *d_in2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *d1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLabel *d2;
    QPushButton *mind;
    QPushButton *mint;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_20;
    QLabel *tout;
    QPushButton *d_start;
    QPushButton *d_end;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *dout;
    QWidget *widget1;
    QLabel *label;
    QPushButton *m_start;
    QPushButton *m_end;
    QLabel *label_7;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *m1;
    QCheckBox *m2;
    QCheckBox *m3;
    QWidget *widget_2;
    QLabel *label_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *f_start;
    QSpacerItem *horizontalSpacer;
    QPushButton *clear;
    QLabel *label_10;
    QLabel *out;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *f_in;
    QPushButton *start;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1614, 905);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new CustomView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 10, 831, 701));
        Graph = new QWidget(centralwidget);
        Graph->setObjectName(QStringLiteral("Graph"));
        Graph->setGeometry(QRect(840, 380, 731, 461));
        label_4 = new QLabel(Graph);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 0, 121, 51));
        label_5 = new QLabel(Graph);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 131, 41));
        label_6 = new QLabel(Graph);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 110, 131, 41));
        d_in1 = new QLineEdit(Graph);
        d_in1->setObjectName(QStringLiteral("d_in1"));
        d_in1->setGeometry(QRect(120, 70, 131, 21));
        d_in2 = new QLineEdit(Graph);
        d_in2->setObjectName(QStringLiteral("d_in2"));
        d_in2->setGeometry(QRect(120, 120, 131, 21));
        layoutWidget = new QWidget(Graph);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 30, 221, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        d1 = new QLabel(layoutWidget);
        d1->setObjectName(QStringLiteral("d1"));

        horizontalLayout->addWidget(d1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        d2 = new QLabel(layoutWidget);
        d2->setObjectName(QStringLiteral("d2"));

        horizontalLayout_2->addWidget(d2);


        verticalLayout->addLayout(horizontalLayout_2);

        mind = new QPushButton(Graph);
        mind->setObjectName(QStringLiteral("mind"));
        mind->setGeometry(QRect(550, 30, 121, 51));
        mint = new QPushButton(Graph);
        mint->setObjectName(QStringLiteral("mint"));
        mint->setGeometry(QRect(550, 120, 121, 51));
        layoutWidget_4 = new QWidget(Graph);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(150, 270, 371, 51));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_9->addWidget(label_20);

        tout = new QLabel(layoutWidget_4);
        tout->setObjectName(QStringLiteral("tout"));

        horizontalLayout_9->addWidget(tout);

        d_start = new QPushButton(Graph);
        d_start->setObjectName(QStringLiteral("d_start"));
        d_start->setGeometry(QRect(100, 340, 181, 71));
        d_end = new QPushButton(Graph);
        d_end->setObjectName(QStringLiteral("d_end"));
        d_end->setGeometry(QRect(390, 340, 201, 71));
        widget = new QWidget(Graph);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 200, 371, 51));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        dout = new QLabel(widget);
        dout->setObjectName(QStringLiteral("dout"));

        horizontalLayout_5->addWidget(dout);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(830, 0, 371, 271));
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 0, 191, 81));
        m_start = new QPushButton(widget1);
        m_start->setObjectName(QStringLiteral("m_start"));
        m_start->setGeometry(QRect(40, 200, 111, 41));
        m_end = new QPushButton(widget1);
        m_end->setObjectName(QStringLiteral("m_end"));
        m_end->setGeometry(QRect(210, 200, 101, 41));
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 60, 199, 54));
        widget2 = new QWidget(widget1);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(120, 110, 141, 81));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m1 = new QCheckBox(widget2);
        m1->setObjectName(QStringLiteral("m1"));

        verticalLayout_2->addWidget(m1);

        m2 = new QCheckBox(widget2);
        m2->setObjectName(QStringLiteral("m2"));

        verticalLayout_2->addWidget(m2);

        m3 = new QCheckBox(widget2);
        m3->setObjectName(QStringLiteral("m3"));

        verticalLayout_2->addWidget(m3);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(1170, 0, 441, 391));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 20, 191, 41));
        widget3 = new QWidget(widget_2);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(80, 120, 301, 61));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        f_start = new QPushButton(widget3);
        f_start->setObjectName(QStringLiteral("f_start"));

        horizontalLayout_4->addWidget(f_start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        clear = new QPushButton(widget3);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout_4->addWidget(clear);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 200, 91, 31));
        out = new QLabel(widget_2);
        out->setObjectName(QStringLiteral("out"));
        out->setGeometry(QRect(90, 230, 251, 111));
        widget4 = new QWidget(widget_2);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(90, 70, 269, 41));
        horizontalLayout_3 = new QHBoxLayout(widget4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        f_in = new QLineEdit(widget4);
        f_in->setObjectName(QStringLiteral("f_in"));

        horizontalLayout_3->addWidget(f_in);

        start = new QPushButton(centralwidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(320, 750, 141, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1614, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\247\204\345\210\222\350\267\257\345\276\204\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\265\267\347\202\271\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\273\210\347\202\271\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\235\347\246\273\344\270\272\357\274\232", Q_NULLPTR));
        d1->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\234\200\345\260\221\347\224\250\346\227\266\344\270\272\357\274\232", Q_NULLPTR));
        d2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        mind->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\234\200\347\237\255\350\267\257\345\276\204", Q_NULLPTR));
        mint->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\234\200\344\274\230\350\267\257\345\276\204", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "\346\234\200\345\235\227\350\267\257\347\272\277\357\274\232", Q_NULLPTR));
        tout->setText(QString());
        d_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        d_end->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\347\272\277\357\274\232", Q_NULLPTR));
        dout->setText(QString());
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\250\241\346\213\237\350\275\246\346\265\201\357\274\232</span></p></body></html>", Q_NULLPTR));
        m_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        m_end->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\350\246\201\346\230\276\347\244\272\347\232\204\350\267\257\346\256\265\357\274\232", Q_NULLPTR));
        m1->setText(QApplication::translate("MainWindow", "\351\200\232\347\225\205\350\267\257\346\256\265", Q_NULLPTR));
        m2->setText(QApplication::translate("MainWindow", "\347\225\245\345\240\265\350\267\257\346\256\265", Q_NULLPTR));
        m3->setText(QApplication::translate("MainWindow", "\346\213\245\345\240\265\350\267\257\346\256\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\257\273\346\211\276\346\234\200\350\277\22130\344\270\252\347\202\271</span></p></body></html>", Q_NULLPTR));
        f_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\346\234\200\350\277\221\347\232\204\347\202\271\346\230\257\357\274\232", Q_NULLPTR));
        out->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\202\271\345\217\267\357\274\232", Q_NULLPTR));
        f_in->setInputMask(QString());
        start->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\276", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\257\274\350\210\252\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
