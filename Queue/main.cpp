#include <iostream>
#include "Queue.h"
#include <string>
using namespace std;
int main()
{
    Queue rq{100002}; // with capacity 100002
    int q;
    cin>>q;
    for (int i=0; i<q; i++)
    {
        try
        {
            string cmd;
            cin>>cmd;
            if(cmd=="enqueue")
            {
                int data;
                cin>>data;
                rq.enqueue(data);
            }
            else if(cmd=="dequeue")
            {
                cout<<rq.dequeue()<<endl;
            }
        }
        catch(Queue::bad_op) // enqueue on full, dequeue on empty
        {
            cout << "Operation Exception" <<endl;
        }
    }
    return 0;
}
