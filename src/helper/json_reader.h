#ifndef JSON_READER_H
#define JSON_READER_H

#include <nlohmann/json.hpp>

using namespace std;

nlohmann::json read_json_file(std::string filename);

#endif // JSON_READER_H

