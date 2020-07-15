//
// Created by Administrator on 2020/3/11 0011.
//
#include <iostream>
using namespace std;
void RotateMatrix(int** a, int rows, int cols){
    int** b = new int*[rows];
    for(int i = 0; i < rows; ++i){
        b[i] = new int[cols];
    }
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j<cols; ++j){
            b[rows-j-1][i] = a[i][j];
        }
    }
    a = b;
    delete[] b;
    b = nullptr;
}
//不用外部空间，n阶
void RotateMatrix2(int a[][3], int n){
    for(int i = 0; i < n>>1; ++i){
        for(int j = i; j < n-1-i; ++j){
            int temp = a[i][j];
            a[i][j] = a[j][n-1-i];
            a[j][n-1-i] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[n-1-j][i];
            a[n-1-j][i] = temp;
        }
    }
}

int main(){
    int a[3][3] = {1,2,3,4,5,6,7,8,9};
    RotateMatrix2(a, 3);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << a[i][j] << endl;
        }
    }
}
//
//#include<stdio.h>
//void print(int a[][10]){
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            printf("%3d",a[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main(){
//    int a[10][10];
//    int k = 0;
//    //原图像
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            a[i][j] = k++;
//        }
//    }
//    //顺时针旋转90
//    int shun90[10][10];
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            shun90[j][9-i] = a[i][j];
//        }
//    }
//    //逆时针旋转90
//    int ni90[10][10];
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            ni90[9-j][i] = a[i][j];
//        }
//    }
//    //旋转180
//    int zhuan180[10][10];
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            zhuan180[9-i][9-j] = a[i][j];
//        }
//    }
//    printf("原图像\n\n");
//    print(a);
//    printf("\n\n顺时针90\n\n");
//    print(shun90);
//    printf("\n\n逆时针90\n\n");
//    print(ni90);
//    printf("\n\n转180\n\n");
//    print(zhuan180);