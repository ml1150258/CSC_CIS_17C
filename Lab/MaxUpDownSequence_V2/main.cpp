/*
    Author: Dr. Mark E. Lehr
    Date:   May 20th, 2021  10:07am
    Purpose:Pigeon Application counting up/down sequences
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //Library using random numbers
#include <ctime>       //Time Library
#include <iomanip>     //Format Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void fillAry(int [],int,bool=false);    //[1-N] Fill Sequence
void fillAry(int [],int,int,int,bool=false);//MN Sequence
void prntAry(int [],int);               //Print Individual Sequence
void shuffle(int [],int);               //Randomize Sequence
void filUpDn(int [],int [],int [],int); //Increasing/Decreasing Sequence Fill
void prntAll(int [],int [],int [],int); //Print the combined arrays
int   maxSeq(int [],int);               //Simple max
int   minSeq(int [],int);               //Simple min
int  mxSubSq(int [],int,int,bool);      //Dynamic Incremental Program
void simPltY(int,int,int[],int);        //Simple Y plot
void smPltXY(int,int,int[],int [],int); //Simple XY plot

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    
    //Declare variables
    const int SIZE=500000/3;//Maximum Size of the 3 arrays
    int sequence[SIZE]={};  //Arrays initialized to 0
    int up[SIZE]={};        //Arrays initialized to 0
    int down[SIZE]={};      //Arrays initialized to 0
    int L;                  //Sequence length
    int mu,delta,d;         //Subsequence length
    
    //Initialize variables
    mu=5;                   
    delta=5;
    d=0;
    L=mu*delta+d;
 
    //Fill the Sequence
    //fillAry(sequence,L);
    fillAry(sequence,mu,delta,d,true);
    
    //Process, map inputs to outputs
    //shuffle(sequence,L);
    //Fill the Up/Down Parallel arrays
    for(int i=0;i<L;i++){
        up[i]   = mxSubSq(sequence,i,L,true);
        down[i] = mxSubSq(sequence,i,L,false);
    }
    
    //Output the results
    cout<<"The Parallel Arrays"<<endl;
    prntAll(sequence,down,up,L);
    cout<<"Theory says according to the Pidgeon Hole Principle"<<endl;
    cout<<"Sequence Length <= Max of Decreasing * Max of Increasing Sequence Length"<<endl;
    int maxsequ=maxSeq(up,L);
    int maxseqd=maxSeq(down,L);
    int maxutq=maxsequ*maxseqd;
    cout<<"    "<<L<<" <= "<<maxseqd<<" * "<<maxsequ<<" = "<<maxutq<<endl;
    
    //Plot the data
    simPltY(75,25,sequence,L);
    smPltXY(75,25,sequence,down,L);
    
    //Exit stage right
    return 0;
}

int  maxSeq(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(max<a[i])max=a[i];
    }
    return max;
}
int  minSeq(int a[],int n){
    int min=a[0];
    for(int i=1;i<n;i++){
        if(min>a[i])min=a[i];
    }
    return min;
}

//Dynamic O(n^2) Sequence Count
int mxSubSq(int a[],int strt, int stop,bool isUp) {
    //upDown array to store sub-problem solution. upDown stores the length
    //of the longest increasing/decreasing subsequence ending with aSub[i]
    //which is filled from a[strt+i] to a[stop]
    int n=stop-strt;//Sub sequence array length
    int aSub[n];    //Sub sequence array of a[]
    int upDown[n];  //Increasing/Decreasing length
    //Copy and initialize the arrays
    for(int i=0;i<n;i++){
        aSub[i]=a[strt+i];
        upDown[i]=0;
    }
    int otrMax=0;//Initialize the overall maximum
    
    for(int i= 0; i<n; i++) {
        int max= 0; //This calculates the length of maximum sequence
        
        //Do for each elements in Sub-array aSub[0..i-1]
        for(int j= 0; j< i; j++) {
            // find longest decreasing subsequence that ends with aSub[j]
            // where aSub[j] is more than the current element aSub[i]
            if(isUp){//This segment does the increasing subsequence
                if(aSub[j] < aSub[i]) {
                    if(upDown[j] > max) max = upDown[j];
                }
            }else{  //This segment does the decreasing subsequence
                if(aSub[j] > aSub[i]) {
                    if(upDown[j] > max) max = upDown[j];
                }
            }
        }
        
        //Count of ith element is max Count upto i + 1 (include aSub[i])
        upDown[i]= max + 1;
        
        // to maintain overall LDS of the array
        if(upDown[i] > otrMax) otrMax = upDown[i];
    }
    
    return otrMax;
}

void prntAll(int s[],int u[],int d[],int n){
    cout<<"    Sequence  Decreasing  Increasing"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(10)<<s[i]
            <<setw(10)<<u[i]
            <<setw(10)<<d[i]<<endl;
    }
}

void filUpDn(int a[],int u[],int d[],int n){
    for(int i=0;i<n;i++){
        u[i]=mxSubSq(a,i,n,true);
        d[i]=mxSubSq(a,i,n,false);
    }
}

void shuffle(int a[],int n){
    int rndIndx;
    for(int shuffl=1;shuffl<=7;shuffl++){
        for(int i=0;i<n;i++){
            do{
                rndIndx=rand()%n;
            }while(rndIndx==i);
            int temp=a[i];
            a[i]=a[rndIndx];
            a[rndIndx]=temp;
        }
    }
}

void prntAry(int a[],int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int m,int n,int d,bool invert){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[cnt++]=(i+1)*m-j;
        }
    }
    for(int i=m*n;i<n*m+d;i++){
        a[i]=n*m-i;
    }
    if(invert){
        int half=(n*m+d)/2;
        int end=n*m-1;
        for(int i=0;i<half;i++){
            int temp=a[i];
            a[i]=a[end-i];
            a[end-i]=temp;
        }
    }
}

void fillAry(int a[],int n,bool invert){
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    if(invert){
        int half=n/2;
        int end=n-1;
        for(int i=0;i<half;i++){
            int temp=a[i];
            a[i]=a[end-i];
            a[end-i]=temp;
        }
    }
}

void simPltY(int xd,int yd,int data[],int n){
    //Create a plot surface
    char surf[yd][xd];
    //Initialize the surface
    for(int i=yd-1;i>=0;i--){
        for(int j=0;j<xd;j++){
            surf[i][j]=' ';
        }
    }
    //Fill the boundary frame
    for(int j=0;j<xd;j++){
        surf[0][j]='-';
        surf[yd-1][j]='-';
    }
    for(int i=yd-1;i>=0;i--){
        surf[i][0]='|';
        surf[i][xd-1]='|';
    }
    //Scale the data and fill
    int maxY=maxSeq(data,n);
    int minY=minSeq(data,n);
    for(int j=0;j<n;j++){
        int datay=(data[j]-minY)*(yd-1)/(maxY-minY);
        int datax=j*(xd-1)/(n-1);
        surf[datay][datax]='x';
    }
    //Print the array
    cout<<endl;
    for(int i=yd-1;i>=0;i--){
        for(int j=0;j<xd;j++){
            cout<<surf[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void smPltXY(int xd,int yd,int xData[],int yData[],int n){
    //Create a plot surface
    char surf[yd][xd];
    //Initialize the surface
    for(int i=yd-1;i>=0;i--){
        for(int j=0;j<xd;j++){
            surf[i][j]=' ';
        }
    }
    //Fill the boundary frame
    for(int j=0;j<xd;j++){
        surf[0][j]='-';
        surf[yd-1][j]='-';
    }
    for(int i=yd-1;i>=0;i--){
        surf[i][0]='|';
        surf[i][xd-1]='|';
    }
    //Scale the data and fill
    int maxY=maxSeq(yData,n);
    int minY=minSeq(yData,n);
    int minX=minSeq(xData,n);
    int maxX=maxSeq(xData,n);
    for(int j=0;j<n;j++){
        int datay=(yData[n-j-1]-minY)*(yd-1)/(maxY-minY);
        int datax=(xData[j]-minX)*(xd-1)/(maxX-minX);
        surf[datay][datax]='x';
    }
    //Print the array
    cout<<endl;
    for(int i=yd-1;i>=0;i--){
        for(int j=0;j<xd;j++){
            cout<<surf[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}