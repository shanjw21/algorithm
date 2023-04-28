#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> dist;
queue<string>q;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
/*
    题目描述：[八数码难题](https://www.acwing.com/problem/content/847/)
    
    较好的题解：https://www.acwing.com/solution/content/15149/
    思路：一个布局对应一个字符串，对应一个状态点，从一个布局变到另一个布局就对应走过一条边，从初始状态走到最终状态
    计算最少的步数就是BFS问题。
    unordered_map<string,int>dist:键值对映射储存字符串变换所走的步数。
    队列维护扩展到的节点（字符串）
    dx[4],dy[4]存方向偏移量

    技巧：用map容器，绑定字符串与步数
    一维与二维下标位置转换的技巧。

输入样例：
2 3 4 1 5 x 7 6 8
输出样例：
19
*/

int bfs(string start){
    string end = "1238x4765";
    dist[start] = 0;
    q.push(start);
    while(q.size()){
        auto s = q.front();
        q.pop();
        if(s == end)    return dist[s]; // 到达目标
        int k = s.find('x'); // 记录x在字符串的位置
        int x = k / 3, y = k % 3; // 坐标转换
        for(int i = 0; i < 4; i++){
            auto a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= 3 || b < 0 || b >= 3)  continue;
            int distance = dist[s]; // 记录未交换前的dist值
            swap(s[k], s[a*3+b]); // 交换
            if(!dist.count(s)){
                q.push(s);
                dist[s] = distance + 1; // 如果没有扩展过就扩展
            }
            swap(s[k], s[a*3+b]); // 还原
        }
    }
    return -1;
}

int main(){
    string c;
    string start;
    for(int i = 0; i < 9; i++){
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;
}