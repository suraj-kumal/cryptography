#include <iostream>
#include <string>

using namespace std;

int totient(int n) {
    int result = n;

    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int ext_euc(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = ext_euc(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int modulo(int base, int exponent, int mod) {
    int x = 1;
    int y = base;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        exponent = exponent / 2;
    }

    if ((x % mod) < 0) {
        return (mod + (x % mod));
    } else {
        return x % mod;
    }
}
int main() {
    int cipher[50];
    int n, p, q, t, x, y, d = 1, e = 2;
    string message, encrypt, decrypt;

    cout << "Enter your message: ";
    getline(cin, message);

    for (char &c : message) {
            c = toupper(c) - 65;
    }

    cout << "Enter prime numbers p and q: ";
    cin >> p >> q;

    n = p * q;
    t = totient(n);

    while (ext_euc(e, t, x, y) != 1) {
        e++;
     }

    while (((e * d) % t) != 1) {
            d++;
    }

    cout << "\nEncrypted Message is: ";

    for (size_t i = 0; i < message.length(); i++) {
        cipher[i] = modulo(message[i], e, n);
        encrypt.push_back(static_cast<char>((modulo(message[i], e, n) + 65) % 128));
        cout << encrypt[i];
    }

    cout << "\n";

    cout << "\nDecrypted Message is: ";

    for (size_t i = 0; i < encrypt.length(); i++) {
        decrypt.push_back(static_cast<char>((modulo(cipher[i], d, n) + 65)));
        cout << decrypt[i];
    }

    cout << "\n";
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;

    return 0;
}
