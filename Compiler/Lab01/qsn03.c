//Write a C program to test whether given input is keyword or not 
#include <stdio.h>
#include <string.h>

int main()
{
    char op[10], choice;

    do
    {
        printf("Enter an operator: ");
        scanf("%s", op);

        if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 ||strcmp(op, "/") == 0 || strcmp(op, "%") == 0 || 
            strcmp(op, "==") == 0 ||strcmp(op, "=") == 0 || strcmp(op, "+=") == 0 ||
            strcmp(op, "!=") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<") == 0 || 
            strcmp(op, ">>") == 0 || strcmp(op, "<<") == 0 ||
            strcmp(op, ">=") == 0 || strcmp(op, "<=") == 0 ||
            strcmp(op, "&&") == 0 ||strcmp(op, "&") == 0 ||strcmp(op, "|") == 0 ||strcmp(op, "~") == 0)
        {
            printf("Valid operator\n");
        }
        else
        {
            printf("Invalid operator\n");
        }

        printf("Do you want to test another operator? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you!\n");
    return 0;
}