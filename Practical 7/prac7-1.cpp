
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int n) {
        capacity = n;
        arr = new int[n];
        front = -1;
        rear = -1;
        size = 0;
    }

    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        if (size == 0) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = token;
        size++;

        printFront();
    }

    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Served token: " << arr[front] << endl;

        if (size == 1) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;

        printFront();
    }

    void printFront() {
        if (size == 0) {
            cout << "Front token: None" << endl;
        } else {
            cout << "Front token: " << arr[front] << endl;
        }
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    int n, operations;
    cout<<"Enter the capacity of queue and number of operations to be performed:";
    cin >> n >> operations;

    if (n <= 0) {
        cout << "Invalid capacity" << endl;
        return 0;
    }

    CircularQueue q(n);

    for (int i = 0; i < operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "JOIN") {
            int token;
            cin >> token;
            q.join(token);
        } else if (operation == "SERVE") {
            q.serve();
        } else {
            cout << "Error: Invalid operation" << endl;
        }
    }

    return 0;
}
