#include "json.hpp"
#include "fifo_map.hpp"

//a workaround to give to use fifo_map as map, we are just ignoring the 'less' compare
//https://github.com/nlohmann/json/issues/485
template<class K, class V, class dummy_compare, class A>
using workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json = nlohmann::basic_json<workaround_fifo_map>;

const std::vector<std::string> gameupgrades_list = {
    "starting_sun_lvl1",
    "startingsun2",

    "pf_slots_lvl1",
    "pf_slots_lvl2",

    "sunshovel_lvl1",
    "sunshovel_lvl2",
    "sunshovel3",

    "7_slots",
    "seedslot2",

    "pf_refresh",

    "wallnut_firstaid",

    "manual_mowers_1",

    "feature_quest_pinata_hunt_slot_1",
    "feature_quest_pinata_hunt_slot_2",

    "feature_powerup_vasebreaker_move",
    "feature_powerup_vasebreaker_reveal",
    //"feature_powerup_vasebreaker_color",
    "feature_powerup_vasebreaker_butter",

    "pirate_stargate_start",
    "cowboy_stargate_start",
    "iceage_stargate_start",
    "lostcity_stargate_start",
    "future_stargate_start",
    "dark_stargate_start",
    "eighties_stargate_start",
    "dino_stargate_start",
    "beach_stargate_start",
    "modern_stargate_start",

    // this section can't obtainable in the game
    //"feature_treasure_yeti",

    "upgrade_powerup_duration_1",
    "upgrade_powerup_duration_2",

    "valuable_mowers",
};

const json products_object = {
    {"aliases"  , json::array()},
    {"objclass" , "StoreProductProps"},
    {"objdata"  , {
        {"Descriptions"             , json::array()},
        {"IsAdPlacement"            , false},
        {"IsFree"                   , true},
        //{"IsOneTimePurchase"        , false},
        {"Name"                     , nullptr},
        //{"NoTooltip"                , false},
        {"ObjectCount"              , nullptr},
        {"ObjectItem"               , nullptr},
        {"ObjectType"               , nullptr},
        //{"OneTimeDays"              , 0},
        {"Price"                    , 0},
        {"PriceCoins"               , "0"},
        {"PriceGems"                , "0"},
        {"PriceMints"               , "0"},
        {"ShortDescriptions"        , json::array()},
        //{"LawnShortDescription"     , "PRODUCT_PLANT_SNOWPEA_NONCONSUME_FREE_S"},
        {"Sku"                      , nullptr}
    }}
};

const json MarketScheduleEntries_object = {
    // My secret :>
    {"EndDateTime"          , 2017121607},
    {"Name"                 , nullptr},
    {"ScheduledProducts"    , json::array()},
    // PvZ 2 release date :3
    {"StartDateTime"        , 1373328000}
};

const json ScheduledProducts_object = {
    {"Comment"              , nullptr},
    {"Category"             , ""},
    {"Priority"             , ""},
    {"ABTest"               , ""},
    {"PromotionGroup"       , ""},
    {"AdditionalSegment"    , ""},
    {"SmartKey"             , ""},
    {"SoftCurrency"         , ""},
    {"SoftCost"             , -1},
    {"MaxPurchase"          , -1},
    {"SoftCostPerPurchase"  , -1},
    {"Visuals"              , json::array({"mostpopular", "shine"})},
    {"Sku"                  , json::array()}
};
