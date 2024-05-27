#include <iostream>
#include "secure_crypt.cpp"

int main() {
    std::string message = "Hello, SecureCrypt!";
    int key = 3;

    std::string encrypted_message = encrypt(message, key);
    std::string decrypted_message = decrypt(encrypted_message, key);

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encrypted message: " << encrypted_message << std::endl;
    std::cout << "Decrypted message: " << decrypted_message << std::endl;

    return 0;
}