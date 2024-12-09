# Function to perform Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Function to perform Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Function to display the top five scores
def display_top_five_scores(arr):
    count = min(5, len(arr))  # Get the minimum of 5 or the array size
    print("\nTop 5 scores: ", end="")
    for i in range(count):
        print(arr[i], end=" ")
    print()

# Main function
def main():
    # Input number of students
    n = int(input("Enter the number of students: "))
    
    percentages = []
    
    # Input percentages of the students
    print("Enter the percentages of the students: ")
    for i in range(n):
        percentage = float(input(f"Student {i+1}: "))
        percentages.append(percentage)

    # Input choice for sorting method
    print("\nChoose a sorting method:")
    print("1. Insertion Sort")
    print("2. Shell Sort")
    choice = int(input("Enter your choice (1 or 2): "))

    # Sort and display the top 5 scores based on the user's choice
    if choice == 1:
        insertion_sort(percentages)
        print("\nScores after Insertion Sort: ", percentages)
        display_top_five_scores(percentages)
    elif choice == 2:
        shell_sort(percentages)
        print("\nScores after Shell Sort: ", percentages)
        display_top_five_scores(percentages)
    else:
        print("Invalid choice!")

# Run the main function
if __name__ == "__main__":
    main()
