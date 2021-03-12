#include "const.hpp"

#include <fstream>

void open_error();

void read_lod_rewards(){
    extern std::string path;
    extern int MAX_COSTUME;
    std::ifstream input;
    json js;

    input.open(path + R"(\lod_rewards.json)");
    if (input.fail()) open_error();

    input >> js;
    json Rewards = js.at("objects")[0].at("objdata").at("Rewards");
    for (json i : Rewards){
        if (i.at("Award").get<std::string>().compare("costume") == 0) MAX_COSTUME = std::max(MAX_COSTUME, std::stoi(i.at("AwardParam").get<std::string>()));
    }

    input.close();
}

