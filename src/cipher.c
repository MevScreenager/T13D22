#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void readFile(FILE *fp, char* name);
void writeFile(FILE *fp, char* name);
void encript(char d_name[260], char namedir[2600], int t);
int readDir(DIR *dir, char* namedir);

int main() {
    // #ifdef CIPHER
    DIR *dir;
    FILE *fp = NULL;
    int n, work = 1, name_size = 260, yes = 0;
    char name[name_size], c;
    char namedir[2600];
    while (work) {
        scanf("%d", &n);
        // getchar();
        switch (n) {
            case 1:
                scanf("%s", name);
                readFile(fp, name);  // пуст или не существвует
                yes = 1;
                // printf("===== end 1 =====\n");
                break;
            case 2:
                if (!yes) {
                    printf("n/a\n");
                    break;
                }
                readFile(fp, name);
                writeFile(fp, name);
                // printf("===== end 2 =====\n");
                break;
            case 3:
                readDir(dir, namedir);
                // printf("\n");
                // printf("===== end 3 =====\n");
                break;
            case -1:
                work = 0;
                break;
            default:
                c = getc(stdin);
                while (c != EOF && c != '\n' && c != ' ') {
                    c = getc(stdin);
                }
                printf("n/a\n");
                // printf("===== end d =====\n");
        }
    }
    // #endif  // CIPHER
    return 0;
}

void readFile(FILE *fp, char* name) {
    char c;
    if ((fp = fopen(name, "r")) == NULL) {
        printf("n/a");
        getchar();
    } else {
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
        for (int i = 0; (c = getchar()) != '\n'; i++)
            string[i] = c;
        fputs(string, fp);
        fclose(fp);
    }
    readFile(fp, name);
    printf("\n");
}

int readDir(DIR *dir, char* namedir) {
    struct dirent *entry;
    char name[260], namedircp[2600];
    int t;
    scanf("%s", namedir);
    // getchar();
    if ((dir = opendir(namedir)) == NULL) {
        printf("n/adiiiiiie\n");
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
        // if (d_name[i] == '.' && d_name[i + 1] == 't') {
        //     if ((fp = fopen(d_name, "w")) == NULL) {
        //         printf("n/a\n");
        //         getchar();
        //     } else {
        //         fputs("", fp);
        //         fclose(fp);
        //         getchar();
        //     }
        // }

        if (d_name[i] == '.' && d_name[i + 1] == 't') {
            // printf("%s\n", d_name);
            int size = 0;
            if ((fp = fopen(namedir, "r")) == NULL) {
                // printf("n/a\n");
                getchar();
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
                // getchar();
            }
        }
    }
}
