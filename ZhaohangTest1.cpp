//
// Created by Administrator on 2020/4/29 0029.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> Matrix(N, vector<int>(N, 0));
    for(int i = 0; i < N ; ++i){
        for(int j = 0; j <=i; ++j){
            cin >> Matrix[i][j];
        }
    }
    for(int i = 1; i < N; ++i){
        for(int j = 0; j <=i; ++j){
            if(j == 0){
                Matrix[i][j] += Matrix[i-1][j];
            }else{
                Matrix[i][j] += max(Matrix[i-1][j-1], Matrix[i-1][j]);
            }
        }
    }
    int res = -1;
    for(int i = 0; i < N; ++i){
        res = max(Matrix[N-1][i], res);
    }
    cout << res << endl;
    return 0;
}