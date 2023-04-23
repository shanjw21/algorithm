#include <iostream>

using namespace std;

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