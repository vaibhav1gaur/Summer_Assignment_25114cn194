#include <stdio.h>

int main() {
    int totalSeats = 50;
    int availableSeats = 50;
    int ticketPrice = 12;
    int choice, ticketsToBook;

    while (1) {
        printf("\n--- TICKET BOOKING SYSTEM ---\n");
        printf("1. View Available Seats\n");
        printf("2. Book Tickets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nTotal Seats: %d\n", totalSeats);
            printf("Available Seats: %d\n", availableSeats);
        } 
        else if (choice == 2) {
            printf("\nEnter number of tickets to book: ");
            scanf("%d", &ticketsToBook);

            if (ticketsToBook <= 0) {
                printf("Error: Please enter a valid number of tickets!\n");
            } 
            else if (ticketsToBook > availableSeats) {
                printf("Error: Not enough seats available! Only %d left.\n", availableSeats);
            } 
            else {
                availableSeats -= ticketsToBook;
                int totalCost = ticketsToBook * ticketPrice;
                
                printf("\n--- Booking Successful! ---\n");
                printf("Tickets Booked: %d\n", ticketsToBook);
                printf("Total Amount Paid: $%d\n", totalCost);
                printf("Remaining Seats: %d\n", availableSeats);
            }
        } 
        else if (choice == 3) {
            printf("Thank you for using our system. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}
