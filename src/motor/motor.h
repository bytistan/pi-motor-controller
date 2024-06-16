#ifndef MOTOR_H
#define MOTOR_H

#include <pigpio.h>
#include <iostream>

using namespace std;

struct Motor 
{
    int PIN_FW;
    int PIN_BW;

    int PIN_PWM; // [!] Set speed.    
    
    Motor(int fw, int bw, int pwm) 
       : PIN_FW(fw), PIN_BW(bw), PIN_PWM(pwm) // [!] Set motor.
    {
        if (gpioSetMode(PIN_FW, PI_OUTPUT) != 0 ||
            gpioSetMode(PIN_BW, PI_OUTPUT) != 0 ||
            gpioSetMode(PIN_PWM, PI_OUTPUT) != 0)
        {
            cout << "[-] Error settings GPIO modes\n";
            gpioTerminate();
            return;
        } 
    }

    void go_forward(int speed);
    void go_backward(int speed);
    void stop();
};

#endif
