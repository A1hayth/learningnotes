#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>

uint32_t leftRotate(uint32_t x, uint32_t c) // 循环左移函数
{
    return (x << c) | (x >> 32 - c);
}

std::string md5(const std::string &input)
{

    uint32_t A = 0x67452301;
    uint32_t B = 0xefcdab89;
    uint32_t C = 0x98badcfe;
    uint32_t D = 0x10325476;

    uint32_t T[64] = {// T表
                      0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                      0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                      0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                      0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                      0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                      0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
                      0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                      0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                      0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                      0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                      0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
                      0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                      0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                      0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                      0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                      0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
    // 非线性函数位移
    uint32_t s[64] = {
        // 第一轮：使用非线性函数 F
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        // 第二轮：使用非线性函数 G
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        // 第三轮：使用非线性函数 H
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        // 第四轮：使用非线性函数 I
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
    std::vector<uint8_t> msg(input.begin(), input.end()); // 输入字符串
    uint64_t original_len_bits = input.size() * 8;        // 记录输入长度
    // 先添加一个1位（0x80 表示二进制 1000 0000）
    msg.push_back(0x80);
    // 添加0，使得消息长度对 512 取模后等于 448
    while ((msg.size() * 8) % 512 != 448)
    {
        msg.push_back(0x00);
    }
    // 附加64位原始消息长度
    for (int i = 0; i < 8; i++)
    {
        msg.push_back((uint8_t)((original_len_bits >> (8 * i)) & 0xFF));
    }

    // 处理整个消息，每次 64 字节（512 位）为一个数据块
    for (size_t offset = 0; offset < msg.size(); offset += 64)
    {
        // 将当前 512 位数据块分割为 16 个 32 位小块 M[0..15]（小端）
        uint32_t M[16];
        for (int j = 0; j < 16; j++)
        {
            M[j] = (uint32_t)msg[offset + j * 4] |
                   ((uint32_t)msg[offset + j * 4 + 1] << 8) |
                   ((uint32_t)msg[offset + j * 4 + 2] << 16) |
                   ((uint32_t)msg[offset + j * 4 + 3] << 24);
        }

        // 保存当前状态，供后续累加
        uint32_t a = A;
        uint32_t b = B;
        uint32_t c = C;
        uint32_t d = D;
        // 64步运算，4轮，每轮16步
        for (int i = 0; i < 64; i++)
        {
            uint32_t F_val, g;
            // F函数（AND）F(X,Y,Z) = (X & Y) | ((~X) & Z)
            if (i < 16)
            {
                F_val = (b & c) | ((~b) & d);
                g = i;
            }
            // G函数（OR）G(X,Y,Z) = (X & Z) | (Y & (~Z))
            else if (i < 32)
            {
                F_val = (d & b) | ((~d) & c);
                g = (5 * i + 1) % 16;
            }
            // H函数（XOR）H(X,Y,Z) = X ^ Y ^ Z;
            else if (i < 48)
            {
                F_val = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            }
            // I函数（NOT）I(X,Y,Z) = Y ^ (X | (~Z))
            else
            {
                F_val = c ^ (b | (~d));
                g = (7 * i) % 16;
            }
            // 保存 d 的值，用作临时变量
            uint32_t temp = d;
            // 状态轮换：d <- c, c <- b
            d = c;
            c = b;
            // b = b + ((a + F_val + M[g] + T[i]) 循环左移 s[i] 位)
            b = b + leftRotate(a + F_val + M[g] + T[i], s[i]);

            a = temp; 
        }
        // 处理完当前数据块后，将本块的结果累加到初始状态中
        A += a;
        B += b;
        C += c;
        D += d;
    }
    // 将最终的 A, B, C, D（4 个 32 位数）合并成 128 位哈希值，按小端顺序转换为 32 个十六进制字符
    std::ostringstream oss;
    auto to_hex = [&oss](uint32_t num)
    {
        // 处理 4 个字节，每个字节输出为 2 个十六进制字符
        for (int i = 0; i < 4; i++)
        {
            oss << std::setw(2) << std::setfill('0') << std::hex << ((num >> (8 * i)) & 0xFF);
        }
    };

    to_hex(A);
    to_hex(B);
    to_hex(C);
    to_hex(D);

    // 返回最终的 MD5 哈希值
    return oss.str();
}
int main()
{
    // 提示用户输入字符串
    std::string input;
    std::cout << "请输入字符串: ";
    std::getline(std::cin, input);

    // 调用 MD5 函数获取哈希值
    std::string result = md5(input);
    std::cout << "MD5: " << result << std::endl;

    return 0;
}