#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> history;

    int operations;
    cin >> operations;

    string currentPage = "Home";

    for (int i = 0; i < operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "visit") {
            string page;
            cin >> page;

            history.push_back(currentPage);
            currentPage = page;

            cout << "Current page: " << currentPage << endl;
        }
        else if (operation == "back") {
            if (history.empty()) {
                cout << "Error: No history available" << endl;
            } else {
                currentPage = history.back();
                history.pop_back();

                cout << "Current page: " << currentPage << endl;
            }
        }
    }

    return 0;
}