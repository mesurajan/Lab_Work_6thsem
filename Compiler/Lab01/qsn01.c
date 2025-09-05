//Write a C program to identify whether given line is comment or not 
#include <stdio.h>
#include <string.h>

int main() {
    char line[200], choice[10];

    do {
        printf("Enter a line: ");
        fgets(line, sizeof(line), stdin);

        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '/' && line[1] == '/')
            printf("Single-line comment\n");
        else if (line[0] == '/' && line[1] == '*' &&
                 line[strlen(line)-2] == '*' && line[strlen(line)-1] == '/')
            printf("Multi-line comment (same line)\n");
        else
            printf("Not a comment\n");

        printf("Do you want to exit? (yes/no): ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

    } while (choice[0] == 'n' || choice[0] == 'N');

    printf("Thank you!\n");
    return 0;
}