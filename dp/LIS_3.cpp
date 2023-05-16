/*
    LIS最长上升子序列（二分查找）优化：
    时间复杂度：O(nlogn)
    优化内层循环遍历j到i使用二分查找。二分查找前提是有序序列，所以新开一个数组b,用来记录上升子序列
    关键问题：动态更新b数组
    算法流程：
        1、大则添加：若a[i]大于b[len]，直接将a[i]添加到b[++len]数组中，b[N]数组长度加1，添加1个元素
        2、小就替换：若a[i]小于等于b[len]就用a[i]替换掉b数组中第一个大于或等于a[i]的元素。
        替换后会使b[1..j]这个上升子序列的结尾元素更小；对一个上升子序列，其结尾元素越小，越有利于
        续接其他元素，也就越可能变得更长。
    由于b数组是单调有序的，所以可以使用二分优化查找过程。
    b数组中并不存储最长上升子序列，只是记录最长上升子序列的长度。
    
    输入：
    9
    5 7 1 9 4 6 2 8 3

*/
#include <iostream>
const int N = 1100;
int a[N],b[N];
int len; // 记录上升子序列的长度

using namespace std;

// 最小化查找：查找第一个 >= x 的元素位置
int find(int x){
    int l = 0, r = len + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(b[mid]>=x)   r = mid;
        else    l = mid;
    }
    return r;
}

int main(){
    int n;
    cin >> n;
    int i,j;
    for(int i = 1; i <= n; i++) cin >> a[i];

    len = 1;
    b[1] = a[1];
    for(i = 2; i <=n; i++){
        if(a[i] > b[len]) // 大则加入
            b[++len] = a[i];
        else{ // 小则替换 
            j = find(a[i]);
            b[j] = a[i];
        }
    }
    printf("%d\n",len);
    return 0;
}