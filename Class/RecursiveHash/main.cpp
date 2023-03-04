/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 27th, 2022, 8:30 PM
 * Purpose:  Develop a Template to be copied
 *           for all future programs in CSC/CIS 5
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random Number Generator
#include <ctime>      //Time Array
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float pwrRec(float,int);
float recHash(int,int);
float clsFrm(int,int);
int   simHash(int,int);
float avgHash(int,int,int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    float m,n,nTrials;
    
    //Initialize variables here
    n=365;
    m=n;
    nTrials=1000000;
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Recursive  Hash("<<m<<","<<n<<")="<<recHash(m,n)<<endl;
    cout<<"Cls Form   Hash("<<m<<","<<n<<")="<<clsFrm(m,n)<<endl;
    cout<<"Simulated  Hash("<<m<<","<<n<<")="<<avgHash(m,n,nTrials)<<endl;
    
    //Display the results

    return 0;
}

float avgHash(int m,int n,int nTrials){
    int sum=0;
    for(int i=1;i<=nTrials;i++){
        sum+=simHash(m,n);
    }
    return 1.0f*sum/nTrials;
}

int simHash(int m,int n){
    //Size and Initialize an array
    char days[n];
    for(int i=0;i<n;i++){
        days[i]=0;
    }
    //Hash or randomly choose days to occupy
    for(int i=0;i<m;i++){
        days[rand()%n]=1;
    }
    //Sum the elements in the array
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=days[i];
    }
    return sum;
}

float recHash(int m,int n){
    //Base Condition
    if(m<=0)return 0;
    if(m==1)return 1;
    //Recursive
    float c=1-1.0f/n;
    return c*recHash(m-1,n)+1;
}

float pwrRec(float c,int n){
    //Base Condition
    if(n<=0)return 1;
    if(n==1)return c;
    //Recursion
    return pwrRec(c,n-1)*c;
}


float clsFrm(int m,int n){
    float c=1-1.0f/n;
    return n*(1-pwrRec(c,m));
}