/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs in CSC/CIS 5
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int cnt=0;
    int delt=1;
    
    //Initialize variables here
    for(int time=0;time<=60*60;time+=delt){
        if(time%15==0)cnt++;
        if(time%60==0&&time!=0)cnt--;
        if(time%120==0&&time!=0)cnt--;
        if(time%80==0&&time!=0)cnt--;
        if(time%10==0)cout<<time<<" "<<cnt<<endl;
    }
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results

    return 0;
}