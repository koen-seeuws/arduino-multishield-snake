//
// Created by Koen Seeuws on 20/05/2024.
//

#ifndef COORDINATE_H
#define COORDINATE_H

class Snake;

class Position {
private:
    int x, y;
    mutable Snake *snake;

public:
    Position(int x, int y);

    int getX() const;
    int getY() const;

    Snake *getSnake() const;
    void setSnake(Snake *snake);
};

#endif //COORDINATE_H