//1 C.	Write a program which creates a structure Student which must have the attribute Avg Marks
// with 3 more attributes sort the list of the student in descending order using Bubble sort.	
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int RollNo;
    int year;
    char sec[50];
    float avgM;
};

int main() {
    int n, i, j;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n], temp;

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Year: ");
        scanf("%d", &s[i].year);
        printf("Enter Section: ");
        scanf("%s", s[i].sec);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].RollNo);
        printf("Enter Average Marks: ");
        scanf("%f", &s[i].avgM);
    }

    // Bubble sort in descending order based on avgM
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avgM < s[j + 1].avgM) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Display sorted list
    printf("\nStudents sorted by Average Marks (Descending Order):\n");
    for (i = 0; i < n; i++) {
        printf("Student with Position %d\n", i + 1); 
        printf("Avg marks: %.2f\n Name: %s\n Year: %d\n Sec: %s\n Roll No: %d\n\n", s[i].avgM, s[i].name, s[i].year, s[i].sec, s[i].RollNo);
    }

    return 0;
}
