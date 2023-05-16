/*
    字符串编辑距离：一个字符串经过删除、插入、修改单个字符所需要的最小次数。
    问题描述：输入字符串a,b，输出字符串a到字符串b的编辑距离。
    举例：a = NOTE  b = LOVER   输出：4
    考虑子问题：从a[1...i]到b[1...j]字符的编辑距离。
    状态变量：f[i][j]表示从a[1...i],b[1...j]的编辑距离。
    转移方程推导：
        1.如果a[i] = b[j] 那么 a[1...i-1,i]与b[1...j-1,j]的方程为f[i][j] = f[i-1][j-1]
        2.若a[i] != b[j]则需要考虑 插入、删除、修改的编辑距离的最小值。
            2.1 修改操作即将a[i]改为b[j],即a[1...i-1,i],b[1...j-1,j]对应的方程为：
                f[i][j] = f[i-1][j-1] + 1  eg: LOVT -> LOVE
            2.2 插入操作，即将a[i]后面插入b[j]对应的方程为：f[i][j] = f[i-1][j] + 1;
                eg: LOV -> LOVE 
            2.3 删除操作，即将a[i]最后一个元素删除，对应的方程为：f[i][j] = f[i][j-1] + 1
                eg: LOT -> LO
    综上转移方程为：
    f[i][j] = f[i-1][j-1]  when a[i]= b[j]
            = min(f[i-1][j-1],f[i][j-1],f[i-1][j]) + 1 when a[i] != b[j]
    转移状态：
        f[i-1][j-1]   f[i-1][j]
        f[i][j-1]     f[i][j]
    边界条件：
        f[i][0] = i 第0列，第二个字符为空，所以第一个字符串有几个字符就需要删除几次。
        f[0][j] = j 第0行，第一个字符为空，所以第二个字符串有几个字符就需要插入几次。
    时间复杂度：O(mn),空间复杂度：O(mn)

    [题目描述](https://www.acwing.com/problem/content/904/)
*/
#include <iostream>

using namespace std;
int n,m;
string s1,s2;
const int N = 1010;
int f[N][N];

int main(){
    cin >> n >> s1 >> m >> s2;
    for(int i = 1; i <= n; i++) f[i][0] = i;
    for(int j = 1; j <= m; j++) f[0][j] = j;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // 注意这里s1,s2的下标。
            if(s1[i-1] == s2[j-1])  f[i][j] = f[i-1][j-1];
            else    f[i][j] = min(f[i-1][j-1],min(f[i][j-1],f[i-1][j])) + 1;
        }
    }
    cout << f[n][m] << endl;
    return 0;
}