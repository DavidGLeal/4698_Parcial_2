#pragma once
#include <vector>

class Direction {
public:
    static enum Value {
        NORTH,
        WEST,
        SOUTH,
        EAST
    };

    Direction() = default;
    constexpr Direction(Value value) : value_(value) {}

    static std::vector<Value> values() {
        return std::vector<Value>{ NORTH, WEST, SOUTH, EAST };
    }

#if Enable switch(direction) use case:
    constexpr operator value() const { return value; }
    explicit operator bool() const = delete;
#else
    constexpr bool operator==(Direction a) const { return value_ == a.value_; }
    constexpr bool operator!=(Direction a) const { return value_ != a.value_; }
#endif

    constexpr bool operator<(Direction a) const { return value_ < a.value_; }

    constexpr Value value() { return value_; }
    constexpr Direction opposite() const {
        switch (value_) {
        case NORTH:
            return SOUTH;
        case SOUTH:
            return NORTH;
        case WEST:
            return EAST;
        case EAST:
            return WEST;
        }
    }

private:
    Value value_;
};
