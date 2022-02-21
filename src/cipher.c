#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void readFile(FILE *fp, char* name);
void writeFile(FILE *fp, char* name);
void encript(char d_name[260], int t);
void readDir(DIR *dir, char* namedir);

int main() {
    // #ifdef CIPHER
    DIR *dir;
    FILE *fp = NULL;
    int n, work = 1, name_size = 260, yes = 0;
    char name[name_size];
    char namedir[name_size];
    while (work) {
        scanf("%d", &n);
        getchar();
        switch (n) {
            case 1:
                readFile(fp, name);  // пуст или не существвует
                yes = 1;
                printf("\n");
                break;
            case 2:
                if (!yes) {
                    printf("n/a\n");
                    break;
                }
                writeFile(fp, name);
                break;
            case 3:
                readDir(dir, namedir);
                printf("\n");
                break;
            case -1:
                work = 0;
                break;
            default:
                printf("n/a\n");
                //getchar();
                exit(1);
        }
    }
    // #endif  // CIPHER
    return 0;
}

void readFile(FILE *fp, char* name) {
    char c;
    scanf("%s", name);
    //getchar();
    if ((fp = fopen(name, "r")) == NULL) {
        printf("n/a\n");
        getchar();
    } else {
        for (; (c = fgetc(fp)) != EOF;) {
            printf("%c", c);
        }
        fclose(fp);
        getchar();
    }
}

void writeFile(FILE *fp, char* name) {
    if ((fp = fopen(name, "a")) == NULL) {
        printf("n/a\n");
        getchar();
    } else {
        char string[10000], c;
        scanf("%s", string);
        for (int i = 0; (c = getchar()) != '\n'; i++)
            string[i] = c;
        fputs(string, fp);
        fclose(fp);
        getchar();
    }
}

void readDir(DIR *dir, char* namedir) {
    struct dirent *entry;
    char name[260];
    int t;
    scanf("%s", namedir);
    getchar();
    if (!scanf("%d", &t)) {
        printf("n/a\n");
        getchar();
        return;
    }
    getchar();
    if ((dir = opendir(namedir)) == NULL) {
        printf("n/a\n");
        getchar();
    } else {
        while ((entry = readdir(dir)) != NULL) {
            encript(entry->d_name, t);
        }
    }

}

void encript(char d_name[260], int t) {
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
            int size = 0;
            if ((fp = fopen(d_name, "r")) == NULL) {
                printf("n/a\n");
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
                fp = fopen(d_name, "w");
                for (; (c = fgetc(fpp)) != EOF;) {
                    fputc(c + t, fp);
                }
                fclose(fp);
                fclose(fpp);
                getchar();
            }
        }
    }
}
