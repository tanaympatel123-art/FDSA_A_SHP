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

// Patient Queue implemented using a singly linked list
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

    // Insert a patient at the front
    void insertFront(int token)
    {
        Node* newNode = new Node(token);

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
    }

    // Insert a patient at the rear
    void insertRear(int token)
    {
        Node* newNode = new Node(token);

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
    }

    // Insert at a specific position
    void insertAtPosition(int token, int position)
    {
        // Position 1 means front
        if (position <= 1)
        {
            insertFront(token);
            return;
        }

        // Position greater than length + 1
        // is handled by inserting at rear
        if (position > length + 1)
        {
            cout << "Position is greater than the queue length."
                 << endl;
            cout << "Inserting at rear instead." << endl;

            insertRear(token);
            return;
        }

        Node* newNode = new Node(token);

        Node* current = front;

        // Move to the node before the required position
        for (int i = 1; i < position - 1; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        // If inserted at the end, update rear
        if (newNode->next == nullptr)
        {
            rear = newNode;
        }

        length++;
    }

    // Delete the first patient with the given token
    void deleteByValue(int token)
    {
        // Queue is empty
        if (front == nullptr)
        {
            cout << "Queue is empty. Nothing to delete."
                 << endl;
            return;
        }

        // If the front node contains the token
        if (front->token == token)
        {
            Node* temp = front;

            front = front->next;

            delete temp;

            length--;

            // If queue becomes empty
            if (front == nullptr)
            {
                rear = nullptr;
            }

            cout << "Patient " << token
                 << " deleted successfully." << endl;

            return;
        }

        // Search for the node
        // containing the required token
        Node* current = front;

        while (current->next != nullptr &&
               current->next->token != token)
        {
            current = current->next;
        }

        // Token was not found
        if (current->next == nullptr)
        {
            cout << "Patient " << token
                 << " was not found in the queue."
                 << endl;
            return;
        }

        // Node to be deleted
        Node* temp = current->next;

        // Skip the node
        current->next = temp->next;

        // If deleting the rear node
        if (temp == rear)
        {
            rear = current;
        }

        delete temp;

        length--;

        cout << "Patient " << token
             << " deleted successfully." << endl;
    }

    // Forward traversal
    // Prints from front to rear
    void displayForward()
    {
        cout << "Queue from front to back: ";

        Node* current = front;

        cout << "[ ";

        while (current != nullptr)
        {
            cout << current->token << " ";
            current = current->next;
        }

        cout << "]" << endl;
    }

    // Recursive reverse printing
    void displayReverse(Node* current)
    {
        // Base case
        if (current == nullptr)
        {
            return;
        }

        // First move toward the end
        displayReverse(current->next);

        // Print while returning
        cout << current->token << " ";
    }

    // Public function for reverse printing
    void reversePrint()
    {
        cout << "Queue from back to front: [ ";

        displayReverse(front);

        cout << "]" << endl;
    }

    // Get front node
    Node* getFront()
    {
        return front;
    }

    // Destructor
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
        cout << "4. Delete by Value" << endl;
        cout << "5. Display Forward" << endl;
        cout << "6. Display Reverse" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter patient token: ";
                cin >> token;

                queue.insertFront(token);

                queue.displayForward();
                break;

            case 2:
                cout << "Enter patient token: ";
                cin >> token;

                queue.insertRear(token);

                queue.displayForward();
                break;

            case 3:
                cout << "Enter patient token: ";
                cin >> token;

                cout << "Enter position: ";
                cin >> position;

                queue.insertAtPosition(token, position);

                queue.displayForward();
                break;

            case 4:
                cout << "Enter patient token to delete: ";
                cin >> token;

                queue.deleteByValue(token);

                queue.displayForward();
                break;

            case 5:
                queue.displayForward();
                break;

            case 6:
                queue.reversePrint();
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    cout << "\nFinal Queue:" << endl;

    queue.displayForward();

    queue.reversePrint();

    return 0;
}