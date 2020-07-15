//
// Created by Administrator on 2020/4/20 0020.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


void helper(vector<int>& city, int index, int cur, int& cost, int A, int B, int C, set<int> seen){
    if(index == city.size()-1){
        cost = min(cost, cur);
        return ;
    }
    if(seen.find(index) != seen.end()) return;
    seen.insert(index);
    helper(city, city[index]-1, cur+A, cost, A, B, C, seen);

    if(city[index] > 1){
        city[index] -= 1;
        helper(city, city[index]-1, cur+B, cost, A, B, C, seen);
        city[index] += 1;
    }
    if(city[index] < city.size()){
        city[index] += 1;
        helper(city, city[index]-1, cur+C, cost, A, B, C, seen);
        city[index] -= 1;
    }
}

int main(){
    int N;
    int A;
    int B;
    int C;
    cin >> N >> A >> B >> C;
    vector<int> city(N);
    for(int i = 0; i < N; ++i){
        cin >> city[i];
    }
    int cost = 9999;
    set<int> seen;
    helper(city, 0, 0, cost, A, B, C, seen);

    cout << cost << endl;
    return 0;
}