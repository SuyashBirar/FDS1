#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform quick sort
int partition(vector<float>& arr, int low, int high) {
    float pivot = arr[high];
    int i = low - 1;
    
    // Rearranging the elements based on pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<float>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Find pivot element's index
        quickSort(arr, low, pi - 1);  // Sort the left part
        quickSort(arr, pi + 1, high); // Sort the right part
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

    // Sort the array using Quick Sort
    quickSort(percentages, 0, n - 1);

    // Display the sorted array and the top 5 scores
    cout << "\nScores after Quick Sort: ";
    for (float score : percentages) {
        cout << score << " ";
    }
    
    displayTopFiveScores(percentages);

    return 0;
}
