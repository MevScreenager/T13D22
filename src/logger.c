#ifndef LOGGER_C
#define LOGGER_C

#include <time.h>
#include <stdio.h>
#include "logger.h"

FILE* log_init(char *name) {
    FILE* fp;
    fp = fopen(name, "a");
    return fp;
}

int logcat(FILE* fp, char * message, enum log_level level) {
    long int l_time;
    l_time = time(NULL);
    struct tm *ttime;
    ttime = localtime(&l_time);
    // char timechar[25];
    // timechar = ctime(&ttime);
    switch (level) {
        case 0:
            // fputs("DEBUG", fp);
            // fputs(ctime(&ttime), fp);
            // fputs(message, fp);
            fprintf(fp, "DEBUG\t%s\t%s\n", asctime(ttime), message);
            break;
        case 1:
            fprintf(fp, "TRASE\t%s\t%s\n", asctime(ttime), message);
            break;
        case 2:
            fprintf(fp, "INFO\t%s\t%s\n", asctime(ttime), message);
            break;
        case 3:
            fprintf(fp, "WARNING\t%s\t%s\n", asctime(ttime), message);
            break;
        case 4:
            fprintf(fp, "ERROR\t%s\t%s\n", asctime(ttime), message);
            break;
    }
    return 1;
}

int log_close(FILE* fp) {
    fclose(fp);
    return 1;
}

#endif  // LOGGER_C
