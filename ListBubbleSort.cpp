//
// Created by Administrator on 2020/3/11 0011.
//

#include <iostream>
#include "List.h"
using namespace std;

ListNode* ListBubbleSort(ListNode* head){
    if(!head || !head->next) return head;
    int len = 0;
    ListNode* temp = head;
    while(temp){
        ++len;
        temp = temp->next;
    }
    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode* pre = dummyHead;
    for(int i = 1; i < len; ++i){
        bool flag = true;
        for(int j = 0; j < len - i; ++j){
            if(head->val > head->next->val){
                ListNode* temp = head->next;
                head->next = head->next->next;
                temp->next = head;
                pre->next = temp;
                pre = pre->next;
                flag = false;
            }else{
                pre = pre->next;
                head = head->next;
            }
        }
        if(flag) break;
    }
    return dummyHead->next;
}