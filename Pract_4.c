//4	 
//This C program creates a linked list to store integer elements. It prompts the user to enter elements 
//and add them to the list until the user enters 0. It then traverses the list and prints each 
//element and "=>" until reaching the null pointer. Finally, it displays the number of nodes in the list.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int count = 0, num;

    printf("Enter elements to insert in linked list (Enter 0 to stop):\n");

    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    printf("\nLinked List elements:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Total number of nodes: %d\n", count);

    return 0;
}
