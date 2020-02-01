//面试题24 验证序列是否为二叉搜索树的后序遍历
// Created by Administrator on 2020/1/30 0030.
//

#include <iostream>

bool veritifySequenceOfBST(int* sequence, int length){
    if(!sequence || length <=0) return false;
    int root = sequence[length-1];
    int i = 0;
    for(; i < length; ++i){
        if(sequence[i] > root) break;
    }
    for(auto j = i; j < length; ++j){
        if(sequence[j] < root) return false;
    }
    bool left = true;
    if(i > 0){
        left = veritifySequenceOfBST(sequence, i);
    }
    bool right = true;
    if(i < length - 1){
        right = veritifySequenceOfBST(sequence + i, length - i - 1);
    }
    return left && right;
}

//用vector
#include <vector>
using namespace std;
bool veritifySequenceOfBST2(vector<int> sequence){
    if(sequence.empty()) return false;
    int root = *(sequence.end()-1);
    int i = 0;
    for(; i < sequence.size(); ++i){
        if(sequence[i] > root) break;
    }
    for(int j = i; j < sequence.size(); ++j){
        if(sequence[j] < root) return false;
    }
    bool left = true;
    if(i > 0){
        vector<int> leftSequence(sequence.begin(), sequence.begin()+i);
        left = veritifySequenceOfBST2(leftSequence);
    }
    bool right = true;
    if(i < sequence.size()-1){
        vector<int> rightSequence(sequence.begin()+i, sequence.end()-i-1);
        right = veritifySequenceOfBST2(rightSequence);
    }
    return left && right;
}

//输入一个整数数组，判断是否为BST的前序遍历序列。与此题类似，只是根节点为第一个数。
