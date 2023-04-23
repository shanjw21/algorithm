#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
const int N = 1100;
int g[N][N];
int dist[N][N];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
int n,m;
/*
    题目描述：https://www.acwing.com/problem/content/175/
    多源bfs问题。
    洪水从多个源点发出，每次扩展一步，先到那个点，那个点就确定了最短距离
    dist[N][N]存到源点的距离，兼职判重
    dx[4],dy[4]存方向偏移量
    时间复杂度：O(n + m)
输入样例：
3 4
0001
0011
0110

输出样例：
3 2 1 0
2 1 0 0
1 0 0 1
*/
// 多源bfs问题
void bfs(){
    memset(dist,-1,sizeof (dist));
    queue<pair<int,int>>q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(g[i][j] == 1){
                dist[i][j] = 0;
                q.push({i,j}); // 与单源bfs不同的是初始时将所有的初始点加入队列中。
            }
        }
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m)  continue;
            if(dist[a][b] != -1)    continue; // 判重
            dist[a][b] = dist[t.first][t.second] + 1; // 在原来的距离上加1
            q.push({a,b});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        // %1d是scanf函数中的格式控制符，表示输入一个整数并占用一个字符位置。即每次只能输入一个数字，并且输入的整数位数不能超过1位。
            scanf("%1d",&g[i][j]); //这个限制可以用来防止用户输入错误或超出范围的数据。
    bfs();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << dist[i][j] << ' ';
        cout << endl;
    }
    return 0;
}