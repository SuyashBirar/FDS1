#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;  // Declare only 'head'

    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}  // Initialize head to nullptr

    // Add a node at the beginning of the list
    void addBegin(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    // Add a node at the end of the list
    void addEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add a node at a specific position in the list
    void addAtPosition(int val, int pos) {
        Node* newNode = new Node();
        newNode->data = val;
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove the node from the beginning of the list
    void removeBegin() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove the node from the end of the list
    void removeEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Remove a node by its key (data value)
    void removeKey(int key) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Key not found" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n1. Add at Begin\n";
    cout << "2. Add at End\n";
    cout << "3. Add at Position\n";
    cout << "4. Remove Begin\n";
    cout << "5. Remove End\n";
    cout << "6. Remove by Key\n";
    cout << "7. Print List\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    LinkedList list;
    int choice, value, position;

    // Infinite loop to display menu and execute choices
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to add at Begin: ";
            cin >> value;
            list.addBegin(value);
            break;
        case 2:
            cout << "Enter value to add at End: ";
            cin >> value;
            list.addEnd(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> position;
            list.addAtPosition(value, position);
            break;
        case 4:
            list.removeBegin();
            break;
        case 5:
            list.removeEnd();
            break;
        case 6:
            cout << "Enter key to remove: ";
            cin >> value;
            list.removeKey(value);
            break;
        case 7:
            list.printList();
            break;
        case 8:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option, try again.\n";
        }
    }

    return 0;
}
