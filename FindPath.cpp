//面试题25 二叉树中和为某一值的路径
// Created by Administrator on 2020/1/30 0030.
//

#include "Tree.h"
#include <iostream>
#include <vector>
using namespace std;
void helper(TreeNode* node, int target, vector<int> path){
    if(!node->left && !node->right){
        if(node->val == target){
            path.emplace_back(node->val);
            for(auto i : path){
                cout << i << "->";
            }
            cout << "end" << endl;
        }else{
            return ;
        }
    }else{
        path.emplace_back(node->val);
        if(node->left){
            helper(node->left, target - node->val, path);
        }
        if(node->right){
            helper(node->right, target - node->val, path);
        }
    }
}

void FindPath(TreeNode* root, int target){
    if(!root) return ;
    vector<int> path;
    helper(root, target, path);
}

