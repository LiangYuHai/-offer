//46 不用乘除法、if、for、while等关键字求1+2+..+n
// Created by Administrator on 2020/2/18 0018.
//

//利用构造函数
class Temp{
public:
    Temp(){
        ++n;
        sum += n;
    }
    static int getSum(){return sum;}
    static void reset(){n = 0; sum = 0;}

private:
    static int n;
    static int sum;
};

int Sum(int n){

    Temp::reset();
    Temp* a = new Temp[n];
    delete [] a;
    a = nullptr;
    return Temp::getSum();
}

//利用函数指针
typedef unsigned int (*func)(unsigned int);
unsigned int Sum2_Teminator(unsigned int n){
    return 0;
}

unsigned int Sum2(unsigned int n){
    func f[2] = {Sum2_Teminator, Sum2};
    return f[!!n](n-1) + n;
}

//利用虚函数
class A;
A* array[2];

class A{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};

class B:public A{
public:
    virtual unsigned int Sum(unsigned int n){
        return array[!!n]->Sum(n-1) + n;
    }
};

unsigned int Sum3(unsigned int n){
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;
    return array[!!n]->Sum(n);
}

//模板 编译器将完成以下运算，这要求n为常量，不能动态输入，且编译器
//对递归深度有限制，n不能太大。
template <unsigned int n> struct Sum4{
    enum Value {N = Sum4<n-1>::N + n};
};

template<> struct Sum4<1>{
    enum Value{N=1};
};