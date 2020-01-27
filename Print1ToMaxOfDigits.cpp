//面试题12 打印1到最大的n位数
// Created by Administrator on 2020/1/27 0027.
//

#include <iostream>
using namespace std;

bool Increment(char* number){
    int length = strlen(number);
    bool isOverflow = false;
    int nTakeOver = 1;
    for(auto i = length-1; i>=0; --i){
        int sum = number[i] - '0' + nTakeOver;
        if(sum >= 10){
            if(i == 0){
                isOverflow = true;
            }else{
                number[i] = '0';
            }
        }else{
            number[i] = sum + '0';
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* number){
    int length = strlen(number);
    bool isPad = true;
    for(auto i = 0; i <= length-1; ++i){
        if(number[i]!='0' && isPad) {
            isPad = false;
        }
        if(!isPad){
            cout << number[i] ;
        }
    }
    cout << endl;
}

void Print1ToMaxDigits(int n){
    if(n <= 0) return;
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number)){
        PrintNumber(number);
    }
    delete []number;
}

void Print1ToMaxDigitsRecursively(char* number, int index, int n){
    if(index == n-1){
        PrintNumber(number);
        return ;
    }
    for(int i = 0; i < 10; ++i){
        number[index+1] = '0' + i;
        Print1ToMaxDigitsRecursively(number, index+1, n);
    }
}
void Print1ToMaxDigits2(int n){
    if(n <= 0)
        return ;
    char* number = new char[n+1];
//    memset(number, '0', n);
    number[n+1] = '\0';

    for(int i = 0; i <= 9; ++i){
        number[0] = i + '0';
        Print1ToMaxDigitsRecursively(number, 0, n);
    }
    delete []number;
}

int main(){
    Print1ToMaxDigits2(0);
    Print1ToMaxDigits2(-1);
    Print1ToMaxDigits2(2);
}