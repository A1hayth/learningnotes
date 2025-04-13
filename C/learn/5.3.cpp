#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// 计算 (base^exp) % mod 的快速幂
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 计算 n 的所有质因子
vector<int> get_prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// 判断 g 是否是模 p 的原根
bool is_primitive_root(int g, int p, const vector<int>& factors) {
    int phi = p - 1;
    for (int factor : factors) {
        if (mod_pow(g, phi / factor, p) == 1)
            return false;
    }
    return true;
}

int main() {
    int p = 47;
    int phi = p - 1;

    vector<int> factors = get_prime_factors(phi);

    cout << "模 " << p << " 的所有原根为：" << endl;
    for (int g = 2; g < p; ++g) {
        if (is_primitive_root(g, p, factors)) {
            cout << g << " ";
        }
    }
    cout << endl;
    return 0;
}
