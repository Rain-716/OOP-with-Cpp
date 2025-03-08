#include <iostream>
#include <algorithm>
#include "integerSet.h"
using namespace std;
void integerSet::clear ()
{
    sz=0;
}
unsigned integerSet::size () const
{
    return sz;
}
unsigned integerSet::capacity() const
{
    return cap;
}
bool integerSet::isEmpty() const
{
    return sz==0;
}
void integerSet::print() const
{
    sort(a,a+sz);
    cout<<"{";
    for (unsigned int i=0;i<sz;i++){
        if (i==sz-1){
            cout<<a[sz-1];
            continue;
        }
        cout<<a[i]<<",";
    }
    cout<<"}";
}
bool integerSet::isMember(int n) const
{
    for (unsigned int i=0;i<sz;i++){
        if (a[i]==n){
            return 1;
        }
    }
    return 0;
}
void integerSet::insert(int n)
{
    if (this->isMember(n)){
        return;
    }
    else {
        if (sz==cap){
            throw integerSet::bad_integerSet();
        }
        else {
            a[sz++]=n;
        }
    }
}
integerSet integerSet::setUnion(const integerSet& s) const
{
    integerSet t(sz+s.sz);
    for (unsigned int i=0;i<sz;i++){
        t.insert(a[i]);
    }
    for (unsigned int i=0;i<s.sz;i++){
        t.insert(s.a[i]);
    }
    t.cap=t.sz;
    return t;
}
integerSet integerSet::setIntersection(const integerSet& s) const
{
    integerSet t(min(sz,s.sz));
    for (unsigned int i=0;i<sz;i++){
        if (s.isMember(a[i])){
            t.insert(a[i]);
        }
    }
    t.cap=t.sz;
    return t;
}
integerSet integerSet::setDifference(const integerSet& s) const
{
    integerSet t(sz);
    for (unsigned int i=0;i<sz;i++){
        if (!s.isMember(a[i])){
            t.insert(a[i]);
        }
    }
    t.cap=t.sz;
    return t;
}
integerSet integerSet::setSymmetricdifference(const integerSet& s) const
{
    integerSet t(sz+s.sz),t1(sz),t2(s.sz);
    t1=this->setDifference(s);
    t2=s.setDifference(*this);
    t=t1.setUnion(t2);
    t.cap=t.sz;
    return t;
}
void integerSet::erase(int n)
{
    unsigned int i;
    if (!this->isMember(n)){
        return;
    }
    for (i=0;i<sz;i++){
        if (a[i]==n){
            break;
        }
    }
    for (unsigned int j=i;j<sz-1;j++){
        a[j]=a[j+1];
    }
    sz--;
}
bool integerSet::isSubset(const integerSet& s) const
{
    for (unsigned int i=0;i<s.sz;i++){
        if (!this->isMember(s.a[i])){
            return 0;
        }
    }
    return 1;
}
integerSet& integerSet::operator=(const integerSet& s)
{
    if (this==&s){
        return *this;
    }
    delete[] a;
    cap=s.cap;
    sz=s.sz;
    a=new int[cap];
    for (unsigned int i=0;i<sz;i++){
        a[i]=s.a[i];
    }
    return *this;
}
