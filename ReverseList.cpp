//面试16 反转链表
// Created by Administrator on 2020/1/28 0028.
//
#include <iostream>
#include "List.h"

ListNode* ReverseList(ListNode* head){
    if(!head) return nullptr;
    if(!head->next) return head;
    auto* fast = head;
    ListNode* slow = nullptr;
    while(fast){
        auto* temp = fast;
        fast = fast->next;
        temp->next = slow;
        slow = temp;
    }
    return slow;
}