#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    int math;
    int science;
    int english;
    int total;
    float percentage;
    char result[10];
};

int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- MARKSHEET GENERATION SYSTEM ---\n");
        printf("1. Enter Student Marks\n");
        printf("2. View All Marksheets\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < 100) {
                printf("\nEnter Roll Number: ");
                scanf("%d", &students[count].rollNo);

                printf("Enter Student Name: ");
                scanf("%s", students[count].name);

                printf("Enter Marks for Math (out of 100): ");
                scanf("%d", &students[count].math);

                printf("Enter Marks for Science (out of 100): ");
                scanf("%d", &students[count].science);

                printf("Enter Marks for English (out of 100): ");
                scanf("%d", &students[count].english);

                students[count].total = students[count].math + students[count].science + students[count].english;
                students[count].percentage = students[count].total / 3.0;

                if (students[count].math >= 40 && students[count].science >= 40 && students[count].english >= 40) {
                    strcpy(students[count].result, "Pass");
                } else {
                    strcpy(students[count].result, "Fail");
                }

                count++;
                printf("Marks saved successfully!\n");
            } else {
                printf("System storage full!\n");
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo student records found.\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("\n========================================");
                    printf("\n           OFFICIAL MARKSHEET           ");
                    printf("\n========================================");
                    printf("\nRoll No: %-10d Name: %s", students[i].rollNo, students[i].name);
                    printf("\n----------------------------------------");
                    printf("\nSubject       | Max Marks | Marks Obtained");
                    printf("\n----------------------------------------");
                    printf("\nMath          | 100       | %d", students[i].math);
                    printf("\nScience       | 100       | %d", students[i].science);
                    printf("\nEnglish       | 100       | %d", students[i].english);
                    printf("\n----------------------------------------");
                    printf("\nTotal Marks:  | 300       | %d", students[i].total);
                    printf("\nPercentage:   | %.2f%%", students[i].percentage);
                    printf("\nFinal Result: | %s", students[i].result);
                    printf("\n========================================\n");
                }
            }
        } 
        else if (choice == 3) {
            printf("Exiting system. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
