//面试题33 使数组中的整数拼接成一个最小整数
// Created by Administrator on 2020/2/1 0001.
//
#include <iostream>
#include <string>
using namespace std;
bool InputInvalid = false;

int compare(const void* str1, const void* str2){
    char* strCombine1 = new char[2*10+1];
    char* strCombine2 = new char[2*10+1];
    strcpy(strCombine1, *(const char**)str1);
    strcat(strCombine1, *(const char**)str2);

    strcpy(strCombine2, *(const char**)str2);
    strcat(strCombine2, *(const char**)str1);

    int res = strcmp(strCombine1, strCombine2);
    delete [] strCombine1;
    delete [] strCombine2;
    return res;
}

void SortArrayForMinNumber(int* data, int length){
    if(!data || length <= 0){
        InputInvalid = true;
        return ;
    }

    char** strNumbers = (char**)(new int[length]);
    for(int i = 0; i < length; ++i){
        strNumbers[i] = new char[10+1];
        sprintf(strNumbers[i], "%d", data[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare);

    for(int i = 0; i < length; ++i){
        cout<<strNumbers[i];
    }
    cout << endl;

    for(int i=0; i<length; ++i){
        delete [] strNumbers[i];
    }
    delete[] strNumbers;
}


int compare2(const void* str1, const void* str2){
    string strCombine1 = *(const string*)str1 + *(const string*)str2;
    string strCombine2 = *(const string*)str2 + *(const string*)str1;
    return strCombine1 > strCombine2;
}

void SortArrayForMinNumber2(int* data, int length){
    if(!data || length <= 0) return ;
    string* strNumbers = new string[length];
    for(int i = 0; i < length; ++i){
        strNumbers[i]=to_string(data[i]);
    }
    qsort(strNumbers, length, sizeof(string), compare2);
    for(int i = 0; i < length; ++i){
        cout << strNumbers[i];
    }
    cout << endl;
}

void test1(){
    int data[3] = {3,321,33};
    int length = sizeof(data)/sizeof(data[0]);
    cout << sizeof(string);
    SortArrayForMinNumber2(data, length);
}

int main(){
    test1();
}