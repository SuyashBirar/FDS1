#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Function to calculate the average score of the class
double calculateAverage(const vector<int>& marks) {
    int total = 0;
    int count = 0;
    for (int mark : marks) {
        if (mark != -999) {  // -999 represents an absent student
            total += mark;
            count++;
        }
    }
    return (count == 0) ? 0 : static_cast<double>(total) / count;
}

// Function to find the highest score in the class
int findHighestScore(const vector<int>& marks) {
    int maxScore = -1;
    for (int mark : marks) {
        if (mark != -999) {  // ignore absent students
            maxScore = (maxScore == -1) ? mark : max(maxScore, mark);
        }
    }
    return maxScore;
}

// Function to find the lowest score in the class
int findLowestScore(const vector<int>& marks) {
    int minScore = -1;
    for (int mark : marks) {
        if (mark != -999) {  // ignore absent students
            minScore = (minScore == -1) ? mark : min(minScore, mark);
        }
    }
    return minScore;
}

// Function to count the number of students absent for the test
int countAbsentStudents(const vector<int>& marks) {
    int count = 0;
    for (int mark : marks) {
        if (mark == -999) {
            count++;
        }
    }
    return count;
}

// Function to find the mark with the highest frequency
pair<int, int> findHighestFrequency(const vector<int>& marks) {
    map<int, int> frequency;
    for (int mark : marks) {
        if (mark != -999) {  // ignore absent students
            frequency[mark]++;
        }
    }

    int maxFreq = 0;
    int markWithMaxFreq = -1;
    for (const auto& pair : frequency) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            markWithMaxFreq = pair.first;
        }
    }
    return {markWithMaxFreq, maxFreq};
}

int main() {
    int numberOfStudents;
    cout << "Enter total number of students: ";
    cin >> numberOfStudents;

    vector<int> marks;
    cout << "Enter marks for each student (-999 for absent):" << endl;
    for (int i = 0; i < numberOfStudents; ++i) {
        int mark;
        cout << "Student " << (i + 1) << ": ";
        cin >> mark;
        marks.push_back(mark);
    }

    int choice;
    bool continueProgram = true;
    while (continueProgram) {
        cout << "\n------ MENU ------" << endl;
        cout << "1. Total and Average Marks of the Class" << endl;
        cout << "2. Highest and Lowest Marks in the Class" << endl;
        cout << "3. Number of Students Absent for the Test" << endl;
        cout << "4. Marks with Highest Frequency" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double average = calculateAverage(marks);
                cout << "Average Marks: " << average << endl;
                break;
            }
            case 2: {
                int highest = findHighestScore(marks);
                int lowest = findLowestScore(marks);
                if (highest != -1 && lowest != -1) {
                    cout << "Highest Score: " << highest << endl;
                    cout << "Lowest Score: " << lowest << endl;
                } else {
                    cout << "No scores available." << endl;
                }
                break;
            }
            case 3: {
                int absentCount = countAbsentStudents(marks);
                cout << "Number of Students Absent: " << absentCount << endl;
                break;
            }
            case 4: {
                pair<int, int> result = findHighestFrequency(marks);
                if (result.first != -1) {
                    cout << "Mark with highest frequency: " << result.first 
                         << " (Frequency: " << result.second << ")" << endl;
                } else {
                    cout << "No valid marks entered." << endl;
                }
                break;
            }
            case 5: {
                continueProgram = false;
                cout << "Thanks for using this program!" << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
