#include <iostream>
using namespace std;

// 扩展欧几里得算法，求 ax ≡ 1 (mod m) 的 x，即 a 在 mod m 下的逆元
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// 中国剩余定理求解 x，使得 x ≡ a[i] (mod m[i])
int chinese_remainder(int a[], int m[], int n) {
    int M = 1; // 计算 m1 * m2 * ... * mn
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }
    
    int x = 0;
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i]; // 计算 M_i = M / m_i
        int inv, y;
        extended_gcd(Mi, m[i], inv, y); // 计算 M_i 在 mod m_i 下的逆元
        inv = (inv % m[i] + m[i]) % m[i]; // 确保 inv 是正数
        x = (x + a[i] * Mi * inv) % M;
    }
    return x;
}

int main() {
    int a[] = {2, 4, 6}; // 余数
    int m[] = {3, 5, 7}; // 模数
    int n = 3;
    
    int min_soldiers = 400; // 最少存活人数
    int max_soldiers = 500; // 最多存活人数
    
    int result = chinese_remainder(a, m, n); // 求解 x
    
    // 找到满足 400 ≤ x ≤ 500 的最小 x
    int M = 3 * 5 * 7; // 计算模数的乘积
    while (result < min_soldiers) {
        result += M;
    }
    if (result > max_soldiers) {
        cout << "无法找到合适的解。" << endl;
    } else {
        cout << "韩信的兵士总数为: " << result << endl;
    }
    return 0;
}
