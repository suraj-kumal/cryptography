#include <iostream>
#include <string>
using namespace std;
string encrypt(string text, string key) {
    string encryptedtxt = "";
    int keyIndex = 0;
    for (char character : text) {
        if (isalpha(character)) {
            char shift;
            if (isupper(character)) {
                shift = 'A';
            } else {
                shift = 'a';
            }
            char k_character = key[keyIndex % key.length()];
            char encryptedChar = ((character - shift + k_character - shift) % 26) + shift;
            encryptedtxt += encryptedChar;
            keyIndex++;
        } else {
            encryptedtxt += character;
        }
    }
    return encryptedtxt;
}

int main() {
    string text, key;
    cout << "Vigenere cipher !!!" << endl;
    cout << "Enter the plaintext: ";
    getline(cin, text);
    cout << "Enter the key: ";
    getline(cin, key);
    string encryptedtext = encrypt(text, key);
    cout << "Encrypted ciphertext is: " << encryptedtext << endl;
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;
    cin.get();
    return 0;
}
