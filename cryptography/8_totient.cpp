#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int calculateTotient(int n) {
    int result = 1;
    
    for (int i = 2; i < n; i++) {
        if (gcd(n, i) == 1) {
            result++;
        }
    }

    return result;
}

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n > 0) {
        int totient = calculateTotient(n);
        cout << "The totient (Euler's totient function) of " << n << " is: " << totient << endl;
    } else {
        cout << "Please enter a positive integer." << endl;
    }
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;

    return 0;
}
