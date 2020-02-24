//Liang Yuhai
// Created by Administrator on 2019/12/3 0003.
//中序遍历二叉树，递归和迭代两种方法

#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;
//=============递归===============
void helper(TreeNode*, vector<int>&);

vector<int> Inorder_Recursively(TreeNode* root){
    vector<int> res;
    helper(root, res);
    return res;
}

void helper(TreeNode* node, vector<int>& res){
    if(!node) return ;
    helper(node->left, res);
    res.push_back(node->val);
    helper(node->right, res);
}

//==============迭代=====================

#include <stack>

vector<int> Inorder_Iter(TreeNode* root){

    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> nodes;

    while(!nodes.empty() || root){
        while(root){
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top();
        nodes.pop();
        res.push_back(root->val);
        root = root -> right;
    }
    return res;
}