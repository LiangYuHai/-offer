//
// Created by Administrator on 2020/3/30 0030.
//
//输入: [1,2,3]
//输出:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]

#include <iostream>
#include <vector>

using namespace std;

void helper(int index, vector<int>& test, vector<vector<int>>& res){
    if(index == 3){
        res.push_back(test);
    }
    for(auto i = index; i < test.size(); i++){
        int temp = test[index];
        test[index] = test[i];
        test[i] = temp;
        helper(index+1, test, res);
        temp = test[index];
        test[index] = test[i];
        test[i] = temp;
    }
}

void permute(vector<int> test){
    vector<vector<int>> res;
//    for(auto i = 0; i < test.size(); ++i){
//        helper(i, test, res);
//    }
    helper(0, test, res);
    for(auto v : res){
        for(auto i : v){
            cout << i;
        }
        cout << endl;
    }
}

int main(){

    int T;
    cin >> T;
    for(auto i = 0; i <T; ++i){
        int n;
        cin >> n;
        vector<int> test;
        for(auto j = 0; j < n; ++j){
            int a;
            cin >> a;
            test.push_back(a);
            permute(test);
        }

    }
}