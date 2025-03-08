// framework.cpp
#include <iostream>
#include <fstream>
#include "framework.h"
using namespace std;
int main_loop(Filter* p)
{
    p->start();
    while (p->read())
    {
        p->compute();
        p->write();
    }
    return p->result();
}