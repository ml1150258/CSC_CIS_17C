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
int O,Ps,Os,Oi,Oo;

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
    int size=100;
    int *array;
    
    //Initialize Variables
    array=filAray(size);
    
    //Display before sort
    //prntAry(array,size,10);
    
    //Map inputs to outputs -> i.e. process the inputs
    mrkSort(array,size);
    cout<<"N     = "<<size<<endl;
    cout<<"O     = "<<O<<endl;
    cout<<"Oo    = "<<Oo<<endl;
    cout<<"Oi    = "<<Oi<<endl;
    cout<<"Ps    = "<<Ps<<endl;
    cout<<"Os    = "<<Os<<endl;
    cout<<"Total = "<<O+Oo+Oi+Ps+Os<<endl;
    
    //Display the outputs
    //prntAry(array,size,10);
    
    //Clean up - File closing, memory deallocation, etc....
    destroy(array);

    //Exit Stage Right!
    return 0;
}

void mrkSort(int *a,int n){
    O+=3;
    for(int i=0;i<n-1;i++){
        Oo+=5;
        for(int j=i+1;j<n;j++){
            Oi+=5;
            if(a[i]>a[j]){
                Ps++;
                Os+=15;
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