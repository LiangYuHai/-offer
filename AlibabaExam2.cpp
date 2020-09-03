//矩阵迷宫， 入口‘S'，出口’E‘，可以上下左右走，也可以按中心对称fly x+x^ = n-1 y+y^ = m-1, 最多只能fly 5次，
//求走出迷宫最少多少步。
// Created by Administrator on 2020/3/26 0026.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;


vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

int dfs(vector<string>& board, int i, int j, int n, int m, set<pair<int, int>>& seen, int f, map<pair<int,int>, int> cache){
    int min_count = 99999;
    if(i<0||i>=n||j<0||j>=m||board[i][j]=='#') return min_count;
    if(board[i][j] == 'E') return 0;
    if(cache.find({i,j}) != cache.end()) return cache[{i,j}];
    seen.insert({i, j});
    for(auto k = 0; k < 4; ++k){
        if(seen.find({i+dirs[k][0], j + dirs[k][1]}) != seen.end()) continue;
        int count = dfs(board, i+dirs[k][0], j + dirs[k][1], n, m, seen, f, cache);
        min_count = min(min_count, count);
    }
    if(f < 5 && seen.find({n-1-i, m-1-j}) == seen.end()){
        int count = dfs(board, n-1-i, m-1-j, n, m, seen, f+1,cache);
        min_count = min(min_count, count);
    }
    cache[{i,j}] = min_count+1;
    return min_count + 1;
}

int main(){
    int n;
    int m;
    while (cin >> n >> m){
        cout << n << m << endl;
        vector<string> board;
        for(int i =0; i < n; ++i){
            string temp;
            cin >> temp;
            cout << temp;
            board.push_back(temp);
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'S'){
                    cout << "start";
                    set<pair<int, int>> seen;
                    map<pair<int,int>, int> cache;
                    int count = dfs(board, i, j, n, m, seen, 0, cache);
                    cout << count;
                }
            }
        }
    }
}