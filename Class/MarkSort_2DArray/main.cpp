/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Example of Mark Sort using 2D Array
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int **filAray(int,int);
void prntAry(int **,int,int);
void markSrt(int **,int,int,int);
void destroy(int**,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int rows=10;
    int cols=20;
    int colSort=rand()%cols;
    int **array;
    
    //Initialize all known variables
    array=filAray(rows,cols);
    cout<<"Before Sorting on Column "<<colSort<<endl;
    prntAry(array,rows,cols);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    markSrt(array,rows,cols,colSort);
    
    //Display the Inputs/Outputs
    cout<<"After Sorting on Column "<<colSort<<endl;
    prntAry(array,rows,cols);

    //Clean up the code, close files, deallocate memory, etc....
    destroy(array,rows);
    
    //Exit stage right
    return 0;
}

void destroy(int **a,int rows){
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}

//Function Implementations
void markSrt(int **a,int rows,int cols,int colSort ){
    //Find the smallest element in List i
    for(int i=0;i<rows-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<rows;j++){
            //Logic swap
            if(a[i][colSort]>a[j][colSort]){
                for(int k=0;k<cols;k++){
                    a[i][k]=a[i][k]^a[j][k];
                    a[j][k]=a[i][k]^a[j][k];
                    a[i][k]=a[i][k]^a[j][k];
                }
            }
        }
    }
}


void prntAry(int **a,int rows,int cols){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int **filAray(int rows,int cols){
    //Declare and allocate the array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    int **array=new int*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new int[cols];
    }
    //Fill the array
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            *(*(array+row)+col)=rand()%90+10;//2 Digit Random Array
        }
    }
    return array;
}