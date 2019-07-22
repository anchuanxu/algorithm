#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void __merge(T arr[],int l,int mid,int r){
    T aux[r-l+1];
    for(int i=l;i<=r;i++){
        aux[i-l]=arr[i];
    }
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
    {
        if(i>mid){
            arr[k]=aux[j-l];
            j++;
        }
        else if(j>r){
            arr[k]=aux[i-l];
            i++;
        }
        else if(aux[i-l]<aux[j-l]){
            arr[k]=aux[i-l];
            i++;
        }
        else{
            arr[k]=aux[j-l];
            j++;
        }
    }

    //递归使用归并算法排序，对arr[l...r]的范围进行排序
};

/*
 * //自顶向上的归并排序
template <typename T>
void  __mergeSort(T arr[], int l,int r){

    //优化点：在数据较少的时候考虑插入排序

    // 先考虑越界
    if(l>=r)
        return;
    int mid  = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);

    //普通方法
    __merge(arr,l,mid,r);


    //优化的方法1
    if(arr[mid]>arr[mid+1])
        __merge(arr,l,mid,r);
} */

// 自底向上的归并排序

template <typename T>
void mergeSortBU(T arr[],int n){
    for(int sz=1;sz<=n;sz+=sz)
    {
        for(int i=0;i+sz<n;i+=sz+sz)
            //对arr[i...i+sz-1和arr[i+sz...i+2*sz-1]进行归并
            __merge(arr,i,i+sz-1,min((i+sz+sz-1),n-1));
    }
}

int main() {
    // 测试模板函数，传入整型数组
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    mergeSortBU(a,10);
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}