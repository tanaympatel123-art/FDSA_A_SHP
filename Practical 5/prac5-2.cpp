#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node* next;

    Node(string n)
    {
        name = n;
        next = nullptr;
    }
};

class SinglyCircular
{
private:
    Node* head;
    int count;

public:

    SinglyCircular()
    {
        head = nullptr;
        count = 0;
    }

    // Insert at beginning
    void insertBeginning(string name)
    {
        Node* newNode = new Node(name);

        // Empty circle
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* last = head;

            // Find last node
            while (last->next != head)
            {
                last = last->next;
            }

            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }

        count++;
        display();
    }

    // Insert at end
    void insertEnd(string name)
    {
        Node* newNode = new Node(name);

        // Empty circle
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            last->next = newNode;
            newNode->next = head;
        }

        count++;
        display();
    }

    // Insert after a particular student
    void insertAfter(string student, string newStudent)
    {
        if (head == nullptr)
        {
            cout << "Circle is empty.\n";
            display();
            return;
        }

        Node* current = head;

        do
        {
            if (current->name == student)
            {
                Node* newNode = new Node(newStudent);

                newNode->next = current->next;
                current->next = newNode;

                count++;
                display();
                return;
            }

            current = current->next;

        } while (current != head);

        cout << "Student \"" << student << "\" not found.\n";
        display();
    }

    // Remove a student
    void remove(string student)
    {
        if (head == nullptr)
        {
            cout << "Circle is empty.\n";
            display();
            return;
        }

        // Only one student
        if (head->name == student && head->next == head)
        {
            delete head;
            head = nullptr;
            count = 0;

            display();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        do
        {
            if (current->name == student)
            {
                // If deleting head
                if (current == head)
                {
                    Node* last = head;

                    while (last->next != head)
                    {
                        last = last->next;
                    }

                    head = head->next;
                    last->next = head;

                    delete current;
                }
                else
                {
                    previous->next = current->next;
                    delete current;
                }

                count--;
                display();
                return;
            }

            previous = current;
            current = current->next;

        } while (current != head);

        cout << "Student \"" << student << "\" not found.\n";
        display();
    }

    // Display circle
    void display()
    {
        cout << "Singly Circular: ";

        if (head == nullptr)
        {
            cout << "Empty\n";
            cout << "--------------------------\n";
            return;
        }

        Node* current = head;

        do
        {
            cout << current->name;
            current = current->next;

            if (current != head)
                cout << " -> ";

        } while (current != head);

        cout << " -> HEAD\n";

        cout << "Students: " << count << endl;
        cout << "--------------------------\n";
    }

    ~SinglyCircular()
    {
        if (head == nullptr)
            return;

        Node* current = head->next;

        while (current != head)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
    }
};


int main()
{
    SinglyCircular circle;

    circle.insertEnd("A");
    circle.insertEnd("B");
    circle.insertEnd("C");

    circle.insertBeginning("X");

    circle.insertAfter("B", "Y");

    circle.remove("B");

    circle.remove("X");

    circle.remove("A");

    return 0;
}