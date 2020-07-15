//
// Created by Administrator on 2020/4/10 0010.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int continous(vector<int> value){
    int c = 0;
    int pre = -1;
    int max_C = -1;
    for(auto a : value){
        if(a == 0){
            continue;
        }
        if(a != 0 && a == pre){
            c++;
            max_C = max(c, max_C);
            continue;
        }
        if(a!=0 && a!=pre){
            c = 1;
            pre = a;
            max_C = max(c, max_C);
        }

    }
    return max_C;
}

void dfs(int index, vector<int>& value, int K, int& res){
    if(index == value.size() || K ==0) return;
    else{

        dfs(index+1,value, K ,res);
        value[index] = 0;
        res = max(res, continous(value));
        dfs(index+1, value, K-1, res);

    }
}
int main(){
    int N;
    int K;
    cin >> N;
    cin >> K;
    vector<int> value(N);
    for(int i = 0; i < N; ++i){
        cin >> value[i];
    }
    int res = continous(value);
    dfs(0, value, K, res);
    cout << res << endl;
    return 0;
}