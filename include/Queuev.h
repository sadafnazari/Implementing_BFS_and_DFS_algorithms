#ifndef QUEUEV_H
#define QUEUEV_H
#include <iostream>
#include "Queue.h"
#include <vector>
using namespace std;

class Queuev
{
public:
    vector<vector<int> > queueev;
    int n , frontt , rear;
    Queuev();
    void Insert(vector<int>);
    void Delete();
    void Display();
};

#endif // QUEUEV_H
