# Pi Motor Controller

It was created to control 4 motorized mecanum wheels with Rassbery pi.

## How to Use

1. First, clone the project to your computer:

    ```bash
    git clone https://github.com/findik-faresi/pi-motor-controller
    ```

2. Go to the project directory:

    ```bash
    cd pi-motor-controller
    ```

3. Install the required Python packages:

    ```bash
    ./helper/setup.sh
    ```

4. Update the pin numbers according to your project:

    ```bash
    nano src/motor/pins.h
    ```
    
5. Change main.cpp file according to your project:

    ```bash
    nano src/main.cpp
    ```
    
5. Use helper to build:

    ```bash
    ./build.sh robot
    ```
    
## Features

- You can control 4 motor with 8 direction PWM.
- It have database and database management system if you wanna use.
