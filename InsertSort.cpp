//
// Created by Administrator on 2020/3/9 0009.
//

#include <vector>
using namespace std;

template <typename T>
vector<T> InsertSort(vector<T> numbers){
    if(numbers.empty()) return numbers;
    for(int i = 1; i < numbers.size(); ++i){
        T temp = numbers[i];
        int j = i;
        while(j > 0 && numbers[j-1] > temp){
            numbers[j] = numbers[j-1];
            --j;
        }
        if(j != i){
            numbers[j] = temp;
        }
    }
    return numbers;
}