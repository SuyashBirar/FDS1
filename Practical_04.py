# Function to perform Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function to perform Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Function to display the top 5 scores
def display_top_five(arr):
    top_five = arr[-5:] if len(arr) >= 5 else arr
    print("\nTop Five Scores:")
    for i, score in enumerate(reversed(top_five), start=1):
        print(f"{i}. {score:.2f}%")

# Main function
def main():
    # Input: Number of students and their first-year percentages
    n = int(input("Enter the number of students: "))
    percentages = []

    for i in range(n):
        score = float(input(f"Enter the percentage of student {i+1}: "))
        percentages.append(score)

    # Sorting and displaying top five scores using Selection Sort
    selection_sorted_percentages = percentages.copy()
    selection_sort(selection_sorted_percentages)
    print("\nScores sorted using Selection Sort:")
    print(selection_sorted_percentages)
    display_top_five(selection_sorted_percentages)

    # Sorting and displaying top five scores using Bubble Sort
    bubble_sorted_percentages = percentages.copy()
    bubble_sort(bubble_sorted_percentages)
    print("\nScores sorted using Bubble Sort:")
    print(bubble_sorted_percentages)
    display_top_five(bubble_sorted_percentages)

# Run the program
if __name__ == "__main__":
    main()
