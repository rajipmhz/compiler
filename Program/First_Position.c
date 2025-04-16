#include <stdio.h>
#include <ctype.h>
#include <string.h>

void FIRST(char[], char);
void addToResultSet(char[], char);

int numOfProductions;
char productionSet[10][10];

int main() {
    int i;
    char choice;
    char ch;
    char result[20];

    printf("How many productions?: ");
    scanf("%d", &numOfProductions);
    
    getchar(); // Consume leftover newline character

    for (i = 0; i < numOfProductions; i++) {
        printf("Enter productions number %d: ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &ch);

        result[0] = '\0'; // Reset result before calling FIRST

        FIRST(result, ch);

        printf("\nFIRST(%c) = {", ch);
        for (i = 0; result[i] != '\0'; i++) {
            printf("%c", result[i]);
            if (result[i + 1] != '\0') {
                printf(", ");
            }
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nLab NO: 6\n");
    printf("Name: Rajip Maharjan\n");
    printf("Roll No: 14\n");

    return 0;
}

void FIRST(char *Result, char ch) {
    int i, j, k;
    char subResult[20];
    int foundEpsilon;

    // If ch is a terminal, FIRST(X) = {X}
    if (!isupper(ch)) {
        addToResultSet(Result, ch);
        return;
    }

    // Process each production
    for (i = 0; i < numOfProductions; i++) {
        // Check if the production is of the form X -> ...
        if (productionSet[i][0] == ch) {
            if (productionSet[i][2] == '$') { // If X -> epsilon, add epsilon
                addToResultSet(Result, '$');
            } else {
                j = 2;
                while (productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    subResult[0] = '\0'; // Reset subResult before recursion

                    FIRST(subResult, productionSet[i][j]);

                    // Add FIRST(Y) to FIRST(X)
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToResultSet(Result, subResult[k]);
                    }

                    // Check if epsilon is in FIRST(Y)
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    // If epsilon is not found, stop
                    if (!foundEpsilon) {
                        break;
                    }

                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val) {
    int k;

    // Check if val is already in Result
    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val) {
            return;
        }
    }

    // Add val to Result
    Result[k] = val;
    Result[k + 1] = '\0';
}

