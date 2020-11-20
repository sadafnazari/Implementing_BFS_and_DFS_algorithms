#include "Queue.h"
#include <iostream>

using namespace std;
Queue::Queue()
{
    n = 100;
    frontt = -1;
    rear = -1;
}
void Queue::Insert(int val)
{
    if(rear == n-1)
        cout<<"Queue overflow"<<endl;
    else
    {
        if(frontt == -1)
            frontt = 0;
        rear++;
        queuee[rear] = val;
    }
}
void Queue::Delete()
{
    if(frontt == -1 || frontt > rear)
    {
        cout<<"Queue underflow";
        return;
    }
    else
    {
        frontt++;
    }
}
void Queue::Display()
{
    if(frontt == -1)
        cout<<"Queue is empty"<<endl;
    else
    {
        for(int i= frontt ; i<=rear ; i++)
            cout<<queuee[i]<<endl;
        cout<<endl;
    }
}


