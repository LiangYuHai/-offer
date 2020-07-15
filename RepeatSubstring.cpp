//给出一个非空的字符串，判断这个字符串是否是由它的一个子串进行多次首尾拼接构成的。
//例如，"abcabcabc"满足条件，因为它是由"abc"首尾拼接而成的，而"abcab"则不满足条件。
// Created by Administrator on 2020/3/19 0019.
//

#include <iostream>
#include <string>
using namespace std;

string solution(string str){
    if(str == "") return "";
    auto length = str.size();
    for(auto i = 2; i < length; ++i){
        if(length % i == 0){
            auto sublen = length/i;
            string subStr = str.substr(0, sublen);
            int j = sublen;
            for(; j < length; j+=sublen){
                if(subStr != str.substr(j, j+sublen)) break;
            }
            if(j>=length) return subStr;
        }
    }
    return "";
}

int main(){
    string test;
    while(cin >> test){
        string res = solution(test);
        if(res.empty()) cout << "false" << endl;
        else cout << res << endl;
    }
    return 0;
}