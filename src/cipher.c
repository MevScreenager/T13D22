#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "logger.h"

// #include "logger.c"

void readFile(FILE *fp, char* name, int* yes);
void writeFile(FILE *fp, char* name);
void encript(char d_name[260], char namedir[2600], int t);
int readDir(DIR *dir, char* namedir);

int main() {
    FILE *fp = NULL, *flog;
    flog = log_init("log.txt");
    logcat(flog, "Create file log.txt", debug);
    logcat(flog, "Main start", trace);
    #ifdef CIPHER
    DIR *dir = NULL;
    int n, work = 1, name_size = 260, yes = 0;
    char name[name_size], c;
    char namedir[2600];
    logcat(flog, "Create variables", debug);
    while (work) {
        n = 0;
        scanf("%d", &n);
        logcat(flog, "input number n", info);
        // getchar();
        if (n == 1) {
            logcat(flog, "Variables n = 1", debug);
            scanf("%s", name);
            logcat(flog, "input number name", info);
            logcat(flog, "Start funclion readFile()", debug);
            readFile(fp, name, &yes);  // пуст или не существвует
            logcat(flog, "Buffer clearing", debug);
            // int l = strlen(name);
            // c = name[l -];
            while (c != EOF && c != '\n') {
                c = getc(stdin);
            }
        }
        if (n == 2) {
            logcat(flog, "Variables n = 2", debug);
            if (yes) {
                logcat(flog, "Variables yes - true", debug);
                logcat(flog, "Start funclion writeFile()", debug);
                writeFile(fp, name);
            } else {
                logcat(flog, "Variables yes - false", debug);
                while (c != EOF && c != '\n') {
                    c = getc(stdin);
                }
                printf("n/a\n");
            }
        }
        if (n == 3) {
            logcat(flog, "Variables n = 3", debug);
            logcat(flog, "Start function readDior() and encript()", debug);
            readDir(dir, namedir);
        }
        if (n == -1) {
            logcat(flog, "Variables n = -1", debug);
            work = 0;
        } else {
            logcat(flog, "Buffer clearing", debug);
            c = getc(stdin);
            while (c != EOF && c != '\n') {
                c = getc(stdin);
            }
            printf("n/a\n");
        }
    }
    #endif  // CIPHER
    logcat(flog, "End main() exit", trace);
    return 0;
}

void readFile(FILE *fp, char* name, int *yes) {
    char c;
    if ((fp = fopen(name, "r")) == NULL) {
        printf("n/a");
        getchar();
    } else {
        *yes = 1;
        for (; (c = fgetc(fp)) != EOF;) {
            printf("%c", c);
        }
        fclose(fp);
        getchar();
    }
    printf("\n");
}

void writeFile(FILE *fp, char* name) {
    if ((fp = fopen(name, "a")) == NULL) {
        printf("n/a");
        getchar();
    } else {
        char string[10000], c;
        scanf("%s", string);
        fputs(string, fp);
        fclose(fp);
        fp = fopen(name, "r");
        for (; (c = fgetc(fp)) != EOF;) {
            printf("%c", c);
        }
        fclose(fp);
        getchar();
    }
    printf("\n");
}

int readDir(DIR *dir, char* namedir) {
    struct dirent *entry;
    char namedircp[2600];
    int t;
    scanf("%s", namedir);
    // getchar();
    if ((dir = opendir(namedir)) == NULL) {
        printf("n/a\n");
        strcpy(namedir, namedircp);
        return 0;
    } else {
        scanf("%d", &t);
        strcpy(namedircp, namedir);
        while ((entry = readdir(dir)) != NULL) {
            // printf("%s", entry->d_name);
            if (*(entry->d_name) != '.') {
                encript(entry->d_name, namedir, t);
                strcpy(namedir, namedircp);
            }
        }
        closedir(dir);
        getchar();
        getchar();
    }
    printf("\n");
    return 1;
}

void encript(char d_name[260], char namedir[2600], int t) {
    strcat(namedir, d_name);
    // printf("%s\n", namedir);
    FILE *fp, *fpp;
    for (int i = 0; d_name[i]; i++) {
        if (d_name[i] == '.' && d_name[i + 1] == 'h') {
            if ((fp = fopen(namedir, "w")) == NULL) {
                // printf("n/a\n");
                // getchar();
                break;
            } else {
                fputs("", fp);
                fclose(fp);
                // getchar();
            }
        }

        if (d_name[i] == '.' && d_name[i + 1] == 'c') {
            if ((fp = fopen(namedir, "r")) == NULL) {
                // printf("n/a\n");
                // getchar();
                break;
            } else {
                char c;
                fpp = fopen("HELP.txt", "w");
                for (; (c = fgetc(fp)) != EOF;) {
                    fputc(c, fpp);
                }
                fclose(fp);
                fclose(fpp);
                fpp = fopen("HELP.txt", "r");
                fp = fopen(namedir, "w");
                for (; (c = fgetc(fpp)) != EOF;) {
                    fputc(c + t, fp);
                }
                fclose(fp);
                fclose(fpp);
                getchar();
                break;
            }
        }
    }
}
