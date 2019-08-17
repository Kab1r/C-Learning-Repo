//
// Created by Kabir Kwatra on 2019-08-17.
//

#ifndef C_LEARNING_REPO_MINEFIELD_H
#define C_LEARNING_REPO_MINEFIELD_H

#include <list>
#include "Location.h"

using namespace std;

class Minefield {
private:
    list<list<Location>> grid;
    bool hasLost;

public:
    [[nodiscard]] bool getHasLost() const;

    [[nodiscard]] bool hasWon() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    void print() const;

    bool *check(int x, int y);

    bool flag(int x,int y) const;

    [[nodiscard]] string display(int x, int y) const;

    Minefield(int width, int height);

    explicit Minefield(tuple<int, int> size);

    [[nodiscard]] Location getLocation(int x, int y) const;
};


#endif //C_LEARNING_REPO_MINEFIELD_H
