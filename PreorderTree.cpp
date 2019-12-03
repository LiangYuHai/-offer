//Liang Yuhai
// Created by Administrator on 2019/12/3 0003.
//二叉树的前序遍历,包括迭代和递归两种方法。
#include "Tree.h"
#include <iostream>
#include <vector>
using namespace std;

//===============递归=================
void helper(TreeNode*, vector<int>&);

vector<int> Preorder_Recursively(TreeNode* root){
    vector<int> res;
    helper(root, res);
    return res;
}
void helper(TreeNode* node, vector<int>& res){
    if(!node) return ;
    res.push_back(node->val);
    helper(node->left, res);
    helper(node->right, res);
}

//================迭代====================
#include <stack>
vector<int> Preorder_Iteratively(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        TreeNode* node = nodes.top();
        nodes.pop();
        res.push_back(node->val);
        if(node->right){
            nodes.push(node->right);
        }
        if(node->left) {
            nodes.push(node->left);
        }
    }
    return res;
}