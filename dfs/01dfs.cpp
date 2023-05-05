#include <bits/stdc++.h>

using namespace std;
const int N = 110;
// 出边数组e[N]表示节点N的所有出边组成的数组。
vector<int> e[N];
int ne[N];
/*
    触碰节点的时机：1、入， 2、下， 3、回， 4、离
    多次触碰同一节点的状态空间
    深搜计算：自顶向下：(父算子1,2)
    自底向上：(子算父，3,4)
    入下回离都是都是在当前节点的状态空间完成计算。

    二叉树触碰点的时机：先、中、后
    一条链表的触碰点时机：入、离

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
入 1
下1
入 5
下5
入 2
离 2
回 5
下5
入 6
下6
入 3
离 3
回 6
下6
入 8
离 8
回 6
离 6
回 5
下5
入 7
离 7
回 5
离 5
回 1
下1
入 4
离 4
回 1
离 1
*/
void trace(vector<int>e[],int n){
    cout << "遍历出边数组：" << endl;
    for(int i = 1; i <= n; i++){
        printf("节点 %d 对应的出边是：\t",i);
        for(auto e:e[i]){
            cout << e << ' ';
        }
        cout << endl;
    }
}
// 二叉树触碰点的时机：先、中、后
void Binary_travel(int u){
    // printf("先 %d\n",u);
    Binary_travel(u*2);
    // printf("中 %d\n",u);
    Binary_travel(u*2+1);
    // printf("后 %d\n",u);
}

// 一条链表的触碰点时机：入、离
void dfs(int u){
    // printf("入%d\n",u);
    dfs(ne[u]);
    // printf("离%d\n",u);

}

// 深搜(递归)的状态空间
void dfs(int u, int fa){
    printf("入 %d\n",u); // 1第一次进入点u的状态空间
    for(auto v:e[u]){
        if(v == fa) continue;
        printf("下%d\n",u); // 2，进入点u的后继，向下遍历
        dfs(v,u);
        printf("回 %d\n",u); // 3,回到u点状态空间
    }
    printf("离 %d\n",u);// 离开u点状态空间
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
    //trace(e,n);
    dfs(1,0);

    cout << endl;
    return 0;
}