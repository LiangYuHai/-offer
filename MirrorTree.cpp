//面试19 二叉树的镜像
// Created by Administrator on 2020/1/29 0029.
//

#include <iostream>
#include "Tree.h"

TreeNode* MirrorTree(TreeNode* head){
    if(!head) return nullptr;
    TreeNode* temp = head->left;
    head->left = MirrorTree(head->right);
    head->right = MirrorTree(temp);
    return head;
}