#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

#include "parser.h"

int loadconfig(void)
{
    struct passwd *pw = getpwuid(getuid());

    char *homedir = pw->pw_dir;

    strcat(homedir,"/.kshrc");

    FILE *fptr;

    fptr = fopen(homedir, "r"); 

    if (fptr == NULL) {
        perror("fopen");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), fptr) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        parser(line);
    }

    fclose(fptr);
    return 0;
}
