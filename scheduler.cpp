#include <iostream>
#include <fstream>
#include <string>
#include "scheduler.h"
#include "sensor.h"
#include "sensor.cpp"
#include <chrono>
#include <thread>
using namespace std;

//génère des valeurs aléatoires pour chaque capteur
void Scheduler::randomSensorValue(){
    capteurTemp.randomSensorVal();
    capteurHum.randomSensorVal();
    capteurLum.randomSensorVal();
    capteurSon.randomSensorVal();
}

//demande à l'utilisateur le temps de rafraichissement d'un capteur
template <typename T>
void Scheduler::askRefreshTime(Sensor<T> &capteur){
    cout<<"Entrez le temps de rafraichissement du capteur "<<capteur.sensorName<<endl;
    int input;
    cin>>input;
    while(1)//s'assurer que l'entrée de l'uilisateur est un entier
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Saisie invalide, réessayez svp"<<endl;
            cin>>input;
        }
        if(!cin.fail())
            break;
    }
    capteur.refreshTime=input;
}

//demande le temps de rafraichissement pour chaque capteur
void Scheduler::globalAskRefreshTime(){
    cout<<"Bienvenue dans votre ecosystème IOT"<<endl;
    cout<<"Voulez-vous entrer manuellement les temps de rafraichissement des capteurs ? (y/n)"<<endl;
    string input;
    cin>>input;
    if(input=="y")
    {
        cout<<"Remarque: les temps de rafraichissement sont en millisecondes"<<endl;
        askRefreshTime(capteurTemp);
        askRefreshTime(capteurHum);
        askRefreshTime(capteurLum);
        askRefreshTime(capteurSon);
    }
    else if(input=="n")
    {
        capteurTemp.refreshTime=1000;
        capteurHum.refreshTime=1000;
        capteurLum.refreshTime=1000;
        capteurSon.refreshTime=1000;
    }
    else
    {
        cout<<"Saisie invalide, réessayez svp"<<endl;
        globalAskRefreshTime();
    }
}


//affiche les valeurs de chaque capteur
void Scheduler::globalConsoleWrite(){
    serveur.consoleWrite(capteurTemp);
    serveur.consoleWrite(capteurHum);
    serveur.consoleWrite(capteurLum);
    serveur.consoleWrite(capteurSon);
}

//enregistre les valeurs de chaque capteur dans un fichier
void Scheduler::globalFileWrite(){
    serveur.fileWrite(capteurTemp);
    serveur.fileWrite(capteurHum);
    serveur.fileWrite(capteurLum);
    serveur.fileWrite(capteurSon);
}







