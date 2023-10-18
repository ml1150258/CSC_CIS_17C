/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 10th, 2023, 11:19 AM
 * Purpose:  Recursive Binomial Coefficient
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Temp for Investigation Global Variable, very bad, Lehr gives F's for this!!!!
//Global variables are always initialized to zero for you
int mem,op;

//Function Prototypes
int bCoeff(int,int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    for(int n=0;n<=8;n++){
        cout<<"n = "<<n<<endl;
        for(int i=0;i<=n;i++){
            op=0,mem=0;
            //cout<<bCoeff(n,i)<<" ";
            bCoeff(n,i);
            cout<<"("<<op<<","<<mem<<") ";
        }
        cout<<endl;
    }

    return 0;
}

int bCoeff(int n,int i){
    //Base Condition
    op++;
    if(i==0){op++;return 1;}
    op++;
    if(i==n){op++;return 1;}
    //Recursion
    mem+=2;
    op+=5;
    return bCoeff(n-1,i-1)+bCoeff(n-1,i);
}