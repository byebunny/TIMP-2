#include "modAlphaCipher.h"

void check(const string& Text, const string& key)
{
    try {
        modAlphaCipher cipher(key);
        string cipherText = cipher.encrypt(Text);
        string decryptedText = cipher.decrypt(cipherText);
        // ... Вывод текста и ключа
        if(Text == decryptedText) {
            cout << "Ok\n";
        } else {
            cout << "Err\n";
        }
    } catch(const cipher_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

int main()
{
    check("НОВЫЙГОД", "СКОРО");
    check("НОВЫЙГОД", "скоро");
    check("НОВЫЙГОД", "!СКОРО!");
    check("НОВЫЙГОД", "4657890");
    check("456738290", "NO");
    check("НОВЫЙГОД", "");
    check("45678390", "СКОРО");
    check("", "СКОРО");
}
