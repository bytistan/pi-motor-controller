#include "motor.h"

void Motor::go_forward(int speed) 
{
    gpioWrite(PIN_FW,1);
    gpioWrite(PIN_BW,0);
    gpioPWM(PIN_PWM,speed);
}

void Motor::go_backward(int speed) 
{
    gpioWrite(PIN_BW,1);
    gpioWrite(PIN_FW,0);
    gpioPWM(PIN_PWM,speed);
}

void Motor::stop()
{
    gpioWrite(PIN_FW,0);
    gpioWrite(PIN_BW,0);
    gpioPWM(PIN_PWM,0);
}
