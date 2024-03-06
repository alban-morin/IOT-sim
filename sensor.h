#ifndef PROJETTP_SENSOR_H
#define PROJETTP_SENSOR_H
#include "server.h"
#include <string>
using namespace std;

template <typename T>
class Sensor{
protected:
    T valSensor;
    string sensorName;
    int refreshTime;
    string unit;
public:
    Sensor(const string& name,const string& unite):sensorName(name),unit(unite),valSensor(0),refreshTime(1000){}

    //constructeur par defaut
    Sensor() : Sensor("",""){}

    ~Sensor(){}//destructeur
    Sensor(const Sensor& s){//contructeur par recopie
        valSensor=s.valSensor;
        refreshTime=s.refreshTime;
        sensorName=s.sensorName;
        unit=s.unit;
    }
    Sensor& operator=(const Sensor& s){//operateur d'affectation
        valSensor=s.valSensor;
        refreshTime=s.refreshTime;
        sensorName=s.sensorName;
        unit=s.unit;
        return *this;
    }
    void randomSensorVal();
    T getSensorData();
    friend class Scheduler;
    friend class Server;
};

class TemperatureSensor :public Sensor<float> {
public:
    TemperatureSensor() : Sensor<float>("Temperature sensor", "°C"){
    }
};

class HumiditySensor :public Sensor<float>{
public:
    HumiditySensor() : Sensor<float>("Humidity sensor", "%"){
    }
};

class SoundSensor :public Sensor<int>{
public:
    SoundSensor() : Sensor<int>("Sound sensor", "dB"){
    }
};

class LightSensor :public Sensor<bool>{
public:
    LightSensor() : Sensor<bool>("Light sensor", ""){
    }
};

#endif //PROJETTP_SENSOR_H
