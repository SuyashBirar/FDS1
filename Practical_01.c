#include <stdio.h>

#define ABSENT -999  // Define -999 as the marker for absent students

// Function to calculate the average score of the class
float average(int marks[], int n) {
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] != ABSENT) {
            sum += marks[i];
            count++;
        }
    }
    return (count != 0) ? (float)sum / count : 0;
}

// Function to find the highest score in the class
int highestScore(int marks[], int n) {
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (marks[i] != ABSENT && (max == -1 || marks[i] > max)) {
            max = marks[i];
        }
    }
    return max;
}

// Function to find the lowest score in the class
int lowestScore(int marks[], int n) {
    int min = -1;
    for (int i = 0; i < n; i++) {
        if (marks[i] != ABSENT && (min == -1 || marks[i] < min)) {
            min = marks[i];
        }
    }
    return min;
}

// Function to count the number of students absent for the test
int countAbsent(int marks[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] == ABSENT) {
            count++;
        }
    }
    return count;
}

// Function to find the mark with the highest frequency
int mostFrequentMark(int marks[], int n) {
    int frequency[101] = {0};  // Assuming marks range from 0 to 100
    int maxFreq = 0, mostFrequent = -1;

    for (int i = 0; i < n; i++) {
        if (marks[i] != ABSENT) {
            frequency[marks[i]]++;
            if (frequency[marks[i]] > maxFreq) {
                maxFreq = frequency[marks[i]];
                mostFrequent = marks[i];
            }
        }
    }

    // Display frequency of all marks
    printf("Marks\t| Frequency\n");
    for (int i = 0; i <= 100; i++) {
        if (frequency[i] > 0) {
            printf("%d\t| %d\n", i, frequency[i]);
        }
    }

    return mostFrequent;
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d (-999 for absent): ", i + 1);
        scanf("%d", &marks[i]);
    }

    int choice;
    do {
        printf("\n\n-------------------- MENU --------------------\n");
        printf("1. Average Marks of the Class\n");
        printf("2. Highest and Lowest Marks in the Class\n");
        printf("3. Number of Students Absent for the Test\n");
        printf("4. Marks with Highest Frequency\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Average Marks of the Class: %.2f\n", average(marks, n));
                break;
            case 2:
                printf("Highest Score in Class: %d\n", highestScore(marks, n));
                printf("Lowest Score in Class: %d\n", lowestScore(marks, n));
                break;
            case 3:
                printf("Number of Students Absent: %d\n", countAbsent(marks, n));
                break;
            case 4: {
                int mostFrequent = mostFrequentMark(marks, n);
                printf("Mark with Highest Frequency: %d\n", mostFrequent);
                break;
            }
            case 5:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
