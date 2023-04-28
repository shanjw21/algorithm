#include <bits/stdc++.h>

using namespace std;
const int N = 110;
// 出边数组e[N]表示节点N的所有出边组成的数组。
vector<int> e[N];
bool vis[N];// 判重数组

/*
    dfs遍历有环的图会产生一颗 dfs树, n个点，n-1条边。

测试数据：
8 7 
3 6
8 6
2 5
5 6
1 5
5 7
1 4
打印结果：
1 -> 5
5 -> 2
5 -> 6
6 -> 3
6 -> 8
5 -> 7
1 -> 4
*/

// 打印对图深搜生成的DFS树
void dfs(int u){
    vis[u] = true; // 标记访问过，防止再次访问
    for(auto v: e[u]){
        if(vis[v])  continue; // 如果遍历过了，就跳过
        printf("%d -> %d\n",u,v); // 从u到v打印，此时在u的状态空间里。
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