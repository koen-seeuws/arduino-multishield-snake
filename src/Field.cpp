//
// Created by Koen Seeuws on 21/05/2024.
//

#include <Field.h>

Field::Field(const int width, const int height) : width(width), height(height), positions(new Position **[width]) {
    for (int x = 0; x < width; x++) {
        positions[x] = new Position *[height];
        for (int y = 0; y < height; y++) {
            positions[x][y] = new Position(x, y);
        }
    }
}

Field::~Field() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            delete positions[x][y];
        }
        delete[] positions[x];
    }
    delete[] positions;
}

Position *Field::getPosition(const int x, const int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return nullptr; // or throw an exception
    }
    return positions[x][y];
}

int Field::getWidth() const {
    return width;
}

int Field::getHeight() const {
    return height;
}
