#include "des.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>
using namespace std;

string final_permutation(string s)
{
    string rs = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rs += s[T6[i][j] - 1];
        }
    }
    return rs;
}

/**

 *P盒置换函数 32位->32位

 *函数说明：s为S盒的输出

 */
string P_box(string s)
{
    string rs = "";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rs += (s[P[i][j] - 1]);
        }
    }
    return rs;
}

/**

 *S盒置换函数 48位->32位

 *函数说明：s为48位数据

 *返回值为32位

 */
string S_box(string s)
{
    string rs = "";
    string s1;
    int k1, k2;//S盒的行号和列号
    int h = 1;//决定使用那个S盒
    for (int i = 0; i <= 42; i = i + 6, h++)
    {
        k1 = (s[i] - '0') * 2 + (s[i + 5] - '0') * 1;
        k2 = (s[i + 1] - '0') * 8 + (s[i + 2] - '0') * 4 + (s[i + 3] - '0') * 2 + (s[i + 4] - '0') * 1;
        int x = S[h - 1][k1][k2];
        s1 = "";
        int y = 8;
        for (int j = 1; j <= 4; j++)
        {
            if (x < y)
            {
                s1 += "0";
                y /= 2;
            }
            else
            {
                s1 += "1";
                x = x % y;
                y /= 2;
            }
        }
        rs += s1;
    }
    return rs;
}

/**

 *异或运算函数

 *要求位数相同

 */
string XOR(string s1, string s2)
{
    string rs = "";
    for (int i = 0; i < s1.length() && i < s2.length(); i++)
    {
        rs += ((s1[i] - '0') ^ (s2[i] - '0')) + '0';
    }
    return rs;
}

/**

 *数据扩展函数 32->48

 *函数说明：s为数据的右半部分 32位

 *扩展成48位的输出

 */
string plaintext_righthalf_extended_permutation(string s)
{
    string rs = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rs += s[T5[i][j] - 1];
        }
    }
    return rs;
}

/**

 *密钥压缩置换函数 56位->48位

 *函数说明：s为56为的密钥

 *输出为48位的子密钥

 */
string secret_key_compression_replacement(string s)
{
    string rs = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rs += s[T4[i][j] - 1];
        }
    }
    return rs;
}

/**

 *密钥循环左移函数 56位->56位

 *函数说明：k为左移位数 s为密钥

 *返回值位数不变

 */
string secret_ket_left_move(int k, string s)//密钥循环左移k位
{
    string s1 = s.substr(0, 28);
    string s2 = s.substr(28, 28);
    string rs = s1.substr(k, 28 - k) + s1.substr(0, k) + s2.substr(k, 28 - k) + s2.substr(0, k);
    return rs;
}

/**

 *密钥初始置换函数 64位->58位

 *函数说明：s为64位的初始密钥

 *返回值为58位

 */
string secret_key_initial_permutation(string s)
{
    string rs = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            rs += s[T2[i][j] - 1];
        }
    }
    return rs;
}

/**

 *明文初始置换函数 64位->64位

 *函数说明：s为初始明文 64位

 *返回值为6位

 */
string plaintext_initial_permutation(string s)//明文初始置换
{
    string rs = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rs += s[T1[i][j] - 1];
        }
    }
    return rs;
}

/**

 *16进制转2进制函数

 *函数说明：s为16进制字符串

 *返回为2进制字符串

 */
string H(string s)
{
    string s1;
    string rs = "";
    for (int i = 0; i < s.length(); i++)
    {
        int x;
        if (s[i] >= '0' && s[i] <= '9')
        {
            x = s[i] - '0';
        }
        else
        {
            x = s[i] - 'A' + 10;
        }
        s1 = "";
        int y = 8;
        for (int j = 1; j <= 4; j++)
        {
            if (x < y)
            {
                y /= 2;
                s1 += "0";
            }
            else
            {
                s1 += "1";
                x = x % y;
                y = y / 2;
            }
        }
        rs += s1;
    }
    return rs;
}

/**

*2进制转16进制函数

*str为2进制字符串

*返回值为16进制字符串

*/
string G(string str)
{
    string rs = "";
    char temp;
    for (int i = 0; i <= str.length() - 4; i = i + 4)
    {
        int x = (str[i] - '0') * 8 + (str[i + 1] - '0') * 4 + (str[i + 2] - '0') * 2 + str[i + 3] - '0';

        if (x >= 10)
        {
            temp = (char)(x - 10 + 'A');
        }
        else
        {
            temp = (char)(x + '0');
        }
        rs += temp;
    }
    return rs;
}

/**

 *封装函数f

 *函数说明：接收32位数据和48位的子密钥 产生一个32位的输出

 *str1:32位数据  str2:48位的子密钥

 *返回值32位

 */

string f(string str1, string str2)
{
    string expendR = plaintext_righthalf_extended_permutation(str1);
    //cout << "32位数据扩展为48位结果:" << expendR << endl;

    string rs = XOR(expendR, str2);
    //cout << "密钥和扩展数据异或结果:" << rs << endl;

    rs = S_box(rs);
    //cout << "S盒替代结果(48->32):" << rs << endl;

    rs = P_box(rs);
    //cout << "P盒替代结果(32->32):" << rs << endl;

    return rs;
}

/**

 *子密钥生成函数

 *函数说明：s为给定的密钥

 *生成16个子密钥

 */
string Keys[20];

void generateKeys(string s)
{
    s = secret_key_initial_permutation(s);

    for (int i = 1; i <= 16; i++)
    {
        s = secret_ket_left_move(T3[i - 1], s);
        Keys[i] = secret_key_compression_replacement(s);
        //cout << "K" << i << ":" << Keys[i] << endl;
    }
    cout << endl;
}

/**

 *DES加密函数 64位->64位

 *函数说明：str1为64位的给定明文

 *返回值为64位的密文

 */
string encrypt(string str1)
{
    //第一步:明文初始置换 64->64
    str1 = plaintext_initial_permutation(str1);
    //cout << "明文初始置换结果(64->64):" << str1 << endl << endl;

    //第二步:数据分组
    string left = str1.substr(0, 32);
    string right = str1.substr(32, 32);
    //cout << "L0:" << left << endl;
    //cout << "R0:" << right << endl << endl;

    string newleft;

    //第三步:16轮迭代
    for (int i = 1; i <= 16; i++)
    {
        //cout << "第" << i << "次迭代" << endl;
        newleft = right;

        right = XOR(left, f(right, Keys[i]));

        left = newleft;

        //cout << "L[" << i << "]:" << left << endl;
        //cout << "R[" << i << "]:" << right << endl << endl;
    }

    //第四步:合并数据 注意位R16L16
    string rs = right + left;
    //cout << "R16L16:" << rs << endl << endl;

    //结尾置换
    rs = final_permutation(rs);
    //cout << "最终置换结果:" << rs << endl << endl;
    return rs;

}
/**

*解密函数

*str为密文

*输出明文

*/
string decrypt(string str)
{
    //把密文当作明文进行初始明文置换
    str = plaintext_initial_permutation(str);
    //cout << "密文当作明文初始置换结果(64->64):" << str << endl << endl;

    //分组
    string left = str.substr(0, 32);
    string right = str.substr(32, 32);


    string newleft;

    //逆序的子密钥使用 16轮迭代
    for (int i = 16; i >= 1; i--)
    {

        newleft = right;
        right = XOR(left, f(right, Keys[i]));
        left = newleft;
    }

    //合并
    string rs = right + left;

    //最后置换
    rs = final_permutation(rs);
    //cout << "最终置换结果:" << rs << endl << endl;

    return rs;
}

// CBC模式的加密函数
string encryptCBC(string str1, string iv) {
    // 将明文分成64位的块
    vector<string> blocks;
    for (size_t i = 0; i < str1.length(); i += 64) {
        blocks.push_back(str1.substr(i, 64));
    }

    string ciphertext = "";
    string previousCiphertextBlock = iv;

    for (string block : blocks) {
        // CBC模式：与前一个密文块异或
        block = XOR(block, previousCiphertextBlock);

        // DES加密
        string encryptedBlock = encrypt(block);

        // 保存当前密文块
        previousCiphertextBlock = encryptedBlock;

        // 添加到最终密文
        ciphertext += encryptedBlock;
    }

    return ciphertext;
}

// CBC模式的解密函数
string decryptCBC(string str1, string iv) {
    // 将密文分成64位的块
    vector<string> blocks;
    for (size_t i = 0; i < str1.length(); i += 64) {
        blocks.push_back(str1.substr(i, 64));
    }

    string plaintext = "";
    string previousCiphertextBlock = iv;

    for (string block : blocks) {
        // DES解密
        string decryptedBlock = decrypt(block);

        // CBC模式：与前一个密文块异或
        decryptedBlock = XOR(decryptedBlock, previousCiphertextBlock);

        // 保存当前密文块
        previousCiphertextBlock = block;

        // 添加到最终明文
        plaintext += decryptedBlock;
    }

    return plaintext;
}


//RSA============================================================================================================
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


int main()
{
    unsigned long long p = 4294967311ULL;
    unsigned long long q = 4294967357ULL;
    unsigned long long n = p * q;
    unsigned long long phi = (p - 1) * (q - 1);
    unsigned long long e = 65537;

    while (gcd(e, phi) != 1) e += 2;
    unsigned long long d = modInverse(e, phi);
    size_t blockSize = 8; // 每块 8 个 hex 字符（32 位）


    cout << "加密请输入0，解密请输入1:";
    int choice;
    cin >> choice;
    if (choice != 0 && choice != 1) {
        cout << "输入错误，请输入0或1" << endl;
        return 1;
    }
    if (choice == 0) 
    {
    //明文 16进制
    string str1 = " ";
    cout << "请输入明文： ";
    cin >> str1;
    //密钥16进制
    string str2 = "133457799BBCDFF1";
    string iv = "1000000000000000";   // 初始化向量
    string temp = str1;//保存十六进制的明文以便后面验证算法正确性

    vector<string> blocks = splitHex(str2, blockSize);
    vector<unsigned long long> encryptedBlocks;
    vector<unsigned long long> decryptedBlocks;

    unsigned long long key = 0;
    for (const auto& blk : blocks) {
        unsigned long long m = hexToULL(blk);
        if (m >= n) {
            cout << "明文块过大：" << blk << "，请使用更大的密钥。" << endl;
            return 1;
        }
        unsigned long long c = modExp(m, e, n);
        encryptedBlocks.push_back(c);
        cout << "密钥块" << c << endl; 
        
    }

    //进制转换 16->2
    str1 = H(str1);
    str2 = H(str2);
    iv = H(iv);

    generateKeys(str2);


    //明文加密
    string rs = encryptCBC(str1,iv);

    cout << "密文（16进制）：" << G(rs) << endl;
    }   


else if (choice == 1) 
    {
    string str2 = "133457799BBCDFF1";

    cout << "请输入密文： ";
    string ciphertext = " ";
    cin >> ciphertext;
    //密钥16进制

    vector<unsigned long long> encryptedBlocks;
    vector<unsigned long long> decryptedBlocks;
    cout << "请输入密钥块1： ";
    string key1 = " ";
    cin >> key1;
    encryptedBlocks.push_back(hexToULL(key1));
    cout << "请输入密钥块2： ";
    string key2 = " ";
    cin >> key2;
    encryptedBlocks.push_back(hexToULL(key2));
    string iv = "1000000000000000";   // 初始化向量

    for (auto c : encryptedBlocks) {
        unsigned long long m = modExp(c, d, n);
        decryptedBlocks.push_back(m);
    }

    // 拼接还原明文
    stringstream decryptedHex;
    for (auto m : decryptedBlocks) {
        string part = ullToHex(m);
        // 补零保持块大小
        while (part.length() < blockSize) part = "0" + part;
        decryptedHex << part;
    }

    cout << "\n最终还原的十六进制明文: " << str2 << endl;

    ciphertext = H(ciphertext);
    str2 = H(str2);
    iv = H(iv);

    //生成16个子密钥
    generateKeys(str2);

    string text = decryptCBC(ciphertext,iv);
    cout << "明文（16进制）：" << G(text) << endl;
    }

    return 0;
}