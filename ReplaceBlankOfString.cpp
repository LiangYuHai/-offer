//面试题4 字符串空格替换成%20
// Created by Administrator on 2019/11/29 0029.
//考查字符串

#include <iostream>
bool InputInvalid = false;
char* ReplaceBlank(char* str, int length){
    if(!str || length < 1){
        InputInvalid = true;
        return nullptr;
    }

    int numOfBlank = 0;
    int originalLength = 0;
    int i = 0
    while(str[i] != '\0'){
        ++originalLength;
        if(*str == ' ') ++numOfBlank;
        ++i;
    }
    int newLength = originalLength + 2*numOfBlank;
    if(newLength > length){
        InputInvalid = false;
        return nullptr;
    }
//    str[newLength--] = '\0';
    while(originalLength >= 0 && newLength > originalLength){
        if(str[originalLength] == ' '){
            str[newLength--] = '0';
            str[newLength--] = '2';
            str[newLength--] = '%';
        }else{
            str[newLength] = str[originalLength--];
        }
    }
    return str;
}