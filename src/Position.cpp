//
// Created by Koen Seeuws on 20/05/2024.
//

#include <Position.h>

Position::Position(const int x, const int y) : x(x), y(y), snake(nullptr) {
};

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

Snake *Position::getSnake() const {
    return snake;
}

void Position::setSnake(Snake *snake) {
    this->snake = snake;
}
