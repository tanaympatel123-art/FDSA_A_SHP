#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    const int SIZE = 10;
    vector<stack<int>> shelves(SIZE);

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cout << "Enter book code: ";
        cin >> code;

        int index = code % SIZE;
        shelves[index].push(code);

        cout << "Book " << code
             << " placed on shelf " << index << endl;
    }

    cout << "\nFinal Shelf Contents:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            stack<int> temp = shelves[i];

            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        }

        cout << endl;
    }

    return 0;
}