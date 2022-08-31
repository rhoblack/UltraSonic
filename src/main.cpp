#include <iostream>
#include <wiringPi.h>
#include "UltraSonic.h"

int main()
{
    int trigPin = 5;
    int echoPin = 4;

    UltraSonic ultraSonic(trigPin, echoPin);

    int distance;

    while(1)
    {
        distance = ultraSonic.readDistance();
        std::cout << "distance = " << distance << "cm" <<std::endl;

        delay(700);
    }

    return 0;
}
