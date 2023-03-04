/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Nov 3rd, 2021, 2: PM
 * Purpose:  Sorting Class
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Vector.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=100;
    Vector<char> array(size);
    Vector<char> *ptr;
    
    //Map inputs to outputs here, i.e. the process
    ptr=&array;
    
    //Display the results
    cout<<"Display the Original Random Vector"<<endl;
    ptr->display(10);
    
    //Testing the memory modifying data
    cout<<"Display Modified Vector with change of data"<<endl;
    ptr->setData(101,66);
    ptr->display(10);
    
    //Testing resizing functionality
    cout<<"Display Modified Vector with resizing"<<endl;
    ptr->reSize(150);
    ptr->display(10);

    //Exit stage left
    return 0;
}