//面试题34 丑数
// Created by Administrator on 2020/2/2 0002.
//

#include <iostream>

bool IsUgly(int number){
    while(number % 2 == 0){
        number /= 2;
    }
    while(number % 3 == 0){
        number /= 3;
    }
    while(number % 5 == 0){
        number /= 5;
    }
    return number == 1;
}
bool InputInvalid = false;
int GetUglyNumber(int index){
    if(index <= 0){
        InputInvalid = true;
        return 0;
    }

    int count = 0;
    int number = 1;
    while(count != index){
        if(IsUgly(number)) count++;
        number++;
    }
    return number;
}

//方法一效率低；
//方法二以空间换时间；

int Min(const int a, const int b, const int c){
    int min = (a < b) ? a : b;
    return min = (min < c) ? min : c;
}

int GetUglyNumber2(int index){
    if(index <= 0){
        InputInvalid = true;
        return 0;
    }

    int* uglyNumbers = new int[index];
    uglyNumbers[0] = 1;
    int* pMultiply2 = uglyNumbers;
    int* pMultiply3 = uglyNumbers;
    int* pMultiply5 = uglyNumbers;
    int nextUglyIndex = 1;
    while(nextUglyIndex < index){
        uglyNumbers[nextUglyIndex] = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        while(*pMultiply2*2 <= uglyNumbers[nextUglyIndex])
            pMultiply2++;
        while(*pMultiply3*3 <= uglyNumbers[nextUglyIndex])
            pMultiply3++;
        while(*pMultiply5*5 <= uglyNumbers[nextUglyIndex])
            pMultiply5++;
        nextUglyIndex++;
    }
    int res = uglyNumbers[index-1];
    delete[] uglyNumbers;
    return res;
}
//这种方法不需要在非丑数上计算，但需要数组保存已有的丑数。
//如果要保存1500个丑数，需要4*1500 == 6K个字节(6KB)的空间消耗。