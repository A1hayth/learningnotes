#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 扩展欧几里得算法求逆元
tuple<int, int, int> extended_gcd(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [gcd, x1, y1] = extended_gcd(b, a % b);
    return {gcd, y1, x1 - (a / b) * y1};
}

// 中国剩余定理求解
int chinese_remainder_theorem(const vector<int>& a, const vector<int>& m) {
    int M = accumulate(m.begin(), m.end(), 1, multiplies<int>());
    int result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        int Mi = M / m[i];
        auto [gcd, inv, _] = extended_gcd(Mi, m[i]);
        if (gcd != 1) return -1; // 无解
        result += a[i] * Mi * inv;
    }
    return (result % M + M) % M; // 确保结果为正
}

int main() {
    vector<int> a = {2, 4, 6};  // 余数
    vector<int> m = {3, 5, 7};  // 模数

    int total_soldiers = chinese_remainder_theorem(a, m);
    if (total_soldiers == -1) {
        cout << "无解！" << endl;
        return 0;
    }
    
    // 考虑实际范围
    for (int x = total_soldiers; x <= 1500; x += 105) { // 105是3*5*7的最小公倍数
        if (x >= 1000 && x <= 1100) { // 确保战死400~500人
            cout << "韩信的兵士总数: " << x << endl;
            break;
        }
    }
    return 0;
}