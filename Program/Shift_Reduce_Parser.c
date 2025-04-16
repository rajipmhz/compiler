#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip_sym[20], stack[20];
int ip_ptr = 0, st_ptr = 0, len, i;
char temp[2], temp2[2];
char act[20];

void check();

void main() {
    printf("\n\t\t Shift Reduce Parser\n");

    printf("\n Grammar\n");
    printf("\n E -> E + E");
    printf("\n E -> E / E");
    printf("\n E -> E * E");
    printf("\n E -> a / b");

    printf("\n Enter the input symbol:");
    gets(ip_sym);

    printf("\n\t Stack implementation table");
    printf("\n Stack \t\t Input Symbol \t\t Action");
    printf("\n-----------\t\t-------------\t\t---------\n");

    printf("\n$\t\t%s$\t\t\t---", ip_sym);

    strcpy(act, "Shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);

    len = strlen(ip_sym);

    for (i = 0; i < len; i++) {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;

        printf("\n $%s\t\t%s$\t\t\t%s", stack, ip_sym, act);

        strcpy(act, "Shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);

        check();
        st_ptr++;
    }
    st_ptr++;
    check();
}

void check() {
    int flag = 0;
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';

    // Reduce E -> a / E -> b
    if ((!strcmp(temp2, "a")) || (!strcmp(temp2, "b"))) {
        stack[st_ptr] = 'E';
        if (!strcmp(temp2, "a"))
            printf("\n $%s\t\t%s\t\t\tE -> a", stack, ip_sym);
        else
            printf("\n $%s\t\t%s$\t\t\tE -> b", stack, ip_sym);
        flag = 1;
    }

    // Check for operators
    if ((!strcmp(temp2, "+")) || (!strcmp(temp2, "*")) || (!strcmp(temp2, "/"))) {
        flag = 1;
    }

    // Reduce E -> E + E, E -> E / E, E -> E * E
    if ((!strcmp(stack, "E+E")) || (!strcmp(stack, "E/E")) || (!strcmp(stack, "E*E"))) {
        strcpy(stack, "E");
        st_ptr = 0;

        if (!strcmp(stack, "E+E"))
            printf("\n $%s\t\t%s\t\t\tE -> E + E", stack, ip_sym);
        else if (!strcmp(stack, "E/E"))
            printf("\n $%s\t\t%s\t\t\tE -> E / E", stack, ip_sym);
        else if (!strcmp(stack, "E*E"))
            printf("\n $%s\t\t%s\t\t\tE -> E * E", stack, ip_sym);

        flag = 1;
    }

    // Accept condition
    if (!strcmp(stack, "E") && ip_ptr == len) {
        printf("\n $%s\t\t%s$\t\t\tAccept", stack, ip_sym);
        printf("\nLab NO:11\n");
printf("Name:Rajip Maharjan\n");
printf("Roll no:14");
        exit(0);
    }

    // Reject condition
    if (flag == 0) {
        printf("\n%s\t\t\t%s\t\t Reject", stack, ip_sym);
    }

    return;
}

