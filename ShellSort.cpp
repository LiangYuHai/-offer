//
// Created by Administrator on 2020/3/10 0010.
//
#include <iostream>
#include <vector>
using namespace std;
//template <typename T>
void ShellSort(vector<int>& numbers){
    if(numbers.empty()) return ;
    for(unsigned int gap = numbers.size()/2; gap >=1; gap /= 2){
        for(unsigned int i = gap; i < numbers.size(); ++i){
            unsigned int j = i;
            int temp = numbers[j];
            while (j-gap >= 0 && numbers[j-gap] > temp){
                numbers[j] = numbers[j-gap];
                j -= gap;
            }
            if(j!=i){
                numbers[j] = temp;
            }
        }
    }

}



int main(){
    vector<int> test={0,5,8,9,3,1};
    ShellSort(test);
    for(auto &a : test){
        cout << a << endl;
    }
}