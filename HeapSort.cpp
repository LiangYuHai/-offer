//
// Created by Administrator on 2020/3/10 0010.
//

#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int>& numbers, int index, int len){
    int left = index*2+1;
    int right = index*2+2;
    int max = index;
    if(left < len && numbers[max] < numbers[left]) max = left;
    if(right < len && numbers[max] < numbers[right]) max = right;
    if(max != index){
        int temp = numbers[index];
        numbers[index] = numbers[max];
        numbers[max] = temp;
        Heapify(numbers, max, len);
    }
}

void BuildMaxHeap(vector<int>& numbers){
    if(numbers.size() <=1) return;
    int len = numbers.size();
    for(int i = len>>1; i>=0; i--){
        Heapify(numbers, i, len);
    }
}

//void Heapify(vector<int> numbers, int index, int len){
//    int left = index*2+1;
//    int right = index*2+2;
//    int min = index;
//    if(left < len && numbers[left] < numbers[min]) min = left;
//    if(right < len && numbers[right] < numbers[min]) min = right;
//    if(min!=index){
//        int temp = numbers[min];
//        numbers[min] = numbers[index];
//        numbers[index] = temp;
//        Heapify(numbers, min, len);
//    }
//}
//
//void BuildMinHeap(vector<int> numbers){
//    if(numbers.size() <= 1) return;
//    for(int i = numbers.size()/2; i >= 0; i--){
//        Heapify(numbers, i, numbers.size());
//    }
//}
void HeapSort(vector<int> numbers){
    if(numbers.empty() || numbers.size()==1) return ;
    BuildMaxHeap(numbers);
    for(int i = numbers.size()-1; i >=0; i--){
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        Heapify(numbers, 0, i);
    }
}

int main(){
    vector<int> test={0,1,5,8,3,2};
    HeapSort(test);
    for(auto &a: test){
        cout << a << endl;
    }
}