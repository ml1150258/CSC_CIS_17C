/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 11th, 2020, 12:36 PM
 * Purpose:  Building an array of Objects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "SimpleObject.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
Simple **fillSmp(int);
void prntSmp(Simple **,int);
void dstrSmp(Simple **,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables and Initialize
    int size=5;
    Simple **simple=fillSmp(size);
    
    //Display the outputs
    prntSmp(simple,size);
    
    //Reallocate Memory
    dstrSmp(simple,size);

    //Exit stage right or left!
    return 0;
}

void dstrSmp(Simple **s,int n){
    for(int i=0;i<n;i++){
        delete s[i];
    }
    delete []s;
}

void prntSmp(Simple **s,int n){
    for(int i=0;i<n;i++){
        cout<<s[i]->getData()<<endl;
    }
}

Simple **fillSmp(int n){
    Simple **simp=new Simple*[n];
    for(int i=0;i<n;i++){
        simp[i]=new Simple(i);
    }
    return simp;
}