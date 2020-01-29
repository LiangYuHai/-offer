//面试15链表中导数第K个结点
// Created by Administrator on 2020/1/28 0028.
//
#include <iostream>
#include "List.h"
using namespace std;

ListNode* FindKthToTail(ListNode* head, int K){
    if(K <= 0 || !head) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(K){
        fast = fast->next;
        --K;
        if(!fast){
            cout << "the length of the list is shorter than K" << endl;
            return nullptr;
        }
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}