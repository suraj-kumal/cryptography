#include <iostream>
using namespace std;
// Function to calculate the GCD using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    // Input two numbers from the user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    // Calculate the GCD of the two numbers
    int greatestCommonDivisor = gcd(num1, num2);
    // Check if the GCD is 1 (numbers are coprime)
    if (greatestCommonDivisor == 1) {
        cout << num1 << " and " << num2 << " are coprime." << endl;
    } else {
        cout << num1 << " and " << num2 << " are not coprime." << endl;
    }
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;
    return 0;
}
