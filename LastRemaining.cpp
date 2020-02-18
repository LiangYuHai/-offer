//面试题45 圆圈中最后剩下的数字
// Created by Administrator on 2020/2/18 0018.
//
#include <list>
using namespace std;
int LastRemaining(int n, int m){
    if(n < 1 || m < 1)
        return -1;
    list<int> numbers;
    for(int i = 0; i < n; ++i) numbers.emplace_back(i);
    list<int>::iterator iter = numbers.begin();
    while (numbers.size()>1){
        for(int i = 1; i < m; ++i){
            ++iter;
            if(iter == numbers.end()) iter = numbers.begin();
        }
        list<int>::iterator next = ++iter;
        if(next == numbers.end()) next = numbers.begin();
        numbers.erase(--iter);
        iter = next;
    }
    return *(numbers.begin());
}
