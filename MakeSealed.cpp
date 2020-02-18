//48. 不能被继承的类
// Created by Administrator on 2020/2/18 0018.
//


//把构造函数和析构函数私有化；当一个类继承时调用构造函数就会报错
//当该类实例化和释放实例时，用公有静态函数
class SealedClass{
public:
    static SealedClass Make(){
        return new SealedClass();
    }
    static void Delete(SealedClass* a){
        delete a;
    }
private:
    SealedClass(){};
    ~SealedClass(){};
};


//使用虚拟继承

template <T>
class SealedClass{
    friend T;
private:
    SealedClass(){};
    ~SealedClass(){};
};

//SealedClass2实例化时，因为SealedClass2是SealedClass的友元类型而可以调用基类的私有构造函数
class SealedClass2:virtual public SealedClass<SealedClass2>{
public:
    SealedClass2(){};
    ~SealedClass2(){};
};

//继承报错，会跳过SealedClass2而直接调用SealedClass<SealedClass2>的构造函数，从而报错。
class Try:public SealedClass2{
public:
    Try(){};
    ~Try(){};
};