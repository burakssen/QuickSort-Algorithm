#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include "MyDataArray.h"
#include "data.h"
#include <string>
#include <ctime>

int partition(MyDataArray& , int, int); // partition method prototype

void QuickSort(MyDataArray &myDataArray, int low, int high){   // quicksort method
    if (low < high) // if pivot is greater than the lower digit
    {
        int pivot = partition(myDataArray, low, high);  // partiton method sorts list by comparing pivot (which in this case last item) with other items

        QuickSort(myDataArray, low, pivot - 1); // go to left
        QuickSort(myDataArray, pivot + 1, high);    // go to right
    }
}

int partition(MyDataArray &myDataArray, int low, int high){

    Data *pivot;
    pivot = &myDataArray.getData(high); // get the last items data

    int index = low; // set index to lowest item

    for(int i = low; i < high; i++){
        if(pivot->getCountry().compare(myDataArray.getData(i).getCountry().c_str()) < 0){ // if pivots country data is early from the i th data's in the alphabetical order
            myDataArray.swap(i,index); // swicth i th data with indexed data
            index++; // increse the index
        }
        else if(pivot->getCountry().compare(myDataArray.getData(i).getCountry().c_str()) == 0) // if pivots country data is same with the i th data's
        {
            if(pivot->getTotalProfit() > myDataArray.getData(i).getTotalProfit()){ // if total profit of the pivots is greater then the ith data

                myDataArray.swap(i,index);  //switch indexed data with ith data
                index++;// increase the index
            }
        }
    }

    myDataArray.swap(index, high); // swap the indexed data with the pivot data because indexed data is greater than the pivot
    return index; // return index
}


#endif //ALGORITHM_QUICKSORT_H
