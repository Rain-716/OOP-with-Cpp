#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <string>
using namespace std;
class Matrix
{
    private:
        int* a;
        int row,column;
    public:
        Matrix(int r=1,int c=1);
        ~Matrix();
        int getRows() const;
        int getColumns() const;
        int& operator()(const int r,const int c);
        Matrix(const Matrix& m);
        Matrix& operator=(const Matrix& m);
        Matrix (Matrix&& m);
        Matrix& operator=(Matrix&& m);
        friend ostream& operator<<(ostream& out,const Matrix& m);
        friend Matrix operator+(const Matrix& m1,const Matrix& m2);
        class MatrixException
        {
            public:
                string s;
                MatrixException (string ss)
                {
                    s=ss;
                }
        };
};
#endif // MATRIX_H_INCLUDED