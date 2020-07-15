//
// Created by Administrator on 2020/3/9 0009.
//

#include <vector>
using namespace std;

template <typename T>
vector<T> SelectSort(vector<T> numbers){
    for(int i = 0 ; i < numbers.size()-1; ++i){
        int min = i;
        for(int j = i + 1; j < numbers.size(); ++j){
            if(numbers[j] < numbers[min]){
                min = j;
            }
        }
        if(min == i) continue;
        T temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
    return numbers;
}