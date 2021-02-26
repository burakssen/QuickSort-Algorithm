#ifndef ALGORITHM_DATA_H
#define ALGORITHM_DATA_H
#include <string>

class Data {
    std::string country;
    std::string item_type;
    std::string order_id;
    int units_sold;
    float total_profit;
public:
    Data(std::string,std::string,std::string,int,float);
    Data();
    std::string &getCountry();  //get country method
    std::string &getItemType();  //get item type method
    std::string &getOrderId();  //get order id method
    int &getUnitsSold();  //get units sold method
    float &getTotalProfit();  //get total profit method
   
    void operator=(Data*); // equals operator assigns data's properties directly another data
   

    ~Data();
};


#endif //ALGORITHM_DATA_H
