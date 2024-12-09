def longest_word(sentence):
    words = sentence.split()
    longest = max(words, key=len)
    print("Word with the longest length:", longest)


def char_frequency(sentence, char):
    frequency = sentence.count(char)
    print(f"Frequency of '{char}' in the string:", frequency)


def is_palindrome(sentence):
    # Removing spaces and converting to lowercase for palindrome check
    normalized_sentence = ''.join(sentence.split()).lower()
    if normalized_sentence == normalized_sentence[::-1]:
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")


def first_substring_index(sentence, substring):
    index = sentence.find(substring)
    if index != -1:
        print(f"The index of the first occurrence of '{substring}':", index)
    else:
        print(f"'{substring}' not found in the string.")


def word_occurrences(sentence):
    words = sentence.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    print("Occurrences of each word:")
    for word, count in word_count.items():
        print(f"{word}: {count}")


# Main function to interact with the user and demonstrate each function
def main():
    sentence = input("Enter a string: ")
    
    # Display word with the longest length
    longest_word(sentence)
    
    # Determine frequency of a particular character
    char = input("Enter a character to find its frequency: ")
    char_frequency(sentence, char)
    
    # Check if the string is a palindrome
    is_palindrome(sentence)
    
    # Display index of first occurrence of a substring
    substring = input("Enter a substring to find its first occurrence index: ")
    first_substring_index(sentence, substring)
    
    # Count occurrences of each word in the string
    word_occurrences(sentence)

# Run the main function
main()
