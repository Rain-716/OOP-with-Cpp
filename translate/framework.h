// framework.h
#ifndef FRAMEWORK_H_INCLUDED
#define FRAMEWORK_H_INCLUDED
struct Filter
{
    virtual void start () {}
    virtual int read ()=0;
    virtual void write () {}
    virtual void compute () {}
    virtual int result ()=0;
    virtual ~Filter () {}
};
#include "yourApp.h"
int main_loop(Filter* p);
#endif // FRAMEWORK_H_INCLUDED