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
    mutable bool isDead;
public:
    explicit Snake(int length, Field *field);

    ~Snake();

    void turnLeft();

    void turnRight();

    void move() const;

    Direction getDirection() const;

    int getLength() const;

    Position **getPostions() const;

    bool getIsDead() const;
};

#endif //SNAKE_H
