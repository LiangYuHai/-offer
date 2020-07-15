//阿里3.20实习笔试题
// Created by Administrator on 2020/3/20 0020.
//给n个上升字符串，选择任意个拼接起来，问能拼出最长的上升字符串长度

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Comp(const string& a, const string& b){
    return a.back() != b.back() ? a.back() < b.back() : a[0] < b[0];
}

int solution(vector<string> nums){
    sort(nums.begin(), nums.end(), Comp);
    vector<int> dp(26,0);
    int start;
    int end;

    for(int i = 0; i < nums.size(); ++i){
        start = nums[i][0]-'a';
        int len = nums[i].size();
        for(int j = 0; j < i; ++j){
            if(nums[j].back()-'a' <= start){
                end = nums[i].back()-'a';
                dp[end] = max(dp[end], dp[nums[j].back()-'a'] + len);
            }
        }
    }
    return dp[end]
}

int main(){
    int n ;
    cin >> n;
    vector<string> nums(n);
    for(auto i = 0; i < n; ++i){
        cin >> nums[i];
    }
    cout << solution(nums) << endl;
}
