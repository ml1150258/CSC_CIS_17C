/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Example of Mark Sort
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants
int opeq,opm,opinc,opgt,oplt,opadd,opindx;

//Function Prototypes
int *filAray(int);
void prntAry(const int *,int,int);
void markSrt(int *,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=1600;
    int perLine=10;
    int *array;
    
    //Initialize all known variables
    array=filAray(size);
    //cout<<"Before Sorting"<<endl;
    //prntAry(array,size,perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    markSrt(array,size);
    
    //Display the Inputs/Outputs
    //cout<<"After Sorting"<<endl;
    //prntAry(array,size,perLine);
    cout<<"N = Size to Sort      = "<<size<<endl;
    cout<<"Operator equal        = "<<opeq<<" times"<<endl;
    cout<<"Operator minus        = "<<opm<<" times"<<endl;
    cout<<"Operator less than    = "<<oplt<<" times"<<endl;
    cout<<"Operator ++           = "<<opinc<<" times"<<endl;
    cout<<"Operator add          = "<<opadd<<" times"<<endl;
    cout<<"Operator index        = "<<opindx<<" times"<<endl;
    cout<<"Operator greater than = "<<opgt<<" times"<<endl;
    cout<<"Total Operations      = "
            <<opeq+opm+oplt+opinc+opadd+opindx+opgt<<" times"<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    
    //Exit stage right
    return 0;
}

//Function Implementations
void markSrt(int *a,int n){
    //Find the smallest element in List i
    int nm1=n-1;
    opeq+=2;
    opm+=1;
    for(int i=0;i<nm1;i++){
        oplt+=1;
        opinc+=1;
        //Swap as you go to place the smallest element at the top
        opadd+=1;
        opeq+=1;
        for(int j=i+1;j<n;j++){
            oplt+=1;
            opinc+=1;
            //Logic swap
            opindx+=2;
            opgt+=1;
            if(a[i]>a[j]){
                opeq+=3;
                opindx+=4;
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}


void prntAry(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand();//2 Digit Random Array
    }
    return array;
}