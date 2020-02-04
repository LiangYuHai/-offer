//面试题37 找两个链表的第一个共同结点
// Created by Administrator on 2020/2/3 0003.
//

#include <iostream>
#include "List.h"

unsigned int GetListLength(ListNode* head){
    unsigned int length = 0;
    while(head){
        length++;
        head = head -> next;
    }
    return length;
}
ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2){
    if(!head1 || !head2) return nullptr;
    unsigned int length1 = GetListLength(head1);
    unsigned int length2 = GetListLength(head2);
    if(length1 > length2){
        while(length1 > length2){
            head1 = head1->next;
            length1--;
        }
    }
    if(length2 > length1){
        while(length2 > length1){
            head2 = head2->next;
            length2--;
        }
    }
    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}
//O(m+n)
