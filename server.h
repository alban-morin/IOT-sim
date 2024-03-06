#ifndef PROJETTP_SERVER_H
#define PROJETTP_SERVER_H
#include "sensor.h"

using namespace std;

class Server{
private :
public:
    template <typename T>
    void consoleWrite(Sensor<T> capteur);
    template <typename T>
    void fileWrite(Sensor<T> capteur);
};

#endif //PROJETTP_SERVER_H
