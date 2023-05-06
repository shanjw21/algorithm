/*
    [题目描述](https://www.acwing.com/problem/content/852/)
    堆优化的dijkstra算法
    稀疏图，通过邻接表存储
*/
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

const int N = 200000;
struct edge{int v, w;};
vector<edge>e[N];// 出边数组
int d[N],vis[N]; // d数组表示到源点距离，vis表示扩展过
int n,m,x,y,z;
priority_queue<pair<int,int>> q;// pair存储<距源点距离，点号>，first存储距离，second存储节点编号,大根堆

void dijkstra(int s){
    memset(d,0x3f,sizeof d);
    d[s] = 0;
    q.push({0,s}); // 源点入队
    while(q.size()){
        auto t = q.top();
        q.pop();
        int u = t.second;
        if(vis[u])  continue; // 每次标记一个节点，从其开始做松弛操作,如果标记过了就跳过
        vis[u] = 1; // 标记入队
        for(auto ed : e[u]){
            auto v = ed.v, w = ed.w;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({-d[v],v}); // 大根堆，距离存成负数。
            }
        }
    }
    if(d[n] == 0x3f3f3f3f)  cout << "-1" << endl;
        else    cout << d[n] << endl;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i<= m; i++){
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back({y,z});
    }
    dijkstra(1);
    return 0;
}