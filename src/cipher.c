#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void readFile(FILE *fp, char* name, int* yes);
void writeFile(FILE *fp, char* name);
void encript(char d_name[260], char namedir[2600], int t);
int readDir(DIR *dir, char* namedir);

int main() {
    // #ifdef CIPHER
    DIR *dir = NULL;
    FILE *fp = NULL;
    int n, work = 1, name_size = 260, yes = 0;
    char name[name_size], c;
    char namedir[2600];
    while (work) {
        n = 0;
        scanf("%d", &n);
        // getchar();
        if (n == 1) {
            scanf("%s", name);
            readFile(fp, name, &yes);  // пуст или не существвует
            // yes = 1;
            }
        else if (n == 2) {
            if (yes) {
                writeFile(fp, name);
            } else {
                printf("n/a\n");
            }
        }
        else if (n == 3) {
            readDir(dir, namedir);
        }
        else if (n == -1) {
            work = 0;
        }
        else {
            c = getc(stdin);
            while (c != EOF && c != '\n' && c != ' ') {
                c = getc(stdin);
            }
            printf("n/a\n");
        }
    }
    // #endif  // CIPHER
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
    }
    printf("\n");
    return 1;
}

void encript(char d_name[260], char namedir[2600], int t) {
    strcat(namedir, d_name);
    // printf("%s\n", namedir);
    FILE *fp, *fpp;
    for (int i = 0; d_name[i]; i++) {
        if (d_name[i] == '.' && d_name[i + 1] == 't') {
            if ((fp = fopen(d_name, "w")) == NULL) {
                printf("n/a\n");
                getchar();
            } else {
                fputs("", fp);
                fclose(fp);
                getchar();
            }
        }

        // if (d_name[i] == '.' && d_name[i + 1] == 't') {
        //     // printf("%s\n", d_name);
            
        //     if ((fp = fopen(namedir, "r")) == NULL) {
        //         // printf("n/a\n");
        //         getchar();
        //     } else {
        //         char c;
        //         fpp = fopen("HELP.txt", "w");
        //         for (; (c = fgetc(fp)) != EOF;) {
        //             fputc(c, fpp);
        //         }
        //         fclose(fp);
        //         fclose(fpp);
        //         fpp = fopen("HELP.txt", "r");
        //         fp = fopen(namedir, "w");
        //         for (; (c = fgetc(fpp)) != EOF;) {
        //             fputc(c + t, fp);
        //         }
        //         fclose(fp);
        //         fclose(fpp);
        //         // getchar();
        //     }
        // }
    }
}
