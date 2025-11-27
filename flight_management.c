#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNo;
    char source[20];
    char destination[20];
    char time[10];
};

int main() {
    struct Flight flights[50];
    int count = 0;     // number of flights stored
    int choice;

    while (1) {
        // Menu
        printf("\n---- FLIGHT MANAGEMENT SYSTEM ----\n");
        printf("1. Add Flight\n");
        printf("2. View All Flights\n");
        printf("3. Search Flight by Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add flight
            printf("\nEnter Flight Number: ");
            scanf("%d", &flights[count].flightNo);

            printf("Enter Source: ");
            scanf("%s", flights[count].source);

            printf("Enter Destination: ");
            scanf("%s", flights[count].destination);

            printf("Enter Time (HH:MM): ");
            scanf("%s", flights[count].time);

            count++;
            printf("Flight added successfully!\n");
        }
        else if (choice == 2) {
            // View all flights
            printf("\n--- List of Flights ---\n");
            for (int i = 0; i < count; i++) {
                printf("\nFlight No: %d\n", flights[i].flightNo);
                printf("Source: %s\n", flights[i].source);
                printf("Destination: %s\n", flights[i].destination);
                printf("Time: %s\n", flights[i].time);
            }
        }
        else if (choice == 3) {
            // Search flight
            int number, found = 0;
            printf("\nEnter Flight Number to Search: ");
            scanf("%d", &number);

            for (int i = 0; i < count; i++) {
                if (flights[i].flightNo == number) {
                    printf("\nFlight Found!\n");
                    printf("Flight No: %d\n", flights[i].flightNo);
                    printf("Source: %s\n", flights[i].source);
                    printf("Destination: %s\n", flights[i].destination);
                    printf("Time: %s\n", flights[i].time);
                    found = 1;
                }
            }
            if (!found)
                printf("Flight not found!\n");
        }
        else if (choice == 4) {
            printf("Exiting Program...\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
}