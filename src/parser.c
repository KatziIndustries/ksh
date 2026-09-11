#include <stdlib.h>
#include <string.h>

#include "ksh.h"
#include "exec.h"

int parser(char *input)
{
    char *args[MAX_ARGS];
    int argc = 0;

    char *token = strtok(input, " \t");

    while (token != NULL && argc < MAX_ARGS - 1) {
        args[argc++] = token;
        token = strtok(NULL, " \t");
    }

    args[argc] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    exec(argc,args);

    return 1;
}