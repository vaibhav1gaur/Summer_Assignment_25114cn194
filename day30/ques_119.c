#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define STR_SIZE 50

typedef struct {
    int id;
    char name[STR_SIZE];
    char department[STR_SIZE];
    float salary;
} Employee;

typedef struct {
    Employee employees[MAX_EMPLOYEES];
    int count;
} ManagementSystem;

int find_employee(ManagementSystem *sys, int id) {
    for (int i = 0; i < sys->count; i++) {
        if (sys->employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void add_employee(ManagementSystem *sys) {
    if (sys->count >= MAX_EMPLOYEES) {
        printf("\n[Error] System storage is full!\n");
        return;
    }

    int id;
    printf("Enter Employee ID (Numbers only): ");
    if (scanf("%d", &id) != 1) {
        printf("\n[Error] Invalid numeric format.\n");
        while (getchar() != '\n');
        return;
    }

    if (find_employee(sys, id) != -1) {
        printf("\n[Error] Employee with ID %d already exists.\n", id);
        return;
    }

    sys->employees[sys->count].id = id;

    printf("Enter Full Name: ");
    scanf(" %[^\n]s", sys->employees[sys->count].name);

    printf("Enter Department: ");
    scanf(" %[^\n]s", sys->employees[sys->count].department);

    printf("Enter Salary: ");
    if (scanf("%f", &sys->employees[sys->count].salary) != 1) {
        printf("\n[Error] Invalid salary format. Defaulting to 0.00\n");
        sys->employees[sys->count].salary = 0.0f;
    }

    sys->count++;
    printf("\n[Success] Record added successfully.\n");
}

void display_employees(ManagementSystem *sys) {
    if (sys->count == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    printf("\n==================== EMPLOYEE RECORDS ====================\n");
    printf("%-10s %-20s %-20s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < sys->count; i++) {
        printf("%-10d %-20s %-20s $%-11.2f\n", 
               sys->employees[i].id, 
               sys->employees[i].name, 
               sys->employees[i].department, 
               sys->employees[i].salary);
    }
    printf("==========================================================\n");
}

void update_salary(ManagementSystem *sys) {
    int id;
    printf("Enter Employee ID to update salary: ");
    scanf("%d", &id);

    int idx = find_employee(sys, id);
    if (idx == -1) {
        printf("\n[Error] Employee record not found.\n");
        return;
    }

    printf("Current Salary for %s: $%.2f\n", sys->employees[idx].name, sys->employees[idx].salary);
    printf("Enter New Salary: ");
    scanf("%f", &sys->employees[idx].salary);

    printf("\n[Success] Salary updated successfully.\n");
}

int main() {
    ManagementSystem sys = { .count = 0 };
    int choice;

    sys.employees[0].id = 1001;
    strcpy(sys.employees[0].name, "Alice Smith");
    strcpy(sys.employees[0].department, "Engineering");
    sys.employees[0].salary = 85000.50f;
    sys.count = 1;

    while (1) {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee Record\n");
        printf("2. View All Employee Records\n");
        printf("3. Update Employee Salary\n");
        printf("4. Exit Application\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Exiting application.\n");
            break;
        }

        switch (choice) {
            case 1: add_employee(&sys); break;
            case 2: display_employees(&sys); break;
            case 3: update_salary(&sys); break;
            case 4: printf("\nClosing application. Goodbye!\n"); return 0;
            default: printf("\n[Error] Invalid Selection. Try again.\n");
        }
    }
    return 0;
}
