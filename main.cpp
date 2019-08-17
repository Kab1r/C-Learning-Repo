#include <iostream>
#include "Minefield.h"

using namespace std;
int main() {
    tuple<int, int> size = tuple(5, 5);

    Minefield minefield = Minefield(size);

    while (!minefield.getHasLost() && !minefield.hasWon()) {
        minefield.print();
        string action;
        while (action != "check" && action != "flag") {
            cout << "Select an action (check/flag): ";
            cin >> action;
            cout << endl;
        }
        int x = -1;
        while (x < 0 || x >= minefield.getWidth()) {
            cout << "Select an X-coordinate: ";
            cin >> x;
            cout << endl;
        }
        int y = -1;
        while (y < 0 || y >= minefield.getHeight()) {
            cout << "Select a Y-coordinate: ";
            cin >> y;
            cout << endl;
        }
        if (action == "check") {
            bool* state = minefield.check(x, y);
            if (state == nullptr)
                cout << "Location must not be flagged when checked." << endl;
        } else if (action == "flag") {
            minefield.flag(x, y);
        }

    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}