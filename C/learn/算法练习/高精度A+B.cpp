//https://www.luogu.com.cn/problem/P1601
#include <bits/stdc++.h>
using namespace std;
int a[10001],b[10001],c[10001];
int len1,len2;
string s1,s2;
int main(){
    cin >> s1;
    cin >> s2;
    len1 = s1.size();
    len2 = s2.size();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i = 0; i < len1;i++)
        a[i] = s1[i] - '0';
    for(int i = 0; i < len2;i++)
        b[i] = s2[i] - '0';
     int len = max(len1,len2);
    for(int i = 0;i < len;i++){
        c[i] += a[i] + b[i];
        c[i+1] += c[i] / 10;
        c[i] = c[i] % 10; 
    }
    if(c[len])len++;
    for(int i = len - 1;i>=0;i--) cout << c[i] ;
    return 0;
}