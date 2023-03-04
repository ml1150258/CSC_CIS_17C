/*
    Author: Dr. Mark E. Lehr
    Date:   May 18th, 2021  4:12pm
    Purpose:Totient
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <cmath>       //Math Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void eulrPhi(int [],int);//Function that calculates the Totient
void prntAry(int []);    //Print the Relative Array
void clean(int [],int);  //Initialize the Array

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=1000; //Size larger than n for static can be 500,000
    int rlPrime[SIZE]={};//Relative Prime Array
    int n;               //phi(n) where n is max to investigate
    
    //Initialize variables
    n=200;
    
    //Process, map inputs to outputs
    for(int j=2;j<=n;j++){
        eulrPhi(rlPrime,j);//Euler phi(n)

        //Display your initial conditions as well as outputs.
        prntAry(rlPrime);  //Special print to output the sequence
        clean(rlPrime,n);  //Need to clean the array each time
    }
    
    //Exit stage right
    return 0;
}

void clean(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=0;
    }
}

void eulrPhi(int rlPrime[],int n){
    if(n<=1)return;
    rlPrime[0]=n;
    int cnt=n-1;     //1 is always included
    int sqrRel=n/2+1;//Start at 2 but no need to go more than half way
    for(int i=2;i<=sqrRel;i++){
        if(n%i==0){//Eliminate all multiples
            for(int j=i;j<n;j+=i){
                if(rlPrime[j]==0)cnt--;//If the first time marked
                rlPrime[j]=1;//Simply mark by 1
            }
        }
    }
    rlPrime[n]=cnt;
}

void prntAry(int a[]){
    int cnt=1;
    
    cout<<endl<<"phi("<<setw(3)<<a[0]<<") = "
            <<setw(3)<<a[a[0]]<<" elements {";
    for(int i=1;i<=a[0];i++){
        if(a[i]==0&&cnt<a[a[0]]){
            cout<<i<<",";
            cnt++;
        }else if(a[i]==0&&cnt==a[a[0]]){
            cout<<i<<"}"<<endl;
        }
    }
}