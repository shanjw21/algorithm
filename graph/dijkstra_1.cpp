#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
/*
    单源最短路：dijkstra算法
    e[u]出边数组，存放点u的出边， d[u]存放点u到源点的最短距离， vis[u]标记点u是否出集合
    算法流程：
        1、初始时，所有点都在集合里，vis=0,d[s]=0, 其他d[other] = inf；
        2、从集合中选一个距离源点最小的点u,打标记移出圈；
        3、对u的所有出边执行 “松弛操作”(尝试更新邻点v的最小距离)
        4、重复2,3操作，直到集合内为空为止
    只适用于边权大于0的图。

    稠密图：边的条数接近点的平方， n = 10^3, m = 10^6 就是稠密图
    稀疏图：边的条数与点的个数在同一数量级， n = 10^6, m = 10^6就是稀疏图
    时间复杂度： O(n^2 + m) = O(n^2)
    
    输入数据：
    // 5个点,7条边，源点是1
    5 7 1 
    1 3 5
    1 4 2
    1 5 2
    4 2 6
    4 3 2
    5 3 1
    3 2 2
*/
// 结构体edge保存终点和边权
const int N = 1100;
struct edge{int v, w;};
vector<edge> e[N]; // 出边数组
int d[N], vis[N]; // d[u]存放点u到源点的最短距离,vis[u]标记点u是否出集合
int n,m,s;

void dijkstra(int s){
    memset(d,0x3f,sizeof d);
    d[s] = 0;
    for(int i = 1; i < n; i++){
        int u = 0; // 哨兵节点
        // 查找不在集合中的，距离源点最近的点
        for(int j = 1; j <= n; j++)
            if(!vis[j] && d[j] < d[u])  u = j;
        vis[u] = 1; // 标记u已经出集合
        for(auto ed:e[u]){
            int v = ed.v, w = ed.w;
            if(d[v] > d[u] + w) d[v] = d[u] + w;
        }
    }
}

int main(){
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        e[a].push_back({b,w});
    }
    dijkstra(s);
}
