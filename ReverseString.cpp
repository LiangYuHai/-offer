//面试题42. 翻转单词顺序 VS 左旋转字符串
// Created by Administrator on 2020/2/9 0009.
//

void Reverse(char* pBegin, char* pEnd){
    if(!pBegin || !pEnd) return ;
    while(pBegin < pEnd){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        ++pBegin;
        --pEnd;
    }
}

char* ReverseString(char* pStr){
    if(!pStr) return pStr;
    char* pBegin = pStr;
    char* pEnd = pStr;
    while(*pEnd != '\0'){
        pEnd++;
    }
    --pEnd;
    Reverse(pBegin, pEnd);
    pBegin = pEnd = pStr;
    while (*pBegin != '\0'){
        if(*pEnd == ' ' || *pEnd == '\0'){
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else if(*pBegin == ' '){
            pBegin++;
            pEnd++;
        }
        else pEnd++;
    }
    return pStr;
}

#include <string>
using namespace std;
char* LeftRotateString(char* pStr, int n){
    if(!pStr || n < 0) return pStr;
    int length = strlen(pStr);
    char* pFirstBegin = pStr;
    char* pFirstEnd = pStr+n-1;
    char* pSecondBegin = pStr + n;
    char* pSecondEnd = pStr + length-1;
    Reverse(pFirstBegin, pFirstEnd);
    Reverse(pSecondBegin, pSecondEnd);
    Reverse(pFirstBegin, pSecondEnd);
    return  pStr;
}