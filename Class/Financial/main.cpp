/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 18th, 2023, 11:19 AM
 * Purpose:  Financial Solutions
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float addRec(float,float,int);
float addEq(float,float,int);
float addFor(float,float,int);
float mltRec(float,float,int);
float mltEq(float,float,int);
float mltFor(float,float,int);
float powRec(float,int);
float powFor(float,int);
float cmbRec(float,float,float,int);
float cmbEq(float,float,float,int);
float cmbFor(float,float,float,int);


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    float p,d,c;
    int n,i;
    
    //Initialize variables here
    p=100;
    d=10;
    n=50;
    i=6;
    c=(1+i/100.0);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"addRec("<<p<<","<<d<<","<<n<<") = "<<addRec(p,d,n)<<endl;
    cout<<" addEq("<<p<<","<<d<<","<<n<<") = "<<addEq(p,d,n)<<endl;
    cout<<"addFor("<<p<<","<<d<<","<<n<<") = "<<addFor(p,d,n)<<endl;
    cout<<"mltRec("<<p<<","<<c<<","<<n<<") = "<<mltRec(p,c,n)<<endl;
    cout<<" mltEq("<<p<<","<<c<<","<<n<<") = "<<mltEq(p,c,n)<<endl;
    cout<<"mltFor("<<p<<","<<c<<","<<n<<") = "<<mltFor(p,c,n)<<endl;
    p=0;
    d=10000;
    cout<<"cmbRec("<<p<<","<<c<<","<<d<<","<<n<<") = "<<cmbRec(p,c,d,n)<<endl;
    cout<<" cmbEq("<<p<<","<<c<<","<<d<<","<<n<<") = "<<cmbEq(p,c,d,n)<<endl;
    cout<<"cmbFor("<<p<<","<<c<<","<<d<<","<<n<<") = "<<cmbFor(p,c,d,n)<<endl;
            

    return 0;
}

float cmbFor(float p,float c,float d,int n){
    float sum=p;
    for(int i=1;i<=n;i++){
        sum*=c;
        sum+=d;
    }
    return sum;
}
float cmbRec(float p,float c,float d,int n){
    //Base Condition
    if(n==0)return p;
    //Recursion
    return c*cmbRec(p,c,d,n-1)+d;
}
float cmbEq(float p,float c,float d,int n){
    float cton=powRec(c,n);
    return p*cton+d*(1-cton)/(1-c);
}

float mltFor(float p,float c,int n){
    float prod=p;
    for(int i=1;i<=n;i++){
        prod*=c;
    }
    return prod;
}

float mltRec(float p,float c,int n){
    //Base Condition
    if(n<=0)return p;
    //Recursion
    return c*mltRec(p,c,n-1);
}

float powFor(float c,int n){
    float prod=1;
    for(int i=1;i<=n;i++){
        prod*=c;
    }
    return prod;
}

float powRec(float c,int n){
    //Base Condition
    if(n<=1)return c;
    //Recursion
    return c*powRec(c,n-1);
}

float mltEq(float p,float c,int n){
    return p*powRec(c,n);
}

float addFor(float p,float d,int n){
    float sum=p;
    for(int i=1;i<=n;i++){
        sum+=d;
    }
    return sum;
}
float addRec(float p,float d,int n){
    //Base Condition
    if(n<=0)return p;
    //Recursion
    return addRec(p,d,n-1)+d;
}
float addEq(float p,float d,int n){
    return p+n*d;
}