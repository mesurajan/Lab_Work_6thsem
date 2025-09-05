//Write a c program to implement DFA for accepting even number of 0's and 1's
#include <stdio.h>

int main()
{
    char str[100];
    char choice;

    do
    {
        int i = 0;
        int state = 0;

        printf("Enter a string over {0,1}: ");
        scanf("%s", str);

        while (str[i] != '\0')
        {
            switch (state)
            {
            case 0:
                if (str[i] == '0')
                    state = 2;
                else
                    state = 1;
                break;

            case 1:
                if (str[i] == '0')
                    state = 3;
                else
                    state = 0;
                break;

            case 2:
                if (str[i] == '0')
                    state = 0;
                else
                    state = 3;

                break;

            case 3:
                if (str[i] == '0')
                    state = 1;
                else
                    state = 2;

                break;
            }
            if (i == -1)
                break;
            i++;
        }

        if (i != -1)
        {
            if (state == 0)
                printf("The string is accepted.\n");
            else
                printf("The string is rejected.\n");
        }

        printf("Do you want to enter another string? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");
    return 0;
}