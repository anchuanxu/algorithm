#include <iostream>
#include <algorithm>


using namespace std;

template<typename T>
void InsertSort(T arr[],int n){
    for(int i=0;i<n;i++){
        //寻找元素arr[i]合适的插入位置
        //写法１　未升级版本
        /*for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else
                break;
        }*/
        //写法２　升级版本 代码比较少
        for(int j=i;j>0&&arr[j]<arr[j-1];j--){
            swap(arr[j],arr[j-1]);
        }
        //写法３　更少的时间开销，节省了交换次数，更适合有序交换
        T e = arr[i]; //复制当前元素
        int j;//j保存元素e应该插入的位置
        for(j=i;j>0&&arr[j-1]>e;j--){
            arr[j] = arr[j-1];
        }
        arr[j]=e;
       }
    return;
}


int main() {

    // 测试模板函数，传入整型数组
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    InsertSort( a , 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // 测试模板函数，传入浮点数数组
    float b[4] = {4.4,3.3,2.2,1.1};
    InsertSort(b,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;

    // 测试模板函数，传入字符串数组
    string c[4] = {"D","C","B","A"};
    InsertSort(c,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<c[i]<<" ";
    cout<<endl;


    return 0;
}