#ifndef ALGORITHM_SAVEFILE_H
#define ALGORITHM_SAVEFILE_H

#include <fstream>
#include "MyDataArray.h"
#include <iomanip>

void saveFile(MyDataArray* myDataArray){
    std::ofstream file;
    file.open("sorted.txt");// open a sorted file

    std::string line = "Country\tItem Type\tOrder ID\tUnits Sold\tTotal Profit"; // create template text
    std::string country; // temp property variables
    std::string item_type;
    std::string order_id;
    int units_sold;
    float total_profit;
    file<<line<<std::endl; // write the first line
    for(int i = myDataArray->getSize() - 1; i >= 0; i--){
        //get all data
        country = myDataArray->getData(i).getCountry();
        item_type = myDataArray->getData(i).getItemType();
        order_id = myDataArray->getData(i).getOrderId();
        units_sold = myDataArray->getData(i).getUnitsSold();
        total_profit = myDataArray->getData(i).getTotalProfit();
        //write all data
        file<<country<<"\t"<<item_type<<"\t"<<order_id<<"\t"<<units_sold<<"\t";
        //write with precision 2
        file<<std::fixed <<std::setprecision(2)<<total_profit<<std::endl;
    }
    file.close(); // close the file


}
#endif //ALGORITHM_SAVEFILE_H
