#include <iostream>
#include <vector>
using namespace std;

// 快速幂 (a^k mod m)
int mod_pow(int a, int k, int m) {
    int result = 1;
    a %= m;
    while (k > 0) {
        if (k % 2 == 1) result = (1LL * result * a) % m;
        a = (1LL * a * a) % m;
        k /= 2;
    }
    return result;
}

// 计算 a mod p 的最小正阶
int order_mod(int a, int p) {
    for (int k = 1; k < p; ++k) {
        if (mod_pow(a, k, p) == 1) {
            return k;
        }
    }
    return -1;
}

int main() {
    int p = 47;
    cout << "a\tord_" << p << "(a)" << endl;
    for (int a = 1; a < p; ++a) {
        cout << a << "\t" << order_mod(a, p) << endl;
    }
    return 0;
}
