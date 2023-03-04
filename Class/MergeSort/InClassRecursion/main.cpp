/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 1st, 2021, 8:27 PM
 * Purpose:  Example Recursion
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const double PI=atan(1)*4;

//Function Prototypes Here
float rExpVal(int,int);
float expVal(int,int);
float rFV(float,float,int);
float nonrFV(float,float,int);
int   bCoeff(int,int);
int   max(int *,int,int);
float rSin(float);
float rCos(float);
double rSin(double);
double rCos(double);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Try the expected value recursion
    cout<<"Loop Expected Value km=64, n=64      = "<<expVal(64,64)<<endl;
    cout<<"Recursive Expected Value km=64, n=64 = "<<rExpVal(64,64)<<endl;
    //Do the future value computations
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Cmath output of future value     -> pv=100, i=0.08, n=9 -> $"
            <<100*pow(1+0.08,9)<<endl;
    cout<<"Loop output of future value      -> pv=100, i=0.08, n=9 -> $"
            <<nonrFV(100,0.08,9)<<endl;
    cout<<"Recursive output of future value -> pv=100, i=0.08, n=9 -> $"
            <<rFV(100,0.08,9)<<endl;
    //Test the recursive binomial coeffcient i.e. combination
    cout<<"Combination(5,2) = "<<bCoeff(5,2)<<endl;
    //Output Pascal's Triangle
    for(int r=0;r<=20;r++){
        for(int c=0;c<=r;c++){
            cout<<bCoeff(r,c)<<" ";
        }
        cout<<endl;
    }
    //Test the maximum recursive function by filling an
    //array and finding the max
    int *array=new int[10];
    srand(static_cast<unsigned int>(time(0)));
    cout<<"The array to find the maximum value"<<endl;
    for(int i=0;i<10;i++){
        array[i]=rand()%90+10;
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"The max value = "<<max(array,0,10)<<endl;
    //Test the mutual recursive functions
    cout<<fixed<<setprecision(6)<<showpoint;
    cout<<"The Recursive sin of PI/4 = 45% sqrt(2)/2 = "<<rSin(PI/4)<<endl;
    cout<<"The Recursive cos of PI/4 = 45% sqrt(2)/2 = "<<rCos(PI/4)<<endl;
    cout<<"The Math Lib  sin of PI/4 = 45% sqrt(2)/2 = "<<sin(PI/4)<<endl;
    cout<<"The Math Lib  cos of PI/4 = 45% sqrt(2)/2 = "<<cos(PI/4)<<endl;
    cout<<"As a check sqrt(2)/2 = "<<sqrt(2)/2<<endl;
    //Exit
    delete []array;
    return 0;
}

double rSin(double angle){
    //Base condition
    if(abs(angle)<0.000001)return angle-angle*angle*angle/6;
    //Recursion
    return 2*rSin(angle/2)*rCos(angle/2);
}

double rCos(double angle){
    //Base condition
    if(abs(angle)<0.000001)return 1-angle*angle/2;
    //Recursion
    double a=rCos(angle/2);
    double b=rSin(angle/2);
    return a*a-b*b;
}


float rSin(float angle){
    //Base condition
    if(abs(angle)<0.000001)return angle-angle*angle*angle/6;
    //Recursion
    return 2*rSin(angle/2)*rCos(angle/2);
}

float rCos(float angle){
    //Base condition
    if(abs(angle)<0.000001)return 1-angle*angle/2;
    //Recursion
    float a=rCos(angle/2);
    float b=rSin(angle/2);
    return a*a-b*b;
}

int   max(int *a,int beg,int end){
    //Base condition
    if(end-beg<=1)return a[beg];
    //Recursion
    int half=(end+beg)/2;
    int m1=max(a,beg,half);
    int m2=max(a,half,end);
    return(m1>m2?m1:m2);
}

int   bCoeff(int r,int c){
    //Base Conditions
    if(c==0)return 1;
    if(r==c)return 1;
    //Recursion
    return bCoeff(r-1,c-1)+bCoeff(r-1,c);
}

float expVal(int km,int n){
    //Base Condtion
    if(km<=0)return 0;
    float sum=0;
    //Loop to solve the recursion
    for(int i=1;i<=km;i++){
        sum*=(1-1.0f/n);
        sum+=1;
    }
    return sum;
}

float rExpVal(int km,int n){
    //Base Condition
    if(km<=0)return 0;
    if(km==1)return 1;
    //Recursion
    return 1+rExpVal(km-1,n)*(1-1.0f/n);
}

float rFV(float pv,float i,int n){
    //Base Condition
    if(n<=0)return pv;
    return rFV(pv,i,n-1)*(1+i);
}

float nonrFV(float pv,float i,int n){
    //Base Condition
    float fv=pv;
    //Loop
    for(int j=1;j<=n;j++){
        fv*=(1+i);
    }
    return fv;
}