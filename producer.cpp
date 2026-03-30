#include <stdio.h>
#include <stdlib.h>

// Initialize mutex to 1
int mutex = 1;

// Number of full and empty slots
int full = 0;
int empty = 10;

// Item counter
int x = 0;

// Producer function
void producer() {
    mutex--;        // lock
    full++;         // increase full slots
    empty--;        // decrease empty slots
    x++;            // produce item

    printf("\nProducer produces item %d", x);

    mutex++;        // unlock
}

// Consumer function
void consumer() {
    mutex--;        // lock
    full--;         // decrease full slots
    empty++;        // increase empty slots

    printf("\nConsumer consumes item %d", x);
    x--;            // remove item

    mutex++;        // unlock
}

// Main function
int main() {
    int n;

    while (1) {
        printf("\n1. Press 1 for Producer");
        printf("\n2. Press 2 for Consumer");
        printf("\n3. Press 3 for Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {

        case 1:
            if ((mutex == 1) && (empty != 0)) {
                producer();
            } else {
                printf("\nBuffer is full!");
            }
            break;

        case 2: 
            if ((mutex == 1) && (full != 0)) {
                consumer();
            } else {
                printf("\nBuffer is empty!");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}
