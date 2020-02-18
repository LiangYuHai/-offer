//面试题44 扑克牌的顺子
// Created by Administrator on 2020/2/17 0017.
//

#include <iostream>
int Compare(const void *arg1, const void *arg2){
    return *(int*)arg1 - *(int*)arg2;
}
bool IsContinuous(int* numbers, int length){
    if(!numbers || length < 1) return false;
    qsort(numbers, length, sizeof(int), Compare);
    int numberOfzeros = 0;
    for(int i = 0; i < length; ++i){
        if(numbers[i] == 0) numberOfzeros++;
    }
    int small = numberOfzeros;
    int big = small+1;
    int spans = 0;
    while(big <= length-1){
        if(numbers[big] == numbers[small]) return false;
        spans += numbers[big] - numbers[small] - 1;
        big++;
        small++;
    }
    return spans <= numberOfzeros;
}