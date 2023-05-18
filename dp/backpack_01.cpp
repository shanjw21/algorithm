/*
    [问题描述](https://www.acwing.com/problem/content/2/)
    1.确定状态变量(函数)
        状态变量：f[i][j]表示前i件物品放入容量为j的背包的最大价值。
    2.确定状态转移方程
        当前背包容量为j，考虑第i件物品能否放入，是否放入？
        (1)若当前背包容量j<w[i]不能放入。则f[i][j] = f[i-1][j]
        (2)若当前背包容量j>=w[i]，能放入，要比较代价：
            若第i件物品不放入则f[i][j] = f[i-1][j]
            若第i见物品放入，则f[i][j] = f[i-1][j-w[i]] + c[i]
        状态转移方程：
            f[i][j] = f[i-1][j],(j < w[i])
            f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+c[i])(j>=w[i])

        f[i-1][j-w[i]]   f[i-1][j]
        +c[i]         f[i][j]
    3.确定边界条件:
        f[i][j] = 0表示没有放东西且背包容量为0，则价值也是0.

    最大价值是物品数量i与背包容量j的函数。
    设f[i][j]表示前i件物品放入背包容量j的最大价值。
    最终的最大价值就是物品数量从0增长到n,背包容量从0增长到m时的f[n][m]
*/
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010;
int v[N],w[N]; // 背包体积与价值
int f[N][N]; // 状态数组
int n,m;

#if 0
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    // 边界条件:f[0][j]与f[i][0]
    for(int i = 1; i <= n; i++){ // 物品i
        for(int j = 0; j <= m; j++){ // 容量j
            if(j < w[i]) // 不选第i件物品   
                f[i][j] = f[i-1][j]
            else // 选第i件物品但要比较代价。   
                f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+c[i]);
        }
    }
    // f[n][m]表示从前n个物品选择体积不超过m的所有选择方案中的价值最大值
    cout << f[n][m] << endl;
    return 0;
}
#endif


/*
    由于第i行的数据都是由第i-1行更新来的，所以用一维数组f[j]来只记录一行数据进行滚动更新。
    但是如果是顺序循环，f[j-w[i]]会先于f[j]更新，即用新值f[j-w[i]更新f[j]会出错。
*/
#if 1
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    // 边界条件:f[0][j]与f[i][0]
    for(int i = 1; i <= n; i++){ // 物品i
        for(int j = 0; j <= m; j++){ // 容量j
            if(j < w[i])
                f[j] = [j]
            else //  顺序循环f[j-w[i]]会先于f[j]更新，用新值更新f[j]出错。
                f[j] = max(f[j],f[j-w[i]]+c[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
#endif

/*
   让j值逆序循环，逆序更新f[j]的值，逆序使得f[j]先于f[j-w[i]]更新即用旧值
   f[j-w[i]]更新f[j]，用上一行的f[j-w[i]]更新f[j]所以正确。
*/
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    // 边界条件:f[0][j]与f[i][0]
    for(int i = 1; i <= n; i++){ // 物品i
        for(int j = m; j >= w[i]; j++){ // 到w[i]为止防止小于0
            f[j] = max(f[j],f[j-w[i]]+c[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}