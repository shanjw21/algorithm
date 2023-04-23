#include <iostream>
#include <vector>
#include <queue>

/*

    宽搜的计算：出队后，入队前，结束后
    宽搜的性质：队列中的元素关于层次满足 两段性 和 单调性 
        两段性：同一时间，队列中仅有两层节点
        单调性：先入队的先出队。

测试用例：
8 7
1 2
1 3
2 4
2 5
2 6
3 7
3 8
1 出队
    2入队
    3入队
2 出队
    4入队
    5入队
    6入队
3 出队
    7入队
    8入队
4 出队
5 出队
6 出队
7 出队
8 出队
*/

using namespace std;
const int N = 30;
int n, m;
vector<int>e[N]; // 出边数组
int visited[N]; // 标记数组
queue<int>q; // 辅助队列

void bfs(int u){
    visited[u] = 1;
    q.push(u);
    while(q.size()){
        int x = q.front();
        q.pop();
        printf("%d 出队\n",x);
        // 出队后可以计算
        for(int y : e[x]){
            if(visited[y])  continue;
            visited[y] = 1;
            printf("    %d入队\n",y);
            // 入队之前可以计算
            q.push(y);
        }
    }
    // 结束后可以计算。
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    bfs(1);
    return 0;
}