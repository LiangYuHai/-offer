//49 atoi
// Created by Administrator on 2020/2/18 0018.
//

#include <iostream>
using namespace std;

bool InputInvalid = true;
long long atoi(char* str){
    if(!str) {
        return 0;
    }
    bool minus = false;
    if(*str == '+') str++;
    if(*str == '-'){
        minus = true;
        ++str;
    }
    if(*str == '\0'){
        return 0;
    }
    long long number = 0;
    unsigned short int flag = minus ? 1 : -1;
    while(*str != '\0'){
        if(*str < '0' || *str > '9' || (minus && number > 0x7fffffff) || (!minus && number < 0x80000000)) return 0;
        number = 10*number + flag*(*str - '0');
    }
    InputInvalid = false;
    return minus ? -number : number;
}

