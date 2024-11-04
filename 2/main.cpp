#include <iostream>
#include <string>
#include "modAlphaCipher.h"

void check(string Text, int key) {
    try {
        string cipherText;
        string decryptedText;
        modCipher cipher(key, Text);
        cipherText = cipher.encryption(Text);
        decryptedText = cipher.transcript(cipherText, Text);
        cout << "Ключ = " << key << endl;
        cout << Text << endl;
        cout << cipherText << endl;
        cout << decryptedText << endl;
    } catch(const cipher_error & e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

int main() {
    try {
        check("NEWYEAR", 3);
        check("NEWYEAR", 2025); 
        check("2025", 3);
        check("", 2025);
    } catch (const cipher_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
