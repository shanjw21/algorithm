#include <iostream>

using namespace std;
const int N = 20;
int g[N][N];
int n,m;
int dx[4] = {-2,-1,1,2},dy[4] = {1,2,2,1};
int total;

void dfs(int x, int y){
    if(x == n && y == m){
        total += 1;
        return;
    }
    for(int i = 0; i < 4; ++i){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a > n || b < 0 || b > m)  continue;
        if(g[a][b]) continue;
        g[a][b] = 1;
        dfs(a,b);
        g[a][b] = 0;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    g[0][0] = 1;
    dfs(0,0);
    printf("%d\n",total);
}