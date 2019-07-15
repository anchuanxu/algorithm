//
// Created by xu on 19-7-15.
//

#include "iostream"
#include <algorithm>
#include "SortTestHelper.h"
#include "Student.h"

using  namespace std;

template <typename T>
void InsertSort(T arr[], int n){
    for(int i=1 ;i<n;i++){
        //寻找当前第i个元素合适的位置
        for(int j=i;j>0;j++){
            if(arr[j]<arr[j-1])
                swap(arr[j] ,arr[i]);
            else
                break;
        }
    }
}

int main(){
    int n=10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);


    SortTestHelper::testSort("Insert Sort",insertionSort,arr,n);
    SortTestHelper::testSort("select Sort",selectionSort,arr2,n);
    delete[] arr;
    delete [] arr2;
    return 0;
}
