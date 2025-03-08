// yourApp.cpp
#include "yourApp.h"
using namespace std;
Your_filter::Your_filter (ifstream& In,ofstream& Out,char* studentCode,char* courseCode) 
    : in(std::move(In)), out(std::move(Out))
{
    studentin.open(studentCode);
    coursein.open(courseCode);
}
Your_filter::~Your_filter ()
{
    in.close();
    out.close();
    studentin.close();
    coursein.close();
}
void Your_filter::start ()
{
    s temp;
    while (in >> temp.sCode >> temp.cCode >> temp.grade) {
        vec.push_back(temp);
    }
    N = vec.size();
}
int Your_filter::read ()
{
    if (!studentin||!coursein){
        return 0;
    }
    
    sCode.clear();
    sName.clear();
    cCode.clear();
    cName.clear();
    
    string scode, sname, ccode, cname;
    while(studentin >> scode >> sname) {
        sCode.push_back(scode);
        sName.push_back(sname);
    }
    while(coursein >> ccode >> cname) {
        cCode.push_back(ccode);
        cName.push_back(cname);
    }
    
    ii = sCode.size();
    jj = cCode.size();
    return 1;
}
void Your_filter::write ()
{
    out<<N<<" lines translated."<<endl;
    for (int i=0;i<N;i++){
        out<<vec[i].sName<<" "<<vec[i].cName<<" "<<vec[i].grade<<endl;
    }
}
void Your_filter::compute ()
{
    for (int i=0;i<N;i++){
        for (int j=0;j<ii;j++){
            if (vec[i].sCode==sCode[j]){
                vec[i].sName=sName[j];
                break;
            }
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<jj;j++){
            if (vec[i].cCode==cCode[j]){
                vec[i].cName=cName[j];
                break;
            }
        }
    }
}
int Your_filter::result ()
{
    return out.good();
}
