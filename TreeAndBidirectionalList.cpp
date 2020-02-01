//面试题27. 二叉搜索树与双向链表
// Created by Administrator on 2020/1/31 0031.
//

#include "Tree.h"
#include <iostream>
#include "List.h"
#include <stack>
#include <vector>
using namespace std;

struct BinaryListNode{
    int val;
    BinaryListNode* left;
    BinaryListNode* right;
    BinaryListNode() = default;
    explicit BinaryListNode(int x) : val(x), left(nullptr), right(nullptr){}
};
BinaryListNode* ConverNode(TreeNode* treeNode){
    BinaryListNode* convertNode = new BinaryListNode(treeNode->val);
    return convertNode;
}
BinaryListNode* Convert(TreeNode* root){
    if(!root) return nullptr;
    stack<TreeNode*> treeNodeStack;
    vector<BinaryListNode*> res;

    while(!treeNodeStack.empty() || root){
        while(root){
            treeNodeStack.emplace(root);
            root = root->left;
        }
        root = treeNodeStack.top();
        treeNodeStack.pop();
        res.emplace_back(ConverNode(root));
        root = root ->right;
    }

    for(int i = 0; i < res.size()-1; ++i){
        res[i]->right = res[i+1];
        res[i+1]->left = res[i];
    }
    return res[0];
}