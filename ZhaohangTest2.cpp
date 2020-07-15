//
// Created by Administrator on 2020/4/29 0029.
//链接：https://ac.nowcoder.com/acm/contest/5246/B
//来源：牛客网
//
// 在一场集体婚礼上，有n对新人需要坐在连续排列的 2n个座位上合影，同一对新人彼此挨着。由于进场时各对新人并未按序入座，请计算最少交换座位的次数，以便使每对新人均可并肩坐在一起。一次交换可选择任意两人，让他们互换座位。
//       全部新人的序号可用 0 到 2n-1 的整数表示，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)。
//       row[i]指最初坐在第 i 个座位上的新人编号，i是从0到（2n-1）的一个升序全排列，row不存在重复值。
//输入描述:
//输入共有2行，第一行为n，即共有多少对新人(2≤n≤100000 )，第二行为row，即2n个座位上的初始新人编号。
//输出描述:
//输出最少交换座位的次数。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//template <typename T>
//
//int helper2(vector<int>& test, int& res, int i, int n){
//    for(int j = i+1; j < 2*n-1; ++j){
//        if(abs(test[i]-test[j]) == 1){
//            if((j & 1) == 1){
//                if(abs(test[j-1] - abs(test[i+1])) == 1){
//                    int temp = test[j];
//                    test[j] = test[i+1];
//                    test[i+1] = temp;
//                    res++;
//                }else{
//                    helper(test, res, i+1, n)
//                }
//            }else{
//                if(abs(test[j+1] - abs(test[i+1])) == 1){
//                    int temp = test[j];
//                    test[j] = test[i+1];
//                    test[i+1] = temp;
//                    res++;
//                }
//            }
//        }
//    }
//}
bool check(vector<int>& test){
    for(int i = 0; i < test.size()-1; ++i){
        if(abs(test[i]-test[i+1]) != 1){
            return false;
        }
    }
    return true;
}

void helper(int index, vector<int>& test, int& res, int n, int cur){
    if(index == 2*n-1){
        res = min(res, cur);
        return ;
    }else{
        for(int i = index; i < 2*n; ++i){
            int temp = test[index];
            test[index] = test[i];
            test[i] = temp;
            cur++;
            if(check(test)){
                res = min(res, cur);
                break;
            }

            helper(index+1, test, res, n, cur);
            temp = test[index];
            test[index] = test[i];
            test[i] = temp;
            --cur;

        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> test(2*n);
    for(int i = 0; i < 2*n; ++i){
        cin >> test[i];
    }
    int res = 9999;
    int index = 0;
    int cur = 0;
    helper(index, test, res, n, cur);
    cout << res << endl;
    return 0;
}