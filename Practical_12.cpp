#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    
public:
    // Constructor to initialize the deque with given capacity
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    
    // Destructor to free memory
    ~Deque() {
        delete[] arr;
    }

    // Function to check if deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if deque is full
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    // Function to add an element at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front.\n";
            return;
        }
        
        if (front == -1) {  // If deque is empty
            front = 0;
            rear = 0;
        } else if (front == 0) {  // Wrap around to the end
            front = capacity - 1;
        } else {
            front--;  // Move front towards the beginning
        }
        
        arr[front] = value;
        cout << "Inserted " << value << " at the front.\n";
    }

    // Function to add an element at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear.\n";
            return;
        }
        
        if (front == -1) {  // If deque is empty
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {  // Wrap around to the beginning
            rear = 0;
        } else {
            rear++;  // Move rear towards the end
        }
        
        arr[rear] = value;
        cout << "Inserted " << value << " at the rear.\n";
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }
        
        cout << "Deleted " << arr[front] << " from the front.\n";
        
        if (front == rear) {  // If there's only one element left
            front = rear = -1;
        } else if (front == capacity - 1) {  // Wrap around to the beginning
            front = 0;
        } else {
            front++;  // Move front towards the end
        }
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }
        
        cout << "Deleted " << arr[rear] << " from the rear.\n";
        
        if (front == rear) {  // If there's only one element left
            front = rear = -1;
        } else if (rear == 0) {  // Wrap around to the end
            rear = capacity - 1;
        } else {
            rear--;  // Move rear towards the beginning
        }
    }

    // Function to display the elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        
        cout << "Deque elements: ";
        
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);  // Create a deque with capacity of 5 elements

    // Test the deque operations
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    
    dq.display();

    dq.deleteRear();
    dq.deleteFront();
    
    dq.display();

    dq.insertRear(30);
    dq.insertFront(1);
    dq.insertRear(40);
    
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    
    dq.display();

    return 0;
}
