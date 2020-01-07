//面试题8： 旋转数组的最小数字
// Created by Administrator on 2020/1/7 0007.
//
#include <iostream>
using namespace std;
int minInOrder(int* data, int length, int start, int end){
    int min = start;
    int i;
    for(i = start+1; i <= end; ++i){
        if(data[i] < data[min]){
            min = i;
        }
    }
    return min;
}
int minOfRotatedArray(int* data, int length){
    if(!data || length<=0)
        throw new exception("Invalid Parameters");
    int start = 0;
    int end = length-1;
    int mid = 0;
    while(data[start] >= data[end]){
        if(end-start == 1){
            mid = end;
            break;
        }
        mid = (start+end)/2;
        if(data[start] == data[mid] && data[mid] == data[end]){
            mid = minInOrder(data, length, start, end);
            break;
        }
        if(data[mid]>=data[start]){
            start = mid;
        }
        else if(data[mid]<=data[end]){
            end = mid;
        }
    }
    return data[mid];
}

void test1(){
    int data[]={4,5,6,1,2,3};
    int length = sizeof(data)/ sizeof(*data);
    int gt = 1;
    if(minOfRotatedArray(data, length) == gt)
        cout<<"True"<<endl;
    else{
        cout<<"False"<<endl;
    }
}

void test2(){
    int data[]={1,2,3,4,5,6};
    int length = sizeof(data)/ sizeof(*data);
    int gt=1;
    if(minOfRotatedArray(data, length) == gt){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}

void test3(){
    int data[] = {1};
    int length = 0;
    minOfRotatedArray(data, length);
}

void test4(){
    int data[] = {1,0,1,1,1};
    int length = sizeof(data)/ sizeof(*data);
    int gt = 0;
    if(gt == minOfRotatedArray(data, length)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

}

void test5(){
    int data[] = {1,1,1,0,1};
    int length = sizeof(data)/ sizeof(*data);
    int gt = 0;
    if(gt == minOfRotatedArray(data, length)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

}
int main(){
    test1();
    test2();
//    test3();
    test4();
    test5();
}

