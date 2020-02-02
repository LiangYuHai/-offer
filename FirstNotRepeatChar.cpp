//面试题35 第一个没重复的字符
// Created by Administrator on 2020/2/2 0002.
//

#include <iostream>
#include <map>
#include <string>
//using namespace std;
//O（n）
char FirstNotRepeatChar(char* pString){
    if(!pString) return '\0';
    unsigned int hashTable[256];

    char* p = pString;
    for(unsigned int & i : hashTable)
        i = 0;

    while(*p != '\0'){
        hashTable[*p] ++;
        p++;
    }
    p = pString;
    while(*p != '\0'){
        if(hashTable[*p] == 1) return *p;
        p++;
    }
    return '\0';
}


char FirstNotRepeatChar2(std::string& str){
    if(str.empty()) return '\0';
    std::map<char, int> hashTable;

    for(auto & i: str){
        if(hashTable.find(i) == hashTable.end()) hashTable[i] = 1;
        else hashTable[i] ++ ;
    }
    for(auto & i : str){
        if(hashTable[i] == 1) return i;
    }
    return '\0';
}

void test1(){
    std::string str = "abacc";
    std::cout << FirstNotRepeatChar2(str);
}

int main(){
    test1();
}