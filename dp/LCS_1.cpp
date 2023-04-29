/*
    最长公共子序列(Longest Common Sequence, LCS)
    状态变量：
        f[i][j]记录序列a[1...i]和b[1...j]的最长公共子序列长度。
        考虑末尾元素a[i]和b[j]是否在公共子序列中：
        1、若a[i]=b[j],则a[i],b[j]在公共子序列中，f[i][j] = f[i-1][j-1]+1
        2、若a[i]!=b[j],且a[i]不在公共子序列中，则可以去掉a[i]，所以f[i][j] = f[i-1][j]
        3、若a[i]!=b[j],且b[j]不在公共子序列中，则可以去掉b[j],所以f[i][j] = f[i][j-1]
        最终的答案就是f[m][n]

    递推式：
        f[i][j] = f[i-1]+f[j-1]+1, a[i]=b[j]
                = Max(f[i-1][j],f[i][j-1]), a[i]!=b[j]      
    边界条件：f[0][j] = 0; f[i][0] = 0

    记录序列：pre[i][j]标记前驱位置
             pre[i][j] = 1; 左上方
             pre[i][j] = 2; 左边
             pre[i][j] = 3; 上边

    f[i][j]数组的转移:         
            f[i-1][j-1] f[i-1][j]
            f[i][j-1]   f[i][j]
    pre[i][j] = 1; 表示从左上方即f[i-1][j-1]转移过来的
    pre[i][j] = 2; 表示从左边f[i][j-1]转移过来的
    pre[i][j] = 3; 表示从上方f[i-1][j]转移过来的

*/

#include <iostream>
#include <cstring>

char a[200] = "ADABBC";
char b[200] = "DBDCA";
char f[201][201]; // 长度数组
char pre[201][201]; // 前驱数组
int n,m;

// 输出公共子序列最大长度
void LCS(){
    int i,j;
    m = strlen(a);
    n = strlen(b);
    for(int i = 1; i <= m; i++){ // m行
        for(int j = 1; j<= n; j++){ // n列
            if(a[i-1] == b[j-1]){
                f[i][j] = f[i-1][j-1] + 1; // 注意下标，f[][]从1开始，a[],b[]字符串从0开始
                pre[i][j] = 1; // 表示由左上方转移过来的
            }
            else if(f[i][j-1] > f[i-1][j]){
                f[i][j] = f[i][j-1];
                pre[i][j] = 2; // 表示由左边转移过来的
            }
            else{
                f[i][j] = f[i-1][j];
                pre[i][j] = 3;// 表示由上边转移过来的
            }
        }
    }
    printf("%d\n",f[m][n]);
}

// 输出公共子序列最大长度序列
void getLCS(){
    int i, j, k;
    char s[200]; // 存储公共自序列
    i = m, j = n, k = f[m][n]; // 倒推子序列
    while(i >0 && j > 0){
        if(pre[i][j] == 1){ // 左上方转移来的,也是公共子序列元素。
            s[k--] = a[i-1];
            i--, j--;
        }
        else if(pre[i][j] == 2){// 左边转移来的
            j--;
        }
        else    i--; // 上边转移来的
    }

}

int main(){
    LCS(); // 输出最长长度
    getLCS(); // 输出子序列
    return 0;
}