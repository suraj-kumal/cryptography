#include <iostream>
#include <windows.h>
using namespace std;

// Function to calculate (base^exponent) % mod efficiently
long long modPow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    // Clear the console screen
    system("cls");

    long long prime, base, privateA, privateB, publicA, publicB, secretA, secretB;

    cout << "Enter a prime number (P): ";
    cin >> prime;

    cout << "Enter a base (G): ";
    cin >> base;

    cout << "Enter Alice's private key (a): ";
    cin >> privateA;

    cout << "Enter Bob's private key (b): ";
    cin >> privateB;

    // Calculate public keys
    publicA = modPow(base, privateA, prime);
    publicB = modPow(base, privateB, prime);

    // Exchange public keys (In a real-world scenario, this would be done over a secure channel)
    cout << "Alice sends her public key to Bob: " << publicA << endl;
    cout << "Bob sends his public key to Alice: " << publicB << endl;

    // Calculate shared secrets
    secretA = modPow(publicB, privateA, prime);
    secretB = modPow(publicA, privateB, prime);

    cout << "Secret key computed by Alice: " << secretA << endl;
    cout << "Secret key computed by Bob: " << secretB << endl;

    // Verify that the shared secrets are equal (they should be)
    if (secretA == secretB) {
        cout << "Shared secret key match! " << endl;
    } else {
        cout << "Shared secrets key do not match. Error in the key exchange." << endl;
    }
    
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;

    return 0;
}
