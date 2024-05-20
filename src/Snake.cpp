//
// Created by Koen Seeuws on 20/05/2024.
//

#include "Snake.h"
#include <Coordinate.h>

Snake::Snake() : direction(RIGHT), length(2), coordinates(new Coordinate*[length])  {
    for (int x = 0; x < length; x++) {
        coordinates[x] = new Coordinate(x, 0);
    }
}

Snake::~Snake() {
    for (const Coordinate* coordinate: coordinates) {
        delete coordinate;
    }
    delete[] coordinates;
}

void Snake::turnLeft() {
    short value = direction - 1;
    if (value < RIGHT)
        value = UP;
    direction = static_cast<Direction>(value);
}

void Snake::turnRight() {
    short value = direction + 1;
    if (value > UP)
        value = RIGHT;
    direction = static_cast<Direction>(value);
}

void Snake::move() const {
    //TODO: TEST!
    const auto newCoordinates = new Coordinate*[length];

    for (unsigned int snakeSegment = 0; snakeSegment < length - 1; snakeSegment++) {
        newCoordinates[0] = coordinates[snakeSegment + 1];
    }

    const auto oldTail = coordinates[0];
    delete oldTail;

    Coordinate *newHead;
    const auto oldHead = coordinates[length - 1];
    switch (direction) {
        case RIGHT: newHead = new Coordinate(oldHead->getX() + 1, oldHead->getY());
            break;
        case DOWN: newHead = new Coordinate(oldHead->getX(), oldHead->getY() - 1);
            break;
        case LEFT: newHead = new Coordinate(oldHead->getX() - 1, oldHead->getY());
            break;
        case UP: newHead = new Coordinate(oldHead->getX(), oldHead->getY() + 1);
            break;
        default: newHead = new Coordinate(oldHead->getX(), oldHead->getY());
    }

    newCoordinates[length - 1] = newHead;

    delete[] coordinates;
    coordinates = newCoordinates;
}

Direction Snake::getDirection() {
    return direction;
}

Coordinate **Snake::getCoordinates() {
    return coordinates;
}
