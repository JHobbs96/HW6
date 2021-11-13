// This program demonstrates the CaesarCipher class' 
// Big 4 operations and overloaded operators 
#include "CaesarCipher.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    CaesarCipher cc;
    string encryptedWord = cc.encrypt("Hello, world!");
    cout << "Encrypted: " << encryptedWord << endl;
    string decryptedWord = cc.decrypt(encryptedWord);
    cout << "Decrypted: " << decryptedWord << endl;
    return 0;
}
