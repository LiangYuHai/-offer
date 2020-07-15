//
// Created by Administrator on 2020/4/11 0011.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        int N;
        int M;
        cin >> N;
        cin >> M;
        vector<vector<int>> sets(N);
        map<int,int> m;
        for(int i = 0; i < N; ++i){
            sets[i].push_back(i+1);
            m[i+1] = i;
        }
        for(int i = 0; i < M; ++i){
            int type;
            cin >> type;
            if(type == 1){
                int x;
                int y;
                cin >> x >> y;
                if(m[x] == m[y]) continue;
                sets[m[x]].push_back(y);

                for(auto it = sets[m[y]].begin(); it != sets[m[y]].end(); ++it){
                    if(*it == y){
                        sets[m[y]].erase(it);
                        break;
                    }
                }
                m[y] = m[x];
            }
            if(type == 2){
                int x;
                cin >> x;
                if(sets[m[x]].size() == 1) continue;
                for(auto it = sets[m[x]].begin(); it != sets[m[x]].end(); ++it){
                    if(*it == x){
                        sets[m[x]].erase(it);
                        break;
                    }
                }
                for(int s = 0; s < sets.size(); ++s){
                    if(sets[s].empty()){
                        sets[s].push_back(x);
                        m[x] = s;
                    }
                }
//                vector<int> temp = {x};
//                sets.push_back(temp);
//                m[x] = sets.size()-1;
            }
            if(type == 3){
                int x;
                cin >> x;
                cout << sets[m[x]].size() << endl;
            }
        }
    }
    return 0;
}
