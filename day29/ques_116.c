#include <stdio.h>

int main() {
    char name[30] = "Wireless Mouse";
    int quantity = 15;
    double price = 25.50;
    
    int choice;
    int amount;

    while (1) {
        printf("\n=== PRODUCT STATUS ===\n");
        printf("Item: %s\n", name);
        printf("Stock Count: %d\n", quantity);
        printf("Unit Price: $%.2f\n", price);
        printf("======================\n");

        printf("1. Add Inbound Stock\n");
        printf("2. Sell/Remove Outbound Stock\n");
        printf("3. Close Program\n");
        printf("Choose options (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter quantity to add: ");
            scanf("%d", &amount);
            quantity = quantity + amount;
            printf("✅ Stock added successfully!\n");
        } 
        else if (choice == 2) {
            printf("Enter quantity to remove: ");
            scanf("%d", &amount);
            
            if (amount > quantity) {
                printf("❌ Error: Not enough items in stock!\n");
            } else {
                quantity = quantity - amount;
                printf("✅ Stock removed successfully!\n");
            }
        } 
        else if (choice == 3) {
            printf("👋 Goodbye!\n");
            break;
        } 
        else {
            printf("❌ Invalid choice. Try again.\n");
        }
    }

    return 0;
}
