/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleObject.h
 * Author: rcc
 *
 * Created on February 20, 2020, 12:54 PM
 */

#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

class Simple{
    private:
        int data;
    public:
        Simple(int d){data=d;};
        int  getData(){return data;};
};

#endif /* SIMPLEOBJECT_H */

