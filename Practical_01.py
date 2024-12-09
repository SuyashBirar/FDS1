# Function for average score of the class
def average(listofmarks):
    total = 0
    count = 0
    for mark in listofmarks:
        if mark != -999:  # -999 represents an absent student
            total += mark
            count += 1
    avg = total / count if count != 0 else 0
    print("Total Marks : ", total)
    print("Average Marks : {:.2f}".format(avg))

# Function for highest score in the test for the class
def Maximum(listofmarks):
    max_score = None
    for mark in listofmarks:
        if mark != -999:  # skip absent students
            max_score = mark
            break
    for mark in listofmarks:
        if mark != -999 and mark > max_score:
            max_score = mark
    return max_score

# Function for lowest score in the test for the class
def Minimum(listofmarks):
    min_score = None
    for mark in listofmarks:
        if mark != -999:  # skip absent students
            min_score = mark
            break
    for mark in listofmarks:
        if mark != -999 and mark < min_score:
            min_score = mark
    return min_score

# Function for counting the number of students absent for the test
def absentcount(listofmarks):
    count = 0
    for mark in listofmarks:
        if mark == -999:
            count += 1
    return count

# Function for displaying marks with highest frequency
def maxFrequency(listofmarks):
    frequency_dict = {}
    for mark in listofmarks:
        if mark != -999:  # skip absent students
            frequency_dict[mark] = frequency_dict.get(mark, 0) + 1
    max_freq = max(frequency_dict.values()) if frequency_dict else 0
    most_frequent_mark = max(frequency_dict, key=frequency_dict.get) if frequency_dict else None
    print("Marks\t| Frequency")
    for mark, freq in frequency_dict.items():
        print(f"{mark}\t| {freq}")
    return most_frequent_mark, max_freq

# Main function
def main():
    marksinFDS = []
    numberofstudents = int(input("Enter total number of students: "))
    
    for i in range(numberofstudents):
        marks = int(input(f"Enter marks of student {i + 1} (-999 for absent): "))
        marksinFDS.append(marks)

    flag = 1
    while flag == 1:
        print("\n\n-------------------- MENU --------------------")
        print("1. Total and Average Marks of the Class")
        print("2. Highest and Lowest Marks in the Class")
        print("3. Number of Students Absent for the Test")
        print("4. Marks with Highest Frequency")
        print("5. Exit\n")

        choice = int(input("Enter your choice (from 1 to 5): "))
        
        if choice == 1:
            average(marksinFDS)
        elif choice == 2:
            print("Highest Score in Class : ", Maximum(marksinFDS))
            print("Lowest Score in Class : ", Minimum(marksinFDS))
        elif choice == 3:
            print("Number of Students Absent in the Test : ", absentcount(marksinFDS))
        elif choice == 4:
            mark, freq = maxFrequency(marksinFDS)
            if mark is not None:
                print(f"Highest frequency is of marks {mark}, appearing {freq} times.")
            else:
                print("No valid marks entered.")
        elif choice == 5:
            flag = 0
            print("Thanks for using this program!")
        else:
            print("!! Wrong Choice !!")
        
        if choice != 5:
            cont = input("Do you want to continue (yes/no): ").strip().lower()
            if cont == "no":
                flag = 0
                print("Thanks for using this program!")

# Run the main function
main()
