#ifndef CONFIG_H
#define CONFIG_H

#define DEFAULT_REPO "https://svn.openfortress.fun/svn/open_fortress/"
#define DEFAULT_NAME "open_fortress"

size_t getRepoURL(char*, size_t);
size_t getRepoName(char*, size_t);

#endif