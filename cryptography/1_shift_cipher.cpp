#include<iostream>
#include<string>
using namespace std;
string encrypt(string text,int shift){
    string encryptedtxt = " ";
    for (char character : text) {
        if (isalpha(character)) {
            char shiftedCharacter = character + shift;                 
            if (isupper(character)) {
                if (shiftedCharacter > 'Z') {
                    shiftedCharacter -= 26;
                } else if (shiftedCharacter < 'A') {
                    shiftedCharacter += 26;
                }
            }
            else if (islower(character)) {
                if (shiftedCharacter > 'z') {
                    shiftedCharacter -= 26;
                } else if (shiftedCharacter < 'a') {
                    shiftedCharacter += 26;
                }
            }
            encryptedtxt += shiftedCharacter;
        } else {

            encryptedtxt += character;
        }
    }
    return encryptedtxt;
}
int main(){
    string text;
    int shift;
    cout<<"shift cipher !!"<<endl;
    cout<<"enter the plaintext : ";
    getline(cin,text);
    cout<<"enter the shift value : ";
    cin>>shift;
    string encryptedtext = encrypt(text,shift);
    cout<<"encrypted ciphertext is : "<<encryptedtext<<endl;
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;
    cin.get();
    return 0;
} 