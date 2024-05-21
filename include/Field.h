//
// Created by Koen Seeuws on 21/05/2024.
//

#ifndef FIELD_H
#define FIELD_H

#include <Position.h>

class Field {
private:
    int width;
    int height;
    mutable Position ***positions;

public:
    explicit Field(int width, int height);

    ~Field();

    Position *getPosition(int x, int y) const;

    int getWidth() const;

    int getHeight() const;
};

#endif //FIELD_H
