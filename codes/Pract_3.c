//3	Design, Develop and Implement a menu driven Program in C for the 
//following operations on QUEUE of Characters (Array Implementation of 
//Queue with maximum size MAX)
//a. Insert an Element on to QUEUE
//b. Delete an Element from QUEUE
//c. Demonstrate Overflow and Underflow situations on QUEUE
//d. Display the status of QUEUE
//e. Exit
//Support the program with appropriate functions for each of the above operations.	


#include <stdio.h>
#define MAX 5

char Q[MAX];
int front = -1, rear = -1;

void EnQ();
void DeQ();
void display();

int main() {
    int choice;
    printf("1. Insert an Element in Queue\n2. Delete an Element from Queue\n3. Display the status of Queue\n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                EnQ();
                break;
            case 2:
                DeQ();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert an element in queue
void EnQ() {
    char ele;   
    printf("Enter character to insert: ");
    scanf(" %c", &ele);

    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert '%c'\n", ele);
    } else {
        if (front == -1)
            front = 0;
        Q[++rear] = ele;
        printf("'%c' inserted into queue.\n", ele);
    }
}

// Function to delete an element from queue
void DeQ() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No element to delete.\n");
    } else {
        printf("'%c' deleted from queue.\n", Q[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

// Function to display queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements (front to rear): ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", Q[i]);
        }
        printf("\n");
    }
}


