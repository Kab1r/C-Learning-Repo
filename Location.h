//
// Created by Kabir Kwatra on 2019-08-17.
//

#ifndef C_LEARNING_REPO_LOCATION_H
#define C_LEARNING_REPO_LOCATION_H

#include <string>

using namespace std;

class Location {
private:
    bool isMine;
    bool isFlagged;
    bool isChecked;
public:
    explicit Location(bool isMine);

    bool invertFlag();

    bool *check();

    [[nodiscard]] bool getIsChecked() const;

    [[nodiscard]] bool getIsFlagged() const;

    [[nodiscard]] string display() const;
};


#endif //C_LEARNING_REPO_LOCATION_H
