//面试题47 不用加减乘除做加法

#include <iostream>

int Add(int num1, int num2){
    int sum, carry;
    while(num2 != 0){
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    return num1;
}

//不用新变量交换两值
int exchange(int* num1, int* num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}