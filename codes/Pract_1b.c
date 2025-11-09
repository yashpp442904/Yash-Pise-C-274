//1 B.	
//Write a program to implement a Binary Search algorithm. Write a search function 
//which takes a SearchList as its first parameter and a Comparable as its second. 
//If either parameter is null, or if the SearchList is empty, you should return NULL.
//implement the following algorithm: 
//• Examine the value in the middle of the current array and print it. 
//• If the midpoint value is the value that we are looking for, return true 
//• If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
//• if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
//• Continue until you find the value, or until the start reaches the end, 
	


#include <stdio.h>
#include <stdbool.h>
int getkey(int arr[], int n, int key);

int main() {
    int arr[100], n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = getkey(arr, n, key);

    if(index == -1)
        printf("Key %d not found in the array.\n", key);
    else
        printf("Key %d found at index %d.\n", key, index);

    return 0;
}

int getkey(int arr[], int n, int key) {
    int beg = 0, end = n - 1;
    int mid,index =-1;

    while (beg <= end) {
        mid = (beg + end) / 2;

        printf("Middle value = %d at index %d\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf("Key %d found at index %d.\n", key, mid);
            return true;
        } 
        else if (key > arr[mid]) {
            printf("Key is greater than middle value, moving start to index %d\n", mid + 1);
            beg = mid + 1;
        } 
        else { 
            printf("Key is smaller than middle value, moving end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    return index;
}

