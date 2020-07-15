//矩阵乘法
// Created by johanliang on 2020/7/15.
//


#include <iostream>
#include "vector"

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int X[a][b], Y[b][c];
    auto Z = new int*[a];
    for(int i = 0; i < a; ++i){
        Z[i] = new int[c];
        for(int j = 0; j< c; ++j){
            Z[i][j] = 0;
        }
    }
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < b; ++j){
            cin>>X[i][j];
        }
    }
    for(int i = 0; i < b; ++i){
        for(int j = 0; j < c; ++j){
            cin >> Y[i][j];
        }
    }

    for(int i = 0; i < a; ++i){
        for(int j = 0; j < c; ++j){
            for(int k = 0; k < b; ++k){
                Z[i][j] += X[i][k]*Y[k][j];
            }
            cout << Z[i][j];
        }
        cout << endl;
    }
    return 0;
}