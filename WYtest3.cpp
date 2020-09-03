//
// Created by Administrator on 2020/4/11 0011.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
void dfs(vector<int>& nums, vector<int>& wrong, vector<int>& weigth, int n, int index, int& cur_d , int& dis){
    if(index == n){
        dis = min(cur_d, dis);
    }else{
        if(cur_d > dis) return ;
        for(int i = index; i < n; ++i){
            int temp = wrong[index];
            wrong[index] = wrong[i];
            wrong[i] = temp;
            cur_d += weigth[i]*abs(i-index);
            if(cur_d > dis ||nums[index] == wrong[index]) {
                cur_d -= weigth[i]*abs(i-index);
                temp = wrong[index];
                wrong[index] = wrong[i];
                wrong[i] = temp;
                continue;
            }
            dfs(nums, wrong, weigth, n, index+1, cur_d, dis);
            cur_d -= weigth[i]*abs(i-index);
//            dis -= (weigth[index]+weigth[i])*(i-index);
            temp = wrong[index];
            wrong[index] = wrong[i];
            wrong[i] = temp;
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<int> weigth(n);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> weigth[i];
        }
        int dis = 1000;
        vector<int> wrong = nums;
        int cur_d = 0;
        dfs(nums, wrong, weigth, n, 0, cur_d, dis);
        cout << dis << endl;
    }
    return 0;
}