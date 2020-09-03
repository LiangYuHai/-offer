//
// Created by Administrator on 2020/4/14 0014.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include "Tree.h"
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

int solution(TreeNode* root, int& max_sum){
    if(!root) return 0;
    int left = max(solution(root->left, max_sum), 0);
    int right = max(solution(root->right, max_sum), 0);
    max_sum = max(root->val + left + right, max_sum);
    return left > right ? left + root->val : right + root->val;
}

int main(){
    int max_sum = INT_MIN;
    solution(root, max_sum);
    return max_sum
}