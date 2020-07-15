//Liang Yuhai
// Created by Administrator on 2019/12/4 0004.
//快排

#include <stack>
#include <iostream>
using namespace std;

template <typename T>
int helper(T data[], int start, int end){
    if(!data || start==end) return start;
    int small = start-1;
    for(int i = start; i < end; ++i){
        if(data[i]<data[end]) {
            ++small;
            if (small != i) {
                T temp = data[i];
                data[i] = data[small];
                data[small] = temp;
            }
        }
    }
    ++small;
    T temp = data[end];
    data[end] = data[small];
    data[small] = temp;
    return small;
}


int helper2(int data[], int start, int end){
    if(!data || start == end) return start;
    int key = end;
    while(start < end){
        while (start < end && data[start] <= data[key]){
            ++start;
        }
        while(start < end && data[end] >= data[key]){
            --end;
        }
        int temp = data[start];
        data[start] = data[end];
        data[end] = temp;
    }
    int temp = data[start];
    data[start] = data[key];
    data[key] = temp;
    return start;
}

template <typename T>
void QuickSort(T data[], int start, int end){
    int size = sizeof(data)/sizeof(data[0]);
    if(!size) return ;
    int index = helper2(data,start,end);
    if(index>start){
        QuickSort(data, start, index-1);
    }
    if(index<end){
        QuickSort(data, index+1, end);
    }
}


//非递归

void QuickSort_stack(int data[], int length){
    if(!data) return ;
    stack<int> s;
    s.push(0);
    s.push(length-1);
    while(!s.empty()){
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        int index = helper2(data, left, right);
        if(index-1 > left){
            s.push(left);
            s.push(index-1);
        }
        if(index+1 < right){
            s.push(index+1);
            s.push(right);
        }
    }

}
int main(){
    int test[] = {0,2,6,1,3,5};
    QuickSort_stack(test, 6);
    for(auto &a: test){
        cout << a << endl;
    }
}