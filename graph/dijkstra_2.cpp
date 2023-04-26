#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

/*
    朴素dijkstra的问题在于i每次循环都得找一次此时距离源点最近的点，这个操作是O(n)的，可以使用堆(优先队列)优化这个查找过程。
    声明优先队列 priority_queue q 存放距离源点的{距离与点}，这样每次循环就能直接取得距离源点距离最近的点。

    创建一个pair类型的大根堆(小根堆)q{-距离，点},把距离取负值，距离最小的元素最大，一定在堆顶。

    算法流程：
        1、初始化 {0,s}入队， d[s] = 0, d[other] = inf
        2、弹出队头距离最小的点u,若u扩展过就跳过，否则打上标记
        3、对u的所有出边 v 做 “松弛操作”，将 {-d[v],v}压入队尾
        4、重复2，3步操作，直到队列为空
*/

const int N = 1100;
struct edge{int v, w;}; // 保存出边点和权值
vector<edge> e[N]; // 出边数组
int d[N], vis[N];
int n,m,s;
priority_queue<pair<int,int>>q; // 大根堆
/*
typedef pair<int,int>PII；
priority_queue<PII,vector<PII>,greater<PII>> heap; 对应的小根堆写法
*/

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

