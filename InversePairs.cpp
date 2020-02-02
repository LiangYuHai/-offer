//面试题36 数组中有多少逆序对
// Created by Administrator on 2020/2/2 0002.
//

#include <iostream>

int InversePairsCore(int* data, int* copy, int start, int end){
    if(!data || start >= end) return 0;
    int length = (end - start)/2;
    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);
    int i = start + length;
    int j = end;
    int count = 0;
    int index = end;
    while (i >= start && j >= start + length +1){
        if(data[i] > data[j]){
            count += j - start - length;
            copy[index--] = data[i--];
        }else{
            copy[index--] = data[j--];
        }
    }
    for(; i >= start; --i){
        copy[index--] = data[i];
    }
    for(; j >= start + length + 1; --j){
        copy[index--] = data[j];
    }
    return left + right + count;
}

int InversePairs(int* data, int length){
    if(!data || length <= 0) return 0;
    int* copy = new int[length];
    for(int i = 0; i < length; ++i){
        copy[i] = data[i];
    }
    int start = 0;
    int end = length - 1;
    int res = InversePairsCore(data, copy, start, end);
    delete [] copy;
    return res;
}

void test1(){
    int data[4] = {7, 5, 6, 4};
    std::cout << InversePairs(data, 4) << std::endl;
}

int main(){
    test1();
}