#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int exec(int argc,char *args[])
{
    (void)argc;
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        execvp(args[0], args);

        perror(args[0]);
        exit(EXIT_FAILURE);
    }

    waitpid(pid, NULL, 0);

    return 0;
}
