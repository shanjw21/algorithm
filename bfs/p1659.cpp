#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
char g[N][N];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int n,m,ans;
queue<pair<int,int>>q;

/*
    判断 “连通性” 和统计 “连通块个数” 的问题 统称 “洪水覆盖” 问题。
    用 DFS 和 BFS 均可解决
    注意判重， 避免死循环。
    连通性问题不是回溯问题，不需要回溯。

    判重技巧： 节点变性
    时间复杂度： O(n + m)
*/

void dfs(int x, int y){
    g[x][y] = '.';
    for(int i = 0; i < 8; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m)  continue;
        if(g[a][b] == '.')  continue;
        dfs(a,b);
    }
}

void bfs(int x, int y){
    g[x][y] = '.';
    q.push({x,y});
    while(q.size()){
        auto node = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int a = node.first + dx[i];
            int b = node.second + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m)  continue;
            if(g[a][b] == '.')  continue;
            // 扩展 {a,b} 将点{a,b}入队
            g[a][b] = '.';
            q.push({a,b});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'W'){
                ans += 1;
                // dfs(i,j);
                bfs(i,j);
            }
        }
    cout << ans << endl;
    return 0;
}