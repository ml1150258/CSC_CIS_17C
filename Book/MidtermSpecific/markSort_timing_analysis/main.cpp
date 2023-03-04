/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Timing Analysis
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Library
#include <ctime>      //Time Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
int *filAray(int);
void destroy(int *);
void prntAry(int *,int,int);
void mrkSort(int *,int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables - Known and Unknown, units, range, description
    int size=25000;
    int *array;
    
    //Initialize Variables
    array=filAray(size);
    
    //Display before sort
    //prntAry(array,size,10);
    
    //Map inputs to outputs -> i.e. process the inputs
    int beg=time(0);
    mrkSort(array,size);
    int end=time(0);
    cout<<"For N="<<size<<" Mark Sort Takes "
        <<end-beg<<" Seconds"<<endl;
    
    //Display the outputs
    //prntAry(array,size,10);
    
    //Clean up - File closing, memory deallocation, etc....
    destroy(array);

    //Exit Stage Right!
    return 0;
}

void mrkSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void destroy(int *a){
    delete []a;
}

//Function Implementations
int *filAray(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand();//[10-99]
    }
    return array;
}