#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "ksh.h"
#include "parser.h"
#include "prompt.h"

int main(void)
{
    char line[MAX_LINE];
    int running = 1;

    loadconfig();

    while (running) {
        char *PS1 = getenv("PS1");
        print_prompt(PS1);
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
