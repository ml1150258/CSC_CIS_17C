/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 11th, 2023, 11:19 AM
 * Purpose:  All Forms Calculated
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>      //Log and Exponential Function
#include <iomanip>    //Format Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
int bCfRec(int,int);     //nCm - Recursive Call
float bCfLog1(int,int);  //nCm - Sum of Log 3 For-Loops
float bCfLog2(int,int);  //nCm - Sum of Log 2 For-Loops
float bCfLog3(int,int);  //nCm - Sum of Log 1 For-Loops
int bCfMem1(int,int);    //nCm - Square Memory 2-D Array
int bCfMem2(int,int);    //nCm - Symmetric Square Memory 2-D Array
int bCfMem3(int,int);    //nCm - Symmetric Triangular Memory 2-D Array
int bCfMem4(int,int);    //nCm - Symmetric 2x1Dim Array
int *bCfMem4(int);       //nCm - Return Entire Row - Symmetric 2x1Dim Array
void prtLine(int *,int); //Print a Line Array
void prntRec(int **,int);//Print a Rectangular Array
void prntTri(int **,int);//Print a Triangular Array


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    
    //Initialize variables here
    int nPower=21;
    nPower=nPower<2?2:nPower;
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<fixed<<setprecision(0);
    cout<<"Pascal's Triangle"<<endl;
    for(int n=0;n<=nPower;n++){
        //cout<<"n = "<<n<<endl;
        for(int i=0;i<=n;i++){
            cout<<bCfLog1(n,i)<<" ";
        }
        cout<<endl;
    }
    
    //Display the results
    int *nCm=bCfMem4(nPower);
    cout<<endl<<nPower<<"Cm"<<endl;
    prtLine(nCm,nPower);
    delete []nCm;

    return 0;
}

void prtLine(int *a,int n){
    for(int i=0;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void prntRec(int **a,int n){
    cout<<endl;
    for(int row=0;row<=n;row++){
        for(int col=0;col<=n;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntTri(int **a,int n){
    cout<<endl;
    for(int row=0;row<=n;row++){
        for(int col=0;col<=row;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int *bCfMem4(int n){
    //Create a dynamic array then delete when done
    int **array=new int*[2];
    for(int row=0;row<2;row++){
        array[row]=new int[n+1];
    }
    //Base Condition
    for(int row=0;row<2;row++){
        for(int col=0;col<=n;col++)
        array[row][col]=1;
    }
    //Recursion and Symmetrical
    bool rowMod2,nrowMod2;
    for(int row=2;row<=n;row++){
        rowMod2=row%2;
        nrowMod2=!rowMod2;
        for(int col=1;col<=row/2;col++){
            array[rowMod2][row-col]=array[rowMod2][col]=array[nrowMod2][col-1]+
                                                        array[nrowMod2][col];
        }
    }
    //Copy then clear memory
    int *nCm=new int[n+1];
    for(int i=0;i<=n;i++){
        nCm[i]=array[rowMod2][i];
    }
    delete []array[rowMod2];
    delete []array[nrowMod2];
    delete []array;
    //Return results
    return nCm;
}

int bCfMem4(int n,int m){
    //Base Condition
    if(m==0)return 1;
    if(m==n)return 1;
    //Create a dynamic array then delete when done
    int **array=new int*[2];
    for(int row=0;row<2;row++){
        array[row]=new int[n+1];
    }
    //Base Condition
    for(int row=0;row<2;row++){
        for(int col=0;col<=n;col++)
        array[row][col]=1;
    }
    //Recursion and Symmetrical
    bool rowMod2,nrowMod2;
    for(int row=2;row<=n;row++){
        rowMod2=row%2;
        nrowMod2=!rowMod2;
        for(int col=1;col<=row/2;col++){
            array[rowMod2][row-col]=array[rowMod2][col]=array[nrowMod2][col-1]+
                                                        array[nrowMod2][col];
        }
    }
    //prntTri(array,n);
    //Before deleting store output
    int arraynm=array[rowMod2][m];
    //clear memory
    for(int row=0;row<2;row++){
        delete []array[row];
    }
    delete []array;
    //Return results
    return arraynm;
}

int bCfMem3(int n,int m){
    //Base Condition
    if(m==0)return 1;
    if(m==n)return 1;
    //Create a dynamic array then delete when done
    int **array=new int*[n+1];
    for(int row=0;row<=n;row++){
        array[row]=new int[row+1];
    }
    //Base Condition
    for(int row=0;row<=n;row++){
        array[row][0]=1;
        array[row][row]=1;
    }
    //Recursion and Symmetrical
    for(int row=2;row<=n;row++){
        for(int col=1;col<=row/2;col++){
            array[row][row-col]=array[row][col]=array[row-1][col-1]+array[row-1][col];
        }
    }
    //prntTri(array,n);
    //Before deleting store output
    int arraynm=array[n][m];
    //clear memory
    for(int row=0;row<=n;row++){
        delete []array[row];
    }
    delete []array;
    //Return results
    return arraynm;
}

int bCfMem2(int n,int m){
    //Base Condition
    if(m==0)return 1;
    if(m==n)return 1;
    //Create a dynamic array then delete when done
    int **array=new int*[n+1];
    for(int row=0;row<=n;row++){
        array[row]=new int[n+1];
    }
    //Base Condition
    for(int row=0;row<=n;row++){
        array[row][0]=1;
        array[row][row]=1;
    }
    //Recursion and Symmetrical
    for(int row=2;row<=n;row++){
        for(int col=1;col<=row/2;col++){
            array[row][col]=array[row-1][col-1]+array[row-1][col];
            array[row][row-col]=array[row][col];
        }
    }
    //prntTri(array,n);
    //Before deleting store output
    int arraynm=array[n][m];
    //clear memory
    for(int row=0;row<=n;row++){
        delete []array[row];
    }
    delete []array;
    //Return results
    return arraynm;
}

int bCfMem1(int n,int m){
    m=m<=n/2?m:n-m;
    //Base Condition
    if(m==0)return 1;
    //if(m==n)return 1;
    //Create a dynamic array then delete when done
    int **array=new int*[n+1];
    for(int row=0;row<=n;row++){
        array[row]=new int[n+1];
    }
    //Base Condition
    for(int row=0;row<=n;row++){
        array[row][0]=1;
        array[row][row]=1;
    }
    //Recursion and Symmetrical
    for(int row=2;row<=n;row++){
        for(int col=1;col<=row;col++){
            array[row][col]=array[row-1][col-1]+array[row-1][col];
        }
    }
    //prntTri(array,n);
    //Before deleting store output
    int arraynm=array[n][m];
    //clear memory
    for(int row=0;row<=n;row++){
        delete []array[row];
    }
    delete []array;
    //Return results
    return arraynm;
}

float bCfLog3(int n,int m){
    //1 Log Sum
    float sum=0;
    //n!/(n-m)!/m! Loop
    for(int i=1;i<=n;i++){
        sum += i<=m     ? -log(i):0;
        sum += i>=n-m+1 ?  log(i):0;
    }
    return exp(sum);
}

float bCfLog2(int n,int m){
    //2 Log Sums
    float sum=0;
    //n!/(n-m)! Loop
    for(int i=n-m+1;i<=n;i++){
        sum+=log(i);
    }
    //m!
    for(int i=1;i<=m;i++){
        sum-=log(i);
    }
    return exp(sum);
}

float bCfLog1(int n,int m){
    //3 Log Sums
    float sum=0;
    //n! Loop
    for(int i=1;i<=n;i++){
        sum+=log(i);
    }
    //(n-m)!
    for(int i=1;i<=n-m;i++){
        sum-=log(i);
    }
    //m!
    for(int i=1;i<=m;i++){
        sum-=log(i);
    }
    return exp(sum);
}

int bCfRec(int n,int i){
    //Base Condition
    if(i==0)return 1;
    if(i==n)return 1;
    //Recursion
    return bCfRec(n-1,i-1)+bCfRec(n-1,i);
}