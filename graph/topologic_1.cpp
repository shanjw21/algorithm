#include <bits/stdc++.h>
using namespace std;

/*
    卡嗯算法：
    e[x]存放x的邻点，tp存放拓扑序列，din[x]存放x的入度
    算法流程：核心是使用队列维护一个入度为0的节点的集合
        1、初始化,队列q压入所有入度为0的点
        2、每次从q中取出一个点x放入数组tp;
        3、将x的所有出边删除，即将出边的入度减一，若边(x,y)删除后，y的入度变为0，则将y压入q中
        4、不断重复2,3过程，直到队列q为空
        5、若tp中的元素个数等于n，则有拓扑序，否则，有环。
*/

const int N = 1100;
int n,m;
vector<int>e[N],tp;
int din[N];

bool toposort(){
    // 队列q维护一个入度为0的序列
    queue<int>q;
    // 初始将所有入度为0的节点入队
    for(int i  = 1; i <= n; i++)
        if(din[i] == 0) 
            q.push(i);
    // 每次从q中取出一个点x放入数组tp;        
    while(q.size()){
        int x = q.front();
        q.pop();
        tp.push_back(x);
        // 将x的所有出边删除，即将出边的入度减一，若边(x,y)删除后，y的入度变为0，则将y压入q中
        for(auto y : e[x]){
            if(--din[y] == 0)   q.push(y);
        }
    }
    // 若tp中的元素个数等于n，则有拓扑序，否则，有环。
    return tp.size() == n;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        din[b] ++;
    }
    // 返回假，说明图中存在环，否则输出拓扑序
    if(!toposort()) puts("图中有环");
    else
        for(auto x : tp)    cout << x << ' ';
        cout << endl;
    return 0;
}