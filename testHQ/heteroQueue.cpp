#include "heteroQueue.h"
using namespace std;
INT::INT (const int i)
{
    value=i;
}
void INT::print() const
{
    cout<<"INT : "<<value<<endl;
}
CHAR::CHAR (const char c)
{
    value=c;
}
void CHAR::print() const
{
    cout<<"CHAR : "<<value<<endl;
}
PhoneNumber::PhoneNumber (const string n,const long long num)
{
    name=n;
    number=num;
}
void PhoneNumber::print() const
{
    cout<<"PhoneNumber : "<<name<<" "<<number<<endl;
}
istream& operator>>(istream& in,PhoneNumber& p)
{
    in>>p.name>>p.number;
    return in;
}
void Hqueue::enqueue (Base* obj)
{
    q.push(obj);
}
void Hqueue::dequeue()
{
    if (!this->isEmpty()){
        Base* obj=q.front();
        obj->print();
        q.pop();
        delete obj;
    }
    else {
        throw Hqueue::bad_op("Empty");
    }
}
bool Hqueue::isEmpty() const
{
    return q.empty();
}