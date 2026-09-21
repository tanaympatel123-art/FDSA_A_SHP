#include <iostream>
#include <string>
using namespace std;

// Node of Doubly Linked List
class Node
{
public:
    string song;
    Node* prev;
    Node* next;

    Node(string name)
    {
        song = name;
        prev = nullptr;
        next = nullptr;
    }
};

// Playlist class
class Playlist
{
private:
    Node* head;
    Node* tail;
    int count;

public:

    // Constructor
    Playlist()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Add song at beginning
    void addBeginning(string name)
    {
        Node* newNode = new Node(name);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
        display();
    }

    // Add song at end
    void addEnd(string name)
    {
        Node* newNode = new Node(name);

        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
        display();
    }

    // Insert song after a specific song
    void insertAfter(string existingSong, string newSong)
    {
        Node* current = head;

        // Search for the existing song
        while (current != nullptr && current->song != existingSong)
        {
            current = current->next;
        }

        // Song not found
        if (current == nullptr)
        {
            cout << "Song \"" << existingSong << "\" not found.\n";
            display();
            return;
        }

        Node* newNode = new Node(newSong);

        // Connect new node with current node
        newNode->prev = current;
        newNode->next = current->next;

        // If current is not the last node,
        // update the next node's prev pointer
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        else
        {
            // New node becomes the tail
            tail = newNode;
        }

        // Connect current node to new node
        current->next = newNode;

        count++;

        display();
    }

    // Remove first song
    void removeFirst()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            display();
            return;
        }

        Node* temp = head;

        // If only one song exists
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        count--;

        display();
    }

    // Count songs
    void displayCount()
    {
        cout << "Number of songs: " << count << endl;
    }

    // Display playlist from first to last
    void display()
    {
        cout << "Playlist: ";

        Node* current = head;

        if (current == nullptr)
        {
            cout << "Empty";
        }

        while (current != nullptr)
        {
            cout << current->song;

            if (current->next != nullptr)
            {
                cout << " <-> ";
            }

            current = current->next;
        }

        cout << endl;
        cout << "Number of songs: " << count << endl;
        cout << "-----------------------------\n";
    }

    // Destructor
    ~Playlist()
    {
        Node* current = head;

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
    Playlist playlist;

    playlist.addBeginning("Song A");

    playlist.addEnd("Song B");

    playlist.addEnd("Song C");

    playlist.insertAfter("Song B", "Song X");

    playlist.insertAfter("Song C", "Song D");

    playlist.insertAfter("Song Z", "Song Y");

    playlist.removeFirst();

    return 0;
}