/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 6th, 2022, 7:55 PM
 * Purpose:  Savings Recursion
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>      //Math Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float recSave(float,float,int);//Recursive Savings
float savings(float,float,int);//For-Loops
float closfrm(float,float,int);//Closed Form Solution

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    float pv,//Present Value in $'s
     intRate,//Interest Rate %
          fv;//Future Value
    int numCmpd;//Number of compounding periods
    
    //Initialize variables here
    pv=100;//$100
    intRate=0.06f;//6%
    numCmpd=12;//Using rule of 72 72/i=n
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Recursion  Solution fv("<<pv<<","<<intRate<<
            ","<<numCmpd<<")=$"<<recSave(pv,intRate,numCmpd)
            <<endl;
    cout<<"For-Loop   Solution fv("<<pv<<","<<intRate<<
            ","<<numCmpd<<")=$"<<savings(pv,intRate,numCmpd)
            <<endl;
    cout<<"Closed Frm Solution fv("<<pv<<","<<intRate<<
            ","<<numCmpd<<")=$"<<closfrm(pv,intRate,numCmpd)
            <<endl;
    
    //Display the results

    return 0;
}

float closfrm(float pv,float i,int n){
    float c=(1+i);
    return pv*pow(c,n);
}

float savings(float pv,float i,int n){
    float c=(1+i);
    float fv=pv;
    for(int j=1;j<=n;j++){
        fv*=c;
    }
    return fv;
}

float recSave(float pv,float i,int n){
    //Base Case
    if(n<=0)return pv;
    //Recursion
    float c=(1+i);
    return c*recSave(pv,i,n-1);
}