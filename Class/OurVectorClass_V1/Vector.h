/* 
 * File:   Vector.h
 * Author: mlehr
 * Created on November 3, 2021, 1:54 PM
 * Purpose:  Class Specification
 */

#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    private:
        int size;
        int *data;
    public:
        Vector(int);
        ~Vector();
        void sort();
        void display(int);
};


#endif /* VECTOR_H */

