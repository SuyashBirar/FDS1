#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* queue;
    int front, rear, capacity;
    
public:
    // Constructor to initialize the queue
    PizzaParlor(int m) {
        capacity = m;  // Max orders
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~PizzaParlor() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Place an order in the queue
    void placeOrder(int orderId) {
        if (isFull()) {
            cout << "Sorry, the parlor is full. Cannot accept more orders.\n";
            return;
        }

        if (front == -1) {  // If the queue is empty
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {  // Wrap around to the beginning
            rear = 0;
        } else {
            rear++;
        }

        queue[rear] = orderId;
        cout << "Order " << orderId << " has been placed.\n";
    }

    // Serve (remove) an order from the queue
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        int orderId = queue[front];
        cout << "Serving order " << orderId << ".\n";

        if (front == rear) {  // Only one order left
            front = rear = -1;
        } else if (front == capacity - 1) {  // Wrap around to the beginning
            front = 0;
        } else {
            front++;
        }
    }

    // Display the current orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);

    int choice, orderId;

    while (true) {
        cout << "\n----- Pizza Parlor Menu -----\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display current orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order ID: ";
                cin >> orderId;
                parlor.placeOrder(orderId);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
