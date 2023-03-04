/* 
 * File:   Table.h
 * Author: Dr. Mark E. Lehr
 * Created on Feb 25th, 2020, 8:54 AM
 * Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"

class Table:public AbsTabl{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        int getData(int,int)const;
        void setData(int,int,int);
};

#endif	/* TABLE_H */