//
// Created by Administrator on 2020/4/29 0029.
//链接：https://ac.nowcoder.com/acm/contest/5246/C
//来源：牛客网
//
// 小招正在玩一款修塔游戏：系统中有n座高塔，每座高塔由若干个高度相同的方块堆砌而成。修塔游戏的规则为：
//       （1）每次从最高塔的塔尖拿走一个方块
//       （2）每次在最低塔的塔尖堆砌一个方块
//       小招每次只能完成上述两个动作中的一个动作。游戏的目标是使n座高塔中至少有k座高塔的高度相同，请问小招最少需要多少次才能完成游戏。
//输入描述:
//输入共有2行，第一行为n和k(1≤k≤n≤200000 )，第二行为n座塔的高度组成的数组 a1, a2, ...an(1≤aj≤10000)。
//输出描述:
//输出值为最少需要多少次动作才能完成游戏。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

bool check(vector<int>& nums, int k){
    int start = nums[0];
    int end = nums[nums.size()-1];
    int count1 = 0;
    int count2 = 0;
    for(auto a : nums){
        if(a == start){
            count1++;
        }
        if(a == end){
            count2++;
        }
    }
    return count1 == k || count2 == k;

}

void helper(vector<int>& nums, int k, int cur , int& res){
    if(check(nums, k)) {
        res = min(cur, res);
        return ;
    }
//    sort(nums.begin(), nums.end());
    nums[0]++;
    cur++;
    helper(nums, k, cur, res);
    nums[0]--;
    nums[nums.size()-1]--;
    helper(nums,k, cur, res);

}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int cur = 0;
    int res = 9999;
    helper(nums, k, cur, res);

    cout << res << endl;
    return 0;
}