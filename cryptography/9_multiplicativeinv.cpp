#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int multiplicativeInverse(int a, int modulus) {
    int x, y;
    int gcd = extendedGCD(a, modulus, x, y);

    if (gcd != 1) {
        return -1;
    } else {
        return (x % modulus + modulus) % modulus;
    }
}

int main() {
    int a, modulus;

    cout << "Enter a number: ";
    cin >> a;

    cout << "Enter the modulus: ";
    cin >> modulus;

    int inverse = multiplicativeInverse(a, modulus);

    if (inverse != -1) {
        cout << "The multiplicative inverse of " << a << " modulo " << modulus << " is: " << inverse << endl;
    } else {
        cout << "The multiplicative inverse does not exist for " << a << " modulo " << modulus << endl;
    }
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;
    return 0;
}
