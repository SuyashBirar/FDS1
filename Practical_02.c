#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to display the word with the longest length
void longestWord(char *str) {
    int maxLen = 0, len = 0;
    char *start = NULL, *end = NULL, *word = str;
    char longestWord[100];

    while (*word) {
        if (!isspace(*word)) {
            if (len == 0) start = word;
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
                strncpy(longestWord, start, len);
                longestWord[len] = '\0';
            }
            len = 0;
        }
        word++;
    }
    
    // Check last word
    if (len > maxLen) {
        strncpy(longestWord, start, len);
        longestWord[len] = '\0';
    }
    
    printf("Longest Word: %s\n", longestWord);
}

// Function to determine the frequency of occurrence of a particular character
void characterFrequency(char *str, char ch) {
    int count = 0;
    while (*str) {
        if (*str == ch) count++;
        str++;
    }
    printf("Frequency of '%c': %d\n", ch, count);
}

// Function to check if the string is a palindrome
void checkPalindrome(char *str) {
    int len = strlen(str);
    int isPalindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

// Function to find the index of the first occurrence of a substring
void findSubstring(char *str, char *substr) {
    char *pos = strstr(str, substr);
    if (pos)
        printf("Index of first occurrence of '%s': %ld\n", substr, pos - str);
    else
        printf("Substring not found.\n");
}

// Function to count occurrences of each word in the string
void wordFrequency(char *str) {
    char copy[500], *word, *token;
    int count[100] = {0};
    char *words[100];
    int wordCount = 0;

    strcpy(copy, str);
    word = strtok(copy, " ,.-\n");

    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[wordCount] = word;
            count[wordCount]++;
            wordCount++;
        }
        word = strtok(NULL, " ,.-\n");
    }

    printf("Word Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("'%s' : %d\n", words[i], count[i]);
    }
}

int main() {
    char str[500], ch, substr[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Removing newline character

    int choice;
    do {
        printf("\n----- MENU -----\n");
        printf("1. Display word with longest length\n");
        printf("2. Determine frequency of occurrence of a character\n");
        printf("3. Check if the string is a palindrome\n");
        printf("4. Display index of first substring occurrence\n");
        printf("5. Count occurrences of each word in the string\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from buffer

        switch (choice) {
            case 1:
                longestWord(str);
                break;
            case 2:
                printf("Enter character to find frequency: ");
                scanf("%c", &ch);
                characterFrequency(str, ch);
                break;
            case 3:
                checkPalindrome(str);
                break;
            case 4:
                printf("Enter substring to search: ");
                fgets(substr, sizeof(substr), stdin);
                substr[strcspn(substr, "\n")] = '\0';  // Remove newline character
                findSubstring(str, substr);
                break;
            case 5:
                wordFrequency(str);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
