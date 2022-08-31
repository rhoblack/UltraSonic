#include "UltraSonic.h"
#include <wiringPi.h>
#include <unistd.h>
#include <chrono>
#include <iostream>


UltraSonic::UltraSonic(int trig, int echo)
    : triggerPin(trig), echoPin(echo)
{
    wiringPiSetup();
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

UltraSonic::~UltraSonic()
{

}

void UltraSonic::trigger()
{
    digitalWrite(triggerPin, SET);
    usleep(15);
    digitalWrite(triggerPin, RESET);
}

int UltraSonic::caculateDistance()
{
    int count = 0;
    while (!digitalRead(echoPin)) {
        delayMicroseconds(1);
        count++;
        if (count == MAX_COUNT) {
            count = -1;
            return count;
        }
    }

    count = 0;
    while (digitalRead(echoPin)) {
        delayMicroseconds(1);
        count++;
        if (count == MAX_COUNT) {
            count = -1;
            return count;
        }
    }
    return count;
}

int UltraSonic::readDistance()
{
    int distance;

    trigger();
    distance = caculateDistance();
    
    if (distance < 0) return -1;

    return (int)(distance * 0.017);  // distance * 340 / 1000000 * 100 / 2; cm
}