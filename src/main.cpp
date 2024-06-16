#include <iostream>
#include <unistd.h>

#include "controller.h"
// #include "database_manager.h"
#include <cstdlib>

int main() {
    // DatabaseManager db;

    if (gpioInitialise() < 0) {
        std::cout << "[-] pigpio initialization failed\n";
        return 1;
    }

    Controller controller;
    
    gpioTerminate(); 
    return 0;
}
