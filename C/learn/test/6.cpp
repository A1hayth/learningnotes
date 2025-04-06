#include <iostream>
using namespace std;

// 快速幂计算 a^b mod p
int mod_pow(int a, int b, int p) {
    int result = 1;
    a = a % p;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (1LL * result * a) % p;
        }
        a = (1LL * a * a) % p;
        b /= 2;
    }
    return result;
}

// 勒让德符号计算函数
int legendre_symbol(int a, int p) {
    if (a % p == 0) return 0;
    int res = mod_pow(a, (p - 1) / 2, p);
    if (res == 1) return 1;
    else if (res == p - 1) return -1;
    else return 0; // 理论上不该出现
}

int main() {
    int a, p;
    cout << "请输入整数 a: ";
    cin >> a;
    cout << "请输入奇素数 p: ";
    cin >> p;

    if (p <= 2) {
        cout << "p 必须是大于 2 的奇素数。" << endl;
        return 1;
    }

    int result = legendre_symbol(a, p);
    cout << "勒让德符号 (" << a << "/" << p << ") = " << result << endl;

    return 0;
}
