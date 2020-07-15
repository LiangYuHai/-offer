//
// Created by Administrator on 2020/4/6 0006.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> test = {-1, 0, 1, 2, -1, -4};
    sort(test.begin(), test.end());
    vector<vector<int>> res;
    for(auto i = 0; i < test.size()-2; ++i){
        if(i > 0 && test[i-1] == test[i]) continue;
        int left = i + 1;
        while(test[left+1] == test[left]) {
            left++;
        }
        int right = test.size()-1;
        while(test[right-1] == test[right]){
            right--;
        }
        while(left < right){
            if(test[i]+test[left]+test[right] == 0){
                vector<int> temp = {test[i], test[left], test[right]};
                res.push_back(temp);
                left++;
                right--;
            }
            if(test[i]+test[left]+test[right] < 0){
                ++left;
                continue;
            }
            if(test[i]+test[left]+test[right] > 0){
                --right;
                continue;
            }
        }
    }
    for(auto r : res){
        for(auto a : r){
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}