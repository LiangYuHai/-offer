//面试题11. 数值的整数次方
// Created by Administrator on 2020/1/26 0026.
//

#include <iostream>
bool FalseInput = false;
bool Equal(double a, double b){
    return (a - b) > -0.0000001 && (a - b) < 0.0000001;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent){
    double result = 1;
    for(auto i = 0; i <exponent; ++i){
        result *= base;
    }
    return result;
}

double PowerWithUnsignedExponent2(double base, unsigned int exponent){
    if(exponent == 0) return 1;
    if(exponent == 1) return base;
    double result = PowerWithUnsignedExponent2(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1) result *= base;
    return result;
}

double Power(double base, int exponent){
    if(Equal(base, 0.0) && exponent<0){
        FalseInput = true;
        return 0.0;
    }
    auto absExponent = (unsigned int)(exponent);
    if(exponent < 0){
        absExponent = (unsigned int)(-exponent);
    }
    double result = PowerWithUnsignedExponent2(base, absExponent);
    if(exponent < 0){
        result = 1/result;
    }
    return result;
}

void test1(){
    if(Equal(Power(3.0,3), 27.0)) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}

void test2(){
    if(Equal(Power(0,3), 0)) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}

void test3(){
    if(Equal(Power(1.0,3), 1.0)) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}

void test4(){
    if(Equal(Power(-3.0,3), -27.0)) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}

void test5(){
    if(Equal(Power(3.0,-3), 1/27.0)) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}


void test6(){
    if(Equal(Power(3.0,0), 1)) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}

void test7(){
    if(Equal(Power(0,-3), 0.0) && FalseInput) std::cout << "True" << std::endl;
    else std::cout<<"False"<<std::endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}
