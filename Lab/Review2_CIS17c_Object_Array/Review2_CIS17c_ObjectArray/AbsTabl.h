/* 
 * Author: Dr. Mark E. Lehr
 * Created on Feb 25th, 2020, 8:54 AM
 * Specification for the abstract Table Class
 */

#ifndef ABSTABL_H
#define	ABSTABL_H

#include "RowAray.h"

class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual int getData(int,int)const = 0;
};

#endif	/* ABSTABL_H */