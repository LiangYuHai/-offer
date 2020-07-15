//
// Created by Administrator on 2020/4/20 0020.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int helper(vector<vector<int>>& matrix, int i, int j, int a, int b){
    int m = -1;
    for(int k = 0; k < a; ++k){
        for(int z = 0; z < b; ++z){
            m = max(matrix[i+k][j+z], m);
        }
    }
    return m;
}
int main(){
    int n;
    int m;
    int a;
    int b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            matrix[i][j] = (i+1)*(j+1)%10;
        }
    }
    int res = 0;
    for(int i = 0; i + a <= n; ++i){
        for(int j = 0; j + b <= m; ++j){
            res += helper(matrix, i, j, a, b);
        }
    }
    cout << res << endl;
    return 0;
}
