/*
    数塔问题：动态规划 逆推法解决
    (x,y) 由两条路径的经过：(x+1,y)与(x+1,y+1)
    时间复杂度为 ： O(n^2)
    输出路径。
        pre[N][N]数组用于记录路径,这里记录(i,j)是由哪个点计算出来的。
        g[N][N]用于备份数组
    
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1100;
struct node{
    int x,y;
};
int f[N][N],g[N][N];
node pre[N][N];
int n, ans;
// 先序遍历输出点，终止条件是到pre[4][2]，默认是0，所以到这里停止。感觉不如numer_triangle_5.cpp中记录y的偏移量简单巧妙
node print(int x, int y){
        if(x == 4)    return {x,y};
        printf("%d -> ",g[x][y]);
        node p = pre[x][y];
        print(p.x,p.y);
    }

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
                pre[i][j] = {i+1,j}; // 记录y轴的偏量，向下
            }
            else{
                f[i][j] += f[i+1][j+1];
                pre[i][j] = {i+1,j+1}; // 向右下
            }
        }
    // 输出数塔最大值
    cout << "max = " <<  f[1][1] << endl;
    // 输出数塔的最大值路径
    node p = print(1,1);
    cout << g[p.x][p.y] << endl;
    return 0;
}