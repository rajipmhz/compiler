#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i = 0, j = 0, x = 0, n, flag = 0;
    void *p, *add[15];
    char srch, b[15], d[15], c;

    // Input expression
    printf("Enter expression terminated by $: ");
    while ((c = getchar()) != '$') {
        b[i] = c;
        i++;
    }
    b[i] = '\0'; // Null-terminate the string
    n = i;

    printf("Given expression is: %s\n", b);

    // Symbol Table Header
    printf("Symbol table:\n");
    printf("Symbol\t Address\t\t Type\n");

    // Processing the expression
    for (j = 0; j < n; j++) {
        c = b[j];

        if (isalpha(c)) {
            if (j == n - 1 || b[j + 1] == '+' || b[j + 1] == '-' || b[j + 1] == '*' || b[j + 1] == '=') {
                p = malloc(sizeof(char));
                add[x] = p;
                d[x] = c;
                printf("%c\t %p\t identifier\n", c, p);
                x++;
            }
        }
    }

    // Symbol search
    printf("Enter the symbol to be searched: ");
    scanf(" %c", &srch);

    for (i = 0; i < x; i++) {
        if (srch == d[i]) {
            printf("Symbol found in table:\n");
            printf("Symbol\t Address\t\t Type\n");
            printf("%c\t %p\t identifier\n", srch, add[i]);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Symbol not found in the table.\n");
    }

    // Free allocated memory
    for (i = 0; i < x; i++) {
        free(add[i]);
    }
printf("\nLab NO:10\n");
printf("Name:Rajip Maharjan\n");
printf("Roll no:14");
    return 0;
}

