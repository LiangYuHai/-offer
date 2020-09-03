//
// Created by johanliang on 2020/7/29.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void helper(int index, vector<int>& roads, int step, int& res){
    if(index == 0 && roads[0] == 0){
        res = max(step, res);
        return ;
    }
    if(index == roads.size() && roads[index-1] == 0){
        res = max(step, res);
        return ;
    }
    if(roads[index-1] == 0 && roads[index] == 0){
        res = max(step, res);
        return ;
    }

    if(index > 0 && roads[index-1]){
        roads[index-1]--;
        helper(index-1, roads, step+1, res);
        roads[index-1]++;
    }
    if(index < roads.size() && roads[index]) {
        roads[index]--;
        helper(index + 1, roads, step + 1, res);
        roads[index]++;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> roads(n-1);
    for(int i = 0; i < n-1; ++i){
        cin >> roads[i];
    }
    int res = -1;
    int step = 0;
    for(int i = 0; i < n; ++i){
        helper(i, roads, step, res);
    }
    cout << res << endl;
    return 0;
}
