#include "sensor.h"
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

template <typename T>
void Sensor<T>::randomSensorVal(){
    srand(time(NULL));
    if(this->sensorName=="Humidity sensor"){
         this->valSensor=(rand()%10000)/100; //retourn un nb à virgule entre 0 et 100
    }
    else if(this->sensorName=="Temperature sensor"){
        float t;
        t=rand()%10000;
        t=t/100;
        t=((t*45)/100)-15;//generateur entre -15 et 30 à partir d'un nb entre 0 et 100
        this->valSensor=t;
    }
    else if(this->sensorName=="Sound sensor"){
        this->valSensor = (rand()%1001)/100+10;//genère un nombre entre 10 et 110 avec 2 décimales
    }
    else if(this->sensorName=="Light sensor"){//genère un booléen aléatoire
        int l=rand()%1000;
        if(l>500){this->valSensor=true;}
        else{this->valSensor=false;}
    }
    else this->valSensor= 0;
}

template <typename T>
T Sensor<T>::getSensorData(){//retourne la valeur du capteur en dormant pendant son refresh time
    this_thread::sleep_for(chrono::milliseconds(refreshTime));
    return valSensor;
}



