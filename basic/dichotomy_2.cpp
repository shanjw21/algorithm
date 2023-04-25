#include <iostream>

using namespace std;

/*
    浮点数二分：最大化查找
    题目描述：求一个浮点数(-10000 <= y <= 10000)的三次方根

*/
// 最大化查找，这里不存在溢出的问题。
double find(double y){
    double l = -100, r = 100;
    while(r - l > 1e-5){
        double mid = (l + r) / 2;
        if(mid*mid*mid <= y)    l = mid;
        else    r = mid;
    }
    return l;
}

int main(){
    double y;
    cin >> y;
    printf("%.3lf\n",find(y));
    return 0;
}