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
#include "TPCamera.h"


TPCamera::TPCamera(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//Initialisation du port serie
	serial.setBaudRate(QSerialPort::Baud9600);
	serial.setPortName("COM1");
	serial.setDataBits(QSerialPort::Data8);
	serial.setParity(QSerialPort::NoParity);
	if (serial.open(QIODevice::ReadWrite)) {
		ui.status->setText("Liaison serie effectue");
	}
	else {
		ui.status->setText("Liaison serie echoue");
	}
	
	ui.off->setVisible(false);

	timer = new QTimer();	
}

//Allume la camera
void TPCamera::startCam() {
	serial.write(camOnData);
	ui.on->setVisible(false);
	ui.off->setVisible(true);
}

//Eteint la camera
void TPCamera::stopCam() {
	serial.write(camOffData);
	ui.on->setVisible(true);
	ui.off->setVisible(false);
}

//Fait zoomer la caméra en fonction de la position du curseur sur la slidebar de l'IHM
void TPCamera::zoom() {
	int value = ui.zoom->value();
	
	if(value == 1){
		serial.write(zoomStopData);
		qDebug() << value;
	}
	if(value == 2) {
		serial.write(zoomPlusData);
		qDebug() << value;
	}
	if(value == 0) {
		serial.write(zoomMinusData);
		qDebug() << value;
	}
}

//Remet la position de la caméra à zero
void TPCamera::resetCam()
{
	serial.write(resetCamData);
}

//Lève la caméra jusqu'a son maximum
void TPCamera::up()
{
	serial.write(upData);
}

//Baisse la caméra jusqu'a son maximum
void TPCamera::down()
{
	serial.write(downData);
}

//Tourne la caméra à gauche jusqu'a son maximum
void TPCamera::left()
{
	serial.write(leftData);
}

//Tourne la caméra à droite jusqu'a son maximum
void TPCamera::right()
{
	serial.write(rightData);
}

//Arrete le déplacement de la caméra
void TPCamera::stop()
{
	serial.write(stopData);
}

//Lance un patern de déplacements lorsque le timer du slot autoMove est fini
void TPCamera::autoMoveLoop()
{
	//Les déplacement se stoppe a la fin du 3ème tour
	if (generalLoop == 3) {
		QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(autoMoveLoop()));
		return;
	}
	//Pattern qui représente les differents mouvement qui change à chaque fin de timer
	if (timerLoop == 0) {
			serial.write(upData);
			timerLoop = 1;
			return;
	}
	if (timerLoop == 1) {
		serial.write(leftData);
		timerLoop = 2;
		return;
	}
	if (timerLoop == 2) {
		serial.write(downData);
		timerLoop = 3;
		return;
	}
	if (timerLoop == 3) {
		serial.write(rightData);
		timerLoop = 4;
		return;
	}
	if (timerLoop == 4) {
		serial.write(upData);
		timerLoop = 5;
		return;
	}
	if (timerLoop == 4) {
		serial.write(upData);
		timerLoop = 5;
		return;
	}
	if (timerLoop == 5) {
		serial.write(resetCamData);
		timerLoop = 0;
		generalLoop++;
		return;
	}
}

//slot qui cconecte le slot autoMoveLoop à la fin du timer et initialise le timer
void TPCamera::autoMove()
{
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(autoMoveLoop()));
	timer->start(5000);
}