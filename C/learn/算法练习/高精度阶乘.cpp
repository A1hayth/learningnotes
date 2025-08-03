//https://www.luogu.com.cn/problem/P1009
#include <bits/stdc++.h>
using namespace std;

int n,a[10005],s[10005],mid[10005];

void add(){
    memset(mid,0,sizeof(mid));//重置mid数组
    mid[0] = max(a[0],s[0]);
    for(int i = 1;i <= mid[0]; i++){
        mid[i] += a[i] + s[i];
        mid[i + 1] = mid[i] /10;
        mid[i] %= 10;
    }
    while(mid[mid[0] + 1] > 0){
            mid[mid[0] + 2] = mid[mid[0] + 1] / 10;
            mid[mid[0] + 1] %= 10;
            mid[0]++;
    }
    for(int i = 1; i <= mid[0];i++ ) s[i] = mid[i];
    s[0] = mid[0];

}

int main(){
    cin >> n;
    a[0] = 1;
    a[1] = 1;
    s[0] = 1;
    s[1] = 0;

    for(int y = 1 ;y <= n ;y++){
        memset(mid,0,sizeof(mid));//重置mid数组
        mid[0] = a[0];
//计算阶乘
        for(int i = 1; i <= a[0];i++){
            mid[i] +=  a[i] * y;
            mid[i + 1] = mid[i] / 10;
            mid[i] %= 10; 
        }
//处理更高进位
        while(mid[mid[0] + 1] > 0){
            mid[mid[0] + 2] = mid[mid[0] + 1] / 10;
            mid[mid[0] + 1] %= 10;
            mid[0]++;
        }
        for(int i = 1;i <= mid[0];i++)a[i] = mid[i];
        a[0] = mid[0];
        add();
    }
    for(int i = s[0];i > 0;i--)cout << s[i];
    return 0;
}