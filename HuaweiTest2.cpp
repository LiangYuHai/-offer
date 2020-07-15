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

int main(){
    string p;
    string line;
    cin >> p;
    cin >> line;
    unsigned int len = p.size();
    int i = 0;
    while(line.find(p, i) != string::npos && line[line.find(p, i) + len] == '['){
        int index = line.find(p, i);
        int addr_index = index + len + 6;
        string addr;
        while(line[addr_index] != ','){
            addr += line[addr_index];
            ++addr_index;
        }
        addr_index+=6;
        string mask;
        while(line[addr_index] != ','){
            mask += line[addr_index];
            ++addr_index;
        }
        addr_index+=5;
        string val;
        while(line[addr_index] != ']'){
             val += line[addr_index];
             ++addr_index;
        }
        cout << addr << " " << mask << " " << val << endl;
        i = addr_index;
    }
    return 0;
}