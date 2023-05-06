/*
    对Bellman算法的优化：只有本轮被更新的点，其出边才有可能引起下一轮的松弛操作。
    用队列维护被更新的点的集合

    vis[u]标记点u是否在队内，cnt[v]记录边数，判负环。
    算法流程：
        1、初始化，s入队，标记s在队内，d[s]=0,d[other]=inf;
        2、从队头弹出点u，标记u不在队内；
        3、枚举u的所有出边，执行松弛操作，记录从s走到v的边数，并判断负环，若v不在队内则把v压入队尾，打上标记
        4、重复2,3步操作，直到队列为空。
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
const int N = 100010;
int d[N];
struct edge{int v, w;};// 出边数组
int vis[N],cnt[N];
queue<int>q;

bool spfa(int s){
    // 1、初始化d[s],s入队
    memset(d,0x3f,sizeof d);
    d[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(q.size()){
        auto u = q.front();
        q.pop();
        vis[u] = 0; // 标记出队
        for(auto ed : e[u]){ // 扩展出边进行松弛化操作
            int v = ed.v, w = ed.w;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1; // 记录边数
                if(cnt[v] >= n) return true; // n条边说明存在负环
                if(!vis[v]) q.push(v),vis[v] = 1;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m,&s);
    for(int i = 1; i<= m; i++){
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back({y,z});
    }
    spfa(s);
    return 0;
}