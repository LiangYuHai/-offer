//
// Created by Administrator on 2020/4/26 0026.
//大概就是求无向图的连通子图的最长路径，换了个壳

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;


void helper(int root, multimap<int,int>& m, int& res, set<int>& seen){
    if(seen.find(root) != seen.end()) return;
    seen.insert(root);
    res += 1;
    auto children = m.equal_range(root);
    for(auto it = children.first; it!=children.second; ++it){
        helper(it->second, m, res, seen);
    }
}
int main(){
    int T;
    cin >> T;
    for(int t= 0; t <T; ++t){
        int n;
        cin >> n;
        multimap<int, int> m;
        for(int i = 0; i < n; ++i){
            int x;
            int y;
            cin >> x >> y;
            m.insert({x, y});
            m.insert({y,x});
        }

        int res = 0;
        for(auto it = m.begin(); it != m.end(); ++it){
            int cur = 0;
            set<int> seen;

            helper(it->first, m, cur, seen);
            res = max(res, cur);
        }
        cout << res << endl;
    }
    return 0;
}
