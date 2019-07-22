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

template <typename T>
void  __mergeSort(T arr[], int l,int r){
    // 先考虑越界
    if(l>=r)
        return;
    int mid  = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    __merge(arr,l,mid,r);
}
int main() {
    // 测试模板函数，传入整型数组
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    __mergeSort( a ,0,9 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}