//
// Created by Administrator on 2019/12/4 0004.
//

#ifndef JZOFFER_CSTACK_H
#define JZOFFER_CSTACK_H

#include <queue>
using namespace std;


template <typename T> class CStack
{
public:
    CStack(){};
    ~CStack(){};
    void appendTail(T node);
    T deleteNode();

private:
    queue<T> q1;
    queue<T> q2;
};


#endif //JZOFFER_CSTACK_H
