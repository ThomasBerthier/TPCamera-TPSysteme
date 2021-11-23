//*********************************************************************************************
//* Programme : TPCamera.cpp											date : 23/11/2021
//*---------------------------------------------------------------------------------------------------------
//* derni�re mise a jour : 23/11/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  BOUCHER Louis
//*				  CAUET Clément
//*--------------------------------------------------------------------------------------------------------
//* BUT : Gérer les déplacemets et le zoom d'une caméra EVID30.
//*Programmes associés : main.cpp
//*********************************************************************************************
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TPCamera.h"
#include <qserialport.h>
#include<qserialportinfo.h>
#include <qdebug.h>
#include <qtimer.h>

class TPCamera : public QMainWindow
{
    Q_OBJECT

public:
    TPCamera(QWidget *parent = Q_NULLPTR);

private:
    Ui::TPCameraClass ui;
	QSerialPort serial;
	int lastZoomValue;
	// Trame a envoyé a la camera pour effectuer les differentes instructions
	QByteArray camOnData = QByteArray::fromHex("81 01 04 00 02 FF");
	QByteArray camOffData = QByteArray::fromHex("81 01 04 00 03 FF");
	QByteArray zoomPlusData = QByteArray::fromHex("81 01 04 07 02 FF");
	QByteArray zoomMinusData = QByteArray::fromHex("81 01 04 07 03 FF");
	QByteArray zoomStopData = QByteArray::fromHex("81 01 04 07 00 FF");
	QByteArray resetCamData = QByteArray::fromHex("81 01 06 02 18 14 00 00 00 00 00 00 00 00 FF");
	QByteArray leftData = QByteArray::fromHex("81 01 06 01 09 14 01 03 FF");
	QByteArray rightData = QByteArray::fromHex("81 01 06 01 10 10 02 03 FF");
	QByteArray upData = QByteArray::fromHex("81 01 06 01 07 07 03 01 FF");
	QByteArray downData = QByteArray::fromHex("81 01 06 01 10 10 03 02 FF");
	QByteArray stopData = QByteArray::fromHex("81 01 06 01 05 05 03 03 FF");

	QTimer *timer;
	int timerLoop = 0;
	int generalLoop = 0;

public slots:
	void zoom();
	void resetCam();
	void autoMove();
	void up();
	void down();
	void left();
	void right();
	void stop();
	void autoMoveLoop();
	void startCam();
	void stopCam();
};
