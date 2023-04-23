#include <iostream>
#include <queue>

using namespace std;
/*
    定义一个n行m列的二维数组，1表示墙壁，0表示可以走，只能横着走或竖着走不能斜着走，
    要求编程找出从左上角到右下角的最短路线.
    数据保证有唯一解。

输入数据：
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出：
0 0
1 0
2 0
2 1
2 2
2 3
2 4
3 4
4 4
*/
const int N = 10;
int g[N][N];
struct node{
    int x, y;
};
node pre[N][N]; // 储存前驱节点
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
int n;


void bfs(int x, int y){
    queue<node>q;
    g[x][y] = 1;
    q.push({x,y});
    while(q.size()){
        auto u = q.front(); // 取出队头节点
        q.pop(); // 队头出队
        for(int i = 0; i < 4; i++){
            int a = u.x + dx[i], b = u.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= n)  continue;
            if(g[a][b]) continue;
            g[a][b] = 1; // 打标记,省的重复入队
            q.push({a,b}); // 扩展入队
            pre[a][b] = u; // 记录 点(a,b)是由 u 扩展过来的
        }
    }
}

void print(int x, int y){
    if(x == 0 && y == 0)    return;
    auto u = pre[x][y]; // 取出(x,y)前置节点位置
    print(u.x, u.y); // 递归访问前置节点
    cout << x << ' ' << y << endl; // 离，还在x y的状态空间里面。
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    bfs(0,0);
    puts("0 0");
    print(n-1, n-1);
    return 0;
}