#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    const int R = 7;
    int table[SIZE];

    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % SIZE;
        int h2 = R - (id % R);
        int index = h1;
        int j = 0;

        while (table[index] != -1 && j < SIZE) {
            j++;
            index = (h1 + j * h2) % SIZE;
        }

        if (j == SIZE) {
            cout << "Hash table is full. ID "
                 << id << " cannot be inserted.\n";
        } else {
            table[index] = id;
            cout << "Student ID " << id
                 << " assigned to slot " << index << endl;
        }
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            cout << "Slot " << i << ": Empty\n";
        else
            cout << "Slot " << i << ": " << table[i] << endl;
    }

    return 0;
}