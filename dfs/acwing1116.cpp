#include <iostream>
#include <cstring>

/*
    题目描述：https://www.acwing.com/problem/content/1118/
    使用回溯法求问题的解决方案。
    g[N][N]用来建图和判重。
    变量cnt用来记录遍历的个数。
*/

using namespace std;
const int N = 10;
int g[N][N];
int n, m,ans;
int dx[8] = {-2,-1,1,2,2,1,-1,-2}, dy[8] = {1,2,2,1,-1,-2,-2,-1};

void dfs(int x, int y, int cnt){
    // 当cnt==n*m即遍历完棋盘上所有位置时，ans加1
    if(cnt == n*m){
        ans += 1;
        return;
    }

    for(int i = 0; i < 8; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m)  continue;
        if(g[a][b]) continue;
        g[a][b] = 1;// 锁定现场
        dfs(a,b,cnt+1);
        g[a][b] = 0; // 回溯，恢复现场
    }
}

int main(){
    int t;
    cin >> t;
    while(t --){
        int x, y;
        cin >> n >> m >> x >> y;
        ans = 0;
        g[x][y] = 1;
        dfs(x,y,1);
        cout << ans << endl;
        memset(g,0,sizeof(g)); // 每一个新的查询，将g[N][N]恢复成未遍历
    }
    return 0;
}