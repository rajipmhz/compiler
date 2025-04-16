#include <stdio.h>
#include <string.h>

int main() {
    char arithmetic[5] = {'+', '-', '*', '/', '%'};
    char relational[4] = {'<', '>', '!', '='};
    char bitwise[5] = {'&', '^', '~', '|'};
    char str[2] = {' ', ' '};
    int valid = 0; // Flag to indicate if a valid operator is found

    printf("Enter value to be identified: ");
    scanf("%s", &str);

    int i;

    // Checking for Logical Operators
    if (((str[0] == '&' || str[0] == '|') && str[0] == str[1]) || (str[0] == '!' && str[1] == '\0')) {
        printf("\nIt is a Logical operator");
        valid = 1;
    }

    // Checking for Relational Operators
    for (i = 0; i < 4; i++) {
        if (str[0] == relational[i] && (str[1] == '=' || str[1] == '\0')) {
            printf("\nIt is a Relational Operator");
            valid = 1;
            break;
        }
    }

    // Checking for Bitwise Operators
    for (i = 0; i < 4; i++) {
        if ((str[0] == bitwise[i] && str[1] == '\0') || 
            ((str[0] == '<' || str[0] == '>') && str[1] == str[0])) {
            printf("\nIt is a Bitwise Operator");
            valid = 1;
            break;
        }
    }

    // Checking for Ternary Operator
    if (str[0] == '?' && str[1] == ':') {
        printf("\nIt is a Ternary operator");
        valid = 1;
    }

    // Checking for Unary, Assignment, and Arithmetic Operators
    for (i = 0; i < 5; i++) {
        if ((str[0] == '+' || str[0] == '-') && str[0] == str[1]) {
            printf("\nIt is a Unary operator");
            valid = 1;
            break;
        } 
        else if ((str[0] == arithmetic[i] && str[1] == '=') || (str[0] == '=' && str[1] == ' ')) {
            printf("\nIt is an Assignment operator");
            valid = 1;
            break;
        } 
        else if (str[0] == arithmetic[i] && str[1] == '\0') {
            printf("\nIt is an Arithmetic operator");
            valid = 1;
            break;
        }
    }

    // If no valid operator was found
    if (!valid) {
        printf("\nThe input is not a valid operator");
    }

printf("\nLab NO:9\n");
printf("Name:Rajip Maharjan\n");
printf("Roll no:14");

    return 0;
}

