/*
    数塔问题：动态规划解法  顺推法
    定义F[N][N]表示从点(1,1)出发到达(x,y)的路径最大权值和,最终答案为： ans = max{F[N][1],F[N][2]...F[N][N]}
    根据最后一步向左向右分为两种情况：
        向左：最后一步是从(x-1,y)走到(x,y)分为两部分，从(1,1)走到(x-1,y),从(x-1,y)走到(x,y):F[x-1][y] + g[x][y];
        向右：F[x-1][y-1] + g[x][y]
        F[x][y]是两者的最大值即：F[x][y] = max{F[x-1][y-1], F[x-1][y]} + g[x][y]
        F[1][1]的计算不能再用状态转移方程计算，是直接赋予的一个特值 g[1][1].

    总结：
        状态转移方程：F[x][y] = max{F[x-1][y-1], F[x-1][y]} + g[x][y]
        边界条件：F[1][1] = g[1][1]
        边界条件成立的原因：如果从(1,1)出发到达(1,1)，那么路径最大权值和就是g[1][1]本身，因为它就是唯一的一个点。所以定义F[1][1] = g[1][1]是合理的。
    
    输入数据：
    5
    13
    11 8
    12 7 26
    6 14 15 8
    12 7 13 24 11

    输出：84

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1100;
int g[N][N], F[N][N];
int n, ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> g[i][j];

    F[1][1] = g[1][1]; // 边界条件
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            F[i][j] = max(F[i-1][j-1], F[i-1][j]) + g[i][j]; // 状态转移方程
    for(int i = 1; i <= n; i++) ans = max(ans,F[n][i]); // 求最大值
    cout << ans << endl;
    return 0;
}