#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[100];
    int top = -1;

    int operations;
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "place") {
            int tray;
            cin >> tray;

            if (top == n - 1) {
                cout << "Error: Stack is full" << endl;
            } else {
                top++;
                stack[top] = tray;
                cout << "Top tray: " << stack[top] << endl;
            }
        }
        else if (operation == "take") {
            if (top == -1) {
                cout << "Error: Stack is empty" << endl;
            } else {
                cout << "Top tray: " << stack[top] << endl;
                top--;
            }
        }
    }

    return 0;
}