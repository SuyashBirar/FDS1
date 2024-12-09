# Function to perform Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# Function to display the top five scores
def display_top_five_scores(arr):
    top_five = arr[:5]
    print("\nTop 5 scores:")
    for score in top_five:
        print(score)

def main():
    n = int(input("Enter the number of students: "))

    percentages = []
    
    # Input the percentages of students
    print("Enter the percentages of the students: ")
    for i in range(n):
        percentage = float(input(f"Student {i + 1}: "))
        percentages.append(percentage)

    # Sort the array using Quick Sort
    sorted_percentages = quick_sort(percentages)
    
    # Display sorted percentages
    print("\nSorted percentages: ")
    print(sorted_percentages)

    # Display the top five scores
    display_top_five_scores(sorted_percentages)

if __name__ == "__main__":
    main()
