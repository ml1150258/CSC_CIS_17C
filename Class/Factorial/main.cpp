/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 7th, 2021, 11:51 AM
 * Purpose: Factorials
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
int factFor(int);//Factorial Product
int factRec(int);//Factorial Recursive 

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n;
    
    //Initialize Variables
    n=10;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Factorial with a for-loop  "<<n<<"! = "<<factFor(n)<<endl;
    cout<<"Factorial with a Recursion "<<n<<"! = "<<factRec(n)<<endl;
    
    //Display the outputs
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations

int factFor(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

int factRec(int n){
    //Base Case
    if(n<=1)return 1;
    //Recursive Representation
    return factRec(n-1)*n;
}