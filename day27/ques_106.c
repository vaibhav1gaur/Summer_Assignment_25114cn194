#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[50];
    char role[50];
    float salary;
} Employee;

void addEmployee();
void viewEmployees();
void updateEmployee();
void deleteEmployee();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n===================================\n");
    printf("    EMPLOYEE MANAGEMENT SYSTEM     \n");
    printf("===================================\n");
    printf("1. Add Employee\n");
    printf("2. View All Employees\n");
    printf("3. Update Employee Salary/Role\n");
    printf("4. Delete Employee\n");
    printf("5. Exit\n");
    printf("===================================\n");
}

void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar();

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Role: ");
    fgets(emp.role, sizeof(emp.role), stdin);
    emp.role[strcspn(emp.role, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);

    printf("Employee record added successfully!\n");
}

void viewEmployees() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found. Try adding an employee first.\n");
        return;
    }

    Employee emp;
    printf("\n-------------------------------------------------------------------\n");
    printf("%-10s %-25s %-20s %-10s\n", "ID", "Name", "Role", "Salary");
    printf("-------------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("%-10d %-25s %-20s $%-9.2f\n", emp.id, emp.name, emp.role, emp.salary);
    }
    printf("-------------------------------------------------------------------\n");
    fclose(file);
}

void updateEmployee() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &targetId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == targetId) {
            found = 1;
            getchar();

            printf("Enter New Role: ");
            fgets(emp.role, sizeof(emp.role), stdin);
            emp.role[strcspn(emp.role, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            fseek(file, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, file);
            break;
        }
    }

    fclose(file);
    if (found) {
        printf("Employee record updated successfully!\n");
    } else {
        printf("Employee with ID %d not found.\n", targetId);
    }
}

void deleteEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == targetId) {
            found = 1;
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Employee record deleted successfully!\n");
    } else {
        printf("Employee with ID %d not found.\n", targetId);
    }
}