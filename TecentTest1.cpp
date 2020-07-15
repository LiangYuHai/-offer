//
// Created by Administrator on 2020/4/26 0026.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    map<int, int> blood_money;
    for(int i = 0; i < n; ++i){
        int c;
        int w;
        cin >> c >> w;
        blood_money[c] = w;
    }

    auto big = blood_money.begin();

    auto small = blood_money.begin();
    int cur_b = 0;
    int cur_m = 0;
    int res = -1;
    while( big != blood_money.end()){
        cur_b += big->first;
        cur_m += big->second;
        while(cur_b > m) {
            cur_b -= small->first;
            cur_m -= small->second;
            small++;
        }
        if(small == big && small != blood_money.begin()) break;
        res = max(cur_m, res);
        big++;
    }
    cout << res << endl;
    return 0;
}
