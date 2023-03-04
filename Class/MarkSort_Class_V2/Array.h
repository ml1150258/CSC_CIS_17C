/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 13th, 2021, 2:00 PM
 * Purpose:  Array Class Specification
 * Includes:  Data and Procedural Prototypes
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    public:
        int size;
        int *data;
    public:
        void setSize(int);
        void setData(int,int);
        int  getData(int);
        void destroy();
        void display();
        void filAray(int);
        void markSrt();
};

#endif /* ARRAY_H */

