//面试题29. 数组中出现次数超过一半的数字
// Created by Administrator on 2020/1/31 0031.
//


//O(n)时间复杂度
int Partition(int* data, int start, int end){
    if(!data || start >= end) return start;
    int small = start - 1 ;
    for(int i = start; i <= end -1; ++i){
        if(data[i] < data[end]){
            small++;
            if(small != i){
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
    return small;
}

bool InputInvalid = false;

bool CheckMoreThanHalf(int* data, int length, int res){
    int count = 0;
    for(auto i = 0; i < length; ++i){
        if(res == data[i]) count++;
    }
    return count*2 > length;
}

int MoreThanHalfNum(int* data, const int length){
    if(!data || length <= 0){
        InputInvalid = true;
        return 0;
    }
    int start = 0;
    int end = length - 1;
    int middle = length >> 1;
    int index = Partition(data, start, end);
    while(index != middle){
        if(index < middle){
            index = Partition(data, index+1, end);
        }
        if(index > middle){
            index = Partition(data, start, index-1);
        }
    }
    int res = data[middle];
    if(!CheckMoreThanHalf(data, length, res)){
        InputInvalid = true;
        return 0;
    }
    return res;
}


//方法2 时间复杂度O（n），但无需修改data数组

int MoreThanHalfNum2(int* data, int length){
    if(!data || length <= 0){
        InputInvalid = true;
        return 0;
    }
    int count = 1;
    int res = data[0];
    for(int i = 1; i < length; ++i){
        if(count == 0){
            res = data[i];
            count = 1;
        }
        if(data[i] == res){
            count++;
        }else{
            count--;
        }
    }
    if(!CheckMoreThanHalf(data, length, res)){
        InputInvalid = true;
        return 0;
    }
    return res;
}
