#ifndef COMMAND_H
#define COMMAND_H

struct Command {
    char* name;
    int (*func)(int, char**);
    char* description;
};

#endif