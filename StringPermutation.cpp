//面试题28 字符串排列
// Created by Administrator on 2020/1/31 0031.
//相关题目：八皇后问题，八顶点问题
#include <iostream>
using namespace std;


void Permutation(char* pStr, char* pBegin){
    if(*pBegin == '\0'){
        cout << pStr << endl;
    }else{
        for(auto i = pBegin; *i != '\0'; ++i){
            char temp =*i;
            *i = *pBegin;
            *pBegin = temp;
            Permutation(pStr, pBegin+1);
            temp = *i;
            *i = *pBegin;
            *pBegin = temp;
        }
    }
}

void Permutation(char* pStr){
    if(pStr == nullptr) return ;
    Permutation(pStr, pStr);
}

////n个字符组合问题
//void Combination(char* pCharacters, int n, char* res, char* pBegin){
//    if(*pBegin == '\0'){
//        cout << res << endl;
//    }
//    for(int i = 0; i < n; ++i){
//        bool visited = false;
//        for(int j = 0 ; res[j]!='\0'; ++j){
//            if(res[j] == pCharacters[i]){
//                visited = true;
//                break;
//            }
//        }
//        if(visited) continue;
//        *pBegin = pCharacters[i];
//        Combination(pCharacters, n, res, pBegin+1);
//    }
//}
//void Combination(char* pCharacters){
//    if(!pCharacters) return ;
//    for(int m = 1; m < sizeof(pCharacters)/sizeof(pCharacters[0]); ++m){
//        char res[m+1];
//        res[m] = '\0';
//        Combination(pCharacters, sizeof(pCharacters)/sizeof(pCharacters[0]), res, res);
//    }
//}