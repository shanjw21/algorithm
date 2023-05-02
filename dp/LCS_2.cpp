/*
    最长公共子串(LCS):
    公共子串：字符必须是连续相等的
    公共子序列：字符必须是相等的，可以不连续

    状态变量：
        f[i][j]表示以a[i]和b[j]为结尾的公共子串的长度
        只有当两个字符串中的字符连续相等时，公共子串的长度才不断增加，否则清零。
    
    递推式：
        1、若a[i]=b[j],则可以构成公共子串;f[i][j] = f[i-1][j-1]+1
        2、若a[i]!=b[j]则不能构成公共子串;f[i][j] = 0
    
    边界条件：
        f[0][j] = 0
        f[i][0] = 0

    f[i][j]数组的转移:         
            f[i-1][j-1]     0
            0               f[i][j]
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
char a[200] = "ABACCB";
char b[200] = "AACCAB";
int f[201][201];

void LCS(){
    int m,n;
    m = strlen(a);
    n = strlen(b);
    int ans = 0, ans_idx; // ans记录最长子串长度，ans_idx记录最长子串在b中的索引
    for(int i = 1; i <= m; i++){
        for(int j = 1; j<=n; j++){
            if(a[i-1] == b[j-1]){ // 注意下标
                f[i][j] = f[i-1][j-1] + 1; 
            }
            else    f[i][j] = 0;
            if(f[i][j] > ans){
                ans = f[i][j];
                ans_idx = j - 1; // 记录最长子串的索引
            }
        }
    }
    cout << "ans = " << ans << " length = " << ans_idx << endl;
    printf("最长子串是： \n");
    for(int i = ans_idx - ans + 1; i <= ans_idx; i++){
        printf("%c ",b[i]);
    }
    cout << endl;
}

int main(){
    LCS();

    return 0;
}
