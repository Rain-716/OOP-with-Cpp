#include <iostream>
#include "matrix.h"
 
using namespace std;
 
void testBasicOperations() {
    Matrix m1(3, 3);
    for (int i = 0; i < 9; ++i) {
        m1(i / 3, i % 3) = i + 1;
    }
 
    Matrix m2 = m1;
    Matrix m3(m1);
 
    Matrix m4;
    m4 = m1;
 
    cout << "Matrix m1:" << endl;
    cout << m1 << endl;
 
    cout << "Matrix m2 (copy constructor):" << endl;
    cout << m2 << endl;
 
    cout << "Matrix m3 (copy assignment):" << endl;
    cout << m3 << endl;
 
    cout << "Matrix m4 (copy assignment after default construction):" << endl;
    cout << m4 << endl;
 
    Matrix m5 = m1 + m2;
    cout << "Matrix m5 (m1 + m2):" << endl;
    cout << m5 << endl;
}
 
void testExceptions() {
    Matrix m1(2, 2);
    m1(1, 1) = 1;
    m1(1, 2) = 2;
    m1(2, 1) = 3;
    m1(2, 2) = 4;
 
    try {
        cout << "Accessing out of range element (row): ";
        cout << m1(3, 1) << endl;
    } catch (const Matrix::MatrixException& e) {
        cout << "Caught exception: " << e.s << endl;
    }
 
    try {
        cout << "Accessing out of range element (column): ";
        cout << m1(1, 3) << endl;
    } catch (const Matrix::MatrixException& e) {
        cout << "Caught exception: " << e.s << endl;
    }
 
    Matrix m2(2, 3);
    Matrix m3(3, 2);
 
    try {
        Matrix m4 = m2 + m3;
    } catch (const Matrix::MatrixException& e) {
        cout << "Caught exception (matrix addition): " << e.s << endl;
    }
}
 
void testMoveSemantics() {
    Matrix m1(3, 3);
    for (int i = 0; i < 9; ++i) {
        m1(i / 3 + 1, i % 3 + 1) = i + 1;
    }
 
    Matrix m2 = move(m1);
    cout << "Matrix m2 after move:" << endl;
    cout << m2 << endl;
 
    // m1 should be in a valid but unspecified state after move
    try {
        cout << "Matrix m1 after move (should not be accessible): ";
        for (int i = 0; i < 9; ++i) {
            cout << m1(i / 3 + 1, i % 3 + 1) << " ";
        }
        cout << endl;
    } catch (const Matrix::MatrixException& e) {
        cout << "Caught exception: " << e.s << endl;
    }
 
    Matrix m3;
    m3 = move(m2);
    cout << "Matrix m3 after move assignment:" << endl;
    cout << m3 << endl;
 
    // m2 should be in a valid but unspecified state after move assignment
    try {
        cout << "Matrix m2 after move assignment (should not be accessible): ";
        for (int i = 0; i < 9; ++i) {
            cout << m2(i / 3 + 1, i % 3 + 1) << " ";
        }
        cout << endl;
    } catch (const Matrix::MatrixException& e) {
        cout << "Caught exception: " << e.s << endl;
    }
}
 
int main() {
    testBasicOperations();
    cout << endl;
    testExceptions();
    cout << endl;
    testMoveSemantics();
 
    return 0;
}