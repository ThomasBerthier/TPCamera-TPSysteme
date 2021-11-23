/********************************************************************************
** Form generated from reading UI file 'TPCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPCAMERA_H
#define UI_TPCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TPCameraClass
{
public:
    QWidget *centralWidget;
    QLabel *status;
    QSlider *zoom;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TPCameraClass)
    {
        if (TPCameraClass->objectName().isEmpty())
            TPCameraClass->setObjectName(QString::fromUtf8("TPCameraClass"));
        TPCameraClass->resize(600, 400);
        centralWidget = new QWidget(TPCameraClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        status = new QLabel(centralWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(40, 20, 61, 16));
        zoom = new QSlider(centralWidget);
        zoom->setObjectName(QString::fromUtf8("zoom"));
        zoom->setEnabled(false);
        zoom->setGeometry(QRect(200, 60, 19, 160));
        zoom->setOrientation(Qt::Vertical);
        TPCameraClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TPCameraClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TPCameraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TPCameraClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TPCameraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TPCameraClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TPCameraClass->setStatusBar(statusBar);

        retranslateUi(TPCameraClass);
        QObject::connect(zoom, SIGNAL(sliderMoved(int)), TPCameraClass, SLOT(zoom()));

        QMetaObject::connectSlotsByName(TPCameraClass);
    } // setupUi

    void retranslateUi(QMainWindow *TPCameraClass)
    {
        TPCameraClass->setWindowTitle(QCoreApplication::translate("TPCameraClass", "TPCamera", nullptr));
        status->setText(QCoreApplication::translate("TPCameraClass", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TPCameraClass: public Ui_TPCameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPCAMERA_H
