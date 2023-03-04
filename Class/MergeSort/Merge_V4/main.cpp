/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 2, 2021, 1:19 PM
 * Purpose: Create a Recursive sort
 *          Apply the merge recursively to sort the array
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int  *fill(int);
void print(int *,int,int);
void merge(int *,int,int,int);
void mrgSort(int *,int,int);
int *combine(int *,int,int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Allocate the arrays
    int n=10,perLine=10;
    int *a=fill(n);
    int *b=fill(3*n);
    int *ab=combine(a,n,b,3*n);
    //Print the arrays
    print(a,n,perLine);
    print(b,3*n,perLine);
    print(ab,4*n,perLine);
    //Merge the arrays then print
    mrgSort(ab,0,4*n);
    print(ab,4*n,perLine);
    //Deallocate data
    delete []a;
    delete []b;
    delete []ab;
    //Exit stage right
    return 0;
}

void mrgSort(int *a,int beg,int end){
    int center=(beg+end)/2;
    if((center-beg)>1)mrgSort(a,beg,center);
    if((end-center)>1)mrgSort(a,center,end);
    merge(a,beg,center,end);
}

void merge(int *hilow,int beg,int nlow,int nhigh){
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge
    int *c=new int[span];  //Allocate Memory
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){
            c[i]=hilow[cnth++];
        }else if(cnth==nhigh){
            c[i]=hilow[cntl++];
        }else if(hilow[cntl]<hilow[cnth]){
            c[i]=hilow[cntl++];
        }else{
            c[i]=hilow[cnth++];
        }
    }
    //Copy back and deallocate memory
    for(int i=0;i<span;i++){
        hilow[beg+i]=c[i];
    }
    delete []c;
}

int *combine(int *a,int na,int *b,int nb){
    //Allocate memory
    int *ab=new int[na+nb];
    //First a
    for(int i=0;i<na;i++){
        ab[i]=a[i];
    }
    //Then b
    for(int i=na;i<na+nb;i++){
        ab[i]=b[i-na];
    }
    //Return the combination
    return ab;
}

void print(int *a,int n,int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fill(int n){
    //Allocate memory
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    return a;
}