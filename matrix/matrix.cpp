#include <iostream>
#include "matrix.h"
using namespace std;
Matrix::Matrix(int r,int c)
{
    row=r;
    column=c;
    a=new int[r*c];
}
Matrix::~Matrix()
{
    delete [] a;
    a=nullptr;
}
int Matrix::getRows() const
{
    return row;
}
int Matrix::getColumns() const
{
    return column;
}
int& Matrix::operator()(const int r,const int c)
{
    if (r>row){
        throw Matrix::MatrixException("row is out of range");
    }
    if (c>column){
        throw Matrix::MatrixException("column is out of range");
    }
    return a[(r-1)*column+c-1];
}
Matrix::Matrix(const Matrix& m)
{
    row=m.row;
    column=m.column;
    a=new int[row*column];
    for (int i=0;i<row*column;i++){
        a[i]=m.a[i];
    }
}
Matrix& Matrix::operator=(const Matrix& m)
{
    if (this!=&m){
        delete [] a;
        a=nullptr;
        row=m.row;
        column=m.column;
        a=new int[row*column];
        for (int i=0;i<row*column;i++){
            a[i]=m.a[i];
        }
    }
    return *this;
}
Matrix::Matrix (Matrix&& m)
{
    a=m.a;
    row=m.row;
    column=m.column;
    m.a=nullptr;
    m.row=0;
    m.column=0;
}
Matrix& Matrix::operator=(Matrix&& m)
{
    if (this!=&m){
        a=m.a;
        row=m.row;
        column=m.column;
        m.a=nullptr;
        m.row=0;
        m.column=0;
    }
    return *this;
}
ostream& operator<<(ostream& out,const Matrix& m)
{
    for (int i=0;i<m.row*m.column;i++){
        out<<m.a[i];
        if ((i+1)%m.column){
            out<<" ";
        }
        else {
            out<<endl;
        }
    }
    return out;
}
Matrix operator+(const Matrix& m1,const Matrix& m2)
{
    if ((m1.row!=m2.row)||(m1.column!=m2.column)){
        throw Matrix::MatrixException("two matrixes have different shapes");
    }
    Matrix m(m1.row,m1.column);
    for (int i=0;i<m.row*m.column;i++){
        m.a[i]=m1.a[i]+m2.a[i];
    }
    return m;
}