#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

// 将十六进制字符串转为整数（支持32位以内）
unsigned long long hexToULL(const string& hex) {
    unsigned long long result = 0;
    for (char c : hex) {
        result <<= 4;
        if (c >= '0' && c <= '9') result += c - '0';
        else if (c >= 'A' && c <= 'F') result += c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') result += c - 'a' + 10;
    }
    return result;
}

// 将整数转为十六进制字符串
string ullToHex(unsigned long long value) {
    stringstream ss;
    ss << std::hex << value;
    return ss.str();
}

// 快速幂算法
unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// 最大公约数
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b) {
        unsigned long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// 模逆
unsigned long long modInverse(unsigned long long e, unsigned long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    while (newr != 0) {
        long long quotient = r / newr;
        long long temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) throw std::runtime_error("e is not invertible");
    if (t < 0) t += phi;
    return t;
}

// 字符串分块
vector<string> splitHex(const string& hex, size_t blockSize) {
    vector<string> blocks;
    for (size_t i = 0; i < hex.length(); i += blockSize) {
        blocks.push_back(hex.substr(i, blockSize));
    }
    return blocks;
}

int main() {
    // 使用较大素数，生成足够大的 n
    unsigned long long p = 4294967311ULL;
    unsigned long long q = 4294967357ULL;
    unsigned long long n = p * q;
    unsigned long long phi = (p - 1) * (q - 1);
    unsigned long long e = 65537;

    while (gcd(e, phi) != 1) e += 2;
    unsigned long long d = modInverse(e, phi);

    string hexMsg = "133457799BBCDFF1";
    size_t blockSize = 8; // 每块 8 个 hex 字符（32 位）

    vector<string> blocks = splitHex(hexMsg, blockSize);
    vector<unsigned long long> encryptedBlocks;
    vector<unsigned long long> decryptedBlocks;

    cout << "加密过程:" << endl;
    for (const auto& blk : blocks) {
        unsigned long long m = hexToULL(blk);
        if (m >= n) {
            cout << "明文块过大：" << blk << "，请使用更大的密钥。" << endl;
            return 1;
        }

        unsigned long long c = modExp(m, e, n);
        encryptedBlocks.push_back(c);
        cout << "  原始块: " << blk << " 加密后: " << c << endl;
    }

    cout << "\n解密过程:" << endl;
    for (auto c : encryptedBlocks) {
        unsigned long long m = modExp(c, d, n);
        decryptedBlocks.push_back(m);
        cout << "  密文: " << c << " 解密后: " << ullToHex(m) << endl;
    }

    // 拼接还原明文
    stringstream decryptedHex;
    for (auto m : decryptedBlocks) {
        string part = ullToHex(m);
        // 补零保持块大小
        while (part.length() < blockSize) part = "0" + part;
        decryptedHex << part;
    }

    cout << "\n最终还原的十六进制明文: " << decryptedHex.str() << endl;

    return 0;
}
