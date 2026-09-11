#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

int loadconfig(void)
{
    struct passwd *pw = getpwuid(getuid());

    char *homedir = pw->pw_dir;

    strcat(homedir,"/.kshrc");

    FILE *fptr;

    fptr = fopen(homedir, "r"); 

    printf("homedir is %s",homedir);
}
