//面试题21. 包含min函数的栈
// Created by Administrator on 2020/1/29 0029.
//

#ifndef JZOFFER_STACKWITHMIN_H
#define JZOFFER_STACKWITHMIN_H
#include <stack>
template <typename T>
class StackWithMin{
public:
    std::stack<T> data;
    std::stack<T> minData;
    T curMin;
    void push(const T& value);
    void pop();
    T min();
};
#endif //JZOFFER_STACKWITHMIN_H
