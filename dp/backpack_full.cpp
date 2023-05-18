/*
    [题目描述](https://www.acwing.com/problem/content/3/)
    0/1背包：第i件物品放入0,1个
    完全背包：第i件物品放入0，1，2...个
    1.确定状态变量(函数):
        状态变量：f[i][j]表示前i件物品放入容量为j的背包的最大价值。
    2.确定状态转移方程:
        (1)当前背包容量j < w[i]不能放入，f[i][j] = f[i-1][j]
        (2)若当前背包容量j>=w[i]，能放比较代价：
            若第i件物品不放入则f[i][j] = f[i-1][j]
            若第i见物品放入，则f[i][j] = f[i][j-w[i]] + c[i]
        对前i件物品，容量为j-w[i]时已经放入了第i件物品，容量为j时还可以再放入
        第i件物品，所以用f[i][j-w[i]]更新f[i][j].
        转移方程：
            f[i][j] = f[i-1][j],(j < w[i]),(j < w[i])
            f[i][j] = max(f[i-1][j],f[i][j-w[i]] + c[i]),(j >= w[i])
            
                            f[i-1][j]
        f[i][j-w[i]] + c[i]     f[i][j]
        ------------------------->顺序更新
    3.确定边界条件:
        f[i][j] = 0表示没有放东西且背包容量为0，则价值也是0.
    4.确定递推顺序:
        一维数组f[j]只记录一行数据，j值顺序循环，顺序更新f[j]，f[j-w[i]]会
        先于f[j]更新，即用新值f[j-w[i]]更新f[j]用第i行的f[j-w[i]]值更新
        f[j].
*/
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010;
int f[N][N];
int v[N], w[N];
int n, m;

#if 0
int main(){
    for(int i = 1; i <= n; i++){//物品i
        for(int j = 1; j <= m; j++){//容量j
            if(j < w[i])
                f[i][j] = f[i-1][j];
            else    
                f[i][j] = max(f[i-1][j],f[i][j-w[i]]+c[i]);
        }
    }
    cout << f[n][m] << endl
}
#endif

int main(){
    for(int i = 1; i <= n; i++){//物品i
        for(int j = w[i]; j <= m; j++){//容量j   
            f[j] = max(f[j],f[j-w[i]]+c[i]);
        }
    }
    cout << f[n][m] << endl
}