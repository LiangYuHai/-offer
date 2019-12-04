//Liang Yuhai
// Created by Administrator on 2019/12/4 0004.
//双栈实现队列，双队列实现栈

#include <iostream>
#include "CQueue.h"
#include "CStack.h"
using namespace std;


int main(){

    //=======双栈实现队列测试=========
    CQueue<int> q;
    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;//队列已空，输出错误信息

    //============双队列实现栈测试=============
    CStack<int> s;
    s.appendTail(1);
    s.appendTail(2);
    s.appendTail(3);
    cout << s.deleteNode() <<endl;
    cout << s.deleteNode() <<endl;
    cout << s.deleteNode() <<endl;
    cout << s.deleteNode() <<endl;//已空
    return 0;
}

