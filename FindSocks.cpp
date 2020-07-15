//
// Created by Administrator on 2020/3/27 0027.
//2
//2
//3 2
//3
//0 0 0

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(auto i = 0; i <T; ++i){
        int n;
        cin >> n;
        vector<int> A;
        for(auto j = 0; j < n; ++j){
            int a;
            cin >> a;
            A.push_back(a);
        }
        int res = 0;
        for(auto k : A){
            if(k > 0) res++;
        }
        if(res < 2) cout << -1 << endl;
        else cout << res + 1 << endl;
    }
    return 0;
}