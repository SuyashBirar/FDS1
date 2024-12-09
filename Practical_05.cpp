#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform insertion sort
void insertionSort(vector<float>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform shell sort
void shellSort(vector<float>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
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
    cout << "1. Insertion Sort\n";
    cout << "2. Shell Sort\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    // Sort and display the top 5 scores based on the user's choice
    switch (choice) {
        case 1:
            insertionSort(percentages);
            cout << "\nScores after Insertion Sort: ";
            for (float score : percentages) {
                cout << score << " ";
            }
            displayTopFiveScores(percentages);
            break;

        case 2:
            shellSort(percentages);
            cout << "\nScores after Shell Sort: ";
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
