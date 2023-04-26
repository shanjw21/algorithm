#include <iostream>

using namespace std;
const int N = 100010;
int a[N];
int n;
/*
    二分法模板：
    
    1、指针的跳跃次数 log n
    2、可行区的指针最后一定指向答案。
    3、开区间可以正确处理边界
    4、最大化查找(最后一个 >= a的坐标)可行区在左边；最小化查找(第一个 <= a的坐标)可行区在右边
    测试数据:
    8
    1 2 3 5 5 5 7 8
*/

// 查找最后一个 <= 5 的数的下标：(最大化查找)：可行区在左边；
// [1 2 3 5 5 5] 7 8 可行区 这里 l 始终在可行区内移动， r 始终在可行区外移动
int find_last(int q){
    int l = 0, r = n + 1; // 开区间
    while(l+1 < r){ // l+1 = r时结束
        int mid = l + r >> 1;
        if(a[mid] <= q) l = mid; // mid 在可行区内
        else    r = mid;
    }
    return l;
}
// 查找第一个 >= 5 的数的下标: 最小化查找(第一个 >= a的坐标)可行区在右边          
// 1 2 3 [5 5 5 7 8] 可行区 这里 r 始终在可行区内移动， l 始终在可行区外移动
int find_first(int q){
    int l = 0, r = n+1; // 开区间
    while(l + 1 < r){ // l+1 = r时结束
        int mid = l + r >> 1;
        if(a[mid] >= q) r = mid; // mid在可行区内
        else    l = mid;
    }
    return r;
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++)  cin >> a[i];
    int last = find_last(5);
    cout << "最后一个 <= 5 的数的下标为：" << last << endl;
    int first = find_first(5);
    cout << "第一个 >= 5 的数的下标为：" << last << endl;
}
