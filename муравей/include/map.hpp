#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
struct CellInfo {
    bool hasFood;
    int foodAmount;
    bool hasEnemy;
    bool hasAnthill;
    bool hasAnt;
    bool hasStick;
    void* ptr;
};

struct Position 
{
    float x;
    float y;
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};
struct PositionHash {
    std::size_t operator()(const Position& pos) const 
    {
        return std::hash<int>()(pos.x) ^ (std::hash<int>()(pos.y) << 1);
    }
};
extern std::unordered_map<Position, CellInfo, PositionHash> positionMap;
#endif