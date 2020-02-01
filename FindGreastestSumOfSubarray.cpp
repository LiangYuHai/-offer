//面试题31 连续子数组的最大和
// Created by Administrator on 2020/2/1 0001.
//
bool InputInvalid = false

int FindGreastestSumOfSubarray(int* data, int length){
    if(!data || length <=0){
        InputInvalid = true;
        return 0;
    }
    int curSum = 0;
    int res = INT_MIN;
    for(int i = 0; i < length; ++i){
        if(curSum <= 0){
            curSum = data[i];
        }
        else{
            curSum += data[i];
        }
        if(curSum > res){
            res = curSum;
        }
    }
    return res;
}

