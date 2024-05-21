//
// Created by Koen Seeuws on 20/05/2024.
//

#ifndef SNAKE_H
#define SNAKE_H

#include <Direction.h>
#include <Field.h>
#include <Position.h>

class Snake {
private:
    Direction direction;
    int length;
    Field *field;
    mutable Position **positions;

public:
    explicit Snake(Field *field);

    ~Snake();

    void turnLeft();

    void turnRight();

    bool move() const;

    Direction getDirection() const;

    int getLength() const;

    Position **getPostions() const;
};

#endif //SNAKE_H
