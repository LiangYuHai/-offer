//Liang Yuhai
// Created by Administrator on 2019/12/2 0002.
//链表的添加、删除、插入结点, 递归（本质上就是栈）。

#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() = default;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* addListNode(ListNode* head, int value){
    if(!head) return head = new ListNode(value);
    ListNode* node = head;
    while(head->next){
        head = head->next;
    }
    head->next = new ListNode(value);
    return head;
}

ListNode* insertListNode(ListNode* head, int iVal, int positionVal){
    if(!head) return nullptr;
    ListNode* node = head;
    if(head->val == positionVal){
        ListNode* head = new ListNode(iVal);
        head->next = node;
        return head;
    }

    while(node->next!=nullptr && node->next->val != positionVal){
        node = node->next;
    }
    if(node->next && node->next->val == positionVal){
        ListNode* temp = new ListNode(iVal);
        temp->next = node->next;
        node->next = temp;
    }
    return head;
}

ListNode* deleteListNode(ListNode* head, int deleteVal){
    if(!head) return nullptr;
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
    return head;
}

void printListReversely(ListNode* head){
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

void printListReversely2(ListNode* head){
    if(!head) cout << "nullptr";
    else{
        if(head->next) {
            printListReversely2(head->next);
        }
        cout << head->val << '\t';
    }
    cout << endl;
}
//=========Test Code===========
void Test1(){
    int vals[] = {1,2,3,4};
    ListNode* dummyHead = new ListNode(-1);
    ListNode* node = dummyHead;
    for(auto a : vals){
        node->next = new ListNode(a);
        node = node->next;
    }
    printListReversely2(dummyHead->next);
}

void Test2(){
    printListReversely2(nullptr);
}

void Test3(){
    int vals[] = {1};
    ListNode* dummyHead = new ListNode(-1);
    ListNode* node = dummyHead;
    for(auto a : vals){
        node->next = new ListNode(a);
        node = node->next;
    }
    printListReversely2(dummyHead->next);
}

int main(){
    Test1();
    Test2();
    Test3();
    return 0;
}