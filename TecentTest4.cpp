//
// Created by Administrator on 2020/4/26 0026.
//n个房间，m个数，如果存在两个相邻的房间有相同的数记为A，问多少种组合满足A。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;


bool helper(vector<vector<int>>& data, int i, int j, int k){

    for(int q = 0; q < k-1; ++q){
        if(data[i][q]+data[j][q] != data[i][q+1]+data[j][q+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<vector<int>> data(n, vector<int>(k, 0));
    for(int i = 0;i < n; ++i){
        for(int j = 0; j < k; ++j){
            cin >> data[i][j];
        }
    }
    int res = 0;
    set<int> seen;
    for(int i = 0;i < n-1; ++i){
        if(seen.find(i) != seen.end()) continue;
        for(int j = i+1; j < n; ++j){
//            if(seen.find(j) != seen.end()) continue;
            if(helper(data, i, j, k)){
                res++;
                seen.insert(j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
