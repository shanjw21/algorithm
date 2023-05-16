/*
    [dijkstra算法模板题](https://www.luogu.com.cn/problem/P3371)
*/
#include <iostream>
#include <vector>
#include <string.h>
#define inf 2147483647
using namespace std;

const int N = 100010;
int n,m,s;
struct edge{int v, w;};
vector<edge>e[N];
int dist[N],vis[N];

void dijkstra(int s){
    for(int i = 0; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    for(int i = 1; i < n; i++){// n层循环，因为每层循环从集合中找出一个节点更新其他节点到源点的距离，所以外面是n层循环。
        int u = 0;
        for(int j = 1; j <= n; j++)
            // 查找不在集合中的，距离源点最近的点
            if(!vis[j] && dist[j] < dist[u])  u = j;
        vis[u] = 1; // 标记出集合
        for(auto ed : e[u]){// 枚举邻边
            int v = ed.v, w = ed.w;
            if(dist[v] > dist[u] + w)
                dist[v] = dist[u] + w; // 松弛操作
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 1; i<= m; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[a].push_back({b,c});
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
        printf("%d ",dist[i]);
    return 0;
}