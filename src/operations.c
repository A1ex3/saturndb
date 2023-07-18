#include "operations.h"

/*
FILE* OpenFile(struct Settings *settings, const char* mode)
{
    FILE* file = fopen(settings->PATH, mode);
    if (file == NULL) {
        return NULL;
    }
    return file;
}

void CloseFile(FILE* file) {
    if (file != NULL) {
        fclose(file);
    }
}
*/

DLL_EXPORT FILE_ERROR Put(char t_hash[], char key[], char value[])
{
    if (t_hash == NULL || key == NULL || value ==NULL)
    {
        return MISSING_PARAMETERS;
    }

    const char* h_t_hash = buildString(t_hash);

    HashTable table;
    memset(&table, 0, sizeof(HashTable));

    ReadHashTableFromFile(&table, h_t_hash);

    AddKeyValuePair(&table, key, value);

    WriteHashTableToFile(&table, h_t_hash);
    
    free((void*)h_t_hash);

    return 0;
}

DLL_EXPORT const char* Get(char t_hash[],char key[])
{
    if (t_hash == NULL || key == NULL)
    {
        return NULL;
    }

    const char* h_t_hash = buildString(t_hash);

    HashTable table;
    ReadHashTableFromFile(&table, h_t_hash);
    
    char* value = FindValueByKey(&table, key);
    if (value != NULL) {
        free((void*)h_t_hash); 
        return value;
    } else {
        free((void*)h_t_hash); 
        return NULL;
    }
}

DLL_EXPORT FILE_ERROR Del(char t_hash[],char key[])
{
    if (t_hash == NULL || key==NULL)
    {
        return MISSING_PARAMETERS;
    }
    const char* h_t_hash = buildString(t_hash);

    HashTable table;
    memset(&table, 0, sizeof(HashTable));

    ReadHashTableFromFile(&table, h_t_hash);

    RemoveKeyValuePair(&table, key);

    WriteHashTableToFile(&table, h_t_hash);

    free((void*)h_t_hash); 

    return 0;
}

DLL_EXPORT FILE_ERROR TableDel(char t_hash[])
{
    if (t_hash == NULL)
    {
        return MISSING_PARAMETERS;
    }
    const char* h_t_hash = buildString(t_hash);
    if (remove(h_t_hash) != 0)
    {
        free((void*)h_t_hash); 
        return DELETION_ERROR;
    }
    free((void*)h_t_hash); 
    return 0;
}