#ifndef COMMON_H
#define COMMON_H

#ifdef __GNUC__
#define UNUSED __attribute__((__unused__))
#define FALLTHROUGH __attribute__ ((fallthrough))
#else
#define UNUSED
#define FALLTHROUGH
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"

struct stat getStat(const char* path);
bool isFile(const char* path);
bool isDir(const char* path);

int removeDir(const char *path);

#ifdef __cplusplus
}
#endif

#endif