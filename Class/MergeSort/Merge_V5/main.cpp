/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 8th, 2021 1:19 PM
 * Purpose: Create a Recursive sort
 *          Speed the process up by creating
 *          a structure with working space
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
struct Data{
    int size;
    int *hilow;
    int *c;
};

//Global Constants

//Function Prototypes
Data *fill(int);
void print(Data *,int);
void merge(Data *,int,int,int);
void mrgSort(Data *,int,int);
void destroy(Data *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the arrays
    int n=100,perLine=10;
    Data *a=fill(n);
    //Print the arrays
    print(a,perLine);
    //Sort the arrays then print
    mrgSort(a,0,a->size);
    print(a,perLine);
    //Deallocate data
    destroy(a);
    //Exit stage right
    return 0;
}

void destroy(Data *a){
    //Deallocate data elements
    delete []a->hilow;
    delete []a->c;
    delete a;
}

void mrgSort(Data *a,int beg,int end){
    int center=(beg+end)/2;
    if((center-beg)>1)mrgSort(a,beg,center);
    if((end-center)>1)mrgSort(a,center,end);
    merge(a,beg,center,end);
}

void merge(Data *a,int beg,int nlow,int nhigh){
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){
            a->c[i]=a->hilow[cnth++];
        }else if(cnth==nhigh){
            a->c[i]=a->hilow[cntl++];
        }else if(a->hilow[cntl]<a->hilow[cnth]){
            a->c[i]=a->hilow[cntl++];
        }else{
            a->c[i]=a->hilow[cnth++];
        }
    }
    //Copy back
    for(int i=0;i<span;i++){
        a->hilow[beg+i]=a->c[i];
    }
}

void print(Data *a,int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->hilow[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Data *fill(int n){
    //Allocate memory
    Data *data=new Data;
    data->size=n;
    data->hilow=new int[n];
    data->c=new int[n];
    for(int i=0;i<n;i++){
        data->hilow[i]=rand()%90+10;
        data->c[i]=0;
    }
    return data;
}