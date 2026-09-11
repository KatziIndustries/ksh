#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_LINE 1024

int main(void)
{
    char line[MAX_LINE];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0') {
            continue;
        }

        char *args[MAX_ARGS];
        int argc = 0;

        char *token = strtok(line, " \t");

        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc++] = token;
            token = strtok(NULL, " \t");
        }

        args[argc] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            execvp(args[0], args);

            perror(args[0]);
            exit(EXIT_FAILURE);
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}
