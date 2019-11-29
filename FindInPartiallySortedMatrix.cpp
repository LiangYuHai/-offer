//
// Created by Administrator on 2019/11/29 0029.
//二维数组中的查找：在一个二维数组中，每一行从左到右递增，
//每一列从左到右递增。输入这样一个二维数组和一个整数，判断
//数组中是否有该整数。
#include <iostream>

bool Find(int* matrix, int rows, int columns, int number){
    if(!matrix || !rows || !columns) return false;
    int row = 0, col = columns-1;
    while(row < rows && col >=0){
        if(matrix[row*columns + col] == number) return true;
        if(matrix[row*columns + col] > number) --col;
        if(matrix[row*columns + col] < number) ++row;
    }
    return false;
}


//================测试代码 test code ================

void Test1(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = 8;
    bool res = true;
    if(Find((int*)matrix, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}

void Test2(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = 7;
    bool res = false;
    if(Find((int*)matrix, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}

void Test3(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = 1;
    bool res = true;
    if(Find((int*)matrix, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}
void Test4(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = 12;
    bool res = true;
    if(Find((int*)matrix, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}

void Test5(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = 12;
    bool res = false;
    if(Find(nullptr, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}
void Test6(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = -1;
    bool res = false;
    if(Find((int*)matrix, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}
void Test7(){
    int matrix[][4] = {{1,2,4,6},{2,3,8,9},{4, 5,9,10},{5,8,11,12}};
    int number = 100;
    bool res = false;
    if(Find((int*)matrix, 4, 4, number) == res){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}