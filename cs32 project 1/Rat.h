//
//  Rat.h
//  rat-survival-cpp
//
//  Created by Siyan Tang on 4/9/24.
//  Copyright © 2024 Siyan Tang. All rights reserved.
//

#ifndef RAT_INCLUDED
#define RAT_INCLUDED

#include <iostream>

class Arena;

class Rat
{
public:
    // Constructor
    Rat(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;
    
    // Mutators
    void move();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};

#endif //RAT_INCLUDED