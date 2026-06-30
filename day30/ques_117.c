#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);

int main() {
    struct Student database[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(database, &studentCount);
                break;
            case 2:
                displayStudents(database, studentCount);
                break;
            case 3:
                searchStudent(database, studentCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    
    getchar(); 

    printf("Enter Student Name: ");
    fgets(students[*count].name, NAME_LENGTH, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student record added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n%-12s %-25s %-6s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-12d %-25s %-6.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchRoll;
    int found = 0;

    printf("\nEnter the Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == searchRoll) {
            printf("\n--- Record Found ---\n");
            printf("Roll Number : %d\n", students[i].rollNumber);
            printf("Name        : %s\n", students[i].name);
            printf("Marks       : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", searchRoll);
    }
}
