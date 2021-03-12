#include "const.h"

#include <fstream>
#include <iomanip>

void open_error();

void edit_magento_schedule(){
    extern std::string path;
    extern int MAX_COSTUME;
    std::ifstream input;
    std::ofstream output;
    json js;

    input.open(path + R"(\magento_schedule.json)");
    if (input.fail()) open_error();
    input >> js;
    output.open(path + R"(\magento_schedule.json)");

    for (json::iterator it = js.at("objects").begin(); it <js.at("objects").end(); ++it){
        std::string aliases = it->at("aliases").get<std::vector <std::string> >()[0];
        if (aliases.compare("android") == 0){
            json tmp = MagentoScheduleEntries_object;

            for (int j = 1; j <= MAX_COSTUME; ++j){
                tmp.at("ScheduledProducts").push_back(json({
                    {"Index"    , j},
                    {"Product"  , "h3x4n1um.costume." + std::to_string(j)}
                }));
            }

            it->at("objdata").at("MagentoScheduleEntries").clear();
            it->at("objdata").at("MagentoScheduleEntries").push_back(tmp);
        }
    }

    output << std::setw(4) << js;
    input.close();
    output.close();
}
