//考虑你从家出发步行去往一处目的地，该目的地恰好离你整数单位步长（大于等于1）。你只能朝向该目的地或者背向该目的地行走，而你行走的必须为单位步长的整数倍，且要求你第N次行走必须走N步。
//请就给出目的地离你距离，判断你是否可以在有限步内到达该目的地。如果可以到达的话，请计算到达目的地的最短总步数(不能到达则输出-1)。
// Created by Administrator on 2020/3/20 0020.
//
#include <iostream>
#include <queue>
using namespace std;
int solution(int n){
    if(!n) return 0;
    queue<int> q;
    q.push(0);
    int i = 0;
    while(!q.empty()){
        queue<int> temp;
        i++;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            if(v+i == n || v-i==n) return i;
            temp.push(v-i);
            temp.push(v+i);
        }
        q = temp;

    }
    return -1;
}

int main(){
    int n;
    int res;
    while (cin >> n >> res){
        if(solution(n) == res) cout << "true" << endl;
        else cout << "false" << endl;
    }
}