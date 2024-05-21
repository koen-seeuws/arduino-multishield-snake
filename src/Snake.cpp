//
// Created by Koen Seeuws on 20/05/2024.
//

#include <Snake.h>
#include <Position.h>

Snake::Snake(const int length, Field *field) : direction(RIGHT), length(length), field(field), positions(new Position *[length]), isDead(false) {
    for (int x = 0; x < length; x++) {
        const auto position = field->getPosition(x, 0);
        positions[x] = position;
        position->setSnake(this);
    }
}

Snake::~Snake() {
    delete[] positions;
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
    if(isDead) return;

    auto newPositions = new Position *[length];

    // Shift the snake's body positions
    for (int snakeSegment = 0; snakeSegment < length - 1; ++snakeSegment) {
        newPositions[snakeSegment] = positions[snakeSegment + 1];
    }

    // Get the head position
    auto oldHead = positions[length - 1];
    int x = oldHead->getX(), y = oldHead->getY();

    // Determine the new head position based on the current direction
    switch (direction) {
        case RIGHT: x += 1;
            break;
        case DOWN: y -= 1;
            break;
        case LEFT: x -= 1;
            break;
        case UP: y += 1;
            break;
    }

    // Check for collision with the barrier
    if (x < 0 || x >= field->getWidth() || y < 0 || y >= field->getHeight()) {
        isDead = true;
    }

    // Get the new head position from the field
    const auto newHead = field->getPosition(x, y);

    // Check for collision with itself
    if (newHead->getSnake() != nullptr) {
        isDead = true;
    }

    // Update the snake pointers in the field positions
    positions[0]->setSnake(nullptr);  // Remove snake from old tail
    newHead->setSnake(const_cast<Snake *>(this)); // Set snake to new head
    newPositions[length - 1] = newHead;

    delete[] positions;
    positions = newPositions;
}

Direction Snake::getDirection() const {
    return direction;
}

int Snake::getLength() const {
    return length;
}

Position **Snake::getPostions() const {
    return positions;
}

bool Snake::getIsDead() const {
    return isDead;
}

