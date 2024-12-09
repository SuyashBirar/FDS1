#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform selection sort
void selectionSort(vector<float>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

// Function to perform bubble sort
void bubbleSort(vector<float>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to display the top five scores
void displayTopFiveScores(const vector<float>& arr) {
    int count = min(5, (int)arr.size());  // Get the minimum of 5 or the array size
    cout << "\nTop 5 scores: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Input the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    vector<float> percentages(n);

    // Input the percentages of students
    cout << "Enter the percentages of the students: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> percentages[i];
    }

    int choice;
    cout << "\nChoose a sorting method:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    // Sort and display the top 5 scores based on the user's choice
    switch (choice) {
        case 1:
            selectionSort(percentages);
            cout << "\nScores after Selection Sort: ";
            for (float score : percentages) {
                cout << score << " ";
            }
            displayTopFiveScores(percentages);
            break;

        case 2:
            bubbleSort(percentages);
            cout << "\nScores after Bubble Sort: ";
            for (float score : percentages) {
                cout << score << " ";
            }
            displayTopFiveScores(percentages);
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
