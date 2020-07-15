//
// Created by Administrator on 2020/4/15 0015.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include "Tree.h"
using namespace std;

//bool cmp(const string a, const string b){
//
//}
struct cmp{
    bool operator()(const string a, const string b){
        int i = 0;
        while(i < a.size() && i < b.size()){
            if(a[i] > b[i]){
                return true;

            } else if (a[i] < b[i]){
                return false;
            }
            i++;
        }
        return a.size() > b.size();
    }
};
int main(){
    string line;
    cin >> line;
    string name;
    map<string, int, cmp> names;
    for(int i = 0; i < line.size(); ++i){
        if(line[i] == ',' && !name.empty()){
            names[name] += 1;
            name.clear();
        }else{
            name += line[i];
        }
    }
    if(!name.empty()) names[name] += 1;
    int max_count = INT_MIN;
    string res;
    for(auto it=names.begin(); it !=names.end(); ++it){
        if(it->second >= max_count){
            res = it->first;
            max_count = it->second;
            continue;
        }
//        if(it->second == max_count){
//            int i = 0;
//            while(i < it->first.size() && i < res.size()){
//                if(it->first[i] < res[i]){
//                    res = it->first;
//                    break;
//                } else if (it->first[i] > res[i]){
//                    break;
//                }
//                i++;
//            }
//            if(i == it->first.size()) res = it->first;
//        }
    }

    cout << res << endl;
    return 0;
}