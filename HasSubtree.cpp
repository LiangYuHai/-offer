//面试题18 树A是否存在与树B相同的子结构
// Created by Administrator on 2020/1/28 0028.
//

#include "Tree.h"
#include <iostream>
using namespace std;

bool helper(TreeNode* root1, TreeNode* root2){
    if(!root2) return true;
    if(!root1) return false;
    if(root1->val != root2->val) return false;
    else{
        return helper(root1->left, root2->left) && helper(root1->right, root2->right);
    }
}
bool HasSubtree(TreeNode* root1, TreeNode* root2){
    if(!root1 || ! root2) return false;
    if(root1->val == root2->val) {
        if (helper(root1, root2)) {
            return true;
        }
    }
    return HasSubtree(root1->left, root2) || HasSubtree(root1->right, root2);
}
