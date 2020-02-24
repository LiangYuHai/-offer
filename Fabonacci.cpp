//面试题9.斐波那契数列递归迭代
// Created by Administrator on 2020/1/8 0008.
//青蛙跳台阶，覆盖矩阵

unsigned long Fabonacci_recursively(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return Fabonacci_recursively(n-1) + Fabonacci_recursively(n-2);
}

//时间复杂度大于O（n）,随着n的增大急剧增加
//递归由于函数调用自身，需要消耗时间和空间。
//每一次调用都需要在内存栈中保存参数、返回地址和临时变量（空间）
//往栈里压入和弹出数据都需要时间。
//因此效率不如迭代。

#include <iostream>
unsigned long Fabonacci_iteratively(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    unsigned long result = 0;
    unsigned long FABONACCIMINUSONE = 1;
    unsigned long FABONACCIMINUSTWO = 0;
    for(int i = 2; i <= n; ++i){
        result = FABONACCIMINUSONE + FABONACCIMINUSTWO;
        FABONACCIMINUSTWO = FABONACCIMINUSONE;
        FABONACCIMINUSONE = result;
    }
    return result;
}


//时间复杂度O（n）

//青蛙跳台阶题扩展
//unsigned long frogs(int n){
//    if(n <= 0) return 0;
//    if(n == 1) return 1;
//    unsigned long result =0;
//    for(int i = 1; i <= n-1; ++i){
//        result += frogs(i);
//    }
//    return result;
//}
void test1(){
    if(Fabonacci_recursively(4) == 3.0){
        std::cout<< "True" <<std::endl;
    }else{
        std::cout<< "False" << std::endl;
    }

    if(Fabonacci_iteratively(4) == 3.0){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}

void test2(){
    if(Fabonacci_recursively(5) == 5){
        std::cout<< "True" <<std::endl;
    }else{
        std::cout<< "False" << std::endl;
    }

    if(Fabonacci_iteratively(5) == 5){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}

void test3(){
    if(Fabonacci_recursively(0) == 0){
        std::cout<< "True" <<std::endl;
    }else{
        std::cout<< "False" << std::endl;
    }

    if(Fabonacci_iteratively(0) == 0){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}

void test4(){
    if(Fabonacci_recursively(1) == 1){
        std::cout<< "True" <<std::endl;
    }else{
        std::cout<< "False" << std::endl;
    }

    if(Fabonacci_iteratively(1) == 1){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}

void test5(){
    std::cout << Fabonacci_iteratively(10) << std::endl;
    std::cout << Fabonacci_recursively(10) << std::endl;
}
//
//void test6(){
//    if(frogs(10) == 2e9){
//        std::cout << frogs(10) << std::endl;
//        std::cout << "True" << std::endl;
//    }
//    else{
//        std::cout << "False" << std::endl;
//    }
//}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
//    test6();
}