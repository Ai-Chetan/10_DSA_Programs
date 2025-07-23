/* Program to print structure of students in ascending order of their Roll No */

#include <stdio.h>


// Structure of Student
struct Student {
    char name[50];
    int rollNo;
    float percentage;
}s[5],temp;

void main() {
	
	// Accepting Name, Roll No, and Percentage of 5 Students
    printf("Enter details of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Percentage: ");
        scanf("%f", &s[i].percentage);
    }
	
	
	// Bubble Sorting by Roll No.
    for (int i = 0; i < 5-1; i++) {
        for (int j = 0; j < 5-i-1; j++) {
            if (s[j].rollNo > s[j+1].rollNo) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Roll No:\n");
    printf("Roll No\t Name\t Percentage\n");
    
    // printing array of structure
    for (int i = 0; i < 5; i++) {
        printf("%d\t %s\t %.2f\n", s[i].rollNo, s[i].name, s[i].percentage);
    }
}

//comeents9jflksbdjf