#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdint>

using namespace std;

// 循环左移
uint32_t leftrotate(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

// SHA-1 哈希计算
string sha1(const string &message) {
    // 初始化哈希值
    uint32_t H0 = 0x67452301;
    uint32_t H1 = 0xEFCDAB89;
    uint32_t H2 = 0x98BADCFE;
    uint32_t H3 = 0x10325476;
    uint32_t H4 = 0xC3D2E1F0;

    // 预处理：填充消息
    vector<uint8_t> paddedMessage(message.begin(), message.end());
    
    // 添加 1 位（0x80）
    paddedMessage.push_back(0x80);

    // 计算填充后的总字节数（必须模 64 余 56）
    size_t originalBitLength = message.size() * 8;
    while ((paddedMessage.size() % 64) != 56) {
        paddedMessage.push_back(0);
    }

    // 添加 64 位的原始消息长度（大端模式）
    for (int i = 7; i >= 0; i--) {
        paddedMessage.push_back((originalBitLength >> (i * 8)) & 0xFF);
    }

    // 处理每个 512 位（64 字节）块
    for (size_t i = 0; i < paddedMessage.size(); i += 64) {
        uint32_t W[80];

        // 将前 16 个 32 位字转换为 W[0] - W[15]
        for (int j = 0; j < 16; j++) {
            W[j] = (paddedMessage[i + j * 4] << 24) |
                   (paddedMessage[i + j * 4 + 1] << 16) |
                   (paddedMessage[i + j * 4 + 2] << 8) |
                   (paddedMessage[i + j * 4 + 3]);
        }

        // 扩展 W[16] - W[79]
        for (int j = 16; j < 80; j++) {
            W[j] = leftrotate(W[j - 3] ^ W[j - 8] ^ W[j - 14] ^ W[j - 16], 1);
        }

        // 初始化哈希值
        uint32_t a = H0, b = H1, c = H2, d = H3, e = H4;

        // 80 轮处理
        for (int j = 0; j < 80; j++) {
            uint32_t f, K;
            if (j < 20) {
                f = (b & c) | (~b & d);
                K = 0x5A827999;
            } else if (j < 40) {
                f = b ^ c ^ d;
                K = 0x6ED9EBA1;
            } else if (j < 60) {
                f = (b & c) | (b & d) | (c & d);
                K = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                K = 0xCA62C1D6;
            }

            uint32_t temp = leftrotate(a, 5) + f + e + K + W[j];
            e = d;
            d = c;
            c = leftrotate(b, 30);
            b = a;
            a = temp;
        }

        // 更新哈希值
        H0 += a;
        H1 += b;
        H2 += c;
        H3 += d;
        H4 += e;
    }

    // 生成最终哈希字符串
    stringstream hash;
    hash << hex << setw(8) << setfill('0') << H0
         << hex << setw(8) << setfill('0') << H1
         << hex << setw(8) << setfill('0') << H2
         << hex << setw(8) << setfill('0') << H3
         << hex << setw(8) << setfill('0') << H4;

    return hash.str();
}

int main() {
    string input;
    cout << "输入字符串: ";
    getline(cin, input);
    cout << "SHA-1 哈希: " << sha1(input) << endl;
    return 0;
}
