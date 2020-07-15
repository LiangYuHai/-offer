//
// Created by Administrator on 2020/4/26 0026.
//n个房间，m个数，如果存在两个相邻的房间有相同的数记为A，问多少种组合满足A。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
void helper(int index, int m, int n, vector<int>& nums, int& res){
    if(index == n){
        for(int i = 0; i < n-1; ++i) {
            if (nums[i] == nums[i + 1]) {
                res++;
                return ;
            }
        }
    }else{
        for(int i = 1; i <= m; ++i){
            nums.push_back(i);
            helper(index+1, m, n, nums, res);
            nums.pop_back();
        }
    }

}
int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<int> nums;
    int res = 0;
    helper(0,m,n, nums, res);
    cout << res << endl;
    return 0;
}
