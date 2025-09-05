#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    char choice;

    char keywords[][10] = {"int", "float", "if", "else", "while", "return"};

    do {
        int i = 0;

        printf("\nEnter a string of code: ");
        fgets(str, sizeof(str), stdin);

        printf("\nTokens:\n");

        while (str[i] != '\0') {

            if (isspace(str[i])) {
                i++;
                continue;
            }


            if (isalpha(str[i])) {
                char buffer[20];
                int j = 0;
                while (isalnum(str[i])) {
                    buffer[j++] = str[i++];
                }
                buffer[j] = '\0';

                int isKey = 0;
                for (int k = 0; k < 6; k++) {
                    if (strcmp(buffer, keywords[k]) == 0) {
                        isKey = 1; break;
                    }
                }
                if (isKey)
                    printf(" Keyword : %s \n", buffer);
                else
                    printf(" Identifier : %s\n", buffer);
            }

            else if (isdigit(str[i])) {
                char buffer[20];
                int j = 0;
                while (isdigit(str[i])) {
                    buffer[j++] = str[i++];
                }
                buffer[j] = '\0';
                printf("%s Number : %s\n", buffer);
            }

            else if (strchr("+-*/=<>", str[i])) {
                printf(" Operator : %c \n", str[i]);
                i++;
            }

            else if (strchr(";,(){}", str[i])) {
                printf(" Special Character : %c \n", str[i]);
                i++;
            }

            else {
                printf(" Unknown : %c \n", str[i]);
                i++;
            }
        }


        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Program ended.\n");
    return 0;
}