#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <output file name>"
    exit 1
fi

output_file="../bin/$1"

g++ -I../src/motor -I../src/helper -I../src/database ../src/helper/json_reader.cpp ../src/helper/txt_handler.cpp ../src/motor/controller.cpp ../src/main.cpp ../src/database/table.cpp ../src/database/database_manager.cpp ../src/motor/motor.cpp -o "$output_file" -lpigpio -lsqlite3
