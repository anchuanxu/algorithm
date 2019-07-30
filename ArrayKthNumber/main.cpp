#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
int __partition(T arr[],int l,int r){
    std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
    int j = l;
    for(int i = l + 1;i <= r;i++){
        if(arr[i] < arr[l])
            swap(arr[i],arr[++j]);
    }
    swap(arr[l],arr[j]);

    return j;
}

template <typename T>
int __Sloution(T arr[],int l,int r,int k){
    if(l==r) return arr[l] ;
    int p = __partition(arr , l, r);
    if(k==p) return arr[p];
    else if(k < p) return __Sloution(arr ,0,p-1,k);
    else return __Sloution(arr,p+1,r,k);
}

template <typename T>
int Sloution(T arr[],int n, const int &k) {//求解n长度T序列中第K大的值
    assert(k >=0 && k < n);
    srand(time(NULL));
    return __Sloution(arr ,0,n-1,k);
}

int main() {
    int n;
    int k;
    cin>>n;
    cin>>k;
    int a[n];
    for(int i = 1; i <= n;i++)
        cin>>a[i];
    if(k<=n&&k>0)
        cout<<Sloution(a,n,k)<<endl;
    else
        cout<<"数据不合法"<<endl;
    return 0;
}