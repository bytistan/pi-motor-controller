#include "txt_handler.h"
#include <iostream>
#include <fstream>

std::string read_last_line(const std::string& file_name) {
    std::ifstream file(file_name);

    if (!file) {
        std::cerr << "[-] File failed to open." << std::endl;
        return "";
    }

    std::string last_line;
    std::string line;
    while (std::getline(file, line)) {
        last_line = line;
    }

    file.close();

    return last_line;
}
