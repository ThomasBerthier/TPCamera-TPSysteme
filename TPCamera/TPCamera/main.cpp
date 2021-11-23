//*********************************************************************************************
//* Programme : main.cpp											date : 23/11/2021
//*---------------------------------------------------------------------------------------------------------
//* derni�re mise a jour : 23/11/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  BOUCHER Louis
//*				  CAUET Clément
//*--------------------------------------------------------------------------------------------------------
//* BUT : Initialiser l'IHM qui gère l'application.
//*********************************************************************************************
#include "TPCamera.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPCamera w;
    w.show();
    return a.exec();
}
