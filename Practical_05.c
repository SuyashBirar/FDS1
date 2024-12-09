#include <stdio.h>

#define MAX_STUDENTS 100

// Function to perform Insertion Sort
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Shell Sort
void shellSort(float arr[], int n) {
    int gap, i, j;
    float temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Function to display the top five scores
void displayTopFiveScores(float arr[], int n) {
    int count = (n < 5) ? n : 5;  // Get the minimum of 5 or the array size
    printf("\nTop 5 scores: ");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Input the percentages of students
    float percentages[MAX_STUDENTS];
    printf("Enter the percentages of the students: \n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &percentages[i]);
    }

    printf("\nChoose a sorting method:\n");
    printf("1. Insertion Sort\n");
    printf("2. Shell Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Sort and display the top 5 scores based on the user's choice
    switch (choice) {
        case 1:
            insertionSort(percentages, n);
            printf("\nScores after Insertion Sort: ");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", percentages[i]);
            }
            displayTopFiveScores(percentages, n);
            break;

        case 2:
            shellSort(percentages, n);
            printf("\nScores after Shell Sort: ");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", percentages[i]);
            }
            displayTopFiveScores(percentages, n);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
