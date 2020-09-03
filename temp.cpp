//
// Created by johanliang on 2020/8/8.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    unordered_map<int*, int> M;
    M[a]++;
    for(const auto& it : M){
        cout << it.first << endl;
    }
    return 0;
}