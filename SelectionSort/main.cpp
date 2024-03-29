
#include <iostream>
#include <algorithm>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template <typename T>

void selectionsort(T arr[] , int n)
{
    for (int i=0;i<n;i++)
    {
        // 寻找[i,n)区间里的最小值
        int minIndex = i;
        for(int j = i+1;j<n;j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    selectionsort(a,10);
    for(int i=0;i<10;i++)
    std::cout << a[i] << " ";
    cout<<endl;

    float b[5]={4.3,2.1,5.6,7.7,1.5};
    selectionsort(b,5);
    for(int i=0;i<5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    string c[5]={"B","D","E","A","C"};
    selectionsort(c,5);
    for(int i=0;i<5;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    Student d[4]={{"D",90},{"C",100},{"B",95},{"A",95}};
    selectionsort(d,4);
    for(int i=0;i<4;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;


    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);


    SortTestHelper::testSort("Selection Sort",selectionsort,arr,n);
    delete[] arr;



    return 0;
}
