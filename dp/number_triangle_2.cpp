/**
    数塔问题解法二：记忆化搜索
    输入数据：

    5
    13
    11 8
    12 7 26
    6 14 15 8
    12 7 13 24 11
    输出：84

    f[N][N]：记录从(x,y)出发到终点路径的最大权值和。计算dfs(x,y)时，首先查询f[x][y]，
    f[x][y] != 0 说明 dfs(x,y)已经被计算过了，直接返回f[x][y]，否则计算dfs(x,y)并将
    结果存在f[x][y]中。
    
    考虑从(x,y)出发到终点的路径：
    第一步向左，得到的最大权值
    dfs(x + 1, y) + g[x][y];
    第一步向右，得到的最大权值
    dfs(x + 1, y + 1) + g[x][y];
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1110;
int g[N][N], f[N][N];
int n;

// 定义dfs(int,int):表示从(x,y)出发到终点的路径的所有的最大权值和，答案是dfs(1,1)
int dfs(int x, int y){
    // 记忆化搜索，避免进一步递归
    if(f[x][y] != 0)    return f[x][y];
    if(x == n){ // 边界条件
        f[x][y] = g[x][y];
    }
    else{
        f[x][y] = g[x][y] + max(dfs(x + 1, y),dfs(x + 1, y + 1));
    }
    return f[x][y];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> g[i][j];
    dfs(1,1);
    cout << f[1][1] << endl;
    return 0;
}
