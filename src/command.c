#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "process.h"

void check_input(const char *input) {

    char cmnd[32] = {0};
    char rest[256] = {0};
    int isnumber = 0;
    int isletter = 0;

    int n = sscanf(input, "%31s %255[^\n]", cmnd, rest);
    if (n < 1) return;

    if (strcmp(cmnd, "help") == 0) {
        puts("Commands: run, kill, ps, help, exit");
        return;

    } else if (strcmp(cmnd, "run") == 0) {
        if (n < 2 || rest[0] == '\0') {
            printf("name invalid\n");
            return;
        }
        process_create(rest);
        return;

    } else if (strcmp(cmnd, "kill") == 0) {
        if (n < 2 || rest[0] == '\0') {
            printf("invalid argument\n");
            return;
        }

        for (int i = 0; rest[i] != '\n' && rest[i] != '\0'; i++) {
            char st_char = rest[i];
            if (isdigit((unsigned char)st_char)) {
                isnumber = 1;
            } else if (isalpha((unsigned char)st_char)) {
                isletter = 1;
            }
        }

        if (isnumber && isletter) {
            printf("invalid argument\n");
            return;
        } else {
            if (isletter) {
                process_kill_by_name(rest);
                return;
            } else if (isnumber) {
                int pid = atoi(rest);
                process_kill_by_pid(pid);
                return;
            } else {
                printf("invalid argument\n");
                return;
            }
        }

    } else if (strcmp(cmnd, "ps") == 0) {
        process_list();
        return;
    }

    printf("Unknown command: %s\n", cmnd);
}