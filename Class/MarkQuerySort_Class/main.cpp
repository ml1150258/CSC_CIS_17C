/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Example using a structure and database/query sort
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries
#include "Array1D.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=160;
    int perLine=16;
    Array1D array1D(size);
    
    //Initialize all known variables
    cout<<"Before Sorting"<<endl;
    cout<<"Data Array Before Sorting"<<endl;
    array1D.prntAry(perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    array1D.markSrt();
    
    //Display the Inputs/Outputs
    cout<<"After Sorting"<<endl;
    cout<<"Data Array After Sorting utilizing the Index Array"<<endl;
    array1D.prntAry(perLine);
    
    //Clean up the code, close files, deallocate memory, etc....
    
    //Exit stage right
    return 0;
}