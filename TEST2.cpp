//
// Created by Administrator on 2020/4/10 0010.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int N;
    int M;

    while(cin >> N >> M){
        int res = 0;
        vector<int> value(N);
        for(int i = 0; i < N; ++i){
            cin >> value[i];
        }
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= i; ++j){
                if(i == j){
                    dp[i][j] = value[i];
                }else{
                    dp[i][j] = value[i] + dp[i-1][j];
                }
                if(dp[i][j] % M == 0){
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}