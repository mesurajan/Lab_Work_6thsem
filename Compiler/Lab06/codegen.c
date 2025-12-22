#include <stdio.h>

int main() {
    char x, y, z, op;

    printf("Enter intermediate code (x=y op z): ");
    scanf(" %c=%c%c%c", &x, &y, &op, &z);

    printf("\nTarget Code:\n");
    printf("MOV %c, R1\n", y);

    switch(op) {
        case '+': printf("ADD %c, R1\n", z); break;
        case '-': printf("SUB %c, R1\n", z); break;
        case '*': printf("MUL %c, R1\n", z); break;
        case '/': printf("DIV %c, R1\n", z); break;
    }

    printf("MOV R1, %c\n", x);
    return 0;
}
