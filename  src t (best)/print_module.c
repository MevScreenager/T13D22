#include <stdio.h>
#include <time.h>
#include "print_module.h"

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char (*print)(char), char* message) {
    char *prefix = Log_prefix;
    while (*prefix) {
        print(*prefix);
        prefix += 1;
    }

    print(' ');

    time_t timer = time(NULL);
    char buffer[26];
    struct tm *tm_info = localtime(&timer);
    strftime(buffer, 26, "%H:%M:%S", tm_info);

    char *time = buffer;
    while (*time) {
        print(*time);
        time += 1;
    }

    print(' ');

    while (*message) {
        print(*message);
        message += 1;
    }
}
