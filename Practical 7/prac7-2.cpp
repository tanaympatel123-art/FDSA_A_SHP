
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> patients;
    int operations;
    cin >> operations;

    while (operations--) {
        string operation;
        cin >> operation;

        if (operation == "arrive") {
            string name;
            cin >> name;
            patients.push(name);
        }
        else if (operation == "attend") {
            if (!patients.empty()) {
                patients.pop();
            }
            else {
                cout << "No patients waiting" << endl;
            }
        }

        if (!patients.empty()) {
            cout << "Front patient: " << patients.front() << endl;
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }

    return 0;
}
