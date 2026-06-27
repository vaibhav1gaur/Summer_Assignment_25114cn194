#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    int age;
    char course[50];
} student;

student students[MAX_STUDENTS];
int student_count = 0;

void add_student();
void view_students();
void search_student();

int main() {

    int choice;

    while(1) {
        printf("\n---STUDENT SYSTEM---\n");
        printf("1. Add student\n");
        printf("2. View all students\n");
        printf("3. Search students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: search_student(); break;
            case 4: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void add_student() {
    if(student_count >= MAX_STUDENTS) {
        printf("System full! cannot add more student.\n");
        return;
    }

    student s;
    printf("\nEnter roll number: ");
    scanf("%d", &s.roll_no);

    for(int i=0; i<student_count; i++) {
        if(students[i].roll_no == s.roll_no) {
            printf("Error: roll number already exist!\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", s.name);
    
    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter course: ");
    scanf("%s", &s.course);

    students[student_count] = s;
    student_count++;
    printf("Student add successfully!\n");
}

void view_students() {
    if(student_count == 0) {
        printf("\nNo student record found.\n");
        return;
    }

    printf("\n%-10s %-20s %-5s %-15s\n", "Roll No", "Name", "Age", "Course");
    printf("--------------------------------------------------\n");
    for(int i=0; i<student_count; i++) {
        printf("%-10d %-20s %-5d %-15s\n", students[i].roll_no, students[i].name, students[i].age, students[i].course);
    }
}

void search_student() {
     if(student_count == 0) {
        printf("\nNo student record found.\n");
        return;
    }

    int roll_no;
    printf("\nEnter roll number for search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name:    %s\n", students[i].name);
            printf("Age:     %d\n", students[i].age);
            printf("Course:  %s\n", students[i].course);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll_no);
}