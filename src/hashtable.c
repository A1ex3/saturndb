#include "hashtable.h"

int hash(char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

void AddKeyValuePair(HashTable* table, char* key, char* value) {

    int index = hash(key);

    while (table->table[index].key[0] != '\0') {
        if (strcmp(table->table[index].key, key) == 0) {
            strcpy(table->table[index].value, value);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    strcpy(table->table[index].key, key);
    strcpy(table->table[index].value, value);

}

char* FindValueByKey(HashTable* table, char* key) {
    int index = hash(key);

    while (table->table[index].key[0] != '\0') {
        if (strcmp(table->table[index].key, key) == 0) {
            return table->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return NULL;
}

void RemoveKeyValuePair(HashTable* table, char* key) {
    int index = hash(key);
    int startIndex = index;

    while (table->table[index].key[0] != '\0') {
        if (strcmp(table->table[index].key, key) == 0) {
            table->table[index].key[0] = '\0';
            table->table[index].value[0] = '\0';

            int nextIndex = (index + 1) % TABLE_SIZE;
            while (table->table[nextIndex].key[0] != '\0') {
                int hashIndex = hash(table->table[nextIndex].key);
                if ((nextIndex > index && (hashIndex <= index || hashIndex > nextIndex)) ||
                    (nextIndex < index && (hashIndex <= index && hashIndex > nextIndex))) {
                    strcpy(table->table[index].key, table->table[nextIndex].key);
                    strcpy(table->table[index].value, table->table[nextIndex].value);
                    table->table[nextIndex].key[0] = '\0';
                    table->table[nextIndex].value[0] = '\0';
                    index = nextIndex;
                }
                nextIndex = (nextIndex + 1) % TABLE_SIZE;
            }
            return;
        }
        index = (index + 1) % TABLE_SIZE;

        if (index == startIndex) {
            return;
        }
    }
}

void WriteHashTableToFile(HashTable* table, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    fwrite(table, sizeof(HashTable), 1, file);
    fclose(file);
}

void ReadHashTableFromFile(HashTable* table, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return;
    }

    fread(table, sizeof(HashTable), 1, file);
    fclose(file);
}