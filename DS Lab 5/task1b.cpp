#include <iostream>
using namespace std;

class Maze
{
    int maze[4][4];
    public:
    Maze(int maz[4][4])
    {
        for(int i=0;i<4;i++)
           for(int j=0;j<4;j++)
               maze[i][j]=maz[i][j];
    }
    bool solve(int posr, int posc, int goalr, int goalc)
    {
    if (posr >= 4 || posc >= 4 || posc < 0 || posr < 0)return false;
    if (maze[posr][posc] != 1)return false;
    if (posr == goalr && posc == goalc) 
    {
        maze[posr][posc] = 8;
        return true;
    }

    maze[posr][posc] = 8;

    if (solve(posr + 1, posc, goalr, goalc) ||
        solve(posr - 1, posc, goalr, goalc) ||
        solve(posr, posc + 1, goalr, goalc) ||
        solve(posr, posc - 1, goalr, goalc)) {
        return true;
    }

    // unmark path
    maze[posr][posc] = 1;
    return false;
    }


    void display()
    {
        for(int i=0;i<4;i++)
        {
            cout<<endl;
            for(int j=0;j<4;j++)cout<<maze[i][j]<<' ';
        }
    }
};


int main()
{//1 is open and 0 is blocked.
    int matrix[4][4]
    {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    Maze m(matrix);
    cout<<"maze:";
    m.display();
    cout<<"\n------------------------\n";
    m.solve(0,0,2,0); //path from 0,0 to 2,0
    cout<<"after solving:\n";
    m.display();
    return 0;
}