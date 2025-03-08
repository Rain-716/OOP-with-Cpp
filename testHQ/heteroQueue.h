#ifndef HETEROQUEUE_H_INCLUDED
#define HETEROQUEUE_H_INCLUDED
#include <iostream>
#include <queue>
using namespace std;
class Base
{
    public:
        virtual void print() const=0;
        virtual ~Base() {};
};
class INT : public Base
{
    private:
        int value;
    public:
        INT (const int i);
        void print() const override;
};
class CHAR : public Base
{
    private:
        char value;
    public:
        CHAR (const char c);
        void print() const override;
};
class PhoneNumber : public Base
{
    private:
        string name;
        long long number;
    public:
        PhoneNumber (const string n=" ",const long long num=0);
        void print() const override;
        friend istream& operator>>(istream& in,PhoneNumber& p);
};
class Hqueue
{
    private:
        queue <Base*> q;
    public:
        //类的私有成员是队列，所以没有写构造和析构函数（狗头）
        void enqueue (Base* obj);
        void dequeue (); //测试程序中dequeue后直接就return 0了，所以看不到dequeue输出的内容，调试可以看到dequeue是能输出内容的
        bool isEmpty () const;
        class bad_op
        {
            public:
                string type;
                bad_op(string s)
                {
                    type=s;
                }     
        };
};
#endif