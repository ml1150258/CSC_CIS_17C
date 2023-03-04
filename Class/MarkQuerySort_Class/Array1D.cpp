/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Array 1D Class Implementation
 */

#include <iostream>
using namespace std;
#include "Array1D.h"

//Function Implementations
void Array1D::markSrt(){
    //Find the smallest element in List i
    for(int i=0;i<array->size-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<array->size;j++){
            //Logic swap
            if(array->data[array->indx[i]]>array->data[array->indx[j]]){
                array->indx[i]=array->indx[i]^array->indx[j];
                array->indx[j]=array->indx[i]^array->indx[j];
                array->indx[i]=array->indx[i]^array->indx[j];
            }
        }
    }
}

void Array1D::prntAry(int perLine){
    cout<<endl;
    for(int i=0;i<array->size;i++){
        cout<<array->data[array->indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

    Array1D::Array1D(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    array=new Array;
    array->data=new int[n];
    array->indx=new int[n];
    array->size=n;
    for(int i=0;i<n;i++){
        array->data[i]=rand()%90+10;//2 Digit Random Array
        array->indx[i]=i;
    }
}