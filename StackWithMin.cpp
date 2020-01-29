//面试题21. 包含min函数的栈
// Created by Administrator on 2020/1/29 0029.
//

#include "StackWithMin.h"
#include <iostream>
using namespace std;
template <typename T>
void StackWithMin<T>::push(const T &value) {
    data.push(value);
    if(minData.empty() || value < minData.top()){
        minData.push(value);
    }else{
        minData.push(minData.top());
    }
}

template <typename T>
void StackWithMin<T>::pop() {
    if(data.empty() && minData.empty()){
        throw new exception("stack is empty");
    }
    minData.pop();
    data.pop();
}

template <typename T>
T StackWithMin<T>::min() {
    if(data.empty() && minData.empty()){
        throw new exception("stack is empty");
    }
    return minData.top();
}

int main(){
    StackWithMin<int> s;
    s.push(1);
    s.push(2);
    s.push(0);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
}