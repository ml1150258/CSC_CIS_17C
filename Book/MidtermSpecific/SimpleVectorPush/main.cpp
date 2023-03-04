/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

//User Libraries
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Test an object
    Object a(3),b(4);
    cout<<"One of the Objects"<<a;
    //Test an object by populating the simple vector and print
    SimpleVector<Object> svp(a);
    cout<<"Simple Vector Object Initialization"<<svp[svp.size()-1];
    //Push an Object and printout the last object
    svp.push(b);
    cout<<"Simple Vector Push next object"<<svp[svp.size()-1];
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //print the last one
    for(int i=0;i<100;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    cout<<"Size of the Simple Vector = "<<svp.size()<<endl;
    cout<<"The last object in the Vector is "<<endl;
    cout<<svp[svp.size()-1];
    //Create another simple by copy constructor
    SimpleVector<Object> csvp(svp);
    cout<<"Size of the Copy Constructed Simple Vector = "<<csvp.size()<<endl;
    cout<<"The last object in the Vector is "<<endl;
    cout<<csvp[csvp.size()-1];
    //Utilize a simple integer Simple Vector
    int size=15;
    SimpleVector<Object> svi(size);
    cout<<"Size of this vector = "<<svi.size()<<endl;
    cout<<"Last 2 Objects of the Simple Vector"<<endl;
    cout<<"The size = "<<svi.size()<<endl<<svi[svi.size()-2]
                                         <<svi[svi.size()-1];
    //Exit
    return 0;
}