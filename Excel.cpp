//面试题10 位运算
// Created by Administrator on 2020/1/22 0022.
//Excel 字母代替数字

#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>
using namespace std;
int transform(char c){
    if(c == 'A') return 1;
    if(c == 'B') return 2;
    if(c == 'C') return 3;
    if(c == 'D') return 4;
    if(c == 'E') return 5;
    if(c == 'F') return 6;
    if(c == 'G') return 7;
    if(c == 'H') return 8;
    if(c == 'I') return 9;
    if(c == 'J') return 10;
    if(c == 'K') return 11;
    if(c == 'L') return 12;
    if(c == 'M') return 13;
    if(c == 'N') return 14;
    if(c == 'O') return 15;
    if(c == 'P') return 16;
    if(c == 'Q') return 17;
    if(c == 'R') return 18;
    if(c == 'S') return 19;
    if(c == 'T') return 20;
    if(c == 'U') return 21;
    if(c == 'V') return 22;
    if(c == 'W') return 23;
    if(c == 'X') return 24;
    if(c == 'Y') return 25;
    if(c == 'Z') return 26;
//    switch(c){
//        case 'A' : return 1;
////        ...
//
//}
    else return 0;
}
int Excel(const string chars){
    int position = chars.size();
    int res = 0;
    for(int i = 0; i < chars.size(); ++i){
        if(transform(chars[i]) == 0){
            throw new exception("Wrong input");
        }
        --position;
        res += pow(26,position)*transform(chars[i]);
    }
    cout << res << endl;
    return res;
}

int main(){
    string AA = "AC";
    if(Excel(AA) == 29){
        cout<<"True"<<endl;
    }
    else{
        cout << "False" << endl;
    }
}
