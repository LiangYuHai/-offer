//
// Created by johanliang on 2020/8/29.
//
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class solution{
public:
    vector<string> soluton(vector<string> strings){
        sort(strings.begin(), strings.end(), compare);
        return strings;
    }
    static bool compare(const string& a, const string& b){
        map<char, int> m = {{'k', 0}, {'s', 1}, {'h', 2}, {'p', 3}, {'q', 4}};
        if(a[0] != b[0]){
            return m[a[0]] < m[b[0]];
        }else{
            string a_s = a.substr(1);
            string b_s = b.substr(1);
            int a_n = stoi(a_s);
            int b_n = stoi(b_s);
            return a_n < b_n;
        }
    }
};

