//小招喵喜欢在数轴上跑来跑去，假设它现在站在点n处，它只会3种走法，分别是：
//1.数轴上向前走一步，即n=n+1
//2.数轴上向后走一步,即n=n-1
//3.数轴上使劲跳跃到当前点的两倍，即n=2*n
//现在小招喵在原点，即n=0，它想去点x处，快帮小招喵算算最快的走法需要多少步？
// Created by Administrator on 2020/3/19 0019.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(int x){
    if(x == 0 || x == 1) return x;
    vector<int> dp(x+1,0);
    dp[0] = 0;
    dp[1] = 1;
    for(auto i = 2; i < x+1; ++i){
        if(i % 2 == 0) dp[i] = 1 + min(dp[i-1], dp[i/2]);
        else dp[i] = 1 + min(dp[i-1], 1 + dp[(i+1)/2]);
    }
    return dp[x];
}

int main(){
    int x;
    while(cin >> x){
        cout << solution(abs(x)) << endl;
    }
    return 0;
}