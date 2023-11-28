#include <stdio.h>

const char *words[20];
int wordcount = 0;

int readLine() {
    char word[20];
    printf("Enter word: ");
    fgets(word, 20, stdin);

    if (word[0] != '\n') {
        words[wordcount] = word;
        printf("%s", words[wordcount]);
        wordcount++;
        return 1;
    }
    return 0;
}

int main(void) {
    int bool = readLine();

    while (bool == 1) {
        bool = readLine();
    }

    printf("First: %s", words[0]);
    printf("Last: %s", words[wordcount - 1]);

    fclose(stdin);
    return 0;
}