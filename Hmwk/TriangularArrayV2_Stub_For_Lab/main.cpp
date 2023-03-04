/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 23rd, 2020, 12:15 pM
 * Purpose:  Triangular array
 *           Complete the fillAry & prntAry function
 *           int **fillAry(int *,int);
 *           void  prntAry(int **,int *,int)
 */

//System Libraries Here
#include <iostream>  //I/O Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  mrkRand(int=1<<15-1);     //PSRNG repeating the same sequence
int *fillAry(int);             //Randomly fill a 1-D column array
void prntAry(int *,int);       //Print a 1-D array
void destroy(int **,int *,int);//Deallocate memory
//Modify the following Functions
int**fillAry(int *,int);       //Randomly fill a triangular array
void prntAry(int **,int *,int);//Print a triangular array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int *col;      //Pointer to column array
    int **trangl;  //Pointer to triangular array
    int rowSize;   //Number of Rows in the Array
    
    //Input or initialize values Here
    cout<<"Input the Number of Rows in the Array"<<endl;
    cin>>rowSize;
    col=fillAry(rowSize);       //Dynamic 1-D array,#Columns in each row
    trangl=fillAry(col,rowSize);//Dynamic triangular array

    //Output Located Here
    cout<<"The Column Array Size"<<endl;
    prntAry(col,rowSize);
    cout<<"The Triangular Array"<<endl;
    prntAry(trangl,col,rowSize);

    //Deallocate the array
    destroy(trangl,col,rowSize);
    
    //Exit
    return 0;
}

//Modify this Function for unequal number of columns per row
//Input rows  -> Number of rows
//      col   -> Column array size n with number of columns in each row
//Output
//      array -> 2D Triangular Array/Matrix
int **fillAry(int *col,int rows){
    int **array=new int*[rows];
    for(int i=0;i<rows;i++){
        array[i]=new int[rows];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            array[i][j]=mrkRand()%9+1;//1 Digit numbers [1-9]
        }
    }
    return array;
}

//Modify this Function for unequal number of columns per row
//Input n     -> Number of rows
//      col   -> Column array size n with number of columns in each row
//      array -> 2D Triangular Array/Matrix
void prntAry(int **array,int *col,int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void destroy(int **a,int *c,int n){
    //Delete every row of the triangular array
    for(int i=0;i<n;i++){
        delete a[i];
    }
    //Delete the pointers
    delete []a;
    delete []c;
}

void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=mrkRand()%9+1;//1 Digit numbers [1-9]
    }
    return array;
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}