//面试题39. 二叉树的深度、判断是否平衡二叉树
// Created by Administrator on 2020/2/4 0004.
//

#include "Tree.h"
#include <cmath>

int TreeDepth(TreeNode* root){
    if(!root) return 0;
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    return left > right ? left + 1 : right + 1;
}

bool IsBalanced(TreeNode* root){
    if(!root) return true;
    bool left = IsBalanced(root->left);
    bool right = IsBalanced(root->right);
    if(!left || !right) return false;
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return abs(leftDepth-rightDepth) <= 1;
}

#include <stack>
#include <map>
using namespace std;
bool IsBalanced2(TreeNode* root){
    if(!root) return true;
    stack<TreeNode*> nodeStack;
    map<TreeNode*, int> hashTable;
    TreeNode* preNode = nullptr;
    while(!nodeStack.empty() || root){
        while(root){
            nodeStack.emplace(root);
            root = root->left;
        }
        root = nodeStack.top();
        if(!root->right || preNode == root->right){
            nodeStack.pop();
            int leftDepth = 0;
            int rightDepth = 0;
            if (root->left) leftDepth = hashTable[root->left];
            if (root->right) rightDepth = hashTable[root->right];
            if (abs(leftDepth - rightDepth) > 1) return false;
            leftDepth > rightDepth ? hashTable[root] = leftDepth + 1 : hashTable[root] = rightDepth + 1;
            preNode = root;
            root = nullptr;
        }else{
            root = root->right;
            preNode = nullptr;
        }
    }
    return true;
}

bool IsBalanced3(TreeNode* pRoot, int* pDepth){
    if(!pRoot){
        *pDepth = 0;
        return true;
    }

    int left;
    int right;
    if(IsBalanced3(pRoot->left, &left) && IsBalanced3(pRoot->right, &right)){
        if(abs(left-right) <= 1) {
            *pDepth = left > right ? left + 1 : right + 1;
            return true;
        }
    }
    return false;
}


