// Write a c program to recognize string under a^*,a^*b^+ and abb
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string belongs to a*
bool isAStar(char str[], int state)
{
    for (int i = 0; i < strlen(str); i++)
    {
        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 0;
            else
                state = 1;
            break;
        case 1:
            state = 1;
            break;
        }
    }
    if (state == 0)
        return true;
    else
        return false;
}

// Function to check if string belongs to a*b+
bool isAStarBPlus(char str[], int state)
{
    for (int i = 0; i < strlen(str); i++)
    {
        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 0;
            else
                state = 1;
            break;
        case 1:
            if (str[i] == 'a')
                state = 2;
            else
                state = 1;
            break;
        case 2:
            state = 2;
            break;
        }
    }
    if (strcmp(str, "abb") == 0)
        return 0;
    if (state == 1)
        return true;
    else
        return false;
}

// Function to check if string is exactly "abb"
bool isABB(char str[], int state)
{
    for (int i = 0; i < strlen(str); i++)
    {
        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 1;
            else
                state = 4;
            break;
        case 1:
            if (str[i] == 'a')
                state = 4;
            else
                state = 2;
            break;
        case 2:
            if (str[i] == 'a')
                state = 4;
            else
                state = 3;
            break;
        case 3:
            state = 4;
            break;
        case 4:
            state = 4;
            break;
        }
    }
    if (state == 3)
        return true;
    else
        return false;
}

int main()
{
    char str[100], choice;
    do
    {
        printf("Enter a string (consisting of 'a' and 'b' only): ");
        scanf("%s", str);

        if (isAStar(str, 0))
        {
            printf("String belongs to language a*\n");
        }
        else if (isAStarBPlus(str, 0))
        {
            printf("String belongs to language a*b+\n");
        }
        else if (isABB(str, 0))
        {
            printf("String belongs to language abb\n");
        }
        else
        {
            printf("String does not belong to any of the given languages.\n");
        }
        printf("Do you want to enter another string? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");
    return 0;
}