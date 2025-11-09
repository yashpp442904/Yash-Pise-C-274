//Design, Develop and Implement a menu driven Program in C for the following operations 
//on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
//a. Push an Element on to Stack 
//b. Pop an Element from Stack 
//c. Demonstrate how Stack can be used to check Palindrome 
//d. Demonstrate Overflow and Underflow situations on Stack 
//e. Display the status of Stack 
//f. Exit 
//Support the program with appropriate functions for each of the above operations.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

int s[MAX];
int top = -1;

void push(int);
void pop();
void display();
void palindrome();

// Main function
int main() {
    int ch, ele;
        printf("1. Push an Element on stack\n");
        printf("2. Pop an Element from stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Display Status of stack\n");
        printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert in stack: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                palindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Thnak You!\n");
                return 0;
            default:
                printf("Invalid choice! \n");
        }
    } while (ch != 5);

    return 0;
}

// Function to push an element
void push(int ele) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", ele);
    } else {
        s[++top] = ele;
        printf("%d pushed onto stack.\n", ele);
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("%d popped from stack.\n", s[top--]);
    }
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

// Function to check if a given string is a palindrome using stack
void palindrome() {
    char str[50];
    char rev[50];
    int i, len;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    len = strlen(str);
    top = -1;  

    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        rev[i] = s[top--];
    }
    rev[i] = '\0';

    // Compare
    if (strcmp(str, rev) == 0)
        printf("%s is a Palindrome.\n", str);
    else
        printf("%s is NOT a Palindrome.\n", str);
}

