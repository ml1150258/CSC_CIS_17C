/* 
 * File:   Vector.h
 * Author: mlehr
 * Created on November 3, 2021, 1:54 PM
 * Purpose:  Class Specification
 */

#include "Vector.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Vector::Vector(int n){
    //Allocate the data
    size=(n>=2 && n<=1000)?n:2;
    data=new int[size];
    //Fill the array
    for(int i=0;i<size;i++){
        data[i]=rand()%90+10;//[10,99]
    }
}

Vector::~Vector(){
    delete []data;
}
        
void Vector::sort(){
    for(int pos=0;pos<size-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<size;i++){//Compare and swap with lower elements in the list
            if(data[pos]>data[i]){//Swap
                data[pos]=data[pos]^data[i];
                data[i]=data[pos]^data[i];
                data[pos]=data[pos]^data[i];
            }
        }
    }
}
        
void Vector::display(int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}
