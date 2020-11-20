#ifndef QUEUEE_H
#define QUEUEE_H
#include <iostream>
using namespace std;

class Queuee
{
public:
    int queuee[1000];
    int n , frontt , rear;
    Queuee();
    void Insert(int);
    void Delete();
    void Display();
};


#endif
