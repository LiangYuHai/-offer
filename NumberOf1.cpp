//面试题10 位运算
// Created by Administrator on 2020/1/24 0024.
//
#include <math.h>
#include <iostream>
using namespace std;

int NumberOf1(int n){
    int count = 0;
    while(n){
        if(n & 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}
//以上方法若n为负数将造成死循环；
//虽然向右移动一位相当于除以2，但不能应尽力用右移运算，除法效率低。

int NumberOf1Optimized(int n){
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(flag & n){
            count++;
        }
        flag = flag << 1;
    }
    return count;
}
//以上方法时间复杂度度为整形二进制的位数，int 32位需要移动32次。
//以下方法优化时间复杂度为二进制中1的个数。
int NumberOf1Optimized2(int n){
    int count = 0;
    while(n){
        count++;
        int m = n-1;
        n = n&m;
    }
    return count;
}
void test0(){
    int n = INT32_MAX;
    if(NumberOf1(n)==31){
        cout << "Test0 True"<< endl;
    }
    else{
        cout << "Test0 False" << endl;
    }
    if(NumberOf1Optimized(n) == 31){
        cout << "Test0 True" << endl;
    }
    else {
        cout << "Test0 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 31){
        cout << "Test0 True" << endl;
    }
    else {
        cout << "Test0 False" << endl;
    }
}

void test1(){
    int n = 2;
    if(NumberOf1(n)==1){
        cout << "Test1 True"<< endl;
    }
    else{
        cout << "Test1 False" << endl;
    }
    if(NumberOf1Optimized(n) == 1){
        cout << "Test1 True" << endl;
    }
    else {
        cout << "Test1 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 1){
        cout << "Test1 True" << endl;
    }
    else {
        cout << "Test1 False" << endl;
    }
}

void test2(){
    int n = 0;
    if(NumberOf1(n)==0) {
        cout << "Test2 True"<< endl;
    }
    else{
        cout << "Test2 False" << endl;
    }
    if(NumberOf1Optimized(n) == 0){
        cout << "Test2 True" << endl;
    }
    else{
        cout << "Test2 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 0){
        cout << "Test2 True" << endl;
    }
    else {
        cout << "Test2 False" << endl;
    }
}

void test3(){
    int n = pow(2,30);
    cout << sizeof(n) << endl;
    if(NumberOf1(n)==1){
        cout << "Test3 True"<< endl;
    }
    else{
        cout << "Test3 False" << endl;
    }
    if(NumberOf1Optimized(n) == 1){
        cout << "Test3 True" << endl;
    }
    else {
        cout << "Test3 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 1){
        cout << "Test3 True" << endl;
    }
    else {
        cout << "Test3 False" << endl;
    }
}

void test4(){
    int n = 3;
    if(NumberOf1Optimized(n) == 2){
        cout << "Test4 True" << endl;
    }
    else {
        cout << "Test4 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 2){
        cout << "Test4 True" << endl;
    }
    else {
        cout << "Test4 False" << endl;
    }
}

void test5(){
    int n = -2;
//    负数用补码表示 注意： 负数的补码是在其原码的基础上，符号位不变，其余位取反，然后加1
    if(NumberOf1Optimized(n) == 31){
        cout << "Test5 True" << endl;
    }
    else{
        cout << NumberOf1Optimized(n) << endl;
        cout << "Test5 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 31){
        cout << "Test5 True" << endl;
    }
    else{
        cout << NumberOf1Optimized2(n) << endl;
        cout << "Test5 False" << endl;
    }
}

void test6(){
    int n = INT32_MIN;
//    负数用补码表示 注意： 负数的补码是在其原码的基础上，符号位不变，其余位取反，然后加1
    if(NumberOf1Optimized(n) == 1){
        cout << "Test6 True" << endl;
    }
    else{
        cout << NumberOf1Optimized(n) << endl;
        cout << "Test6 False" << endl;
    }
    if(NumberOf1Optimized2(n) == 1){
        cout << "Test6 True" << endl;
    }
    else{
        cout << NumberOf1Optimized2(n) << endl;
        cout << "Test6 False" << endl;
    }
}

int main(){
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
