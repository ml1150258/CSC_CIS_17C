/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 10th, 2021, 1:20 PM
 * Purpose:  Operational Analysis
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function
#include <ctime>     //Setting the Random Number Seed
using namespace std;

//User Libraries

//Global Constants
int opeq,oplus,opindx,oprel,opxor,optot,opmin;

//Math, Science, Universal, Conversions, High Dimensioned Arrays
void fillAry(int [],int);
void prntAry(int [],int,int);
void markSort(int [],int);

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=400;//Size of the Array
    int array[SIZE];   //Array
    
    //Initialize Variables
    fillAry(array,SIZE);
    //prntAry(array,SIZE,5);
    
    //Map Inputs to Outputs -> Process
    markSort(array,SIZE);
    
    cout<<"Number ops = "<<optot<<endl;
        
    //Display Inputs/Outputs
    //prntAry(array,SIZE,5);
    
    //Exit the Program - Cleanup
    return 0;
}

void markSort(int a[],int n){
    optot+=3;opeq++;opmin++;oprel++;
    for(int i=0;i<n-1;i++){      //Loop for each position in List
        optot+=4;opeq++;oprel++;oplus+=2;
        for(int j=i+1;j<n;j++){  //Loop to swap with first in List
            optot+=4;oprel++;opindx+=2;oplus++;
            if(a[i]>a[j]){       //Put the smallest at top of List
                optot+=15;opindx+=9;opxor+=3;opeq+=3;
                a[i]=a[i]^a[j];  //In place Swap
                a[j]=a[i]^a[j];  //In place Swap
                a[i]=a[i]^a[j];  //In place Swap
            }
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand();//[0,2^31-1]
    }
}