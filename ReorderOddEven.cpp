//面试题14 调整数组顺序使奇数位于偶数前
// Created by Administrator on 2020/1/28 0028.
//
#include <iostream>
using namespace std;

int* ReorderOddEven(int* number, unsigned int length){
    if(number == nullptr || length <= 1) return number;
    int* start = number;
    int* end = number+length-1;
    while((end-start)>0){
        while((*start & 0x1)){
            ++start;
        }
        while(!(*end & 0x1)){
            --end;
        }
        if((start < end)){
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
    return number;
}

//将函数解耦，能够扩展问题，秒杀offer。
int* Reorder(int* number, unsigned int length, bool (*func)(int)){
    if(number == nullptr || length <= 1) return number;
    int* start = number;
    int* end = number+length-1;
    while(start < end){
        while(!func(*start)){
            ++start;
        }
        while(func(*end)){
            --end;
        }
        if(start < end){
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
    return number;
}

bool isEven(int n){
    return (n & 1) == 0;
}

bool isNegtive(int n){
    return n < 0;
}

bool isDiviedBy3(int n){
    return n % 3 == 0;
}

int main(){
    int data[] = {0,1,2,3,4,7};
    int* res =  Reorder(data, sizeof(data)/ sizeof(*data), isDiviedBy3);
    for(int i = 0; i < sizeof(data)/ sizeof(*data); ++i){
        cout << res[i] << endl;
    }
}
