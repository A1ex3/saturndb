#include "strings.h"

const char* buildString(const char* str) {
    size_t data_len = strlen(str);

    const size_t hash_len = 16;
    uint8_t hash[hash_len];
    MurmurHash3_x64_128(str, data_len, 0, hash);

    char* string = (char*)malloc((2 * hash_len + 1) * sizeof(char));
    if (string == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < hash_len; i++) {
        sprintf(string + (2 * i), "%02x", hash[i]);
    }
    string[2 * hash_len] = '\0';

    return string;
}

char* ctob(const char* _s)
{
    const char* string = (const char*)malloc(strlen(_s) * 2 + 1);
    const unsigned char* bytes = (const unsigned char*)_s;

    for (size_t i = 0; i < strlen(_s); i++) {
        sprintf((char*)(string + i * 2), "%02X", bytes[i]);
    }

    return (char*)string;
}