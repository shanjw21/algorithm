#include <iostream>
/*
    动态规划解决最长上升子序列问题：(LIS)
    题目描述：https://www.acwing.com/problem/content/897/
    状态变量：f[i]记录以 a[i] 为结尾 的最长上升子序列的长度
    递推式：如果 a[i] > a[j]    则 f[i] = max(f[i], f[j] + 1), 1 =< j < i
    时间复杂度：1+2+3+...(n-1) = n(n-1)/2 是O(n^2)

    输入：
        9
        5 7 1 9 4 6 2 8 3

    输出最长上升子序列：
        使用pre[N]记录每次更新f[i]的前驱j点
        使用dfs遍历pre数组，将最长上升子序列输出。
*/

using namespace std;
const int N = 1110;
int a[N],f[N];
int pre[N];

void dfs(int x){
    if(pre[x] == 0){
        cout << a[x] << ' '; // 在这将最后一个值输出。
        return;
    }
    auto p = pre[x];
    dfs(p);
    cout << a[x] << ' '; // 递归回到x 的状态空间 输出a[x]
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], f[i] = 1;

    int ans = 1, pos = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                if(f[i] < f[j] + 1){
                    f[i] = f[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if(ans < f[i]){
            ans = f[i];
            pos = i;
        }
    }
    cout << "ans = " << ans << endl;
    cout << "最长上升子序列为：" << endl;
    dfs(pos);
    cout << endl;
    return 0;
}