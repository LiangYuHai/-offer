//
// Created by Administrator on 2020/4/18 0018.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
using namespace std;

bool paralle(vector<int> &X, vector<int> &Y, int i, int j, int k, int z){
    return abs((Y[i]-Y[j])/(X[i]-X[j])) == abs((Y[k]-Y[z])/(X[k]-X[z]));
}

int countPare(vector<int> &X, vector<int> &Y){
    int count = 0;
    for(int i = 0; i < X.size(); i+=2){
        for(int j = i+2; j < X.size(); j+=2){
            if(paralle(X, Y, i, i+1, j, j+1)){
                count++;
            }
        }
    }
    return count;
}
void helper(int index,  vector<int> &X, vector<int> &Y, int& res){
    if(index == X.size()-1){
        int count = countPare(X, Y);
        res = max(res, count);
    }else{
        for(int i = index; i < X.size(); ++i){
            int tempx = X[index];
            int tempy = Y[index];
            X[index] = X[i];
            Y[index] = Y[i];
            X[i] = tempx;
            Y[i] = tempy;
            helper(index+1, X , Y, res);
            tempx = X[index];
            tempy = Y[index];
            X[index] = X[i];
            Y[index] = Y[i];
            X[i] = tempx;
            Y[i] = tempy;
        }
    }
}
/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solve(int n, vector<int> &X, vector<int> &Y) {
    int res = -10;
    helper(0, X, Y, res);
    return res;
}

/******************************结束写代码******************************/


int main() {
    int n;
    cin >> n;
    vector<int> X, Y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    cout << solve(n, X, Y) << endl;
    return 0;

}