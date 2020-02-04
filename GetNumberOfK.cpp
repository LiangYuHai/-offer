//面试题38 统计排序数组中某个数出现的次数
// Created by Administrator on 2020/2/3 0003.
//

#include <iostream>

int GetFirstK(int* data, int k, int start, int end){
    if(start > end) return -1;
    int res;
    int middle = (start + end)/2;
    if(data[middle] > k)
        res = GetFirstK(data, k, start, middle-1);
    if(data[middle] < k)
        res = GetFirstK(data, k, middle+1, end);
    if(data[middle] == k){
        if((middle != 0 && data[middle-1]!=k) || middle == 0 ) res = middle;
        else{
            res = GetFirstK(data, k, start, middle-1);
        }
    }
    return res;
}

int GetLastK(int* data, int k, int start, int end){
    if(start > end) return -1;
    int middle = (start + end)/2;
    if(data[middle] > k)
        end = --middle;
    else if(data[middle] < k)
        start = ++middle;
    else
        if((middle != (sizeof(data)/sizeof(data[0]) -1) && data[middle+1] !=k) || middle == (sizeof(data)/sizeof(data[0]) -1))
            return middle;
        else
            start = ++middle;
    return GetFirstK(data, k, start, end);
}

int GetNumberOfK(int* data, int k, int length){
    if(!data) return -1;
    int firstKIndex = GetFirstK(data, k, 0, length-1);
    int lastKIndex = GetLastK(data, k, 0, length-1);
    return lastKIndex-firstKIndex+1;
} b