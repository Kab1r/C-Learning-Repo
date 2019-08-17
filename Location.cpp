//
// Created by Kabir Kwatra on 2019-08-17.
//

#include "Location.h"

Location::Location(bool isMine) {
    this->isMine = isMine;
    this->isFlagged = false;
    this->isChecked = false;
}


bool Location::invertFlag() {
    return this->isFlagged = !this->isFlagged;
}

bool *Location::check() {
    if (this->isFlagged)
        return nullptr;

    this->isChecked = true;
    return reinterpret_cast<bool *>(this->isMine);
}

bool Location::getIsFlagged() const {
    return isFlagged;
}

bool Location::getIsChecked() const {
    return isChecked;
}

string Location::display() const { // TODO: Change to have number for neighbor count
    if (this->isChecked) return (this->isMine) ? "\\uD83D\\uDCA3" : "□";
    return (this->isFlagged) ? "⛳" : "▧";
}


