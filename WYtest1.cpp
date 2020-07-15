//
// Created by Administrator on 2020/4/11 0011.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;

vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

double distance(int i, int j, int start_i, int start_j){
    return pow(pow(i-start_i,2) + pow(j-start_j,2),0.5);
}
void dfs(vector<vector<int>>& Matrix, int M, int start_i, int start_j, int i, int j, int& L, vector<vector<bool>>& seen){
    seen[i][j] = true;
    L += Matrix[i][j];
    for(auto dir : dirs){
        if(i+dir[0] >= 0 && i+dir[0] < M && j+dir[1] >= 0 && j+dir[1] < M && seen[i+dir[0]][j+dir[1]] == false && distance(i+dir[0], j+dir[1], start_i, start_j) <= L){
            dfs(Matrix, M, start_i, start_j, i+dir[0], j+dir[1], L, seen);
        }
    }
}
int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        int M;
        int L;
        cin >> M;
        cin >> L;
        vector<vector<int>> Matrix(M, vector<int>(M));
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < M; ++j){
                cin >> Matrix[i][j];
            }
        }
        int start_i;
        int start_j;
        cin >> start_i;
        cin >> start_j;
        vector<vector<bool>> seen(M, vector<bool>(M, false));
        dfs(Matrix, M, start_i, start_j, start_i, start_j, L, seen);
        cout << L;
    }

    return 0;
}