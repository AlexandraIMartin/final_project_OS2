#include <iostream>
#include <random>
#include <thread>
#include "secure_crypt.cpp"

void encrypt_message(const std::string &message, int key, std::string &encrypted_message) {
    try {
        encrypted_message = encrypt(message, key);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Encryption error: " << e.what() << std::endl;
    }
}

void decrypt_message(const std::string &encrypted_message, int key, std::string &decrypted_message) {
    try {
        decrypted_message = decrypt(encrypted_message, key);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Decryption error: " << e.what() << std::endl;
    }
}

int main() {
    std::string message = "Hello, SecureCrypt!";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 255);
    int key = dis(gen);

    std::string encrypted_message, decrypted_message;

    std::thread encrypt_thread(encrypt_message, std::cref(message), key, std::ref(encrypted_message));
    encrypt_thread.join();

    std::thread decrypt_thread(decrypt_message, std::cref(encrypted_message), key, std::ref(decrypted_message));
    decrypt_thread.join();

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encryption key: " << key << std::endl;
    std::cout << "Encrypted message: " << encrypted_message << std::endl;
    std::cout << "Decrypted message: " << decrypted_message << std::endl;

    return 0;
}