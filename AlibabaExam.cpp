//从1到n中选任意的人组成一队，并选其中一人为队长，可以选出多少队？队长不同属于不同队；
// Created by Administrator on 2020/3/26 0026.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        int res = pow(2, n-1)*n;
        cout << res%1000000007 << endl;
    }
}
//通过率80%