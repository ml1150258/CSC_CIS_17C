/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 21st, 2022, 11:25 AM
 * Purpose:  Operational Analysis
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
int Ob=0,Oi=0,Oj=0,POs=0;

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void markSrt(int [],int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    const int SIZE=3200;
    int array[SIZE];
    
    //Initialize variables here
    fillAry(array,SIZE);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    //cout<<"Display the Original Random Array"<<endl;
    //prntAry(array,SIZE,5);
    
    //Testing the memory swap function
    markSrt(array,SIZE);
    
    //Display the results
    //cout<<"Apply a loop on smallest in the list n times = Mark Sort"<<endl;
    //prntAry(array,SIZE,5);
    cout<<"Operational analysis of Mark Sort"<<endl;
    cout<<"With "<<SIZE<<" elements to sort"<<endl;
    cout<<"Operations Before any loops = "<<Ob<<endl;
    cout<<"Operations In First Loop    = "<<Oi<<endl;
    cout<<"Operations In Second Loop   = "<<Oj<<endl;
    cout<<"Operations In Swap          = "<<POs<<endl;
    cout<<"Total Operations            = "<<Ob+Oi+Oj+POs<<endl;
    

    //Exit stage left
    return 0;
}

void markSrt(int a[],int n){
    Ob+=1;
    for(int i=0;i<n-1;i++){//Works on each position in the list
        Oi+=5;
        for(int j=i+1;j<n;j++){//Compare and swap with lower elements in the ljst
            Oj+=5;
            if(a[i]>a[j]){//Swap
                POs+=15;
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()*rand();
    }
}