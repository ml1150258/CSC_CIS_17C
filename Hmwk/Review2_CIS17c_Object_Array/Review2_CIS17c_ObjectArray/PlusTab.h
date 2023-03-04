/* 
 * Author: Dr. Mark E. Lehr
 * Created on Feb 25th, 2020, 8:54 AM
 * Specification for the Table addition operator
 */

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"

class PlusTab:public Table{
    public:
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        PlusTab operator+(const PlusTab &);
};

#endif	/* PLUSTAB_H */