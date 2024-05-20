//
// Created by Koen Seeuws on 20/05/2024.
//

#ifndef SNAKE_H
#define SNAKE_H

#include <Direction.h>
#include <Coordinate.h>

class Snake {
private:
    Direction direction;
    Coordinate* coordinates[];

public:
    explicit Snake();

    void turnLeft();

    void turnRight();

    void move();

    Direction getDirection();

    Coordinate getCoordinates();
};

#endif //SNAKE_H