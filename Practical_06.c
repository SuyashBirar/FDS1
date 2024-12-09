#include <stdio.h>

void quickSort(float arr[], int low, int high);
int partition(float arr[], int low, int high);
void displayTopFiveScores(float arr[], int size);

int main() {
    int n;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    float percentages[n];

    // Input the percentages of students
    printf("Enter the percentages of the students: \n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &percentages[i]);
    }

    // Perform quicksort on the array
    quickSort(percentages, 0, n - 1);

    // Display the top five scores
    displayTopFiveScores(percentages, n);

    return 0;
}

// Function to perform Quick Sort
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(float arr[], int low, int high) {
    float pivot = arr[high];  // Taking the last element as pivot
    int i = (low - 1);  // Index of smaller element

    // Rearranging elements based on pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;  // Increment the index of smaller element
            // Swap arr[i] and arr[j]
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap the pivot element with the element at index i + 1
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to display the top five scores
void displayTopFiveScores(float arr[], int size) {
    int count = (size < 5) ? size : 5;  // Get the minimum of 5 or the array size

    printf("\nTop 5 scores: ");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}
