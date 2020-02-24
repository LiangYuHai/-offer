//面试题26. 复杂链表的复制
// Created by Administrator on 2020/1/31 0031.
//

struct ComplexListNode{
    int val;
    ComplexListNode* next;
    ComplexListNode* sibling;
};

void CloneNodes(ComplexListNode* head){
    ComplexListNode* pNode = head;
    while(pNode){
        ComplexListNode* cloneNode = new ComplexListNode();
        cloneNode->val = pNode->val;
        cloneNode->next = pNode->next;
        cloneNode->sibling = nullptr;

        pNode->next = cloneNode;
        pNode = cloneNode->next;
    }
}

void ConnectSiblingNodes(ComplexListNode* head){
    ComplexListNode* pNode = head;
    while(pNode){
        if(pNode->sibling){
            pNode->next->sibling = pNode->sibling->next;
            pNode = pNode->next->next;
        }
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* head){
    if(!head || !head->next) return nullptr;
    ComplexListNode* pNode = head;
    ComplexListNode* cloneHead = pNode->next;
    ComplexListNode* cloneNode = pNode->next;
    pNode->next = cloneNode->next;
    pNode = pNode->next;
    while(pNode){
        cloneNode->next = pNode->next;
        cloneNode = cloneNode->next;
        pNode->next = cloneNode->next;
        pNode = pNode->next;
    }
    return cloneHead;
}

ComplexListNode* Clone(ComplexListNode* head){
    CloneNodes(head);
    ConnectSiblingNodes(head);
    return ReconnectNodes(head);
}