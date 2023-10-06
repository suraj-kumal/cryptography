#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Modular exponentiation function (to compute a^b mod n)
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Rabin-Miller primality test
bool is_prime_rabin_miller(long long n, int k) {
    if (n <= 1 || n == 4) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    // Find d and r such that n-1 = 2^r * d, where d is odd
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Witness loop
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3);
        long long x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1) {
            continue;
        }
        bool is_composite = true;
        for (int j = 0; j < r; j++) { // Corrected the loop condition here
            x = mod_pow(x, 2, n);
            if (x == n - 1) {
                is_composite = false;
                break;
            }
        }

        if (is_composite) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(nullptr)); // Seed the random number generator with the current time
    long long n;
    int k = 20; // Set a fixed value for the number of iterations
    cout << "Enter a number to test for primality: ";
    cin >> n;
    if (is_prime_rabin_miller(n, k)) {
        cout << n << " is likely prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;
    return 0;
}
