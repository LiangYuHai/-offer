//
// Created by Administrator on 2020/4/6 0006.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> value(N);
    for(int i = 0; i < N; ++i){
        cin >> value[i];
    }
    sort(value.begin(), value.end());
    int j = 0;
    int res = 0;
    for(int i = N-1; i >= 0; --i){
        ++j;
        if(j % 3 == 0) continue;
        res += value[i];
    }
    cout << res << endl;
    return 0;
}