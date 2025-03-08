#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
class Complex
{
     public:
         Complex(double aa,double bb);
         Complex(double aa);
         void add(Complex& y);
         void show();
     private:
         double a,b;
};
#endif // COMPLEX_H_INCLUDED
