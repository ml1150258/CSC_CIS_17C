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
double recSin(double);//Recursive Sin
double recCos(double);//Recursive Cos

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    float x;
    double y;
    
    //Initialize variables here
    x=y=1;//1 Radian
    
    //Display the results
    cout<<"Accuracy using a float"<<endl;
    cout<<"Math Library Sin("<<x<<")="<<sin(x)<<endl;
    cout<<"Recursive    Sin("<<x<<")="<<recSin(x)<<endl;
    cout<<"Math Library Cos("<<x<<")="<<cos(x)<<endl;
    cout<<"Recursive    Cos("<<x<<")="<<recCos(x)<<endl;
    cout<<"Accuracy using a double"<<endl;
    cout<<"Math Library Sin("<<y<<")="<<sin(y)<<endl;
    cout<<"Recursive    Sin("<<y<<")="<<recSin(y)<<endl;
    cout<<"Math Library Cos("<<y<<")="<<cos(y)<<endl;
    cout<<"Recursive    Cos("<<y<<")="<<recCos(y)<<endl;

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

double recSin(double angRad){
    //Base Condition
    double halfAng=angRad/2;
    double tol=1e-6f;//1 part in a million
    if(abs(angRad)<tol)
        return angRad-angRad*angRad*angRad/6;
    //Recursive Return
    return 2*recSin(halfAng)*recCos(halfAng);
}

double recCos(double angRad){
    //Base Condition
    double halfAng=angRad/2;
    double tol=1e-6f;//1 part in a million
    if(abs(angRad)<tol)
        return 1-angRad*angRad/2;
    //Recursive Return
    double a=recCos(halfAng);
    double b=recSin(halfAng);
    return a*a-b*b;

}