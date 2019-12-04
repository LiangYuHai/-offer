//
// Created by Administrator on 2019/12/4 0004.
//

#include "CStack.h"

template<typename T> void CStack<T>::appendTail(const T node) {
    if(q2.empty()){
        q1.push(node);
    }
    if(!q2.empty() && q1.empty()){
        q2.push(node);
    }
}

template<typename T> T CStack<T>::deleteNode() {
    if(!q1.empty() && q2.empty()){
        T temp = q1.front();
        q1.pop();
        while(!q1.empty()){
            q2.push(temp);
            temp = q1.front();
            q1.pop();
        }
        return temp;
    }
    if(q1.empty() && !q2.empty()){
        T temp = q2.front();
        q2.pop();
        while(!q2.empty()){
            q1.push(temp);
            temp = q2.front();
            q2.pop();
        }
        return temp;
    }
    else throw new exception("queue is empty.");
}