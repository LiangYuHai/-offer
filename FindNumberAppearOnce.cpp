//面试题40 找在数组中只出现一次的数
// Created by Administrator on 2020/2/4 0004.
//

#include <iostream>

unsigned int GetFirst1Index(int exclusiveOrRes){
    int index = 0;
    int n = 1;
    while(exclusiveOrRes & 0x1 != 1 && index <= 8*sizeof(int)){
        exclusiveOrRes >> 1;
        index++;
    }
    return index;
}

bool IsIndexBit1(int num, int index){
    num >> index;
    return num & 1 == 1;
}

void FindNumberAppearOnce(int* data, int length, int* num1, int* num2){
    if(!data || length < 2) return ;
    int exclusiveOrRes = 0;
    for(int i = 0; i < length; i++){
        exclusiveOrRes ^= data[i];
    }
    unsigned int indexOf1 = GetFirst1Index(exclusiveOrRes);
    *num1=*num2=0;
    for(int i = 0; i < length; ++i){
        if(IsIndexBit1(data[i], indexOf1)){
            *num1 ^= data[i];
        }else{
            *num2 ^= data[i];
        }
    }
}