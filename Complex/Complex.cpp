#include <iostream>
#include "Complex.h"
using namespace std;
Complex::Complex(double aa,double bb)
{
    a=aa;b=bb;
}
Complex::Complex(double aa)
{
    a=aa;b=0.0;
}
void Complex::add(Complex& y)
{
    a+=y.a;
    b+=y.b;
}
void Complex::show()
{
    if (a||(!a&&!b)){
        cout<<a;
    }
    if (b>0&&a){
        cout<<"+";
    }
    if (b){
        cout<<b<<"i"<<endl;
    }
}
