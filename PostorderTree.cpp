//Liang Yuhai
// Created by Administrator on 2019/12/3 0003.
//后续遍历二叉树，递归和迭代方法

#include <vector>
#include "Tree.h"
using namespace std;

//===========递归===============
void helper(TreeNode*, vector<int>&);

vector<int> Postorder_Recursively(TreeNode* root){
    vector<int> res;
    helper(root, res);
    return res;
}

void helper(TreeNode* node, vector<int>& res){
    if(!node) return ;
    helper(node->left, res);
    helper(node->right, res);
    res.push_back(node->val);
}

//============迭代================

#include <stack>

vector<int> Postorder_Iteratively(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> nodes;
    TreeNode* pre = nullptr;
    while(!nodes.empty()){
        while(root){
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top();

        if(!root->right || pre == root->right){
            res.push_back(root->val);
            nodes.pop();
            pre = root;
            root = nullptr;
        }else{
            root = root->right;
            pre = nullptr;
        }
    }
    return res;
}