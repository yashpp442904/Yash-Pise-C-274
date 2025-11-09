//1 A.	
//Write a program to accept ‘n’ numbers into an array and then calculate 
//the sum of numbers present in odd positions and even positions respectively.	

#include <stdio.h>

int main() {
    int size, i;
    int sum_e = 0, sum_o = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size; i++) {
        if ((i + 1) % 2 == 0)   
            sum_e  += arr[i];
        else                     
            sum_o += arr[i];
    }

    printf("\nSum of numbers at odd positions = %d", sum_o);
    printf("\nSum of numbers at even positions = %d", sum_e);

    return 0;
}
