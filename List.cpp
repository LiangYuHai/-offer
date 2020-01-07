//Liang Yuhai
// Created by Administrator on 2019/12/3 0003.
//List Operations

#include "List.h"
#include <iostream>
ListNode* CreateListNode(int value = 0){
    return new ListNode(value);
}

void ConnectListNodes(ListNode* node1, ListNode* node2){
    if(!node1 || !node2) return ;
    node1->next = node2;
}

void PrintListNode(ListNode* node){
    if(!node) return ;
    std::cout << node->val <<std::endl;
}

void PrintList(ListNode* head){
    if(!head) return ;
    while(head->next){
        std::cout << head->val << "-->" ;
        head = head->next;
    }
    std::cout << head->val << std::endl;
}

void DestoryList(ListNode* head){
    ListNode* node = head;
    while(head){
        head = head->next;
        delete node;
        node = head;
    }
}

void AddToTail(ListNode* head, int value){
    if(!head)  {
        head = new ListNode(value);
        return ;
    }
    ListNode* node = head;
    while(node->next){
        node = node->next;
    }
    node->next = new ListNode(value);
}


void InsertListNode(ListNode* head, int iVal, int positionVal){
    if(!head) return ;
    ListNode* node = head;
    if(head->val == positionVal){
        ListNode* head = new ListNode(iVal);
        head->next = node;
        return ;
    }

    while(node->next!=nullptr && node->next->val != positionVal){
        node = node->next;
    }
    if(node->next && node->next->val == positionVal) {
        ListNode *temp = new ListNode(iVal);
        temp->next = node->next;
        node->next = temp;
    }
}

void RemoveNode(ListNode* head, int deleteVal){
    if(!head) return ;
    ListNode* deleteNode = nullptr;
    if(head->val == deleteVal){
        deleteNode=head;
        head = head->next;
    }
    ListNode* node = head;
    while(node->next && node->next->val != deleteVal){
        node = node->next;
    }
    if(node->next && node->next->val == deleteVal){
        deleteNode = node->next;
        node->next = node->next->next;
    }
    delete deleteNode;
}