/*
    [题目描述](https://www.acwing.com/problem/content/851/)
    稠密图，使用邻接矩阵存储图。
    图中可能存在重边和自环。所有的边权为正值。
*/
#include <iostream>
#include <string.h>
using namespace std;
const int N = 510;
int g[N][N],vis[N],d[N]; // g[N][N]存图，vis[N]集合标记数组，d[N]存到源点的距离
int n,m,x,y,z;

void dijkstra(int s){
    memset(d,0x3f,sizeof d);
    d[s] = 0;
    for(int i = 1; i < n; i++){
        int u = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && d[j] < d[u])
                u = j;
        vis[u] = 1;
        for(int i = 1; i <= n; i++){ // 遍历点到源点的距离，并通过u点尝试进行松弛操作。
            if(d[i] > d[u] + g[u][i])
                d[i] = d[u] + g[u][i];
        }
    }
    if(d[n] == 0x3f3f3f3f)  cout << "-1" << endl;
        else    cout << d[n] << endl;
}

int main(){
    cin >> n >> m;
    memset(g,0x3f,sizeof g); // 需要将g数组初始化为无穷，点之间没有连接的都是inf
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y],z); // 重边选择最小的那条边。
    }
    dijkstra(1);
    return 0;
}