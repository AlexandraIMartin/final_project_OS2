#include <iostream>
#include <random>
#include "secure_crypt.cpp"

int main() {
    std::string message = "Hello, SecureCrypt!";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 255);
    int key = dis(gen);

    std::string encrypted_message = encrypt(message, key);
    std::string decrypted_message = decrypt(encrypted_message, key);

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encryption key: " << key << std::endl;
    std::cout << "Encrypted message: " << encrypted_message << std::endl;
    std::cout << "Decrypted message: " << decrypted_message << std::endl;

    return 0;
}