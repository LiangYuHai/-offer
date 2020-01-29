//面试17 合并两个有序链表
// Created by Administrator on 2020/1/28 0028.
//

#include <iostream>
#include "List.h"
using namespace std;

ListNode* Merge(ListNode* head1, ListNode* head2){
    if(!head2) return head1;
    else if(!head1) return head2;
    ListNode* dummyHead = new ListNode(-1);
    ListNode* p = dummyHead;
    while(head1 && head2){
        if(head1->val < head2->val){
            p->next = head1;
            p = p->next;
            head1 = head1->next;
        }else{
            p->next = head2;
            p = p->next;
            head2 = head2->next;
        }
    }
    if(!head1){
        p->next = head2;
    }
    if(!head2){
        p->next = head1;
    }
    return dummyHead->next;
}