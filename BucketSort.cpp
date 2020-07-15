//
// Created by Administrator on 2020/3/10 0010.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BucketSort(vector<int>& numbers){
    if(numbers.size() <= 1) return;
    int min = *max_element(numbers.begin(), numbers.end());
    int max = *min_element(numbers.begin(), numbers.end());
    int bucketNum = (max-min)/numbers.size()+1;
    vector<vector<int>> bucketArray(bucketNum);
    for(auto &a : numbers){
        unsigned int bucketIndex = (a-min)/numbers.size();
        bucketArray[bucketIndex].push_back(a);
    }

    for(int i = 0; i < bucketNum; ++i){
        sort(bucketArray[i].begin(), bucketArray[i].end());
    }
    unsigned int index = 0;
    for(auto & i : bucketArray) {
        if(i.empty()) continue;
        for (auto &a : i) {
            numbers[index++] = a;
        }
    }
}

int main(){
    vector<int> test = {0,2,7,4,6,9};
    BucketSort(test);
    for(auto a : test){
        cout << a << endl;
    }
}