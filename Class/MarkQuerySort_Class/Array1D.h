/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Array 1D Class Specification
 */

#ifndef ARRAY1D_H
#define ARRAY1D_H

#include "Array.h"

class Array1D{
    private:
        Array *array;
    public:
        Array1D(int);
        ~Array1D(){
            delete []array->data;
            delete []array->indx;
            delete array;
        }
        void prntAry(int);
        void markSrt();
};


#endif /* ARRAY1D_H */

