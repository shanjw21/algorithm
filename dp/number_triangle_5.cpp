/*
    数塔问题：动态规划 逆推法解决
    (x,y) 由两条路径的经过：(x+1,y)与(x+1,y+1)
    时间复杂度为 ： O(n^2)
    输出路径。
        pre[N][N]数组用于记录路径
        g[N][N]用于备份数组
    
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1100;
int f[N][N],pre[N][N],g[N][N];
int n, ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++){
            cin >> f[i][j];
            g[i][j] = f[i][j];
        }
    // 向上逐层累加
    for(int i = n-1; i>=1; i--)
        for(int j = 0; j <= i; j++){
            if(f[i+1][j] > f[i+1][j+1]){
                f[i][j] += f[i+1][j];
                pre[i][j] = 0; // 记录y轴的偏量，向下
            }
            else{
                f[i][j] += f[i+1][j+1];
                pre[i][j] = 1; // 向右下
            }
        }
    // 输出数塔最大值
    cout << "max = " <<  f[1][1] << endl;
    // 输出数塔的最大值路径
    int i = 1,j = 1;
    for(; i <= n-1; i++){
        cout << g[i][j] << "->";
        j = j + pre[i][j]; // 下一行的列数
    }
    cout << g[n][j] << endl; // 为防止多输出一个 -> 最后一个单独输出。
    return 0;
}