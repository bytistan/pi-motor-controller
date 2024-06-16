#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "motor.h"
#include "pins.h"
#include <iostream>

struct Controller
{
    Motor MOTOR_NW;
    Motor MOTOR_NE;
    Motor MOTOR_SW;
    Motor MOTOR_SE;

    int SPEED;

    Controller() :
        MOTOR_NW(NW_PIN_FW, NW_PIN_BW, NW_PIN_PWM),
        MOTOR_NE(NE_PIN_FW, NE_PIN_BW, NE_PIN_PWM),
        MOTOR_SW(SW_PIN_FW, SW_PIN_BW, SW_PIN_PWM),
        MOTOR_SE(SE_PIN_FW, SE_PIN_BW, SE_PIN_PWM),
	SPEED(80) {
		std::cout << "[+] Engines were successfully installed." << std::endl;
	}

    void manual(int order);
    void forward();
    void backward();
    void left();
    void right();
    void turning_right();
    void turning_left();

    void stop();
};


#endif
