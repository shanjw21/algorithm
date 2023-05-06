/*
    Bellman_Ford算法：基于松弛操作的单源最短路算法

    算法流程：
        1、初始化，d[s] = 0, d[other] = inf;
        2、执行多轮循环(最差n轮)。每轮循环，对所有边尝试进行一次松弛操作。
        3、当一轮循环中没有成功进行松弛操作时，算法停止。
    e[N]存u点的出边的邻点和边权，d[u]存储点u到源点的距离。

    每轮循环遍历所有点的所有出边所以是O(m)的，若最短路存在，一轮松弛使得最短路边数至少+1,
    因为最短路边数最多是n-1，所以最多执行n-1次松弛操作，时间复杂度为O(nm)

    如果第n轮循环时仍然有可以松弛的边，说明从s出发，可以抵达一个负环，算法可以判断负环。
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
const int N = 100010;
int d[N];
struct edge{int v, w;};// 出边数组
vector<edge>e[N];
int n,m,s,x,y,z;

bool bellmanford(int s){
    memset(d,0x3f,sizeof d);
    d[s] = 0; // 算法流程1，初始化源点和其他点到源点距离
    bool flag; // 是否松弛
    for(int i = 1; i <= n; i++){ // n轮操作
        flag = false; // 标记为false
        for(int u = 1; u <= n; u++){ // n个点，每个点的出边进行一层松弛操作
            if(d[u] == 0x3f3f3f3f)  continue; // 如果没有被松弛则可以跳过
            for(auto ed : e[u]){ // 枚举点u的所有出边
                int v = ed.v, w = ed.w;
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w; // 松弛操作
                    flag = true; // 发生松弛操作，标记为true
                }
            }
        }
        if(!flag) break; // 如果某一轮循环未发生松弛操作，则算法停止
    }
    return flag; // 第n轮仍然有松弛操作的发生，则图中必定有负环。
}

int main(){
    scanf("%d%d",&n,&m,&s);
    for(int i = 1; i<= m; i++){
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back({y,z});
    }
    bellmanford(s);
    return 0;
}