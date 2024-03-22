/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Sat Apr 20 01:47:50 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *m_k;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *m_length;
    QDoubleSpinBox *m_b;
    QGroupBox *s_transformGB;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *m_aX;
    QDoubleSpinBox *m_aY;
    QDoubleSpinBox *m_aZ;
    QLabel *label_2;
    QDoubleSpinBox *m_bX;
    QDoubleSpinBox *m_bY;
    QDoubleSpinBox *m_bZ;
    QCheckBox *m_aFixed;
    QCheckBox *m_bFixed;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QDoubleSpinBox *m_dt;
    QPushButton *m_reset;
    QLabel *label_7;
    QSpinBox *m_timerValue;
    QPushButton *m_sim;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(972, 656);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QString::fromUtf8("s_mainWindowGridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        m_k = new QDoubleSpinBox(groupBox);
        m_k->setObjectName(QString::fromUtf8("m_k"));
        m_k->setMinimum(-200);
        m_k->setMaximum(200);
        m_k->setSingleStep(0.01);
        m_k->setValue(5);

        gridLayout_3->addWidget(m_k, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        m_length = new QDoubleSpinBox(groupBox);
        m_length->setObjectName(QString::fromUtf8("m_length"));
        m_length->setMinimum(-10);
        m_length->setMaximum(10);
        m_length->setSingleStep(0.01);
        m_length->setValue(1);

        gridLayout_3->addWidget(m_length, 2, 1, 1, 1);

        m_b = new QDoubleSpinBox(groupBox);
        m_b->setObjectName(QString::fromUtf8("m_b"));
        m_b->setMinimum(-200);
        m_b->setMaximum(200);
        m_b->setSingleStep(0.01);
        m_b->setValue(2);

        gridLayout_3->addWidget(m_b, 1, 1, 1, 1);


        s_mainWindowGridLayout->addWidget(groupBox, 1, 1, 1, 1);

        s_transformGB = new QGroupBox(centralwidget);
        s_transformGB->setObjectName(QString::fromUtf8("s_transformGB"));
        gridLayout = new QGridLayout(s_transformGB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(s_transformGB);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_aX = new QDoubleSpinBox(s_transformGB);
        m_aX->setObjectName(QString::fromUtf8("m_aX"));
        m_aX->setMinimum(-8);
        m_aX->setMaximum(8);
        m_aX->setSingleStep(0.01);
        m_aX->setValue(0);

        gridLayout->addWidget(m_aX, 1, 0, 1, 1);

        m_aY = new QDoubleSpinBox(s_transformGB);
        m_aY->setObjectName(QString::fromUtf8("m_aY"));
        m_aY->setMinimum(-8);
        m_aY->setMaximum(8);
        m_aY->setSingleStep(0.01);
        m_aY->setValue(2);

        gridLayout->addWidget(m_aY, 1, 1, 1, 1);

        m_aZ = new QDoubleSpinBox(s_transformGB);
        m_aZ->setObjectName(QString::fromUtf8("m_aZ"));
        m_aZ->setMinimum(-8);
        m_aZ->setMaximum(8);
        m_aZ->setSingleStep(0.01);
        m_aZ->setValue(0);

        gridLayout->addWidget(m_aZ, 1, 2, 1, 1);

        label_2 = new QLabel(s_transformGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        m_bX = new QDoubleSpinBox(s_transformGB);
        m_bX->setObjectName(QString::fromUtf8("m_bX"));
        m_bX->setMinimum(-8);
        m_bX->setMaximum(8);
        m_bX->setSingleStep(0.01);
        m_bX->setValue(0);

        gridLayout->addWidget(m_bX, 3, 0, 1, 1);

        m_bY = new QDoubleSpinBox(s_transformGB);
        m_bY->setObjectName(QString::fromUtf8("m_bY"));
        m_bY->setMinimum(-8);
        m_bY->setMaximum(8);
        m_bY->setSingleStep(0.01);
        m_bY->setValue(-2);

        gridLayout->addWidget(m_bY, 3, 1, 1, 1);

        m_bZ = new QDoubleSpinBox(s_transformGB);
        m_bZ->setObjectName(QString::fromUtf8("m_bZ"));
        m_bZ->setMinimum(-8);
        m_bZ->setMaximum(8);
        m_bZ->setSingleStep(0.01);
        m_bZ->setValue(0);

        gridLayout->addWidget(m_bZ, 3, 2, 1, 1);

        m_aFixed = new QCheckBox(s_transformGB);
        m_aFixed->setObjectName(QString::fromUtf8("m_aFixed"));
        m_aFixed->setChecked(true);

        gridLayout->addWidget(m_aFixed, 0, 1, 1, 1);

        m_bFixed = new QCheckBox(s_transformGB);
        m_bFixed->setObjectName(QString::fromUtf8("m_bFixed"));

        gridLayout->addWidget(m_bFixed, 2, 1, 1, 1);


        s_mainWindowGridLayout->addWidget(s_transformGB, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        s_mainWindowGridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        m_dt = new QDoubleSpinBox(groupBox_2);
        m_dt->setObjectName(QString::fromUtf8("m_dt"));
        m_dt->setDecimals(3);
        m_dt->setMinimum(0.001);
        m_dt->setMaximum(4);
        m_dt->setSingleStep(0.001);
        m_dt->setValue(0.01);

        gridLayout_2->addWidget(m_dt, 0, 1, 1, 1);

        m_reset = new QPushButton(groupBox_2);
        m_reset->setObjectName(QString::fromUtf8("m_reset"));

        gridLayout_2->addWidget(m_reset, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        m_timerValue = new QSpinBox(groupBox_2);
        m_timerValue->setObjectName(QString::fromUtf8("m_timerValue"));
        m_timerValue->setMaximum(1000);
        m_timerValue->setValue(10);

        gridLayout_2->addWidget(m_timerValue, 1, 1, 1, 1);

        m_sim = new QPushButton(groupBox_2);
        m_sim->setObjectName(QString::fromUtf8("m_sim"));
        m_sim->setCheckable(true);
        m_sim->setChecked(true);

        gridLayout_2->addWidget(m_sim, 3, 1, 1, 1);


        s_mainWindowGridLayout->addWidget(groupBox_2, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 972, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Spring using RK4 Integration", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Spring Constants", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Spring Constant (k)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Damping coeff (b)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "rest length", 0, QApplication::UnicodeUTF8));
        s_transformGB->setTitle(QApplication::translate("MainWindow", "Spring Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Position A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Position B", 0, QApplication::UnicodeUTF8));
        m_aFixed->setText(QApplication::translate("MainWindow", "fixed", 0, QApplication::UnicodeUTF8));
        m_bFixed->setText(QApplication::translate("MainWindow", "fixed", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Simulation", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "dt step", 0, QApplication::UnicodeUTF8));
        m_reset->setText(QApplication::translate("MainWindow", "reset", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "timer (ms)", 0, QApplication::UnicodeUTF8));
        m_sim->setText(QApplication::translate("MainWindow", "sim", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
