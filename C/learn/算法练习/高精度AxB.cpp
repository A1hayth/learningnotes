#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[20010];
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
    for(int i = 0;i < len2 ;i++){
        for(int j = 0;j < len1;j++){
            c[i+j] += a[j] * b[i];
        }
    }
    int len = len1 + len2;
    for(int i = 0;i < len ;i++ ){
        
         c[i + 1] += c[i] / 10;
         c[i] %= 10;
    
    }
    if (c[len + 1] != 0) len++;
    while (len > 0 && c[len] == 0) len--;
    for(int i = len;i>=0;i--) cout << c[i];
    return 0;
}