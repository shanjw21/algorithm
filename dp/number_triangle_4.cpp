/*
    数塔问题：动态规划 逆推法解决
    (x,y) 由两条路径的经过：(x+1,y)与(x+1,y+1)
    时间复杂度为 ： O(n^2)
    
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1100;
int f[N][N];
int n, ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> f[i][j];
    // 向上逐层累加
    for(int i = n-1; i>=1; i--)
        for(int j = 0; j <= i; j++)
            f[i][j] += max(f[i+1][j], f[i+1][j+1]);
    // 输出数塔最大值
    cout << f[1][1] << endl;
}