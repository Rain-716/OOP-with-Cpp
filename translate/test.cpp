// test.cpp
#include <iostream>
#include "framework.h"
using namespace std;
int main(int argc,char** argv)
{
    ifstream fin(argv[1]);  // file to be processed
    ofstream fout(argv[2]); // file processed
    if (!fin||!fout) cerr << "Error opening file!" << endl;
    Your_filter f(fin,fout,argv[3],argv[4]);
    return main_loop(&f);
}
// argv[1]: gradeIn File
// argv[2]: gradeOut File
// argv[3]: studentCode File
// argv[4]: courseCode File