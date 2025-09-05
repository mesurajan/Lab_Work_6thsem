#include <stdio.h>

int main()
{
    char str[100];
    int choice;

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
                    state = 1;
                else
                    state = 0;
                break;

            case 1:
                if (str[i] == '0')
                    state = 2;
                else
                    state = 0;
                break;

            case 2:
                if (str[i] == '0')
                    state = 2;
                else
                    state = 0;
                break;
            }
            i++;
        }

        if (state == 2)
            printf("The string is accepted.\n");
        else
            printf("The string is rejected.\n");

        printf("Do you want to enter another string? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("Program terminated.\n");
    return 0;
}