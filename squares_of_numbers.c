#include <stdio.h>

int main() {
    int i, j;

    // for loop to print the first few lines
    for (i = 3; i <= 11; i += 4) {
        j = i * i;
        printf("%-4d %d\n", i, j);
    }

    // do-while loop to print the remaining lines
    i = 15;
    do {
        j = i * i;
        printf("%-4d %d\n", i, j);
        i += 4;
    } while (i <= 19);

    return 0;
}
