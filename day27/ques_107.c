#include <stdio.h>

struct SalaryRecord {
    int empId;
    char name[50];
    float baseSalary;
    float bonus;
    float taxDeduction;
    float netSalary;
};

int main() {
    struct SalaryRecord employees[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- SALARY MANAGEMENT SYSTEM ---\n");
        printf("1. Calculate & Add Salary Slip\n");
        printf("2. View All Salary Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < 100) {
                printf("\nEnter Employee ID: ");
                scanf("%d", &employees[count].empId);

                printf("Enter Employee Name: ");
                scanf("%s", employees[count].name);

                printf("Enter Base Salary ($): ");
                scanf("%f", &employees[count].baseSalary);

                printf("Enter Bonus ($): ");
                scanf("%f", &employees[count].bonus);

                printf("Enter Tax Deduction ($): ");
                scanf("%f", &employees[count].taxDeduction);

                employees[count].netSalary = (employees[count].baseSalary + employees[count].bonus) - employees[count].taxDeduction;

                count++;
                printf("Salary record calculated and saved successfully!\n");
            } else {
                printf("System storage full!\n");
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo salary records found.\n");
            } else {
                printf("\n====================================================================\n");
                printf("%-10s %-15s %-12s %-10s %-10s %-12s\n", "ID", "Name", "Base Sal", "Bonus", "Tax", "Net Salary");
                printf("====================================================================\n");
                
                for (int i = 0; i < count; i++) {
                    printf("%-10d %-15s $%-11.2f $%-9.2f $%-9.2f $%-11.2f\n", 
                           employees[i].empId, 
                           employees[i].name, 
                           employees[i].baseSalary, 
                           employees[i].bonus, 
                           employees[i].taxDeduction, 
                           employees[i].netSalary);
                }
                printf("====================================================================\n");
            }
        } 
        else if (choice == 3) {
            printf("Exiting system. Goodbye!\n");
            break; 
        } 
        else {
            printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}
