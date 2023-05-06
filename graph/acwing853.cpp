#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
const int N = 10010;
struct edge{int v,w;};
vector<edge>e[N];
int d[N],back[N];
int n,m,k,x,y,z;

bool bellmanford(int s){
    memset(d,0x3f,sizeof d);
    d[s] = 0;
    bool flag;
    for(int i = 1; i<= k; i++){ // k的意义：不经过k条边 
        memcpy(back,d,sizeof d);
        for(int u = 1; u <= n; u++){
            if(d[u] == 0x3f3f3f3f)  continue;
            for(auto ed : e[u]){
                int v = ed.v, w = ed.w;
                if(d[v] > back[u] + w){
                    d[v] = back[u] + w; // 使用备份数组更新d[v]防止发生串联。
                }
            }
        }
    }
    if(d[n] > 0x3f3f3f3f / 2)   puts("impossible");
    else    cout << d[n] << endl;
    return flag;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        e[x].push_back({y,z});
    }
    bellmanford(1);
    return 0;
}