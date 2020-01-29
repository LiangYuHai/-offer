//面试题20 顺时针打印矩阵
// Created by Administrator on 2020/1/29 0029.
//

#include <iostream>
using namespace std;
void PrintCircle(int** numbers, int columns, int rows, int start){
    int endX = columns-1-start;
    int endY = rows-1-start;

//  左->右
    for(auto i = start; i <= endX; ++i){
        cout << numbers[start][i] << " ";
    }
    if(endY > start){
        for(auto i = start+1; i <= endY; ++i){
            cout << numbers[i][endX] << " ";
        }
    }
    if(endY > start && endX > start){
        for(auto i = endX-1; i >= start; --i){
            cout << numbers[endY][i] << " ";
        }
    }
    if(endY-1> start && endX > start){
        for(auto i = endY-1; i >= start+1; --i){
            cout << numbers[i][start] << " ";
        }
    }
}
void PrintMatrixClockwisely(int** numbers, int columns, int rows){
    if(!numbers || columns <= 0 || rows <= 0) return ;
    int start = 0;
    while(columns > 2*start && rows > 2*start){
        PrintCircle(numbers, columns, rows, start);
        ++start;
    }
}

void test1(){
    int M[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int* numbers[3];                //指针数组
    for(auto i = 0; i<3; ++i){      //每个指针指向一个数组
        numbers[i] = M[i];
    }
    int columns = 3;
    int rows = 3;
    PrintMatrixClockwisely(numbers, columns, rows);
}

void test2(){
    int** numbers;
    int M[3][3] = {0};
    int* m[3];
    for(int i = 0; i < 3; ++i){
        m[i] = M[i];
    }
    numbers = m;
    PrintMatrixClockwisely(numbers, 3, 3);
}

void test3(){
    int* numbers[1];
    int M[1][1];
    numbers[0] = M[0];
    PrintMatrixClockwisely(numbers, 1, 1);
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}