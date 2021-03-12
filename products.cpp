#include "const.hpp"

#include <fstream>
#include <iomanip>

void open_error();

void edit_products(){
    extern std::string path;
    extern std::vector <std::string> plant_lists;
    extern int MAX_COSTUME;
    std::ifstream input;
    std::ofstream output;
    json js;

    input.open(path + R"(\products.json)");
    if (input.fail()) open_error();
    input >> js;
    output.open(path + R"(\products.json)");

    json::iterator it = js.at("objects").begin();

    while(it < js.at("objects").end()){
        std::string ObjectType = it->at("objdata").at("ObjectType").get<std::string>();
        if (ObjectType.compare("plant") == 0 || ObjectType.compare("costume") == 0) js.at("objects").erase(it);
        else ++it;
    }

    for (std::string s : plant_lists){
        json tmp = products_object;
        std::string aliases = "h3x4n1um.plant." + s;
        tmp.at("aliases").push_back(aliases);
        tmp.at("objdata").at("Name") = "H3x4n1um Plant " + s;
        tmp.at("objdata").at("ObjectCount") = 1;
        tmp.at("objdata").at("ObjectItem") = s;
        tmp.at("objdata").at("ObjectType") = "plant";
        tmp.at("objdata").at("Sku") = aliases;
        js.at("objects").push_back(tmp);
    }

    for (int j = 1; j <= MAX_COSTUME; ++j){
        json tmp = products_object;
        std::string aliases = "h3x4n1um.costume." + std::to_string(j);
        tmp.at("aliases").push_back(aliases);
        tmp.at("objdata").at("Name") = "H3x4n1um Costume " + std::to_string(j);
        tmp.at("objdata").at("ObjectCount") = 1;
        tmp.at("objdata").at("ObjectItem") = std::to_string(j);
        tmp.at("objdata").at("ObjectType") = "costume";
        tmp.at("objdata").at("Sku") = aliases;
        js.at("objects").push_back(tmp);
    }

    //watermark and set IsFree
    for (it = js.at("objects").begin(); it < js.at("objects").end(); ++it){
        //remove lawn string
        it->at("objdata").erase("LawnDescription");
        it->at("objdata").erase("LawnShortDescription");
        //use legacy Descriptions & ShortDescriptions
        it->at("objdata").erase("Descriptions");
        it->at("objdata").erase("ShortDescriptions");
        for (int j = 0; j < 6; ++j){
            //watermark ShortDescriptions
            it->at("objdata")["ShortDescriptions"].push_back(it->at("objdata").at("Name").get<std::string>());
            //watermark Descriptions
            it->at("objdata")["Descriptions"].push_back("Hacked by h3x4n1um    fb.com/nthoanghai");
        }
        //set IsFree
        it->at("objdata").at("IsFree") = true;
    }

    output << std::setw(4) << js;
    input.close();
    output.close();
}
