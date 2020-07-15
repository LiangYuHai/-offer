//
// Created by Administrator on 2020/7/15 0015.
//

#include <iostream>
#include <vector>
using namespace std;
int N, M;

void update(int a, int b, vector<vector<int>>& follow){
    for(int i = 0; i < N; ++i){
        if(follow[i][a] && !follow[i][b]){
            follow[i][b] = 1;
            update(i, b, follow);
        }
    }
}

int main(){
    cin >> N >> M;
    int a, b;
    vector<vector<int>> follow(N, vector<int>(N));
    for(int i = 0; i < M ; ++i){
        cin >> a >> b;
        a--;
        b--;
        follow[a][b] = 1;
        update(a, b, follow);
    }
    int res = 0;
    for(int i = 0; i < N; ++i){
        bool flag = true;
        for(int j = 0; j < N; ++j){
            if(!follow[j][i]){
                flag = false;
                break;
            }
        }
        if(flag){
            ++res;
        }

    }
    cout << res << endl;
    return 0;
}