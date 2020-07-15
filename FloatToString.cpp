//
// Created by Administrator on 2020/3/24 0024.
//

#include <iostream>
#include <string>

using namespace std;

string GetFront(int Front)
{
    string strFront;
    strFront.clear();
    int shang, yu;
    char c = '0';
    while(Front/10>= 1)
    {
        shang = Front/10;
        yu = Front%10;
        c += yu;
        strFront.push_back(c);
        Front = shang;
        c = '0';
    }
    c = '0';
    c += shang;

    strFront.push_back(c);

    string a;

    while(!strFront.empty())
    {
        char tmp = strFront.back();
        strFront.pop_back();
        a.push_back(tmp);
    }

    return a;
}

string GetBehind(float Behind)
{
    string strBehind;
    float xs, xs10;
    int   zs;
    xs = Behind;
    char c = '0';
    while(xs> 0.000001)
    {
        xs10 = xs*10;
        zs = xs10;
        xs = xs10 - zs;
        c += zs;
        strBehind.push_back(c);
        c = '0';
    }
    return strBehind;
}

void main()
{
    float t = 123.45601;
    int zs = t;
    float xs = t - zs;
    string a = GetFront(zs);
    string b = GetBehind(xs);
    char c = '.';
    string result = a + c + b;
    cout<<result.c_str()<<endl;
    system("pause");
}