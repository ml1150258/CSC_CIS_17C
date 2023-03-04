/* 
 * Author: Dr. Mark E. Lehr
 * Purpose:  Complex object to use in Data-Structures for testing purposes
 *           2D square matrix with operator overloading, Copy Construction
 */

#ifndef OBJECT_H
#define	OBJECT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

class Object{
    private:
        int rowcol;
        int **array;
    public:
        Object(int=0);         //Defaulted constructor
        Object(const Object &);//Copy constructor
        ~Object();             //Destructor
        Object operator=(const Object &);//Overloaded equality operator
        bool operator==(const Object &);
        friend ostream& operator<<(ostream& os,const Object &);
        string toString();     //Sends data to a string
};

//Default Constructor
Object::Object(int rc){
    //Allocate a 2D Array
    rowcol=rc>=2?rc:2;
    array=new int*[rowcol];//Allocate the rows
    for(int r=0;r<rowcol;r++){
        array[r]=new int[rowcol];//Allocate the columns/row
    }
    //Fill with data - 2 digit integers
    for(int r=0;r<rowcol;r++){
        for(int c=0;c<rowcol;c++){
            array[r][c]=rand()%90+10;
        }
    }
}

//Copy Constructor
Object::Object(const Object &d){
    rowcol=d.rowcol;
    //Allocate the array
    array=new int*[rowcol];//Allocate the rows
    for(int r=0;r<rowcol;r++){
        array[r]=new int[rowcol];//Allocate the columns/row
    }
    //Fill with data - 2 digit integers
    for(int r=0;r<rowcol;r++){
        for(int c=0;c<rowcol;c++){
            array[r][c]=d.array[r][c];
        }
    }
}
  
//Destructor
Object::~Object(){
    //Deallocate columns first
    for(int r=0;r<rowcol;r++){
        delete []array[r];//Allocate the columns/row
    }
    //Deallocate the rows
    delete []array;
}

//Overloaded equality operator
Object Object::operator=(const Object &right){ 
    //Deallocate columns first
    for(int r=0;r<rowcol;r++){
        delete []array[r];//Allocate the columns/row
    }
    //Deallocate the rows
    if(array!=0)delete []array;
    //Set the new size
    rowcol=right.rowcol;
    //Allocate the array
    array=new int*[rowcol];//Allocate the rows
    for(int r=0;r<rowcol;r++){
        array[r]=new int[rowcol];//Allocate the columns/row
    }
    //Fill with data - 2 digit integers
    for(int r=0;r<rowcol;r++){
        for(int c=0;c<rowcol;c++){
            array[r][c]=right.array[r][c];
        }
    }
    return *this; 
}

bool Object::operator==(const Object &rhs){
    //Compare each data element
    if(rhs.rowcol!=rowcol)return false;
    for(int r=0;r<rhs.rowcol;r++){
        for(int c=0;c<rhs.rowcol;c++){
            if(array[r][c]!=rhs.array[r][c])return false;
        }
    }
    return true;
}
  
//toString function
string Object::toString(){
    //Create a string and return
    string sacum="",s="";
    stringstream ss;
    //Fill the string with array data
    sacum+='\n';
    for(int r=0;r<rowcol;r++){
        for(int c=0;c<rowcol;c++){
            ss.clear();
            ss<<array[r][c];
            ss>>s;
            sacum+=(s+' ');
        }
        sacum+='\n';
    }
    sacum+='\n';
    return sacum;
}

//Overloading the stream operator
ostream& operator<<(ostream& os,const Object &d){
    os<<endl;
    for(int r=0;r<d.rowcol;r++){
        for(int c=0;c<d.rowcol;c++){
            os<<d.array[r][c]<<" ";
        }
        os<<endl;
    }
    os<<endl;
    return os;
}

#endif	/* OBJECT_H */