#include <final_project.h>

std::string encrypt(const std::string &message, int key) {
    if (key <= 0) {
        throw std::invalid_argument("Key must be positive");
    }
    std::string encrypted_message = message;
    for (char &c : encrypted_message) {
        c +=key;
    }
    return encrypted_message;
}

std::string decrypt(const std::string &encrypted_message, int key) {
    if (key <= 0) {
        throw std::invalid_argument("Key must be positive");
    }
    std::string message = encrypted_message;
    for (char &c : message) {
        c -= key;
    }
    return message;
}