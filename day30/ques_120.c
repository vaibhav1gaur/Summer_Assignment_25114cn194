#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LENGTH 30

void add_item(char names[][NAME_LENGTH], float prices[], int quantities[], int *count);
void display_inventory(char names[][NAME_LENGTH], float prices[], int quantities[], int count);
void search_item(char names[][NAME_LENGTH], float prices[], int quantities[], int count);
void calculate_total_value(float prices[], int quantities[], int count);

int main() {
    char item_names[MAX_ITEMS][NAME_LENGTH];
    float item_prices[MAX_ITEMS];
    int item_quantities[MAX_ITEMS];
    int item_count = 0;
    int choice;

    strcpy(item_names[0], "Wireless Mouse");
    item_prices[0] = 25.50;
    item_quantities[0] = 12;
    item_count++;

    strcpy(item_names[1], "Mechanical Keyboard");
    item_prices[1] = 79.99;
    item_quantities[1] = 5;
    item_count++;

    while (1) {
        printf("\n--- Warehouse Inventory System ---\n");
        printf("1. Add New Product\n");
        printf("2. View Stock Inventory\n");
        printf("3. Search Product by Name\n");
        printf("4. Calculate Total Asset Value\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. System shutting down.\n");
            break;
        }

        switch (choice) {
            case 1: 
                add_item(item_names, item_prices, item_quantities, &item_count); 
                break;
            case 2: 
                display_inventory(item_names, item_prices, item_quantities, item_count); 
                break;
            case 3: 
                search_item(item_names, item_prices, item_quantities, item_count); 
                break;
            case 4: 
                calculate_total_value(item_prices, item_quantities, item_count); 
                break;
            case 5: 
                printf("\nExiting system. Data cleared from RAM. Goodbye!\n"); 
                return 0;
            default: 
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}

void add_item(char names[][NAME_LENGTH], float prices[], int quantities[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("\n[Error] Warehouse catalog capacity full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf(" %[^\n]s", names[*count]);

    printf("Enter unit price ($): ");
    scanf("%f", &prices[*count]);

    printf("Enter initial stock quantity: ");
    scanf("%d", &quantities[*count]);

    if (prices[*count] < 0 || quantities[*count] < 0) {
        printf("\n[Error] Invalid price or quantity. Entry aborted.\n");
        return;
    }

    (*count)++;
    printf("\n[Success] Product added to system.\n");
}

void display_inventory(char names[][NAME_LENGTH], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\nInventory empty.\n");
        return;
    }

    printf("\n=================== CURRENT WAREHOUSE STOCK ===================\n");
    printf("%-5s %-25s %-12s %-10s\n", "No.", "Item Description", "Price ($)", "Stock Qty");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-25s %-12.2f %-10d\n", i + 1, names[i], prices[i], quantities[i]);
    }
    printf("===============================================================\n");
}

void search_item(char names[][NAME_LENGTH], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\nInventory catalog is empty.\n");
        return;
    }

    char search_query[NAME_LENGTH];
    int found = 0;

    printf("Enter exact product name to look up: ");
    scanf(" %[^\n]s", search_query);

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], search_query) == 0) {
            printf("\n[Match Found] Index Location: Slot %d\n", i + 1);
            printf("Name:       %s\n", names[i]);
            printf("Unit Price: $%.2f\n", prices[i]);
            printf("In-Stock:   %d units\n", quantities[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n[Notification] Product '%s' not registered in inventory.\n", search_query);
    }
}

void calculate_total_value(float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\nAssets value empty. No items tracking.\n");
        return;
    }

    float total_inventory_value = 0;

    for (int i = 0; i < count; i++) {
        total_inventory_value += (prices[i] * quantities[i]);
    }

    printf("\n=====================================\n");
    printf(" Total Unique Items tracked: %d\n", count);
    printf(" Total Warehouse Assets Value: $%.2f\n", total_inventory_value);
    printf("=====================================\n");
}
