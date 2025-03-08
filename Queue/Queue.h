#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <string>
using namespace std;
class Queue
{
    private:
        int* head;
        int* tail;
        int* start;
        int capacity,Size;
    public:
        Queue (int c=0);
        ~Queue ();
        void enqueue(const int elem);
        int dequeue();
        int peek() const;
        bool isEmpty() const;
        bool isFull() const;
        int size() const;
        Queue& operator=(const Queue &q);
        struct bad_op
        {
            string s;
            bad_op (string ss)
            {
                s=ss;
            }
        };
};
#endif // QUEUE_H_INCLUDED
