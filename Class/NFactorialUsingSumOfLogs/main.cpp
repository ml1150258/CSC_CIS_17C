/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 4th, 2023, 11:19 AM
 * Purpose:  Any Factorial
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>      //Math Library for Exp, Pow, Logs, etc......
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    unsigned int n;
    float nFctrl=0;
    
    
    //Initialize variables here
    n=3;
    
    //Map inputs to outputs here, i.e. the process
    for(int i=1;i<=n;i++){
        nFctrl+=log(i);
    }
    
    //Display the results
    int intPwr=nFctrl;           //Integer Power
    float fltFrc=nFctrl-intPwr;  //Decimal/Fraction
    float base10=nFctrl/log(10);   //Convert to base 10
    int iPwr10=base10;
    float fFrc10=base10-iPwr10;
    
    
    cout<<n<<"! = "<<exp(fltFrc)<<" xExp("<<intPwr<<")"<<endl;
    cout<<n<<"! = "<<pow(10,fFrc10)<<" x10^("<<iPwr10<<")"<<endl;
    

    return 0;
}