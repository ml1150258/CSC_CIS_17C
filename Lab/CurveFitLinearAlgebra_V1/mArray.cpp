//Dr. Mark E. Lehr
//March 5th, 2020
//Quick and Dirty Dynamic Array Class
//Built for speed not error checking
//Know what you are doing or die using it
//The speed mentioned above was not
//speed of execution but speed to code.

//This is the implementation for the
//Mark Array

//Things to do
//  1)  Read in the input file
//           time  current
//  2)  Add in reading the transformation matrix
//  3)  Add in reading start and stop times
//  4)  Output the information as expected
//  5)  Also send to the ftp file


#include "mArray.h"
#include <fstream>
#include <cmath>
using namespace std;

//Constructor from a file
mArray::mArray(char *fn){
    ifstream in;
    in.open(fn);
    double rd,cd;
    in>>rd;
    in>>cd;
    Rows=static_cast<int>(rd);
    Cols=static_cast<int>(cd);
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++){
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
                in>>Data[r][c];
        }
    }
    in.close();
}

//Constructor given rows and cols
//and initialized to zero
mArray::mArray(int rd,int cd){
    Rows=rd;
    Cols=cd;
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++){
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            Data[r][c]=0.0;
        }
    }
}
//Copy constructor
mArray::mArray(const mArray &d){
    Rows=d.Rows;
    Cols=d.Cols;
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++){
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            Data[r][c]=d.Data[r][c];
        }
    }
}
//Copy constructor using array limits
//Also takes the transpose simultaneously
//z==> false take the transpose
//[rb,re]==>Span for rows
//[cb,ce]==>Span for cols
mArray::mArray(bool z,const mArray &d,int rb,int re,int cb,int ce){
    if(z){
        Rows=re-rb+1;
        Cols=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+r][cb+c];
            }
        }
    }else{//with Transpose
        Cols=re-rb+1;
        Rows=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+c][cb+r];
            }
        }
    }
}
//Copy constructor using array limits
//Also takes the transpose simultaneously
//z==> false take the transpose
//[rb,re]==>Span for rows
//[cb,ce]==>Span for cols
mArray::mArray(bool z,const mArray &d){
    int rb=0;
    int re=d.getRows()-1;
    int cb=0;
    int ce=d.getCols()-1;
    if(z){
        Rows=re-rb+1;
        Cols=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+r][cb+c];
            }
        }
    }else{//with Transpose
        Cols=re-rb+1;
        Rows=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++){
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                Data[r][c]=d.Data[rb+c][cb+r];
            }
        }
    }
}
//Destructor
mArray::~mArray(){
    //Delete the columns in all the rows
    //for the 2-Dim Array
    for(int i=0;i<Rows;i++){
        delete []Data[i];
    }

    //Delete all the rows
    //int the array
    delete []Data;
}

//Note the +,- overloading makes an assumption
//on non-equal arrays.  It does this by column
//such that the mod operation is utilized

//Overloaded binary + operator.
//Used for Matrix+Vector additions
//Neural net specific
mArray mArray::operator+(const mArray &right){
    mArray temp(Rows,Cols);
    int m=right.Cols;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            temp.Data[r][c]=Data[r][c]+right.Data[r][c%m];
        }
    }
    return temp;
}
//Overloaded binary - operator.
//Used for Matrix+Vector additions
//Neural net specific
mArray mArray::operator-(const mArray &right){
    mArray temp(Rows,Cols);
    int m=right.Cols;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            temp.Data[r][c]=Data[r][c]-right.Data[r][c%m];
        }
    }
    return temp;
}
//Overloaded binary * operator.
//Typical matrix*matrix multiplication
mArray mArray::operator*(const mArray &right){
    mArray temp(Rows,right.Cols);
    for(int r=0;r<Rows;r++){
        for(int c=0;c<right.Cols;c++){
            for(int k=0;k<Cols;k++){
                    temp.Data[r][c]+=Data[r][k]*right.Data[k][c];
            }
        }
    }
    return temp;
}

//Overloaded equality operator
mArray mArray::operator=(const mArray &right){ 
    Rows=right.Rows;
    Cols=right.Cols;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
                Data[r][c]=right.Data[r][c];
        }
    }
    return *this; 
}

//Neural net activation function
//Note: This is a static function
mArray mArray::logsig(const mArray &a){
    mArray temp(a.Rows,a.Cols);
    for(int r=0;r<a.Rows;r++){
        for(int c=0;c<a.Cols;c++){
                temp.Data[r][c]=1.0/(1.0+exp(-a.Data[r][c]));
        }
    }
    return temp;
}

mArray mArray::invMat(const mArray &m){
    //Allocate memory for the partitioned matrix and the inverse matrix
    mArray a(m.Rows,2*m.Cols);
    mArray mInv(m.Rows,m.Cols);

    //Transfer information to the partitioned matrix
    for(int i=0;i<m.Rows;i++)
        for(int j=0;j<m.Cols;j++)
            a.setData(m.getData(i,j),i,j);
    
    //Fill the right-half of the partitioned matrix with the identity matrix
    for(int i=0;i<a.Rows;i++){
        for(int j=a.Rows;j<a.Cols;j++){
            if(i==j-a.Rows)a.setData(1,i,j);
            else a.setData(0,i,j);
        }
    }
   
    //Calculate the inverse by reducing the 
    for(int i=0;i<a.Rows;i++){
        float t=a.getData(i,i);
        for(int j=i;j<a.Cols;j++)a.setData(a.getData(i,j)/t,i,j);
        for(int j=0;j<a.Rows;j++){
            if(i!=j){
                t=a.getData(j,i);
                for(int k=0;k<a.Cols;k++)
                    a.setData(a.getData(j,k)-t*a.getData(i,k),j,k);
            }
        }
    }
    
    //Transfer the information to the matrix inverse
    for(int i=0;i<m.Rows;i++)
        for(int j=0;j<m.Cols;j++)
            mInv.setData(a.getData(i,j+a.Rows),i,j);

    //Return the allocated inverse matrix
    return mInv;
}

//Sort using an index the content of an array
int *mArray::sort(int c){
    int *indx=new int[Rows];
    for(int i=0;i<Rows;i++){
        indx[i]=i;
    }
    for(int i=0;i<Rows-1;i++){
        for(int j=i;j<Rows;j++){
            if(Data[indx[i]][c]>Data[indx[j]][c]){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    return indx;
}

//Output the matrix or vector to a file
void mArray::mPrint(char *fn){
    ofstream out;
    out.open(fn);
    out<<Rows<<" ";
    out<<Cols<<endl;
    for(int r=0;r<Rows;r++){
        for(int c=0;c<Cols;c++){
            out<<Data[r][c]<<" ";
        }
        out<<endl;
    }
    out.close();
}