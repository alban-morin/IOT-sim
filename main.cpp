#include "server.cpp"
#include "scheduler.h"
#include "scheduler.cpp"

int main() {
    Scheduler scheduler;
    scheduler.globalAskRefreshTime();
    while(true){
        scheduler.randomSensorValue();
        scheduler.globalConsoleWrite();
        scheduler.globalFileWrite();
    }
}
