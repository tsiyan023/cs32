//
//  Player.h
//  rat-survival-cpp
//
//  Created by Siyan Tang on 4/9/24.
//  Copyright © 2024 Siyan Tang. All rights reserved.
//

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <iostream>
#include <string>


class Arena;

class Player
{
public:
    // Constructor
    Player(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;
    
    // Mutators
    std::string dropPoisonPellet();
    std::string move(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};

#endif //PLAYER_INCLUDED