#include "Queuee.h"
#include <iostream>

using namespace std;
Queuee::Queuee()
{
    n = 100;
    frontt = -1;
    rear = -1;
}
void Queuee::Insert(int val)
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
void Queuee::Delete()
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
void Queuee::Display()
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


