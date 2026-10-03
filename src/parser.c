#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "ksh.h"
#include "exec.h"

int parser(char *input)
{
    char *args[MAX_ARGS];
    int argc = 0;

    // splitting input 
    char *token = strtok(input, " \t");

    while (token != NULL && argc < MAX_ARGS - 1) {
        args[argc++] = token;
        token = strtok(NULL, " \t");
    }

    args[argc] = NULL;

    // shell builtins
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    if (strcmp(args[0], "cd") == 0) {
        // change directory
        chdir(args[1]);
        return 1;
    }

    exec(argc,args);

    return 1;
}