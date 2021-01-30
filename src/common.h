#ifndef COMMON_H
#define COMMON_H

#ifdef __GNUC__
#define UNUSED __attribute__((__unused__))
#define FALLTHROUGH __attribute__ ((fallthrough))
#else
#define UNUSED
#define FALLTHROUGH
#endif

#ifdef _WIN32
#include <wow64apiset.h>
#include <processthreadsapi.h>

#define PGRM64 "C:\\Program Files (x86)"
#define PGRM32 "C:\\Program Files"

#define IF_WIN64 \
    BOOL f64; \
    if(IsWow64Process(GetCurrentProcess(), &f64) && f64)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"


int runMod(char*);

struct stat getStat(const char* path);
bool isFile(const char* path);
bool isDir(const char* path);

int removeDir(const char *path);

#ifdef __cplusplus
}
#endif

#endif