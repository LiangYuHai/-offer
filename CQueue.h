//
// Created by Administrator on 2019/12/4 0004.
//

#ifndef JZOFFER_CQUEUE_H
#define JZOFFER_CQUEUE_H
#include <stack>

template <typename T> class CQueue{
public:
    CQueue(){};
    ~CQueue(){};
    void appendTail(T);
    T deleteHead();

private:
    std::stack<T> s1;
    std::stack<T> s2;
};

#endif //JZOFFER_CQUEUE_H
