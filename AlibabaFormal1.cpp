//
// Created by johanliang on 2020/7/29.
//

#include <iostream>

int main(){
    int n;
    cin >> n;
    vector<int> eggs(n);
    for(int i = 0; i < n; ++i){
        cin >> eggs[i];
    }
    int res = 0;
    while(true){
        ++res;
        map<int, int> m;
        for(int i = 0; i < n; ++i) {
            eggs[i] += i + 1;
            if (m.find(eggs[i]) != m.end()) {
                cout << res << endl;
                return 0;
            } else {
                m[eggs[i]]++;
            }
        }
    }
    return 0;
}