#include "const.hpp"

#include <fstream>
#include <iomanip>

void open_error();

void edit_magento_filter(){
    extern std::string path;
    extern std::vector <std::string> plant_lists;
    extern int MAX_COSTUME;
    std::ifstream input;
    std::ofstream output;
    json js;

    input.open(path + R"(\magento_filter.json)");
    if (input.fail()) open_error();
    input >> js;
    output.open(path + R"(\magento_filter.json)");

    for (json::iterator it = js.at("objects")[0].at("objdata").at("ObjectTypeFilters").begin(); it < js.at("objects")[0].at("objdata").at("ObjectTypeFilters").end(); ++it){
        std::string type = it->at("Type").get<std::string>();
        if (type.compare("plant") == 0) it->at("SubTypeFilters") = plant_lists;
        if (type.compare("costume") == 0){
            it->at("SubTypeFilters") = json::array();
            for (int j = 1; j <= MAX_COSTUME; ++j) it->at("SubTypeFilters").push_back(std::to_string(j));
        }
    }

    output << std::setw(4) << js;
    input.close();
    output.close();
}
