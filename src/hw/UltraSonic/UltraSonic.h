#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#include <chrono>

class UltraSonic
{
private:
    const bool RESET = 0;
    const bool SET = 1;
    const int MAX_COUNT = 20000;

    int triggerPin;
    int echoPin;

    void trigger();
    int caculateDistance();

public:
    UltraSonic(int trig, int echo);
    virtual ~UltraSonic();
    int readDistance();
};

#endif /* __ULTRASONIC_H__ */