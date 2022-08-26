#ifndef SPAWN_SYSTEM_HPP
#define SPAWN_SYSTEM_HPP

class Position;

class SpawnSystem {
    public:
        virtual void spawn(const Position& newPosition) = 0;
};

#endif