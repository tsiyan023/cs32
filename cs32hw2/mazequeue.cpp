#include <iostream>
#include <queue>

using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)

{
    queue<Coord> coordqueue;    
    
    coordqueue.push(Coord(sr,sc));  
    maze[sr][sc] = '+'; 
    
    while(!coordqueue.empty())
    {
        Coord popped = coordqueue.front();
        coordqueue.pop();
        if (popped.r() == er  &&  popped.c() == ec) 
        {
            return true;
        }
        
        if (maze[popped.r()-1][popped.c()] == '.')  
        {
            maze[popped.r()-1][popped.c()] = '+';
            coordqueue.push(Coord(popped.r()-1, popped.c()));
        }
        
        if (maze[popped.r()][popped.c()+1] == '.')  
        {
            maze[popped.r()][popped.c()+1] = '+';
            coordqueue.push(Coord(popped.r(), popped.c()+1));
        }
        
        if (maze[popped.r()+1][popped.c()] == '.')   
        {
            maze[popped.r()+1][popped.c()] = '+';
            coordqueue.push(Coord(popped.r()+1, popped.c()));
        }
        if (maze[popped.r()][popped.c()-1] == '.') 
        {
            maze[popped.r()][popped.c()-1] = '+';
            coordqueue.push(Coord(popped.r(), popped.c()-1));
        }

    }
    return false;
}
