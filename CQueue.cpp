//
// Created by Administrator on 2019/12/4 0004.
//

#include "CQueue.h"

template<typename T> void CQueue<T>::appendTail(const T node) {
    s1.push(node);
}

template<typename T> T CQueue<T>::deleteHead() {
    if(s2.empty()){
        while (!s1.empty()) {
            T temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
    }

    if (s2.empty()) throw new exception("queue is empty.");
    else {
        T temp = s2.top();
        s2.pop();
        return temp;
    }
}