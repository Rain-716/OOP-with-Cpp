#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;
Queue::Queue (int c)
{
    capacity=c;
    Size=0;
    start=new int[capacity];
    head=start;
    tail=start-1;
}
Queue::~Queue ()
{
    if (!this->isEmpty()){
        delete [] start;
    }
    start=nullptr;
    head=nullptr;
    tail=nullptr;
}
void Queue::enqueue(const int elem)
{
    if (this->isFull()){
        throw bad_op("Full");
    }
    tail=start+(tail-start+1)%capacity;
    *tail=elem;
    Size++;
}
int Queue::dequeue()
{
    if (this->isEmpty()){
        throw bad_op("Empty");
    }
    int result=*head;
    head=start+(head-start+1)%capacity;
    Size--;
    return result;
}
int Queue::peek() const
{
    if (this->isEmpty()){
        throw bad_op("Empty");
    }
    return *head;
}
bool Queue::isEmpty() const
{
    return Size==0;
}
bool Queue::isFull() const
{
    return Size==capacity;
}
int Queue::size() const
{
    return Size;
}
Queue& Queue::operator=(const Queue &q)
{
    if (this!=&q){
        delete [] start;
        start=nullptr;
        head=nullptr;
        tail=nullptr;
        capacity=q.capacity;
        Size=q.Size;
        start=new int[capacity];
        head=start+(q.head-q.start)%q.capacity;
        tail=head+(q.tail-q.head)%q.capacity;
        for (int i=0;i<Size;i++){
            start[start-head+i]=q.start[q.start-q.head+i];
        }
    }
    return *this;
}
