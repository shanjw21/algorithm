/*
    数塔问题解法一：搜索
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
    测试数据：
    5
    13
    11 8
    12 7 26
    6 14 15 8
    12 7 13 24 11

    输出：84

    时间复杂度分析：O(2^(N-1)),每条路径由N-1步组成，每一步由左右两种选择，所以路径总数是2^(N-1)
*/

const int N = 1100;
int a[N][N];
int n, ans;

// dfs(int,int,int):表示当前已经从(1,1)走到(x,y)，目前已经走过的路径上的权值和为Curr.
void dfs(int x, int y, int cur){
    if(x == n){
        if(cur > ans)   ans = cur;
        return;
    }
    printf("dfs(%d, %d)\n",x, y);
    dfs(x + 1, y, cur + a[x+1][y]);
    dfs(x + 1, y + 1, cur + a[x+1][y+1]);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
    dfs(1,1,a[1][1]);
    cout << ans << endl;
    return 0;
}