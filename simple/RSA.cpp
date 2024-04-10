#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <ctime>


using namespace std;

// 辗转相除法求最大公约数
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 求模逆元
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// 模幂运算
int powerMod(int base, int exponent, int modulus) {
    long long result = 1; // Use long long to prevent overflow
    base %= modulus;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (static_cast<long long>(base) * base) % modulus; // Use long long for base multiplication
    }
    return static_cast<int>(result); // Convert result back to int
}


// 判断是否为素数
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

// 生成大于1000的素数
int generatePrime() {
    int num = rand() % 9000 + 1001; // 生成1001到10000之间的随机数
    while (!isPrime(num))
        num = rand() % 9000 + 1001;
    return num;
}


int main() {
    srand(time(0)); // 使用当前时间作为随机种子

    int p = generatePrime();
    int q = generatePrime();
    while (p == q) // 确保p和q不相等
        q = generatePrime();

    int n = p * q;
    int phi_n = (p - 1) * (q - 1);

    // 选择 e，要求 e 和 phi_n 互质
    int e = 2;
    while (gcd(e, phi_n) != 1)
        e++;

    // 计算 d，即 e 的模逆元
    int d = modInverse(e, phi_n);

    // 输出 p, q, n, e, d, phi(n) 的值
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "n: " << n << endl;
    cout << "e: " << e << endl;
    cout << "d: " << d << endl;
    cout << "phi(n): " << phi_n << endl;

    // 加密明文
    string plaintext = "";
    cout << "Enter the plaintext to be encrypted: ";
    cin >> plaintext;
    string encrypted_text = "";
    for (char c : plaintext) {
        // cout << "C:" << c << endl;
        int m = c;
        // cout << "M:" << m << endl;
        int crypted_char = powerMod(m, e, n);
        // cout << "crypted_char:" << crypted_char << "    " << powerMod(m, e, n) << endl;
        encrypted_text += to_string(crypted_char) + " ";
    }

    // 输出加密后的密文
    cout << "Encrypted text: " << encrypted_text << endl;

    // 解密密文
    string decrypted_text = "";
    istringstream iss(encrypted_text);
    string token;

    while (getline(iss, token, ' ')) {
        if (token != "") {
            int c = stoi(token);
            // cout << "C:" << c << " ";
            int decrypted_char = powerMod(c, d, n);
            // cout << "decrypted_char:" << decrypted_char << "    " << powerMod(c, d, n) << endl;
            decrypted_text += static_cast<char>(decrypted_char);
        }
    }

    // 输出解密后的明文
    cout << "Decrypted text: " << decrypted_text << endl;

    // 输出到文件
    ofstream outfile("RSA_Output.txt");
    if (outfile.is_open()) {
        outfile << "p: " << p << endl;
        outfile << "q: " << q << endl;
        outfile << "n: " << n << endl;
        outfile << "e: " << e << endl;
        outfile << "d: " << d << endl;
        outfile << "phi(n): " << phi_n << endl;
        outfile << "Encrypted text: " << encrypted_text << endl;
        outfile << "Decrypted text: " << decrypted_text << endl;
        outfile.close();
        cout << "Output written to RSA_Output.txt" << endl;
    } else {
        cerr << "Unable to open file for writing!" << endl;
        return 1;
    }

    return 0;
}
