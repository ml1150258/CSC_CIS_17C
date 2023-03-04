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
float powRec(float,int);
float sumCtoi(float,int);
int gcd(int,int);
int bcoef(int,int);
float sumHash(int,int);
int simHash(int,int);
float avgHash(int,int,int);
int linMax(int *,int);
int mrkMax(int *,int,int);
float expRec(float);
double expRec(double);
float sinRec(float);
float cosRec(float);

//Function Prototypes
int *filAray(int);
void prntAry(const int *,int,int);
void markSrt(int *,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    float x=2.0f;
    int n=10,num=210,den=6006;

    
    //Initialize all known variables

    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
 
    
    //Display the Inputs/Outputs
    cout<<"Recursive Pow("<<x<<","<<n
            <<") = "<<powRec(x,n)<<endl;
    cout<<"Non-Recursive Pow("<<x<<","<<n
            <<") = "<<pow(x,n)<<endl;
    cout<<"Recursive sumCtoi("<<x<<","<<n
            <<") = "<<sumCtoi(x,n)<<endl;
    cout<<"Formula sumCtoi = "<<(1-powRec(x,n+1))/(1-x)<<endl;
    int gcdVal=gcd(num,den);
    cout<<"GCD Val = "<<gcdVal<<endl;
    cout<<num<<"/"<<den<<" = "<<num/gcdVal<<"/"<<den/gcdVal<<endl;
    //Pascals Triangle
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<bcoef(i,j)<<" ";
        }
        cout<<endl;
    }
    int nSize=364;
    float c=(1-1.0f/nSize);
    cout<<"Recursive Sum of Hashes("<<nSize<<") = "
            <<sumHash(nSize,nSize)<<endl;
    cout<<"Non-Recursive Sum of Hashes("<<nSize<<") = "
            <<nSize*(1-pow(c,nSize))<<endl;
    cout<<"Simulation Sum of Hashes("<<nSize<<") = "
            <<avgHash(1000000,nSize,nSize)<<endl;
 
    int a[]={1,2,3,4,5,4,3,2,1};
    int b[]={6,5,4,3,4,5,3,2,1};
    int d[]={1,2,3,4,5,6,7,8,9};
    
    cout<<"Max a = "<<mrkMax(a,0,9)<<" = "<<linMax(a,9)<<endl;
    cout<<"Max b = "<<mrkMax(b,0,9)<<" = "<<linMax(b,9)<<endl;
    cout<<"Max d = "<<mrkMax(d,0,9)<<" = "<<linMax(d,9)<<endl;
    
    cout<<fixed<<setprecision(5)<<showpoint;
    for(double w=0.1;w<=1;w+=0.1){
        cout<<"exp("<<w<<")= Math ("<<exp(w)
            <<") float Rec ("<<expRec(static_cast<float>(w))
            <<") double Rec("<<expRec(w)<<")"<<endl;
    }
    
    cout<<endl;
    for(float w=0.1;w<=1;w+=0.1){
        cout<<"sin("<<w<<")= Math ("<<sin(w)
            <<") float Rec ("<<sinRec(static_cast<float>(w))<<")"<<endl;
    }
    
    cout<<endl;
    for(float w=0.1;w<=1;w+=0.1){
        cout<<"cos("<<w<<")= Math ("<<cos(w)
            <<") float Rec ("<<cosRec(static_cast<float>(w))<<")"<<endl;
    }
    
    //Clean up the code, close files, deallocate memory, etc....

    
    //Exit stage right
    return 0;
}

//Function Implementations
float sinRec(float x){
    //Base Condition
    float tol=1e-6f;
    if(abs(x)<tol)return x-x*x*x/6;
    //Recursion
    return 2*sinRec(x/2)*cosRec(x/2);
}

float cosRec(float x){
    //Base Condition
    float tol=1e-6f;
    if(abs(x)<tol)return 1-x*x/2;
    //Recursion
    float a=sinRec(x/2);
    return 1-2*a*a;
}

float expRec(float x){
    //Base Condition
    float tol=1e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursive Call
    float a=expRec(x/2);
    return a*a;
}

double expRec(double x){
    //Base Condition
    double tol=1e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursive Call
    double a=expRec(x/2);
    return a*a;
}

int linMax(int *a,int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(max<a[i])max=a[i];
    }
    return max;
}

int mrkMax(int *a,int beg,int end){
    //Base Case
    if(end-beg<=1)return a[beg];
    //Recursive function
    int half=(beg+end)/2;
    int m1=mrkMax(a,beg,half);
    int m2=mrkMax(a,half,end);
    return m1>m2?m1:m2;
}

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

int bcoef(int n,int j){
    //Base Conditions
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursion
    return bcoef(n-1,j-1)+bcoef(n-1,j);
}

int gcd(int m,int n){
    //Base Condition
    if(m==0)return n;
    //Recursion
    if(m>=n)return gcd(m%n,n);
    return gcd(n%m,m);
}

float sumCtoi(float c,int n){
    //Base Condition
    if(n<=0)return 1;
    //Recursion
    return sumCtoi(c,n-1)+powRec(c,n);
}

float powRec(float x,int n){
    //Base Case
    if(n<=0)return 1;
    //Recursion
    return powRec(x,n-1)*x;
}


void markSrt(int *a,int n){
    //Find the smallest element in List i
    for(int i=0;i<n-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<n;j++){
            //Logic swap
            if(a[i]>a[j]){
                //int temp=a[i];
                //a[i]=a[j];
                //a[j]=temp;
                *(a+i)=*(a+i)^*(a+j);
                *(a+j)=*(a+i)^*(a+j);
                *(a+i)=*(a+i)^*(a+j);
            }
        }
    }
}


void prntAry(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//2 Digit Random Array
    }
    return array;
}