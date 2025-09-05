#include <stdio.h>
#include <string.h>

int isKeyword(const char *word) {
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"};
    int totalKeywords = 32;

    for (int i = 0; i < totalKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1; 
    }
    return 0; 
}

int main() {
    char word[100];
    char choice;

    do {
        printf("Enter a word: ");
        scanf("%s", word);

        if (isKeyword(word))
            printf("'%s' is a C keyword.\n", word);
        else
            printf("'%s' is NOT a C keyword.\n", word);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program ended.\n");
    return 0;
}