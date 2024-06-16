#include "controller.h"

void Controller::forward()
{
    MOTOR_NW.go_forward(SPEED);
    MOTOR_NE.go_forward(SPEED);
    MOTOR_SW.go_forward(SPEED);
    MOTOR_SE.go_forward(SPEED);
}

void Controller::backward()
{
    MOTOR_NW.go_backward(SPEED);
    MOTOR_NE.go_backward(SPEED);
    MOTOR_SW.go_backward(SPEED);
    MOTOR_SE.go_backward(SPEED);
}

void Controller::right()
{
    MOTOR_NW.go_backward(SPEED);
    MOTOR_NE.go_forward(SPEED);
    MOTOR_SW.go_forward(SPEED);
    MOTOR_SE.go_backward(SPEED);
}

void Controller::left()
{
    MOTOR_NW.go_forward(SPEED);
    MOTOR_NE.go_backward(SPEED);
    MOTOR_SW.go_backward(SPEED);
    MOTOR_SE.go_forward(SPEED);
}

void Controller::turning_right()
{
    MOTOR_NW.go_forward(SPEED);
    MOTOR_NE.go_backward(SPEED);
    MOTOR_SW.go_forward(SPEED);
    MOTOR_SE.go_backward(SPEED);
}

void Controller::turning_left()
{
    MOTOR_NW.go_backward(SPEED);
    MOTOR_NE.go_forward(SPEED);
    MOTOR_SW.go_backward(SPEED);
    MOTOR_SE.go_forward(SPEED);
}

void Controller::stop()
{
    MOTOR_NW.stop();
    MOTOR_NE.stop();
    MOTOR_SW.stop();
    MOTOR_SE.stop();
}

void Controller::manual(int order)
{
    switch (order) {
        case 0:
            stop();
            break;
        case 1:
            forward();
            break;
        case 2:
            backward();
            break;
        case 3:
            right();
            break;
        case 4:
            left();
            break;
        case 5:
            turning_right();
            break;
        case 6:
            turning_left();
            break;
    }
}
