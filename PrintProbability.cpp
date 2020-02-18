//面试题43 n个骰子的点数
// Created by Administrator on 2020/2/15 0015.
//

#include <iostream>
#include <cmath>
//递归，空间复杂度大
int MAX_VALUE = 6;
void PrintProbability(int n, int cur, int* res, int val){
    if(cur == 1){
        res[val-n] ++;
    }else{
        for(int i = 1; i <= MAX_VALUE; ++i){
            PrintProbability(n, cur-1, res, val+i);
        }
    }
}

double* PrintProbability(int n){
    if(n <= 0)
        return nullptr;
    int res[MAX_VALUE*n - n + 1];
    memset(res, 0, sizeof(res));
    for(int i = 1; i <= MAX_VALUE; ++i){
        PrintProbability(n, n, res, i);
    }
    int total = pow(MAX_VALUE, n);
    double res2[MAX_VALUE*n-n+1];
    for(auto i = 0; i < MAX_VALUE*n-n+1; ++i){
        res2[i] = (double)res[i]/total;
    }
    return res2;
}

//迭代

void PrintProbability2(int n){
    if(n <= 0) return;
    int* res[2];
    res[0] = new int[MAX_VALUE*n + 1];
    res[1] = new int[MAX_VALUE*n + 1];
    for(int i = 0; i < MAX_VALUE*n + 1; ++i){
        res[0][i] = 0;
        res[1][i] = 0;
    }
    for(int i = 1; i <= MAX_VALUE; ++i) res[0][i] = 1;
    int flag = 0;
    for(int k = 2; k <= n ; ++k){

        for(int i = 0; i < k; ++i) res[1-flag][i] = 0;
        for(int i = k; i < MAX_VALUE*k; ++i){
            for(int j = 1; j<=i && j <= MAX_VALUE; ++j){
                res[1-flag][i] += res[flag][i-j];
            }
        }
        flag = 1 - flag;
    }
    double total = pow(MAX_VALUE, n);

    for(int i = n; i <= MAX_VALUE*n; ++i){
        double ratio = res[flag][i]/total;
        std::cout << i << ':' << ratio << std::endl;
    }
}

