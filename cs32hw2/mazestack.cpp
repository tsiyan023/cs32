#include <iostream>
#include <stack>
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
    stack<Coord> coordStack;     
    
    coordStack.push(Coord(sr,sc));  
    maze[sr][sc] = '+';   
    
    while (!coordStack.empty())
    {
        Coord popped = coordStack.top();
        cerr << popped.r() << "," << popped.c() << endl;
        coordStack.pop();
        if (popped.r() == er  &&  popped.c() == ec) 
        {
            return true;
        }
        
        if (maze[popped.r()-1][popped.c()] == '.')  
        {
            maze[popped.r()-1][popped.c()] = '+';
            coordStack.push(Coord(popped.r()-1, popped.c()));
        }
        
        if (maze[popped.r()][popped.c()+1] == '.')  
        {
            maze[popped.r()][popped.c()+1] = '+';
            coordStack.push(Coord(popped.r(), popped.c()+1));
        }

        if (maze[popped.r()+1][popped.c()] == '.')   
        {
            maze[popped.r()+1][popped.c()] = '+';
            coordStack.push(Coord(popped.r()+1, popped.c()));
        }
        if (maze[popped.r()][popped.c()-1] == '.') 
        {
            maze[popped.r()][popped.c()-1] = '+';
            coordStack.push(Coord(popped.r(), popped.c()-1));
        }

    }
    return false;
}

int main()
{
    
    char maze[10][10] = {

        { 'X','X','X','X','X','X','X','X','X','X'},
        { 'X','.','.','.','.','.','.','.','.','X'},
        { 'X','X','.','X','.','X','X','X','X','X'},
        { 'X','.','.','X','.','X','.','.','.','X'},
        { 'X','.','.','X','.','.','.','X','.','X'},
        { 'X','X','X','X','.','X','X','X','.','X'},
        { 'X','.','X','.','.','.','.','X','X','X'},
        { 'X','.','X','X','X','.','X','X','.','X'},
        { 'X','.','.','.','X','.','.','.','.','X'},
        { 'X','X','X','X','X','X','X','X','X','X'}
    };
    
    if (pathExists(maze, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
    
}
