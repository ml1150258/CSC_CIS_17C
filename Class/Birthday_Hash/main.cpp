/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 20th, 2021, 6:03 PM
 * Purpose:  Some more complex recursions
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
#include <cmath>     //Math library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Recursive Function
int *filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//2 Digit Random Array
    }
    return array;
}
float sumHash(int,int);
int simHash(int,int);
float avgHash(int,int,int);

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
 
    //Display the Inputs/Outputs
    int nSize=365;//Number of days in the year
    int nStud=365; //Number of students in the class
    float c=(1-1.0f/nSize);
    cout<<"Recursive Sum of Hashes("<<nSize<<") = "
            <<sumHash(nSize,nStud)<<endl;
    cout<<"Non-Recursive Sum of Hashes("<<nSize<<") = "
            <<nSize*(1-pow(c,nStud))<<endl;
    cout<<"Simulation Sum of Hashes("<<nSize<<") = "
            <<avgHash(1000000,nSize,nStud)<<endl;
    //Clean up the code, close files, deallocate memory, etc....

    
    //Exit stage right
    return 0;
}

//Function Implementations
float avgHash(int nloop,int n,int m){
    int sum=0;
    for(int i=0;i<nloop;i++){
        sum+=simHash(n,m);
    }
    return 1.0f*sum/nloop;
}

int simHash(int n,int m){
    //Fill and Initialize array to 0
    int *array=filAray(n);
    for(int i=0;i<n;i++){
        array[i]=0;
    }
    //Randomly hash the array
    for(int i=0;i<m;i++){
        array[rand()%n]=1;
    }
    //Sum the array/hashes
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    delete []array;
    return sum;
}
float sumHash(int n,int m){
    //Base Condition
    if(m<=0)return 0;
    if(m==1)return 1;
    //Recursion
    float c=(1-1.0f/n);
    return c*sumHash(n,m-1)+1;
}