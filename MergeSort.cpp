//归并排序 O（nlogn）
// Created by Administrator on 2020/3/9 0009.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> helper(vector<int> numbers, unsigned int start, unsigned int end){
    vector<int> res;
    if(start >= end){
         res.push_back(numbers[start]);
         return res;
    }
    unsigned int mid = (start+end)/2;
    vector<int> left = helper(numbers, start, mid);
    vector<int> right = helper(numbers, mid+1, end);

    unsigned int i = 0;
    unsigned int j = 0;
    while (i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            res.push_back(left[i]);
            i++;
            continue;
        }
        if(left[i] > right[j]){
            res.push_back(right[j]);
            j++;
            continue;
        }
        if(left[i] == right[j]){
            res.push_back(left[i]);
            res.push_back(right[j]);
            i++;
            j++;
            continue;
        }
    }
    if(i != left.size()){
        for(; i < left.size(); i++){
            res.push_back(left[i]);
        }
    }
    if(j != right.size()){
        for(; j < right.size(); j++){
            res.push_back(right[j]);
        }
    }
    return res;
}
vector<int> gsort(vector<int> numbers){
    if(numbers.empty()) return numbers;
    vector<int> res = helper(numbers, 0, numbers.size()-1);
    return res;
}

int main(){
    vector<int> test1 = {1,0,6,4,7};
    vector<int> res = gsort(test1);
    for(auto &a : res){
        cout << a << endl;
    }
}