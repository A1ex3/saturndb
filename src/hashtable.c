#include "hashtable.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int hash(char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

void AddKeyValuePair(HashTable* table, char* key, char* value) {
    pthread_mutex_lock(&mutex);

    int index = hash(key);

    while (table->table[index].key[0] != '\0') {
        if (strcmp(table->table[index].key, key) == 0) {
            strcpy(table->table[index].value, value);
            pthread_mutex_unlock(&mutex);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    strcpy(table->table[index].key, key);
    strcpy(table->table[index].value, value);

    pthread_mutex_unlock(&mutex);
}

char* FindValueByKey(HashTable* table, char* key) {
    pthread_mutex_lock(&mutex);
    int index = hash(key);

    while (table->table[index].key[0] != '\0') {
        if (strcmp(table->table[index].key, key) == 0) {
            pthread_mutex_unlock(&mutex);
            return table->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void RemoveKeyValuePair(HashTable* table, char* key) {
    pthread_mutex_lock(&mutex);
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
            pthread_mutex_unlock(&mutex);
            return;
        }
        index = (index + 1) % TABLE_SIZE;

        if (index == startIndex) {
            pthread_mutex_unlock(&mutex);
            return;
        }
    }
}

void WriteHashTableToFile(HashTable* table, const char* filename) {
    pthread_mutex_lock(&mutex);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        pthread_mutex_unlock(&mutex);
        return;
    }

    fwrite(table, sizeof(HashTable), 1, file);
    fclose(file);
    pthread_mutex_unlock(&mutex);
}

void ReadHashTableFromFile(HashTable* table, const char* filename) {
    pthread_mutex_lock(&mutex);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        pthread_mutex_unlock(&mutex);
        return;
    }

    fread(table, sizeof(HashTable), 1, file);
    fclose(file);
    pthread_mutex_unlock(&mutex);
}