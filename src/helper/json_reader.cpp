#include "json_reader.h"

#include <iostream>
#include <fstream>

nlohmann::json read_json_file(std::string filename) {
  nlohmann::json json;

  try {
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Dosya açılamadı: " << filename << std::endl;
      exit(1);
    }

    file >> json;
  } catch (const std::exception& e) {
    std::cerr << "JSON ayrıştırma hatası: " << e.what() << std::endl;
    exit(1);
  }

  return json;
}

