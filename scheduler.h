#ifndef PROJETTP_SCHEDULER_H
#define PROJETTP_SCHEDULER_H

#include "server.h"
#include "sensor.h"

class Scheduler {
private:
        TemperatureSensor capteurTemp;
        LightSensor capteurLum;
        HumiditySensor capteurHum;
        SoundSensor capteurSon;
        Server serveur;
public:
    //constructeur par defaut
    Scheduler() : capteurTemp(), capteurLum(), capteurHum(), capteurSon(), serveur() {
    }

    //constructeur par recopie
    Scheduler(const Scheduler& other)
            : capteurTemp(other.capteurTemp),
              capteurLum(other.capteurLum),
              capteurHum(other.capteurHum),
              capteurSon(other.capteurSon),
              serveur(other.serveur) {
    }

    // Opérateur d'assignation
    Scheduler& operator=(const Scheduler& other) {
        if (this != &other) {
            capteurTemp = other.capteurTemp;
            capteurLum = other.capteurLum;
            capteurHum = other.capteurHum;
            capteurSon = other.capteurSon;
            serveur = other.serveur;
        }
        return *this;
    }

    //destructeur
    ~Scheduler() {}
    void randomSensorValue();
    void globalConsoleWrite();
    void globalFileWrite();
    template <typename T>
    void askRefreshTime(Sensor<T> &capteur);
    void globalAskRefreshTime();
};

#endif //PROJETTP_SCHEDULER_H
