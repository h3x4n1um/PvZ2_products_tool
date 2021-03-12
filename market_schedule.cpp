#include "const.hpp"

#include <fstream>
#include <iomanip>

void open_error();

void edit_market_schedule(){
    extern std::string path;
    extern std::vector <std::string> plant_lists;
    extern int MAX_COSTUME;
    std::ifstream input;
    std::ofstream output;
    json js;

    input.open(path + R"(\market_schedule.json)");
    if (input.fail()) open_error();
    input >> js;
    output.open(path + R"(\market_schedule.json)");

    json::iterator it = js.at("objects").at(0).at("objdata").at("MarketScheduleEntries").begin();
    while(it < js.at("objects").at(0).at("objdata").at("MarketScheduleEntries").end()){
        bool del = false;
        for (json ScheduledProducts : it->at("ScheduledProducts")){
            for (std::string s : ScheduledProducts.at("Sku").get<std::vector<std::string>>()){
                if (s.find("plant") != std::string::npos || s.find("costume") != std::string::npos){
                    del = true;
                    break;
                }
            }
            if (del) break;
        }

        if (del) js.at("objects").at(0).at("objdata").at("MarketScheduleEntries").erase(it);
        else ++it;
    }

    json plants = MarketScheduleEntries_object;
    plants.at("Name") = "H3x4n1um Hacked Plants";
    for (std::string s : plant_lists){
        json ScheduledProducts = ScheduledProducts_object;
        ScheduledProducts.at("Comment") = "H3x4n1um Plant " + s;
        ScheduledProducts.at("Category") = "Plants";
        ScheduledProducts.at("Sku").push_back("h3x4n1um.plant." + s);
        ScheduledProducts.at("Sku").push_back("h3x4n1um.plant." + s);
        plants.at("ScheduledProducts").push_back(ScheduledProducts);
    }
    js.at("objects").at(0).at("objdata").at("MarketScheduleEntries").push_back(plants);

    json costumes = MarketScheduleEntries_object;
    costumes.at("Name") = "H3x4n1um Hacked Costumes";
    for (int i = 1; i <= MAX_COSTUME; ++i){
        json ScheduledProducts = ScheduledProducts_object;
        ScheduledProducts.at("Comment") = "H3x4n1um Costume " + std::to_string(i);
        ScheduledProducts.at("Category") = "Daily Offers";
        ScheduledProducts.at("Sku").push_back("h3x4n1um.costume." + std::to_string(i));
        ScheduledProducts.at("Sku").push_back("h3x4n1um.costume." + std::to_string(i));
        costumes.at("ScheduledProducts").push_back(ScheduledProducts);
    }
    js.at("objects").at(0).at("objdata").at("MarketScheduleEntries").push_back(costumes);

    output << std::setw(4) << js;
    input.close();
    output.close();
}
