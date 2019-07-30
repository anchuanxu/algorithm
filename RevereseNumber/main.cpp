#include <iostream>
using namespace std;

int cnt;

void Merge(int *a,int l,int r,int *tmp)//数组a 在区间[l,r)内进行归并排序
{
    if(r-l<2) return; //如果数组元素小于两个，return
    int mid = l + ((r-l)/2);
    int pos1 = l, pos2 = mid, pos_tmp = l;
    Merge(a,l,mid,tmp);//左边排序
    Merge(a,mid,r,tmp);//右边排序
    while(pos1 < mid || pos2 < r){//合并两个有序序列
        if(pos2 >= r ||(pos1 < mid)&&(a[pos1] <= a[pos2]))
            tmp[pos_tmp++] = a[pos1++];
        else
            tmp[pos_tmp++] = a[pos2++];
            cnt += mid - pos1; //此时左边一半的元素个数
    }
    for(int i = l;i < r;i++){
        a[i]=tmp[i];
    }

}
int a[100001],tmp[100001],n;

int main() {
    cin>>n;//数列有n个数
    for(int i = 0;i < n; i++){
        cin>>a[i];
    }
    Merge(a,0,n,tmp);
    for(int i = 0;i < n; i++){
        cout<<a[i]<< " ";
    }
    cout<<endl<<cnt<<" "<<endl;
    return 0;
}