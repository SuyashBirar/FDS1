#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Appointment {
    string name;         // Name of the person
    int startTime;       // Start time in minutes (e.g., 9:00 AM = 540 minutes)
    int endTime;         // End time in minutes (e.g., 10:00 AM = 600 minutes)
    Appointment* next;   // Pointer to the next appointment in the list

    Appointment(string n, int sTime, int eTime)
        : name(n), startTime(sTime), endTime(eTime), next(nullptr) {}
};

class AppointmentSchedule {
private:
    Appointment* head;  // Head of the linked list

public:
    AppointmentSchedule() : head(nullptr) {}

    // Function to display the free slots
    void displayFreeSlots(int dayStart, int dayEnd, int minDuration, int maxDuration) {
        cout << "Free slots available for today:\n";
        Appointment* current = head;
        int prevEnd = dayStart;  // Start from the beginning of the day

        while (current != nullptr) {
            // Check if there is a gap between previous appointment's end and the current one
            if (current->startTime - prevEnd >= minDuration) {
                cout << "Free Slot: " << formatTime(prevEnd) << " - " << formatTime(current->startTime) << endl;
            }
            prevEnd = current->endTime; // Update the end time after each appointment
            current = current->next;
        }

        // Check the remaining time after the last appointment
        if (dayEnd - prevEnd >= minDuration) {
            cout << "Free Slot: " << formatTime(prevEnd) << " - " << formatTime(dayEnd) << endl;
        }
    }

    // Function to book an appointment
    bool bookAppointment(string name, int startTime, int duration) {
        int endTime = startTime + duration;
        Appointment* newAppointment = new Appointment(name, startTime, endTime);

        // Check availability
        if (!isTimeAvailable(startTime, endTime)) {
            cout << "Time slot not available.\n";
            delete newAppointment;
            return false;
        }

        // Insert the new appointment in sorted order based on start time
        if (head == nullptr || head->startTime > startTime) {
            newAppointment->next = head;
            head = newAppointment;
            cout << "Appointment booked for " << name << " at " << formatTime(startTime) << " to " << formatTime(endTime) << endl;
            return true;
        }

        Appointment* current = head;
        while (current->next != nullptr && current->next->startTime < startTime) {
            current = current->next;
        }

        newAppointment->next = current->next;
        current->next = newAppointment;

        cout << "Appointment booked for " << name << " at " << formatTime(startTime) << " to " << formatTime(endTime) << endl;
        return true;
    }

    // Function to sort appointments based on start time
    void sortAppointments() {
        if (head == nullptr || head->next == nullptr) return;  // List is empty or has only one element

        // Using bubble sort to sort the appointments
        for (Appointment* i = head; i != nullptr; i = i->next) {
            for (Appointment* j = i->next; j != nullptr; j = j->next) {
                if (i->startTime > j->startTime) {
                    swap(i->startTime, j->startTime);
                    swap(i->endTime, j->endTime);
                    swap(i->name, j->name);
                }
            }
        }
    }

    // Function to cancel an appointment
    bool cancelAppointment(string name, int startTime) {
        if (head == nullptr) {
            cout << "No appointments to cancel.\n";
            return false;
        }

        Appointment* current = head;
        Appointment* prev = nullptr;

        while (current != nullptr) {
            if (current->name == name && current->startTime == startTime) {
                if (prev == nullptr) {
                    head = current->next; // Remove the head appointment
                } else {
                    prev->next = current->next; // Remove the appointment in the middle
                }
                delete current;
                cout << "Appointment for " << name << " at " << formatTime(startTime) << " has been canceled.\n";
                return true;
            }
            prev = current;
            current = current->next;
        }

        cout << "Appointment not found.\n";
        return false;
    }

    // Function to display all appointments
    void displayAppointments() {
        if (head == nullptr) {
            cout << "No appointments booked.\n";
            return;
        }

        cout << "Scheduled Appointments:\n";
        Appointment* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Start Time: " << formatTime(current->startTime) << ", End Time: " << formatTime(current->endTime) << endl;
            current = current->next;
        }
    }

    // Function to format time from minutes (e.g., 540 minutes = 9:00 AM)
    string formatTime(int minutes) {
        int hour = minutes / 60;
        int min = minutes % 60;
        stringstream time;
        time << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << min;
        return time.str();
    }

private:
    // Helper function to check if the time slot is available
    bool isTimeAvailable(int startTime, int endTime) {
        Appointment* current = head;
        while (current != nullptr) {
            if ((startTime < current->endTime && startTime >= current->startTime) || (endTime > current->startTime && endTime <= current->endTime)) {
                return false; // Time slot is not available
            }
            current = current->next;
        }
        return true;
    }
};

int main() {
    AppointmentSchedule schedule;
    int dayStart = 540;  // 9:00 AM in minutes
    int dayEnd = 1020;   // 5:00 PM in minutes

    // Booking appointments
    schedule.bookAppointment("John Doe", 540, 30);  // 9:00 AM - 9:30 AM
    schedule.bookAppointment("Jane Smith", 600, 60); // 10:00 AM - 11:00 AM
    schedule.bookAppointment("Mike Johnson", 660, 45); // 11:00 AM - 11:45 AM

    // Display all appointments
    schedule.displayAppointments();

    // Display free slots
    schedule.displayFreeSlots(dayStart, dayEnd, 30, 60);

    // Cancel an appointment
    schedule.cancelAppointment("Mike Johnson", 660);  // Cancel the 11:00 AM appointment

    // Display all appointments after cancellation
    schedule.displayAppointments();

    // Sort appointments and display
    schedule.sortAppointments();
    cout << "\nAppointments after sorting:\n";
    schedule.displayAppointments();

    return 0;
}
