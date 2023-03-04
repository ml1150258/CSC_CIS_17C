/*Dr. Mark E. Lehr
  March 5th, 2020
  Purpose:  Curve fit of Data Structure empirical timing and/or
            operational analysis
*/
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries 
#include "mArray.h"

//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

//Execution begins here
int main(){
    //Declare the Row and Empirical Data files
    char fn_r[]="r.dat";//r file name
    mArray r(fn_r);     //Independent variable, form of the equation
    char fn_f[]="f.dat";//f file name
    mArray f(fn_f);     //Dependent variable, from empirical data run
    
    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt(false,r); //Transpose of independent variable
    mArray temp=rt*f;   //Calculate from right to left more efficient
    mArray c=mArray::invMat(rt*r)*temp;
    
    //Output the results
    char fn_c[]="c.dat";//c file name
    c.mPrint(fn_c);     //Where curve fit coefficients are printed
    
    return 0;
}