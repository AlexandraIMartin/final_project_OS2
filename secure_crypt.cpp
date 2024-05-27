#include <final_project.h>

std::string encrypt(const std::string &message, int key) {
    std::string encrypted_message = message;
    for (char &c : encrypted_message) {
        c +=key;
    }

    std::string decrypt(const std::string &encrypted_message, int key) {
        std::string message = encrypted_message;
        for (char &c : message) {
            c -= key;
        }
        return message;
    }
}