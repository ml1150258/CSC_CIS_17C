/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 21st, 2021, 11:51 AM
 * Purpose: Pascal Triangle
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
int bCoeff(int,int);//Recursive Binomial Coefficent

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n,j;
    
    //Initialize Variables
    n=12;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Factorial with a for-loop  "<<n<<"! = "<<factFor(n)<<endl;
    cout<<"Factorial with a Recursion "<<n<<"! = "<<factRec(n)<<endl;
    
    //Display the outputs
    cout<<"Pascal's Triangle"<<endl;
    for(int n=0;n<=12;n++){
        for(int j=0;j<=n;j++){
            cout<<bCoeff(n,j)<<" ";
        }
        cout<<endl;
    }
    
    //Compare with the factorial Definition
    n=12;
    j=10;
    cout<<"Using Recursion "<<n<<"C"<<j<<" = "<<bCoeff(n,j)<<endl;
    cout<<"Using formula   "<<n<<"C"<<j<<" = "
            <<factRec(n)/(factRec(n-j)*factRec(j))<<endl;
    
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
int bCoeff(int n,int j){
    //Base conditions for the recursion
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursive Form
    return bCoeff(n-1,j-1)+bCoeff(n-1,j);
}

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