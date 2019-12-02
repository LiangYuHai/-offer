//Liangyuhai
// Created by Administrator on 2019/11/29 0029.
//A1 A2是两个有序数组，A1有足够的空间容纳A2，把A2的数插入A1中，并且所有数字都是有序的。

#include <iostream>
using std::cout; using std::cin; using std::endl;

int* insert(int* A1, int* A2, int A1_len, int A2_len){
    int pre = A1_len-1;
    int behind = A1_len + A2_len -1;
    for(int k = A2_len-1; k>=0; --k) {
        while (A2[k] < A1[pre]) {
            A1[behind] = A1[pre--];
            --behind;
        }
        A1[behind--] = A2[k];
    }
    return A1;
}
//========测试代码 test code =========

void Test1(){
    int A1[100] = {1, 2, 4, 8, 12};
    int A2[] = {3, 5, 9, 13};
    int res[] = {1,2,3,4,5,8,9,12,13};
    int i = 0;
    int* A = insert((int*)A1, (int*)A2, 5, 4);
    for(auto a : res){
        if(A[i] != a){
            cout << "Fail" << endl;
            return;
        }
        ++i;
    }
    cout << "Pass" << endl;
}

void Test2(){
    int A1[100] = {1, 2, 4, 8, 12};
    int A2[1] = {};
    int res[] = {1, 2, 4, 8, 12};
    int i = 0;
    int* A = insert(A1, A2, 5, 0);
    for(auto a : res){
        if(A[i] != a){
            cout << "Fail" << endl;
            return;
        }
        ++i;
    }
    cout << "Pass" << endl;
}
void Test3(){
    int A1[100] = {};
    int A2[] = {3, 5, 9, 13};
    int res[] = {3, 5, 9, 13};
    int i = 0;
    int* A = insert(A1, A2, 0, 4);
    for(auto a : res){
        if(A[i] != a){
            cout << "Fail" << endl;
            return;
        }
        ++i;
    }
    cout << "Pass" << endl;
}

void Test4(){
    int A1[100] = {5,6};
    int A2[] = {1,2,3,4};
    int res[] = {1,2,3,4,5,6};
    int i = 0;
    int* A = insert(A1, A2, 2, 4);
    for(auto a : res){
        if(A[i] != a){
            cout << "Fail" << endl;
            return;
        }
        ++i;
    }
    cout << "Pass" << endl;
}

void Test5(){
    int A1[100] = {1,2,3,4};
    int A2[] = {5,6};
    int res[] = {1,2,3,4,5,6};
    int i = 0;
    int* A = insert(A1, A2, 4, 2);
    for(auto a : res){
        if(A[i] != a){
            cout << "Fail" << endl;
            return;
        }
        ++i;
    }
    cout << "Pass" << endl;
}

int main(){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}