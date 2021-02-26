#include <iostream>
#include "data.h"

Data::Data(std::string country, std::string item_type, std::string order_id, int units_sold, float total_profit) { // custom data constructor
    this->country = country;            //set data properties
    this->item_type = item_type;
    this->order_id = order_id;
    this->units_sold = units_sold;
    this->total_profit = total_profit;
}

Data::Data(){}  //default constructor

std::string &Data::getCountry() {   //get country method
    return this->country;
}

std::string &Data::getItemType() { //get item type method
    return this->item_type;
}

std::string &Data::getOrderId() { //get order id method
    return this->order_id;
}

int &Data::getUnitsSold() { //get units sold method
    return this->units_sold;
}

float &Data::getTotalProfit() { //get get total profit method
    return this->total_profit;
}

Data::~Data() { // data destructor

}

void Data::operator=(Data* data) { // equals operator assigns data's properties directly another data
    this->country = data->country;
    this->item_type = data->item_type;
    this->order_id = data->order_id;
    this->units_sold = data->units_sold;
    this->total_profit = data->total_profit;
}

