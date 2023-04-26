#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

/*
   路径的记录与递归输出：使用pre[N]数组记录前驱节点
   使用dfs_path来递归输出路径
*/

const int N = 1100;
struct edge{int v, w;}; // 保存出边点和权值
vector<edge> e[N]; // 出边数组
int d[N], vis[N],pre[N];
int n,m,s;
priority_queue<pair<int,int>>q; // 大根堆
/*
typedef pair<int,int>PII；
priority_queue<PII,vector<PII>,greater<PII>> heap; 对应的小根堆写法
*/

void dfs_path(int u){
    if(u == s){
        printf("%d ", u);
        return;
    }
    dfs_path(pre[u]);
    printf("%d ",u);
}

void dijkstra(int s){
    // 初始化{0,s}入队， d[s] = 0;
    memset(d,0x3f,sizeof d);
    d[s] = 0;
    q.push({0,s});
    while(q.size()){
        auto t = q.top(); q.pop(); // 取出优先队列队头
        int u = t.second;
        if(!vis[u]) continue; // 如果扩展过则跳过
        vis[u] = 1; // 标记已出队
        for(auto ed : e[u]){ // 对出边做松弛操作
            int v = ed.v, w = ed.w;
            if(d[v] > d[v] + w){
                d[v] = d[u] + w;
                pre[v] = u; // 记录v是由u松弛过来的,u是v的前驱节点。
                q.push({-d[v],v}); // 大根堆
            }
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

