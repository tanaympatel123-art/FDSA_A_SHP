#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 10;
    string slots[SIZE];

    for (int i = 0; i < SIZE; i++) {
        slots[i] = "";
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string reg;
        cout << "Enter registration number: ";
        cin >> reg;

        int index = reg.back() - '0';
        int start = index;

        while (slots[index] != "") {
            index = (index + 1) % SIZE;

            if (index == start) {
                cout << "Parking lot is full. Vehicle "
                     << reg << " cannot be parked.\n";
                break;
            }
        }

        if (slots[index] == "") {
            slots[index] = reg;
            cout << "Vehicle " << reg
                 << " parked at slot " << index << endl;
        }
    }

    cout << "\nFinal Parking Lot State:\n";

    for (int i = 0; i < SIZE; i++) {
        if (slots[i] == "")
            cout << "Slot " << i << ": Empty\n";
        else
            cout << "Slot " << i << ": " << slots[i] << endl;
    }

    return 0;
}