#include <stdio.h>

int main() {
    char buffer; // Single input buffer

    printf("Enter a character (A-Z or a-z): ");
    buffer = getchar(); // Read a single character

    // Clear the input buffer to prevent issues with extra characters
    while (getchar() != '\n');  

    // Validate input
    if ((buffer >= 'A' && buffer <= 'Z') || (buffer >= 'a' && buffer <= 'z')) {
        printf("You entered: %c\n", buffer);
    } else {
        printf("Invalid input! Please enter an alphabet character.\n");
    }

    return 0;
}

