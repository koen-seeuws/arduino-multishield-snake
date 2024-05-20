//
// Created by Koen Seeuws on 20/05/2024.
//

#include "Snake.h"
#include <Coordinate.h>

Snake::Snake() : direction(RIGHT){
    coordinates[0] = new Coordinate(0,0);
    coordinates[1] = new Coordinate(1,0);
}

void Snake::turnLeft(){
    short value = direction - 1;
    if (value < UP)
        value = LEFT;
    direction = static_cast<Direction>(value);
}

void Snake::turnRight(){
    short value = direction + 1;
    if (value > LEFT)
        value = UP;
    direction = static_cast<Direction>(value);
}

void Snake::move() {
    auto snakeLength = sizeof(&coordinates) - 1;

    //TODO: implement moving logic
}

Direction Snake::getDirection(){
    return direction;
}

Coordinate **Snake::getCoordinates(){
    return coordinates;
}