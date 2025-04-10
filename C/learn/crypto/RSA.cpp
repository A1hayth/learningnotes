#include <iostream>
#include <string>
#include <cryptlib.h>
#include <rsa.h>
#include <osrng.h>
#include <base64.h>
#include <files.h>
#include <secblock.h>

using namespace CryptoPP;
using namespace std;

// 生成 RSA 密钥对（2048 位以上）
void GenerateRSAKey(unsigned int keyLength, RSA::PrivateKey& privateKey, RSA::PublicKey& publicKey) {
    AutoSeededRandomPool rng;
    privateKey.GenerateRandomWithKeySize(rng, keyLength);
    publicKey.AssignFrom(privateKey);
}

// 使用公钥加密
string RSAEncrypt(const RSA::PublicKey& publicKey, const string& plainText) {
    AutoSeededRandomPool rng;
    RSAES_OAEP_SHA_Encryptor encryptor(publicKey);

    string cipher;
    StringSource ss1(plainText, true,
        new PK_EncryptorFilter(rng, encryptor,
            new StringSink(cipher)
        )
    );
    return cipher;
}

// 使用私钥解密
string RSADecrypt(const RSA::PrivateKey& privateKey, const string& cipherText) {
    AutoSeededRandomPool rng;
    RSAES_OAEP_SHA_Decryptor decryptor(privateKey);

    string recovered;
    StringSource ss2(cipherText, true,
        new PK_DecryptorFilter(rng, decryptor,
            new StringSink(recovered)
        )
    );
    return recovered;
}

int main() {
    try {
        // 1. 生成密钥对（例如：3072位）
        RSA::PrivateKey privateKey;
        RSA::PublicKey publicKey;
        GenerateRSAKey(3072, privateKey, publicKey);
        cout << "RSA 3072-bit key pair generated." << endl;

        // 2. 原始消息（长度建议 < 密钥位数 / 8 - padding开销，例如 3072-bit 密钥约支持 <= 350 字节）
        string message = "这是一段需要被加密和解密的消息，使用的是RSA 3072位密钥";

        // 3. 加密
        string encrypted = RSAEncrypt(publicKey, message);
        cout << "Encryption done." << endl;

        // 4. 解密
        string decrypted = RSADecrypt(privateKey, encrypted);
        cout << "Decrypted Message: " << decrypted << endl;
    }
    catch (const Exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
