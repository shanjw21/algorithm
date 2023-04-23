#include <bits/stdc++.h>

using namespace std;
const int N = 110;
// 出边数组e[N]表示节点N的所有出边组成的数组。
vector<int> e[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(auto v: e[u]){
        if(vis[v])  continue;
        printf("%d -> %d\n",u,v);
        dfs(v);
    }
}

int main(){
    // n个点，m条边
    int n, m;
    cin >> n >> m;
    // 建图
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);

    cout << endl;
    return 0;
}