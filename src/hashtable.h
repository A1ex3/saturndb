#pragma once

#include "strings.h"

#define TABLE_SIZE 999

typedef struct {
    char key[999];
    char value[999];
} KeyValuePair;

typedef struct {
    KeyValuePair table[TABLE_SIZE];
} HashTable;

//Function for adding a key-value to a hash table
void AddKeyValuePair(HashTable* table, char* key, char* value);

//The function of searching for a key value in a hash table
char* FindValueByKey(HashTable* table, char* key);

//Key-value deletion function from hash table
void RemoveKeyValuePair(HashTable* table, char* key);

//The function of writing a hash table to a file
void WriteHashTableToFile(HashTable* table, const char* filename);

//The function of reading a hash table from a file
void ReadHashTableFromFile(HashTable* table, const char* filename);