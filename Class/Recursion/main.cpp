/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 13th, 2020
 * Purpose:  Examples of Recursion
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int sumSrs(int,int);                //Recursive Sum C^i
int pow(int,int);                   //Recursive x^y integer
float pow(float,int);               //Recursive x^y power
float sav(float,float,int);         //Recursive p*(1+i)^n
float retRec(float,float,float,int);//Recursive Retirement Function
float ret(float,float,float,int);   //Formulaic Retirement function
float retSav(float,float,float,int);//Retirement function in Savings Form
float expSum(int,int);              //Recursive Expected Value sum
float gcd(int,int);                 //Recursive Greatest Common Denominator
int   bcoeff(int,int);              //Recursive Binomial Coefficient

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    int r,e,n;
    float d,i,p;
    
    //Initialize all known variables
    r=2;        //Rational value for sum of 2 power series
    e=10;       //Exponent of the power series
    n=49;       //Number of compounding periods
    d=10000;    //$ Initial Deposit
    i=5.0f/100; //% Interest Rate
    p=0;        //$ Principal
    
    //Let the Recursion Begin!
    cout<<"Recursive Integer Power "<<r<<"^"<<e<<" = "<<pow(r,e)<<endl<<endl;
    
    cout<<"Recursive Series Sum i=0 to "<<e<<" of "<<r<<"^i"<<" = "
            <<sumSrs(r,e)<<endl;
    cout<<"which should equal Formula = (1-"<<r<<"^"<<e+1<<")/(1-"<<r<<")"
            <<" = "<<(1-pow(r,e+1))/(1-r)<<endl<<endl;
    
    cout<<"Recursive Savings = $"<<d<<"(1+"<<i<<")^"<<n<<" = $"
            <<sav(d,i,n)<<endl<<endl;
    
    cout<<"Formula Retirement                  S"<<n<<"= "<<(1+i)
            <<"*S"<<(n-1)<<"+"<<d<<" = $"<<ret(p,d,i,n)<<endl;
     cout<<"Recursion Retirement                S"<<n<<"= "<<(1+i)
             <<"*S"<<(n-1)<<"+"<<d<<" = $"<<retRec(p,d,i,n)<<endl;
     cout<<"Retirement using Savings Recursion  S"<<n<<"= "<<(1+i)
             <<"*S"<<(n-1)<<"+"<<d<<" = $"<<retSav(p,d,i,n)<<endl<<endl;
     
     //Birthday Problem Expectations
     n=365;//n=365 days
     int m=80;//Number students in the class
     int diffCnt=1;
     cout<<"A group size that would have the same Expected Number of Birthdays"
             <<endl;
     cout<<fixed<<setprecision(2)<<showpoint;
     for(int i=5;i<=m;i++){
         int nBDsame=expSum(i,n)+1;
         if(i-nBDsame==diffCnt){
            cout<<i<<" students -> "<<expSum(i,n)<<" -> "<<diffCnt+1
                    <<" same Birthdays"<<endl;
            diffCnt++;
         }
     }
     
     int num=3*5*11;
     int denom=2*3*7*11;
     int comfact=gcd(denom,num);
     cout<<endl<<"num/denom = "<<num<<"/"<<denom
             <<" = "<<num/comfact<<"/"<<denom/comfact<<endl;
     
     //Create Pascal's Triangle
     int rows=20;
     cout<<"Pascal's Triangle"<<endl;
     for(int row=0;row<=rows;row++){
         int sum=0;
         for(int col=0;col<=row;col++){
             int bc=bcoeff(row,col);
             sum+=bc;
             cout<<bc<<" ";
         }
         cout<<" sum of row = "<<sum<<" = 2^"<<row<<" = "<<pow(2,row)<<endl;
     }
 
    //Exit stage right
    return 0;
}

int   bcoeff(int n,int j){
    //Base Condition
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursive State
    return bcoeff(n-1,j-1)+bcoeff(n-1,j);
}

//Function Implementations
float gcd(int m,int n){
    //Base Case
    if(m==0)return n;
    if(m>=n)return gcd(m%n,n);
    return gcd(n%m,m);
}


float expSum(int m,int n){
    float c=1-1.0f/n;
    return n*(1-pow(c,m));
}

float retSav(float p,float d,float i,int n){
    float ddivi=d/i;
    return sav(p,i,n)+sav(ddivi,i,n)-ddivi;
}

float ret(float p,float d,float i,int n){
    float cton=pow(1.0f+i,n);
    return p*cton+d/i*(cton-1);
}

float retRec(float p,float d,float i,int n){
    //Base Case
    if(n==0)return p;
    //Function defined from itself
    return retRec(p,d,i,n-1)*(1+i)+d;
}

float sav(float d,float intRate,int n){
    //Base Case
    if(n==0)return d;
    //Function defined from itself
    return sav(d,intRate,n-1)*(1+intRate);
}

float pow(float r,int n){
    //Base Case
    if(n==0)return 1;
    //Function defined from itself
    return pow(r,n-1)*r;
}

int pow(int r,int n){
    //Base Case
    if(n==0)return 1;
    //Function defined from itself
    return pow(r,n-1)*r;
}

int sumSrs(int r,int n){
    //Base Case
    if(n==0)return 1;
    //Function defined from itself
    return sumSrs(r,n-1)+pow(r,n);
}