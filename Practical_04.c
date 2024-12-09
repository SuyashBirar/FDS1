#include <stdio.h>

#define MAX_STUDENTS 100

// Function for selection sort
void selectionSort(float arr[], int n) {
    int i, j, minIndex;
    float temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        
        // Find the minimum element in unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function for bubble sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    
    for (i = 0; i < n - 1; i++) {
        // Flag to check if any swapping is done in this pass
        int swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element is greater than the next one
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        // If no elements were swapped, break out of the loop
        if (!swapped) {
            break;
        }
    }
}

// Function to display the top five scores
void displayTopFiveScores(float arr[], int n) {
    printf("Top 5 scores:\n");
    
    int topCount = (n < 5) ? n : 5;  // Display only top 5 or less if less than 5 students
    
    for (int i = n - 1; i >= n - topCount; i--) {
        printf("%.2f\n", arr[i]);
    }
}

int main() {
    int n;
    float scores[MAX_STUDENTS];

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input percentage scores
    printf("Enter the percentages of students:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &scores[i]);
    }

    int choice;
    printf("\nSelect Sorting Method:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Sort and display top 5 scores based on the user's choice
    switch (choice) {
        case 1:
            selectionSort(scores, n);
            printf("\nSorted scores (Ascending Order):\n");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", scores[i]);
            }
            printf("\n");
            displayTopFiveScores(scores, n);
            break;
            
        case 2:
            bubbleSort(scores, n);
            printf("\nSorted scores (Ascending Order):\n");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", scores[i]);
            }
            printf("\n");
            displayTopFiveScores(scores, n);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
