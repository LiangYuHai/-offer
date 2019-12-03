//
// Created by Administrator on 2019/12/3 0003.
//

#ifndef JZOFFER_LIST_H
#define JZOFFER_LIST_H
struct ListNode{
    int val;
    ListNode* next;
    ListNode() = default;
    ListNode(int x) : val(x), next(nullptr){}
};

extern ListNode* CreateListNode(int value);
extern void ConnectListNodes(ListNode* node1, ListNode* node2);
extern void PrintListNode(ListNode* node);
extern void PrintList(ListNode* head);
extern void DestoryList(ListNode* head);
extern void AddToTail(ListNode* head, int value);
extern void RemoveNode(ListNode* head, int value);
extern void InsertListNode(ListNode* head, int iVal, int positionVal);
#endif //JZOFFER_LIST_H
