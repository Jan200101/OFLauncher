#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "common.h"
#include "config.h"
#include "svn.h"
#include "steam.h"

#include "command.h"

#define ARRAY_LEN(arr) sizeof(arr) / sizeof(arr[0])

int install(int, char**);
int uninstall(int, char**);
int update(int, char**);
int run(int, char**);
int config(int, char**);
int debug(int, char**);

int help(int, char**);


static const struct Command commands[] = {
    { .name = "install",    .func = install,    .description = "" },
    { .name = "uninstall",  .func = uninstall,  .description = "" },
    { .name = "update",     .func = update,     .description = "" },
    { .name = "run",        .func = run,        .description = "" },
    //{ .name = "config",     .func = config,       .description = "" },
    { .name = "debug",      .func = debug,      .description = "debug function" },
};


int main(int argc, char** argv)
{
    // TODO renable after testing is done
    /*
    if (svn_check())
    {
        fprintf(stderr, "svn_check failed\n");
        return -1;
    }
    */

    if (argc > 1)
    {
        for (unsigned long i = 0; i < ARRAY_LEN(commands); ++i)
            if (!strcmp(commands[i].name, argv[1])) return commands[i].func(argc-1, argv+1);
        fprintf(stderr, "'%s' is not a command\n", argv[1]);
        return 0;
    }
    return help(argc, argv);
}

int install(int argc UNUSED, char** argv UNUSED)
{
    char mod[PATH_MAX];
    getModPath(mod, sizeof(mod));

    if (isDir(mod))
    {
        fprintf(stderr, "Open Fortress is already installed\n");
        return 0;
    }

    char url[PATH_MAX];
    getRepoURL(url, sizeof(url));

    return svn_checkout(mod, url);
}

int uninstall(int argc UNUSED, char** argv UNUSED)
{
    char mod[PATH_MAX];
    getModPath(mod, sizeof(mod));

    if (!isDir(mod))
    {
        fprintf(stderr, "Open Fortress is not installed\n");
        return 0;
    }

    int retval = 0;

    int input = 0;
    fprintf(stderr, "Are you sure you want to delete this directory? [y/n]\n%s\n", mod);

    for(;;)
    {
        bool breakout = false;
        switch((input = fgetc(stdin)))
        {
            case 'y':
                fprintf(stderr, "Deleting\n");
                retval = svn_delete(mod);

                FALLTHROUGH;
            case 'n':
                breakout = true;
                break;

            default:
                fprintf(stderr, "Input y or n\n");
                FALLTHROUGH;
            case 10:
                break;
        }

        if (breakout) break;
    }

    return retval;
}

int update(int argc UNUSED, char** argv UNUSED)
{
    char mod[PATH_MAX];
    getModPath(mod, sizeof(mod));

    if (!isDir(mod))
    {
        fprintf(stderr, "Open Fortress is not installed\n");
        return 0;
    }

    return svn_update(mod);
}

int run(int argc UNUSED, char** argv UNUSED)
{
    char mod[PATH_MAX];
    getModPath(mod, sizeof(mod));

    if (!isDir(mod))
    {
        fprintf(stderr, "Open Fortress is not installed\n");
        return 0;
    }

    runMod(mod);

    return 0;
}

int config(int argc UNUSED, char** argv UNUSED)
{
    return 0;
}

int debug(int argc UNUSED, char** argv UNUSED)
{
    char mod[PATH_MAX];
    getModPath(mod, sizeof(mod));
    char steam[PATH_MAX];
    getSteamPath(steam, sizeof(steam));

    printf("svn_check %i\n"
           "steam path %s\n"
           "mod path %s\n",
           svn_check(),
           steam,
           mod);


    return 0;
}

int help(int argc UNUSED, char** argv UNUSED)
{
    fprintf(stderr, "%s usage\n", NAME);

    size_t longestCommand = 0;
    size_t size = ARRAY_LEN(commands);

    for (size_t i = 0; i < size; ++i)
    {
        size_t commandLength = strlen(commands[i].name);

        if (commandLength > longestCommand) longestCommand = commandLength;
    }

    for (size_t i = 0; i < size; ++i)
    {
        fprintf(stderr, "\t%-*s  %s\n", (int)longestCommand, commands[i].name, commands[i].description);
    }

    return 0;
}