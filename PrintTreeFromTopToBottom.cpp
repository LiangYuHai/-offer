//面试题23. 从上到下打印树（BFS广度优先遍历）
// Created by Administrator on 2020/1/30 0030.
//
#include "Tree.h"
#include <queue>
#include <vector>
using namespace std;

vector<TreeNode*> printTreeFromTopToBottom(TreeNode* root){
    vector<TreeNode*> res;
    if(!root) return res;
    queue<TreeNode*> queueTreeNode;
    queueTreeNode.emplace(root);
    while(!queueTreeNode.empty()){
        TreeNode* node = queueTreeNode.front();
        queueTreeNode.pop();
        res.emplace_back(node);
        if(node->left){
            queueTreeNode.emplace(node->left);
        }
        if(node->right){
            queueTreeNode.emplace(node->right);
        }
    }
    return res;
}