/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 27th, 2022, 7:30 PM
 * Purpose:  Mutual Recursion
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>      //Math Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float recSin(float);//Recursive Sin
float recCos(float);//Recursive Cos

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    float x;
    
    //Initialize variables here
    x=0.1;//1 Radian
    
    //Display the results
    cout<<"Math Library Sin("<<x<<")="<<sin(x)<<endl;
    cout<<"Recursive    Sin("<<x<<")="<<recSin(x)<<endl;
    cout<<"Math Library Cos("<<x<<")="<<cos(x)<<endl;
    cout<<"Recursive    Cos("<<x<<")="<<recCos(x)<<endl;

    return 0;
}

float recSin(float angRad){
    //Base Condition
    float halfAng=angRad/2;
    float tol=1e-6f;//1 part in a million
    if(abs(angRad)<tol)
        return angRad-angRad*angRad*angRad/6;
    //Recursive Return
    return 2*recSin(halfAng)*recCos(halfAng);
}

float recCos(float angRad){
    //Base Condition
    float halfAng=angRad/2;
    float tol=1e-6f;//1 part in a million
    if(abs(angRad)<tol)
        return 1-angRad*angRad/2;
    //Recursive Return
    float a=recCos(halfAng);
    float b=recSin(halfAng);
    return a*a-b*b;

}