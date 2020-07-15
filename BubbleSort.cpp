//冒泡排序
// Created by Administrator on 2020/3/9 0009.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> BubbleSort(vector<T> numbers){
    if(numbers.empty()) return;
    for(int i = 1; i <numbers.size(); ++i){
        bool flag = true;
        for(int j = 0; j < numbers.size()-i; ++j){
            if(numbers[j] > numbers[j+1]){
                T temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
                flag = false;
            }
        }
        if(flag) break;
    }
    return numbers;
}