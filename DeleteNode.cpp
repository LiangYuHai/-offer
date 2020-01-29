//面试题13 O（1）复杂度删除链表节点
// Created by Administrator on 2020/1/28 0028.
//

#include "List.h"
#include <iostream>

ListNode* DeleteNode(ListNode* head, ListNode* toDeleteNode){
    if(!head) return nullptr;
    if(!toDeleteNode) return head;
    if(toDeleteNode->next){
        ListNode* pNext = toDeleteNode->next;
        toDeleteNode->val = pNext->val;
        toDeleteNode->next = pNext->next;
        delete pNext;
        return head;
    } else if(head == toDeleteNode){
        delete toDeleteNode;
        head = nullptr;
        return head;
    }else{
        ListNode* p = head;
        while(p->next != toDeleteNode){
            p = p->next;
        }
        p->next = nullptr;
        delete toDeleteNode;
        return head;
    }
}

//时间复杂度[(n-1)*O(1)+O(n)]/n 还是等于O（1）
//它基于一个假设：toDeleteNode存在于链表中，不然仍然要遍历链表时间复杂度度O（n）