// yourApp.h
#ifndef YOURAPP_H_INCLUDED
#define YOURAPP_H_INCLUDED
#include <vector>
#include <fstream>
#include "framework.h"
using namespace std;
class Your_filter : public Filter
{
    private:
        int N,ii,jj;
        struct s
        {
            string sCode,cCode,sName,cName;
            int grade;
        };
        vector <s> vec;
        vector <string> sCode,cCode,sName,cName;
        ifstream in;
        ofstream out;
        ifstream studentin;
        ifstream coursein;
    public:
        Your_filter (ifstream& In,ofstream& Out,char* studentCode,char* courseCode);
        ~Your_filter ();
        void start () override;
        int read () override;
        void write () override;
        void compute () override;
        int result () override;
};
#endif // YOURAPP_H_INCLUDED