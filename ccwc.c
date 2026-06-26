#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void count_all(FILE *fp, int *lines, int *words, int *bytes) {
    int ch, inword = 0;
    *lines = *words = *bytes = 0;

    while ((ch = fgetc(fp)) != EOF) {
        (*bytes)++;
        if (ch == '\n') (*lines)++;
        if (!isspace(ch)) {
            if (!inword) { (*words)++; inword = 1; }
        } else {
            inword = 0;
        }
    }
}

int count_lines(FILE *fp) {
    int ch, count = 0;
    while ((ch = fgetc(fp)) != EOF)
        if (ch == '\n') count++;
    return count;
}

int count_words(FILE *fp) {
    int ch, count = 0, inword = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (!isspace(ch)) { if (!inword) { count++; inword = 1; } }
        else inword = 0;
    }
    return count;
}

int count_bytes(FILE *fp) {
    int ch, count = 0;
    while ((ch = fgetc(fp)) != EOF) count++;
    return count;
}

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    char *filename = NULL;
    char *flag = NULL;

    // Determine flag and filename
    if (argc == 1) {
        fp = stdin;
    } else if (argc == 2) {
        if (argv[1][0] == '-') {
            flag = argv[1];
            fp = stdin;
        } else {
            filename = argv[1];
        }
    } else if (argc == 3) {
        flag = argv[1];
        filename = argv[2];
    } else {
        fprintf(stderr, "Usage: ccwc [-c|-l|-w|-m] [file]\n");
        return 1;
    }

    if (filename) {
        fp = fopen(filename, "r");
        if (!fp) {
            fprintf(stderr, "ccwc: %s: No such file or directory\n", filename);
            return 1;
        }
    }

    if (!flag) {
        // No flag: print all three counts
        int l, w, b;
        count_all(fp, &l, &w, &b);
        if (filename)
            printf("%d %d %d %s\n", l, w, b, filename);
        else
            printf("%d %d %d\n", l, w, b);
    } else {
        int count = 0;
        if      (strcmp(flag, "-l") == 0) count = count_lines(fp);
        else if (strcmp(flag, "-w") == 0) count = count_words(fp);
        else if (strcmp(flag, "-c") == 0) count = count_bytes(fp);
        else if (strcmp(flag, "-m") == 0) count = count_bytes(fp); // placeholder
        else {
            fprintf(stderr, "ccwc: unknown flag %s\n", flag);
            if (filename) fclose(fp);
            return 1;
        }

        if (filename)
            printf("%d %s\n", count, filename);
        else
            printf("%d\n", count);
    }

    if (filename) fclose(fp);
    return 0;
}
