#include<iostream>
#include<fstream>
#include<string>

#include <cstdlib>
#include "MyDataArray.h"
#include "QuickSort.h"
#include "saveFile.h"
#include <chrono>

using namespace std;


int main(int argc, char**argv){
    auto start = chrono::steady_clock::now(); // start timer for execution time for all the program
    ifstream file;
	file.open("sales.txt");

    if (!file){
		cerr << "File cannot be opened!";
		exit(1);
		}

    //you should read value of N from command line
    int N = atoi(argv[1]); // read value from comment line
	// temp variables for taking datas
	string line;
	string country;
	string item_type;
	string order_id;
	int units_sold;
	float total_profit;

    MyDataArray *myArray; // create my data array pointer
    myArray = new MyDataArray();	// create new array
	getline(file, line); //this is the header line

	for(int i = 0; i<N; i++){

		getline(file, country, '\t'); //country (string)
		getline(file, item_type, '\t'); //item type (string)
		getline(file, order_id, '\t'); //order id (string)
		file >> units_sold; //units sold (integer)
		file >> total_profit; //total profit (float)
	    getline(file, line, '\n'); //this is for reading the \n character into dummy variable.
	    Data* data; // create new data pointer
	    data = new Data(country,item_type,order_id,units_sold,total_profit); //create new data with properties
	    myArray->addData(*data);	//add data to the list
	    delete data;	//delete data
	}
    auto sortStart = chrono::steady_clock::now(); // start timer
    QuickSort(*myArray,0,myArray->getSize() - 1); // sort list
    auto sortEnd = chrono::steady_clock::now();	// end timer
    auto sortDiff = sortEnd - sortStart; // calculate time
    saveFile(myArray);//save sorted array to a file
    auto end = chrono::steady_clock::now();	// end timer for the program
    auto diff = end - start;	//calculate time
    delete myArray;	// delete list
    std::cout <<"Sorting Took: " <<chrono::duration <double, milli> (sortDiff).count() << " ms" << std::endl; // print execution times
    std::cout <<"Program Execution Took: " <<chrono::duration <double, milli> (diff).count() << " ms" << std::endl;
	return 0;
}
