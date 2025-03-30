#include <iostream>
using namespace std;

// 模重复平方法计算 (x^n) % m
long long mod_exp(long long x, long long n, long long m) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) { // 如果 n 是奇数
            result = (result * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return result;
}

int main() {
    long long x, n, m;
    cout << "请输入 x, n, m: ";
    cin >> x >> n >> m;
    cout << "计算结果: " << mod_exp(x, n, m) << endl;
    return 0;
}
