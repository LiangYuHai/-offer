//2020阿里实习3.20笔试题
// Created by Administrator on 2020/3/20 0020.
//从一副扑克牌中拿出一叠，其中包括A,2,3,...,10各四张，从中抽出一些牌，然后按下列方式打出：
//单牌
//对子
//五连顺
//三对
//求最少打出多少次牌可以打光.


#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int min = INT_MAX;

bool check(vector<int>& nums){
    for(auto &a:nums){
        if(a){
            return true;
        }
    }
    return false;
}

void dfs(vector<int>& nums, int& count){
    if(count > min) return ;

    if(!check(nums)){
        if(count < min){
            min = count;
            return ;
        }
    }

//    顺子
    int i = 0;
    while(!nums[i]){
        i++;
    }
    if(i+4 < nums.size() && nums[i] && nums[i+1] && nums[i+2] && nums[i+3] && nums[i+4]){
        nums[i]--;
        nums[i+1]--;
        nums[i+2]--;
        nums[i+3]--;
        nums[i+4]--;
        count++;
        dfs(nums, count);
        for(int j = 0; j < 5; ++j){
            nums[i+j]--;
        }
        count--;
    }
//    三对
    if(nums[i] >= 2 && nums[i+1] >= 2 && nums[i+2] >= 2){
        nums[i]-=2;
        nums[i+1]-=2;
        nums[i+2]-=2;
        count++;
        dfs(nums, count);
        nums[i]+=2;
        nums[i+1]+=2;
        nums[i+2]+=2;
        count--;
    }

//    两对
    if(nums[i] >=2  && nums[i+1] >= 2){
        nums[i]-=2;
        nums[i+1]-=2;
        count++;
        dfs(nums, count);
        nums[i]+=2;
        nums[i+1]+=2;
        count--;
    }

    if(nums[i]){
        nums[i]--;
        count++;
        dfs(nums, count);
        nums[i]++;
        count--;
    }
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 1, 1};
    int count = 0;
    dfs(nums, count);
    cout << min << endl;
}
