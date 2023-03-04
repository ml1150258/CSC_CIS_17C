/* 
 * Author: Dr. Mark E. Lehr
 * Created on March 5th, 2020, 8:54 AM
 * Purpose:  Templated aggregates
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Table.h"

//Global Constants

//Function Prototype
template<class T>
void prntRow(RowAray<T> *,int);
template<class T>
void prntTab(const Table<T> &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows=3,cols=4;
   
   //Test out the Row with integers and floats
   RowAray<int> a(3);RowAray<float> b(4);
   cout<<"Test the Integer Row "<<endl;
   prntRow(&a,3);
   cout<<"Test the Float Row "<<endl;
   prntRow(&b,4);
   
   //Test out the Table with a float
   Table<float> tab1(rows,cols);
   Table<float> tab2(tab1);
   Table<float> tab3=tab1+tab2;
   
   cout<<"Float Table 1 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab1);
   
   cout<<"Float Table 2 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab2);
   
   cout<<"Float Table 3 size is [row,col] = Table 1 + Table 2 ["
           <<rows<<","<<cols<<"]";
   prntTab(tab3);
   
   //Exit Stage Right
   return 0;
}

template<class T>
void prntRow(RowAray<T> *a,int perLine){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

template<class T>
void prntTab(const Table<T> &a){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(8)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}