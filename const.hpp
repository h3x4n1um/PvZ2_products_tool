#include "json.hpp"
#include "fifo_map.hpp"

//a workaround to give to use fifo_map as map, we are just ignoring the 'less' compare
//https://github.com/nlohmann/json/issues/485
template<class K, class V, class dummy_compare, class A>
using workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json = nlohmann::basic_json<workaround_fifo_map>;

const json products_object = {
    {"aliases"  , json::array()},
    {"objclass" , "StoreProductProps"},
    {"objdata"  , {
        {"Descriptions"             , json::array()},
        {"IsAdPlacement"            , false},
        {"IsFree"                   , true},
        {"IsOneTimePurchase"        , false},
        {"Name"                     , nullptr},
        {"NoTooltip"                , false},
        {"ObjectCount"              , nullptr},
        {"ObjectItem"               , nullptr},
        {"ObjectType"               , nullptr},
        {"OneTimeDays"              , 0},
        {"Price"                    , 0.0},
        {"PriceCoins"               , "0"},
        {"PriceGems"                , "0"},
        {"PriceMints"               , "0"},
        {"ShortDescriptions"        , json::array()},
        {"Sku"                      , nullptr}
    }}
};

const json MarketScheduleEntries_object = {
    {"EndDateTime"          , 0},
    {"Name"                 , nullptr},
    {"ScheduledProducts"    , json::array()},
    {"StartDateTime"        , 0}
};

const json ScheduledProducts_object = {
    {"Comment"              , nullptr},
    {"Category"             , ""},
    {"Priority"             , ""},
    {"ABTest"               , ""},
    {"PromotionGroup"       , ""},
    {"AdditionalSegment"    , ""},
    {"SoftCurrency"         , ""},
    {"SoftCost"             , -1},
    {"MaxPurchase"          , -1},
    {"SoftCostPerPurchase"  , -1},
    {"Visuals"              , json::array({"mostpopular", "shine"})},
    {"Sku"                  , json::array()}
};
