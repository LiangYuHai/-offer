//面试题41 和为S的两个数VS和为S的连续正数序列
// Created by Administrator on 2020/2/9 0009.
//

bool FindNumberWithSum(int* data, int length, int sum, int* num1, int* num2){
    if(!data || length < 2) return false;
    int start = 0;
    int end = length-1;
    while(start < end){
        if(data[start] + data[end] == sum){
            *num1 = data[start];
            *num2 = data[end];
            return true;
        } else if (data[start] + data[end] > sum){
            --end;
        } else{
            ++start;
        }
    }
    return false;
}

void PrintSequence(int small, int big){
    for(int i = samll ; i <= big; ++i){
        cout << i << ' ';
    }
    cout << endl;
}

void FindContinuousSequence(int sum){
    if(sum < 3) return ;
    int small = 1;
    int big = 2;
    int end = (sum+1)/2;
    int curSum = small + big;
    while(small < end){
        if(curSum == sum){
            PrintSequence(small, big);
            big++;
            curSum += big;
        }
        else if(curSum > sum){
            curSum -= small;
            ++small;
        }
        else{
            ++big;
            curSum += big;
        }
    }
    return ;
}