#include "Queuev.h"
#include <iostream>
#include "Queue.h"
#include <vector>
using namespace std;
Queuev::Queuev()
{
    n = 100;
    frontt = -1;
    rear = -1;
}
void Queuev::Insert(vector<int> val)
{
    if(rear == n-1)
        cout<<"Queue overflow"<<endl;
    else
    {
        if(frontt == -1)
            frontt = 0;
        rear++;
        queueev[rear] = val;
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
void Queuev::Display()
{
    if(frontt == -1)
        cout<<"Queue is empty"<<endl;
    else
    {
        for(int i= frontt ; i<=rear ; i++)
            queueev[i].
        cout<<endl;
    }
}
