#pragma once

#include "hashtable.h"

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)//compile for windows
#else
    #define DLL_EXPORT//compile for linux
#endif

typedef enum
{
    EXCEPTION = -1,
    FILE_NOT_EXIST = -2,
    KEY_NOT_FOUND = -3,
    MISSING_PARAMETERS = -4,
    DELETION_ERROR = -5,
}FILE_ERROR;

/*
struct Settings
{
    uint64_t CacheSize;
    const char* PATH;
    //FILE* Ffile;

    //FILE_ERROR(*Put)(struct Settings*,char[],char[]);
};
*/
//FILE* OpenFile(struct Settings *settings, const char* mode);
//void CloseFile(FILE* file);

/*
t_hash[] is a file that has a hashed name;
key[] is key in table;
value[] is value in table
*/

//Inserts data into a table
DLL_EXPORT FILE_ERROR Put(char t_hash[],char key[],char value[]);

//Gets the value from the table
DLL_EXPORT const char* Get(char t_hash[],char key[]);

//Removes a value from the table
DLL_EXPORT FILE_ERROR Del(char t_hash[],char key[]);

//Deletes the entire table
DLL_EXPORT FILE_ERROR TableDel(char t_hash[]);