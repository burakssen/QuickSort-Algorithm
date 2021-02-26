
#ifndef ALGORITHM_MYDATAARRAY_H
#define ALGORITHM_MYDATAARRAY_H

#include "data.h"
#include <vector>
#include <iostream>

class MyDataArray {
    std::vector<Data> datas;
    int length = 0;
    int size = 0;
public:
    MyDataArray();
    void addData(Data);
    int getSize();
    Data& getData(int i);
    void swap(int,int);
    ~MyDataArray();
};


#endif //ALGORITHM_MYDATAARRAY_H
