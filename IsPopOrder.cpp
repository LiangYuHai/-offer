//面试题22 栈的压入、弹出序列
// Created by Administrator on 2020/1/30 0030.
//
#include <stack>
using namespace std;
bool isPopOrder(int* pushOrder, int* popOrder, int length){
    if(!pushOrder || !popOrder || length<=0) return false;
    int* curPush = pushOrder;
    int* curPop = popOrder;
    std::stack<int> stackData;
    while(curPop - popOrder < length){
        while(stackData.empty() || stackData.top() != *curPop){
            if(curPush - pushOrder >= length) break;
            stackData.push(*curPush);
            ++curPush;
        }
        if(stackData.top() != *curPop) break;
        stackData.pop();
        ++curPop;
    }
    return stackData.empty() || curPop - popOrder == length;
}