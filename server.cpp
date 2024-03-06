#include <ctime>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "server.h"
#include "sensor.h"
using namespace std;

//affiche les valeurs d'un capteur dans la console
template <typename T>
void Server::consoleWrite(Sensor<T> capteur){
    cout<<capteur.sensorName<<" : "<<capteur.getSensorData()<<capteur.unit<<endl;
}

//enregistre la valeur d'un capteur dans un fichier log
template <typename T>
void Server::fileWrite(Sensor<T> capteur){
    time_t now=time(0);
    char* date=ctime(&now);
    ofstream fichier;
    fichier.open("log.txt",ios::app);
    fichier<<endl<<date;
    fichier<<capteur.sensorName<<endl;
    fichier<<capteur.getSensorData()<<capteur.unit<<endl;
    fichier.close();
}



