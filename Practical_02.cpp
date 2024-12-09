#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

// Function to find and display the word with the longest length
string longestWord(const string& str) {
    istringstream stream(str);
    string word, longest;
    while (stream >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }
    return longest;
}

// Function to determine the frequency of occurrence of a particular character
int charFrequency(const string& str, char ch) {
    int frequency = 0;
    for (char c : str) {
        if (c == ch) {
            frequency++;
        }
    }
    return frequency;
}

// Function to check if a given string is a palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to display the index of the first occurrence of a substring
int indexOfSubstring(const string& str, const string& substring) {
    return str.find(substring);
}

// Function to count occurrences of each word in the string
map<string, int> wordCount(const string& str) {
    istringstream stream(str);
    string word;
    map<string, int> wordFreq;
    while (stream >> word) {
        wordFreq[word]++;
    }
    return wordFreq;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int choice;
    bool continueProgram = true;
    while (continueProgram) {
        cout << "\n------ MENU ------" << endl;
        cout << "1. Display word with the longest length" << endl;
        cout << "2. Determine frequency of a particular character" << endl;
        cout << "3. Check if the string is a palindrome" << endl;
        cout << "4. Display index of the first occurrence of a substring" << endl;
        cout << "5. Count occurrences of each word in the string" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string longest = longestWord(str);
                cout << "Longest word: " << longest << endl;
                break;
            }
            case 2: {
                char ch;
                cout << "Enter character to find its frequency: ";
                cin >> ch;
                int frequency = charFrequency(str, ch);
                cout << "Frequency of '" << ch << "': " << frequency << endl;
                break;
            }
            case 3: {
                bool palindrome = isPalindrome(str);
                if (palindrome) {
                    cout << "The string is a palindrome." << endl;
                } else {
                    cout << "The string is not a palindrome." << endl;
                }
                break;
            }
            case 4: {
                string substring;
                cout << "Enter the substring to find: ";
                cin.ignore();
                getline(cin, substring);
                int index = indexOfSubstring(str, substring);
                if (index != string::npos) {
                    cout << "Index of first occurrence of substring: " << index << endl;
                } else {
                    cout << "Substring not found." << endl;
                }
                break;
            }
            case 5: {
                map<string, int> wordFreq = wordCount(str);
                cout << "Word occurrences:" << endl;
                for (const auto& pair : wordFreq) {
                    cout << pair.first << ": " << pair.second << endl;
                }
                break;
            }
            case 6: {
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
