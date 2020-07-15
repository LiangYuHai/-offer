//
// Created by Administrator on 2020/4/15 0015.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
//#include "Tree.h"
using namespace std;
void dfs(int root, multimap<int, int> m, int& res, int& big, bool& R, set<int>& seen, set<int>& global_seen){

    auto children = m.equal_range(root);
    if(children.first != children.second){
        for(auto it = children.first; it!=children.second; ++it){
            if(seen.find(it->second) != seen.end()){
                R = true;
                return ;
            }
            big += it->second;
            seen.insert(it->second);
            global_seen.insert(it->second);
            dfs(it->second, m, res, big, R, seen, global_seen);
            seen.erase(it->second);
            big -= it->second;
        }
    }else{
        res = max(res, big);
    }
}
int main(){
    int group_num;
    cin >> group_num;
    vector<int> use_func_nums(group_num);
    for(int i = 0; i < group_num; ++i){
        cin >> use_func_nums[i];
    }
    multimap<int, int> m;
    vector<int> Stack;
    vector<int> start;
    for(int i = 0; i < group_num; ++i){
        vector<int> line;
        for(int j = 0; j < use_func_nums[i] + 2; ++j){
            int a;
            cin >> a;
            line.push_back(a);
        }
        if(line.size() == 1 || line[1] < 10){
            cout << "NA" << endl;
            return 0;
        }
        Stack.push_back(line[1]);
        for(int k = 2; k < use_func_nums[i] + 2; ++k){
            m.insert({line[0], line[k]});
        }
    }
    int res = -1;
    bool R = false;
    set<int> global_Seen;
    for(auto it = m.begin(); it != m.end(); ++it){
        if(global_Seen.find(it->first) != global_Seen.end()) continue;
        global_Seen.insert(it->first);
        int big = it->first;
        set<int> seen;
        seen.insert(it->first);
        dfs(it->first, m, res, big, R, seen, global_Seen);
        if(R){
            cout << "R" << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}