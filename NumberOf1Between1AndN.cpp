//面试题32 从1到n整数中1出现的次数
// Created by Administrator on 2020/2/1 0001.
//

#include <iostream>
//此方法时间复杂度O（n*logn）, 其中n有logn位。
//当n很大时，运算效率低。
int NumberOf1Between1AndN(int n){
    if(n <= 0) return 0;
    int res = 0
    for(unsigned int i = 1; i <= n ; ++i){
        while(i){
            if(i % 10 == 1) res++;
            i = i/10;
        }
    }
    return res;
}
//方法二，根据规律直接统计，代码暂时略。