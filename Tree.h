//Liang Yuhai
// Created by Administrator on 2019/12/3 0003.
//数结构

#ifndef JZOFFER_TREE_H
#define JZOFFER_TREE_H

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
#endif //JZOFFER_TREE_H
