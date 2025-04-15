#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    // Declare an array of Student structures
    struct Student students[3];

    // Input student data
    for (int i = 0; i < 3; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]s", students[i].name); // Read name with spaces

        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        printf("\n");
    }

    // Use a pointer to iterate through the array and display student data
    struct Student *ptr;
    ptr = students; // Point to the first element of the array

    printf("Student Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", ptr->name);
        printf("Roll Number: %d\n", ptr->rollNumber);
        printf("Marks: %.2f\n", ptr->marks);
        printf("\n");

        ptr++; // Move the pointer to the next student structure
    }

    return 0;
}