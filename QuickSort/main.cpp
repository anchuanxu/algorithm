#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r){

    T v = arr[l];

    int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

template <typename T>
void __quickSort(T arr[],int l,int r){

    if(l>=r)
        return;

    int p = __partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

template <typename T>
void quicksort(T arr[],int n){
    __quickSort(arr,0,n-1);
}

int main() {
    int a[]={10,9,8,7,6,5,4,3,2,1};
    quicksort(a,10);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" "<<endl;
    }

    return 0;
}