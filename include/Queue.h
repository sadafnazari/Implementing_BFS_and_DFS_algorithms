#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue
{
public:
    int queuee[100];
    int n , frontt , rear;
    Queue();
    void Insert(int);
    void Delete();
    void Display();
};


#endif
