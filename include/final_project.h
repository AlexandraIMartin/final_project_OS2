#ifndef SECURE_CRYPT_H
#define SECURE_CRYPT_H

#include <string>

std::string encrypt(const std::string &message, int key);
std::string decrypt(const std::string &encrypted_message, int key);

#endif //   SECURE_CRYPT_H