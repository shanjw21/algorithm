#include <iostream>

using namespace std;

/*
    题目描述：https://www.luogu.com.cn/problem/P1219
    回溯算法解决八皇后问题
    按行枚举，每行放置一个皇后，pos[N]数组保存第i行放置的皇后在第几列
    c[N]数组记录第j列已经放置了一个皇后。
    p[N]数组记录对角线上放置一个皇后，对角线满足：i + j 相等的格子在一条对角线上
    q[N]数组记录反对角线上放置的皇后，反对角线满足： i-j相等的格子在同一条反对角线上，为了防止出现负数，整体+6偏移。
*/

const int N = 30;
int pos[N],c[N], p[N], q[N];
int ans,n;

void print(){
    if(ans <= 3){
        for(int i = 1; i <= n; i++)
            printf("%d ",pos[i]);
        puts("");
    }
}

void dfs(int i){
    if(i > n){
        ans += 1;
        print();
        return;
    }
    for(int j = 1; j <= n; j++){
        if(c[j] || p[i+j] || q[i-j+n]) continue;
        pos[i] = j; // 记录第i行放在了第j列
        c[j] = p[i+j] = q[i-j+n] = 1; // 标记列，主对角线，斜对角线被占领
        dfs(i + 1);
        c[j] = p[i+j] = q[i-j+n] = 0;
    }
}

int main(){
    cin >> n;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}