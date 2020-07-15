//
// Created by Administrator on 2020/4/18 0018.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

short main(){
    short n;
    short m;
    cin >> n;
    cin >> m;
    vector<short> loss(n);
    for(short i = 0; i < n; ++i){
        cin >> loss[i];
    }
    sort(loss.begin(), loss.end());
    short Q;
    cin >> Q;
    vector<short> qs(Q);
    for(short i = 0; i < Q; ++i){
        cin >> qs[i];
    }
    for(short i = 0; i < Q; ++i){
        short q = qs[i];
        short k = 1;
        short l = 0;
        short count = 0;
        for(short j = q-1; j >= 0; --j){
            if(count == m){
                count = 0;
                k++;
            }
            l += loss[j]*k;
            count++;
        }
        cout << l << endl;
    }
    return 0;
}