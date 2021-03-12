#include "const.hpp"

#include <fstream>

void open_error();

void read_PlantLevels(){
    extern std::string path;
    extern std::vector <std::string> plant_lists;
    std::ifstream input;
    json js;

    input.open(path + R"(\PlantLevels.json)");
    if (input.fail()) open_error();

    input >> js;
    input.close();

    for (json::iterator it = js.at("objects").begin(); it < js["objects"].end(); ++it) plant_lists.push_back(it->at("aliases")[0].get<std::string>());
}
