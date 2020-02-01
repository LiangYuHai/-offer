//Liang Yuhai
// Created by Administrator on 2019/12/4 0004.
//快排


template <typename T>
int helper(T data[], int start, int end){
    if(!data || start==end) return start;
    small = start-1;
    for(int i = start; i < end; ++i){
        if(data[i]<data[end]) {
            ++small;
            if (small != i) {
                T temp = data[i];
                data[i] = data[small];
                data[small] = temp;
            }
        }
    }
    ++small;
    T temp = data[end];
    data[end] = data[small];
    data[small] = temp;
    return small;
}

template <typename T>
void QuitSort(T data[], int start, int end){
    int size = sizeof(data)/sizeof(data[0]);
    if(!size) return ;
    int index = helper(data,start,end);
    if(index>start){
        QuitSort(data, start, index-1);
    }
    if(index<end){
        QuitSort(data, index+1, end)
    }
}