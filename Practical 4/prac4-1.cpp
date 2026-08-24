#include <iostream>
using namespace std;

// Node represents one patient token
class Node
{
public:
    int token;
    Node* next;

    Node(int value)
    {
        token = value;
        next = nullptr;
    }
};

// Queue class
class PatientQueue
{
private:
    Node* front;
    Node* rear;
    int length;

public:

    // Constructor
    PatientQueue()
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
    }

    // Insert a critical patient at the front
    void insertFront(int token)
    {
        Node* newNode = new Node(token);

        // If queue is empty
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
    
        else
        {
            newNode->next = front;
            front = newNode;
        }

        length++;

        cout << "After inserting " << token
             << " at front: ";
        display();
    }

    // Insert a routine patient at the rear
    void insertRear(int token)
    {
        Node* newNode = new Node(token);

        // If queue is empty
        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        length++;

        cout << "After inserting " << token
             << " at rear: ";
        display();
    }

    // Insert a patient at a specific position
    void insertAtPosition(int token, int position)
    {
        // Position 1 means insertion at the front
        if (position <= 1)
        {
            insertFront(token);
            return;
        }

        // If position is greater than current length,
        // insert at the rear
        if (position > length + 1)
        {
            cout << "Position " << position
                 << " is greater than the current queue length."
                 << endl;

            cout << "Patient " << token
                 << " is inserted at the rear instead." << endl;

            insertRear(token);
            return;
        }

        Node* newNode = new Node(token);

        // Traverse to the node just before
        // the required position
        Node* current = front;

        for (int i = 1; i < position - 1; i++)
        {
            current = current->next;
        }

        // Insert new node between current
        // and current->next
        newNode->next = current->next;
        current->next = newNode;

        // If inserted at the end, update rear
        if (newNode->next == nullptr)
        {
            rear = newNode;
        }

        length++;

        cout << "After inserting " << token
             << " at position " << position << ": ";
        display();
    }

    // Display the complete queue
    void display()
    {
        Node* current = front;

        cout << "[ ";

        while (current != nullptr)
        {
            cout << current->token << " ";
            current = current->next;
        }

        cout << "]" << endl;
    }

    // Destructor to free memory
    ~PatientQueue()
    {
        Node* current = front;

        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    PatientQueue queue;

    int choice;
    int token;
    int position;

    int operations;

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 1; i <= operations; i++)
    {
        cout << "\nOperation " << i << endl;

        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Insert at Specific Position" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        cout << "Enter patient token: ";
        cin >> token;

        switch (choice)
        {
            case 1:
                queue.insertFront(token);
                break;

            case 2:
                queue.insertRear(token);
                break;

            case 3:
                cout << "Enter position: ";
                cin >> position;

                queue.insertAtPosition(token, position);
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    cout << "\nFinal Patient Queue: ";
    queue.display();

    return 0;
}