//Liang Yuhai
// Created by Administrator on 2019/12/2 0002.
//链表的添加、删除、插入结点, 递归（本质上就是栈）。
#include "List.h"
#include <iostream>
#include <stack>
using namespace std;


void printListReversely_Iter(ListNode* head){
    stack<ListNode*> nodes;
    if(!head) cout << "nullptr!";
    while(head){
        nodes.push(head);
        head = head->next;
    }
    while(!nodes.empty()){
        ListNode* node = nodes.top();
        nodes.pop();
        cout << node->val << '\t';
    }
    cout << endl;
}

void printListReversely_Recur(ListNode* head){
    if(!head) cout << "nullptr";
    else{
        if(head->next) {
            printListReversely_Recur(head->next);
        }
        cout << head->val << '\t';
    }
    cout << endl;
}
//=========Test Code===========
void Test1(){
    cout << "Test1 begin" << endl;
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);

    printListReversely_Recur(node1);
    cout << "Test1 over" << endl;
}

void Test2(){
    cout << "Test2 begin" << endl;
    printListReversely_Recur(nullptr);
    cout << "Test2 over" << endl;
}

void Test3(){
    cout << "Test3 begin" << endl;
    ListNode* head = CreateListNode(0);
    printListReversely_Recur(head);
    cout << "Test3 over" << endl;
}

int main(){
    Test1();
    Test2();
    Test3();
    return 0;
}