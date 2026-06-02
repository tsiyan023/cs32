//
//  History.h
//  rat-survival-cpp
//
//  Created by Siyan Tang on 4/9/24.
//  Copyright © 2024 Siyan Tang. All rights reserved.
//

#ifndef HISTORY_INCLUDED
#define HISTORY_INCLUDED

#include "globals.h"

#include <iostream>

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
private:
    char m_gridOfHistory[MAXROWS][MAXCOLS];
    int m_rows;
    int m_cols;
};

#endif //HISTORY_INCLUDED