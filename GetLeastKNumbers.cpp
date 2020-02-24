//面试题30. 最小的k个数
// Created by Administrator on 2020/1/31 0031.
//
#include <iostream>
using namespace std;

//时间复杂度O（n），输入数组会被修改。允许修改时可以用此方法。
int Partition(int* data, int start, int end){
    if(!data || start >= end) return start;
    int small = start - 1;
    for(int i = start; i <= end-1; i++){
        if(data[i] < data[end]){
            small++;
            if(i != small){
                int temp = data[i];
                data[i] = data[small];
                data[small] = temp;
            }
        }
    }
    small++;
    int temp = data[end];
    data[end] = data[small];
    data[small] = temp;
    return small
}

void GetLeastKNumbers(int* data, int length, int k){
    if(!data || length < k || !k) return ;
    int start = 0;
    int end = length-1;
    int index = Partition(data, start, end);
    while (index != k-1){

        if(index < k-1){
            index = Partition(data, index + 1, end);
        }

        if(index > k-1){
            index = Partition(data, start, index-1);
        }
    }
    for(auto i = 0; i <= index; ++i){
        cout << data[i] << endl;
    }
}

//O（nlogk），虽然比第一种方法慢，但适合处理海量数据
//如果不能把海量数据一次性读入内存，我们可以从硬盘中每次读入一个数字，
//判断要不要放入LeastNumbers容器即可。
//构建一个容量大小为k的容器--最大堆，由于从头实现最大堆需要大量时间，
//可以采用基于红黑树的是set和multiset。
//以下采用multiset
#include <vector>
#include <set>
void GetLeastNumbers(const vector<int>& data, multiset<int, greater< >>& leastNumbers, int k){
    leastNumbers.clear();
    if(data.empty() || data.size() < k || k <= 0) return ;
    for(auto iter = data.begin(); iter != data.end(); ++iter){
        if(leastNumbers.size() < k){
            leastNumbers.insert(*iter);
        }else{
            auto iterLeastNumber = leastNumbers.begin();
            if(*iter < *iterLeastNumber){
                leastNumbers.erase(iterLeastNumber);
                leastNumbers.insert(*iter);
            }
        }
    }
    for(auto iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter){
        cout << *iter << endl;
    }
}