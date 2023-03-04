/* 
 * Author: Dr. Mark E. Lehr
 * Created on Feb 25th, 2020, 8:54 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "PlusTab.h"

//Global Constants

//Function Prototype
void prntTab(const Table &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows=3,cols=4;
   
   //Test out the Tables
   PlusTab tab1(rows,cols);
   PlusTab tab2(tab1);
   PlusTab tab3=tab1+tab2;
   
   //Print the tables
   cout<<"Abstracted and Polymorphic Print Table 1 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab1);
   cout<<"Copy Constructed Table 2 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab2);
   cout<<"Operator Overloaded Table 3 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab3);

   //Exit Stage Right
   return 0;
}

void prntTab(const Table &a){
    cout<<endl;
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(4)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}