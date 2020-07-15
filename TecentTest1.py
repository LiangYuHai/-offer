# 第一题：打怪  每个怪消耗ci点血，获取wi枚金币，每枚金币可以买m点血，共n个怪，最多赚多少金币。
# 打所有wi*m-ci>0的怪，计算消耗了多少血，最后得到多少金币
#coding=utf-8
import sys
if __name__ == "__main__":

    line = sys.stdin.readline().strip()
    values = list(map(int, line.split()))
    n,p = values[0],values[1]
    c,w = [],[]

    for _ in range(n):
        line = sys.stdin.readline().strip()
        values = list(map(int, line.split()))
        c.append(values[0])
        w.append(values[1])

    # n,p = 3,2
    # c = [1,1,3]
    # w = [1,10,1]

    total_cost = 0
    total_earn = 0

    for i in range(n):
        if c[i] < w[i]*p:
            total_cost += c[i]
            total_earn += w[i]

    res =  total_earn - (total_cost//p) if total_cost % p == 0 else total_earn - (total_cost//p) - 1
    print(res)