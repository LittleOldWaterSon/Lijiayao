#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    int in_word = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        char_count++;

        if (isalpha(c)) {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    fclose(file);

    if (strcmp(argv[1], "-c") == 0) {
        printf("×Ö·ûÊý£º%d\n", char_count);
    } else if (strcmp(argv[1], "-w") == 0) {
        printf("µ¥´ÊÊý£º%d\n", word_count);
    } else {
        printf("Invalid parameter\n");
        return 1;
    }

    return 0;
}

