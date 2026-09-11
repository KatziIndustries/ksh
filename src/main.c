#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ksh.h"
#include "parser.h"

int main(void)
{
    char line[MAX_LINE];
    int running = 1;

    while (running) {
        printf("$ ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0') {
            continue;
        }

        running = parser(line);
    }

    return 0;
}
