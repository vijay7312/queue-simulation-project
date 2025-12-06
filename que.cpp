#include <iostream>
using namespace std;

#define MAX 100   // maximum queue size

int queueArr[MAX];
int frontIdx = -1;
int rearIdx = -1;

// Check if queue is empty
bool isEmpty() {
    return (frontIdx == -1 && rearIdx == -1);
}

// Check if queue is full
bool isFull(int size) {
    return (rearIdx == size - 1);
}

// Insert element in queue
void enqueue(int size, int value) {
    if (isFull(size)) {
        cout << "Queue is FULL. Cannot insert.\n";
        return;
    }
    if (isEmpty()) {
        frontIdx = 0;
        rearIdx = 0;
    } else {
        rearIdx++;
    }
    queueArr[rearIdx] = value;
    cout << value << " inserted.\n";
}

// Remove element from queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY. Nothing to delete.\n";
        return;
    }
    int removed = queueArr[frontIdx];

    if (frontIdx == rearIdx) {
        // Only one element
        frontIdx = rearIdx = -1;
    } else {
        frontIdx++;
    }

    cout << removed << " removed.\n";
}

// Return front element
void front() {
    if (isEmpty()) {
        cout << "Queue is EMPTY.\n";
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}

// Return rear element
void rear() {
    if (isEmpty()) {
        cout << "Queue is EMPTY.\n";
        return;
    }
    cout << "Rear element: " << queueArr[rearIdx] << endl;
}

// Display queue elements
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = frontIdx; i <= rearIdx; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter queue size (max 100): ";
    cin >> size;

    int choice, value;

    do {
        cout << "\n--- Queue Simulation Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(size, value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                front();
                break;

            case 4:
                rear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}