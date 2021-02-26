//
// Created by burak on 30.11.2020.
//

#include "MyDataArray.h"

MyDataArray::MyDataArray() { //custom data array constructor
    this->datas = std::vector<Data>();  // create new vector array
    this->size = this->datas.size();    // set size
}

void MyDataArray::addData(Data data) {  //add data method add's data to vector array
    this->datas.emplace_back(data);
}

MyDataArray::~MyDataArray() { // destructor

}

Data &MyDataArray::getData(int index) {     // get data method gets data from an index
    return this->datas[index];
}

int MyDataArray::getSize() {    //get size method returns size of the vector array
   return this->datas.size();
}

void MyDataArray::swap(int first, int second) {     // swao method swap two data's places
    Data temp;
    temp = this->datas[first];
    this->datas[first] = this->datas[second];
    this->datas[second] = &temp;
}




