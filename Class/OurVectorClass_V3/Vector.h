/* 
 * File:   Vector.h
 * Author: mlehr
 * Created on November 3, 2021, 1:54 PM
 * Purpose:  Class Specification
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Vector{
    private:
        int size;
        T *data;
    public:
        Vector(int);
        ~Vector();
        void sort();
        void display(int);
};

template <class T>
Vector<T>::Vector(int n){
    //Allocate the data
    size=(n>=2 && n<=1000)?n:2;
    data=new T[size];
    //Fill the array
    for(int i=0;i<size;i++){
        data[i]=rand()%26+65;//[65,91]
    }
}

template <class T>
Vector<T>::~Vector(){
    delete []data;
}
       
template <class T>
void Vector<T>::sort(){
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

template <class T>
void Vector<T>::display(int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}


#endif /* VECTOR_H */

