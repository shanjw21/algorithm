#include <iostream>
#include <stdlib.h>

/*
    题目描述：https://www.luogu.com.cn/problem/P1605
    使用回溯法解决迷宫中从起点到终点的方案总数
*/

using namespace std;
const int N = 10;
int g[N][N];
int ans;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
int n,m,t,sx,sy,fx,fy;

void dfs(int x,int y){
    if(x == fx && y == fy){
        ans += 1;
        return;
    }
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > m || g[a][b]) continue;
        g[a][b] = 1;
        dfs(a,b);
        g[a][b] = 0;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i = 1; i <= t; ++i){
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        g[tx][ty] = 1;
    }
    g[sx][sy] = 1;
    dfs(sx,sy);
    printf("%d\n",ans);
    return 0;
}