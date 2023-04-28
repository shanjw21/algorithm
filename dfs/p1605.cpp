#include <iostream>
#include <stdlib.h>
 
/*
    题目描述：https://www.luogu.com.cn/problem/P1605
    使用回溯法解决迷宫中从起点到终点的方案总数

    带恢复现场的DFS又称为回溯算法，一个节点可以反复搜索多次
    主要用途就是搜索方案数。

    算法流程：
        如果到达终点，更新答案，回退
        如果未到达终点，枚举可走路径
            锁定现场
            dfs(下一个节点)
            恢复现场
    
    深搜与回溯：
        从起点开始，向四个方向尝试
        能走就打上标记，锁定现场，然后走过去
        走到走投无路就返回或者达到目的地，更新答案返回
        返回后，去除标记，恢复现场
        继续尝试，直到尝遍所有可能，最终从入口退出
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
        if(a < 1 || a > n || b < 1 || b > m) continue;
        if(g[a][b]) continue;
        g[a][b] = 1; // 锁定现场
        dfs(a,b);
        g[a][b] = 0; // 恢复现场 
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