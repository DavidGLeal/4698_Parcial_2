#pragma once
#include <string>
#include <sstream>

class Coordinate {
public:
    Coordinate() = default;
    
    Coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    static Coordinate transform(Coordinate origin, int shiftX, int shiftY) {
        return Coordinate(origin.getX() + shiftX, origin.getY() + shiftY);
    }

    void transform(int shiftX, int shiftY) {
        x = x + shiftX;
        y = y + shiftY;
    }

    std::string toString() {
        return (std::stringstream() << "(" << x << ", " << y << ")").str();
    }

    bool equals(Coordinate target) {
        return target.getX() == getX() && target.getY() == getY();
    }

    bool operator ==(Coordinate target) {
        return equals(target);
    }

private:
    int x = 0;
    int y = 0;
};