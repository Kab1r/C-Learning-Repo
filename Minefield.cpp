//
// Created by Kabir Kwatra on 2019-08-17.
//

#include <iostream>
#include "Minefield.h"

int Minefield::getWidth() const {
    return (*next(grid.begin(), 0)).size();
}

int Minefield::getHeight() const {
    return this->grid.size();
}

Minefield::Minefield(int width, int height) {
    list<Location> temp_row;
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            temp_row.push_front(Location(false));
        }
        this->grid.push_front(temp_row);
        temp_row = list<Location>();
    }
    this->hasLost = false;
}

bool *Minefield::check(int x, int y) {
    Location location = this->getLocation(x, y);
    bool *check = location.check();
    if (check != nullptr && !hasLost)
        hasLost = check;
    return check;
}

string Minefield::display(int x, int y) const {
    return this->getLocation(x, y).display();

}

Minefield::Minefield(tuple<int, int> size) : Minefield(get<0>(size), get<1>(size)) {}

bool Minefield::getHasLost() const {
    return hasLost;
}

Location Minefield::getLocation(int x, int y) const {
    auto row = *next(this->grid.begin(), x);
    return *next(row.begin(), y);
}


void Minefield::print() const {
    int height = this->getHeight();
    int width = this->getWidth();
    for (int r = -1; r <= height; ++r) { // Each Row
        for (int c = -1; c <= width; ++c) { // Each Col

            if (r == -1 || r == height) { // Top/Bottom Sides
                if (c == -1 || c == width) { // Corners
                    cout << "■";
                } else { // Top/Bottom Borders
                    cout << "▬▬▬";
                }
            } else if (c == -1) { // Left Side
                cout << "⎸";
            } else if (c == width) { // Right Side
                cout << "⎹";
            } else { // Non-Edges
                cout << " " + this->display(c, r) + " ";
            }
        }
        cout << "\n";
    }
}

bool Minefield::hasWon() const {
    for (int r = 0; r < this->getHeight(); ++r) {
        for (int c = 0; c < this->getWidth(); ++c) {
            Location location = this->getLocation(c, r);
            if (!(location.getIsChecked() || location.getIsFlagged())) return false;
            // TODO: Additional Verification for flagged locations (need to be bombs)
        }
    }
    return true;
}

bool Minefield::flag(int x, int y) const {
    return this->getLocation(x, y).invertFlag();
}

