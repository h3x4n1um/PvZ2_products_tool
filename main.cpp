#include "json.hpp"

#include <conio.h>
#include <iostream>
#include <string>

void open_error(){
    std::cerr << "\nCAN'T OPEN FILE!!!" << std::endl;
    getch();
    exit(1);
}

void json_format_error(){
    std::cerr << "\nJSON FORMAT ERROR!!!" << std::endl;
    getch();
    exit(1);
}

void json_parse_error(){
    std::cerr << "\nJSON PARSE ERROR!!!" << std::endl;
    getch();
    exit(1);
}

void read_lod_rewards();
void read_PlantLevels();

void edit_magento_filter();
void edit_products();
void edit_market_schedule();

std::string path = R"(C:\Users\boly4\Desktop\PvZ 2\rton2json)";
std::vector <std::string> plant_lists;
int MAX_COSTUME = 0;

int main(){
    /*std::cout << std::endl
              << "PvZ2 Free Shop 1.0.0 made by h3x4n1um" << std::endl
              << "Enter path: ";
    std::getline(std::cin, path);*/
    try{
        puts("Read lod_rewards");
        read_lod_rewards();
        puts("Read PlantLevels");
        read_PlantLevels();
        puts("Edit magento_filter");
        edit_magento_filter();
        puts("Edit products");
        edit_products();
        puts("Edit market_schedule");
        edit_market_schedule();
    }
    catch(nlohmann::json::exception &e){
        json_parse_error();
    }

    std::cout << "\nDONE!" << std::endl;
    getch();
    return 0;
}
