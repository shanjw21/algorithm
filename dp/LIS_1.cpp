#include <bits/stdc++.h>
/*
    动态规划解决最长上升子序列问题：(LIS)
    题目描述：https://www.acwing.com/problem/content/897/
    状态变量：f[i]记录以 a[i] 为结尾 的最长上升子序列的长度
    初始条件：f[i] = 1
    递推式：如果 a[i] > a[j]    则 f[i] = max(f[i], f[j] + 1), 1 <= j < i
    时间复杂度：1+2+3+...(n-1) = n(n-1)/2 是O(n^2)

    输入：
        9
        5 7 1 9 4 6 2 8 3
*/

const int N = 1100;
int a[N],f[N];

using namespace std;

int main(){
    int n;
    cin >> n;
    // 初始化所有f[i]为1，以自己作为结尾的上升子序列长为1
    for(int i = 1; i <= n; i++) cin >> a[i], f[i] = 1;

    int ans = 1;
    // 固定i枚举j，当a[j] < a[i],比较 f[j] + 1 与f[i]的大小，取大着作为f[i]的值，即最长上升子序列
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans,f[i]);
    }
    cout << ans << endl;
    return 0;
}