#include <stdio.h>

int main() {
    int i, j, k;
        // Outer loop for rows
    for (i = 6; i >= 1; i--) {
        for (k=1; k<=i; k++){
            printf(" ");
        }
        // Inner loop for columns (asterisks)
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\n"); // Move to the next row
    }

    return 0; // Indicate successful execution
}
