/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 29th, 2021, 11:12 AM
 * Purpose:  Euclid Greatest Common Divisor
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
int gcd(int,int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int num,//Integer Numerator of a rational number
        den,//Integer Denominator of a rational number
    calcGCD;//Greatest common divisor
    float rationl;//The Rational Number
    
    //Initialize Variables
    num=6510;
    den=4845;
    rationl=static_cast<float>(num)/den;
    
    //Display the inputs
    cout<<rationl<<" = "<<num<<" / "<<den<<endl;
    
    //Map inputs to outputs -> i.e. process the inputs
    calcGCD=gcd(num,den);
    num/=calcGCD;
    den/=calcGCD;
    rationl=static_cast<float>(num)/den;

    //Display the outputs
    cout<<"The greatest common divisor = "<<calcGCD<<endl;
    cout<<rationl<<" = "<<num<<" / "<<den<<endl;
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
int gcd(int m,int n){
    if(m==0)return n;
    if(n==0)return m;
    return m<=n?gcd(n%m,m):gcd(m%n,n);
}