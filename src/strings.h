#pragma once
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "murmur3.h"

#define SIZE_STRING 256
/*
SHA256 32
SHA512 64
*/

//Returns a hash as a string
const char* buildString(const char* str);

//Returns bytes from a string
char* ctob(const char* _s);