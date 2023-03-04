/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 30th, 2020, 7:55 PM
 * Purpose:  Factorial with Log Comparison
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
int fact(int);
void fact(int,int &,float &);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n;
    int pwr10;
    float frac10;
    
    //Initialize Variables
    n=5000;
    
    //Map inputs to outputs -> i.e. process the inputs
    fact(n,pwr10,frac10);
    
    //Display the outputs
    cout<<n<<"! = "<<fact(n)<<endl;
    cout<<n<<"! = "<<frac10<<" x 10^("<<pwr10<<")"<<endl;

    //Exit Stage Right!
    return 0;
}

//Function Implementations

int fact(int n){
    int prod=1;
    for(int i=1;i<=n;i++){
        prod*=i;
    }
    return prod;
}
void fact(int n,int &pwr10,float &frac10){
    double sumLog=0;
    for(int i=1;i<=n;i++){
        sumLog+=log(i);//Natural Log
    }
    sumLog/=log(10);//Convert to Base 10
    pwr10=sumLog;//Take the integer as the power of 10
    frac10=pow(10,sumLog-pwr10);
}