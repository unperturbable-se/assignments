#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

class Maze
{
    enum Block{WALL,EMPTY};
    Block** maze;
    int row,col;
    public:
    void randomGenerate(int seed=0)
    {
        // 0=down,1=right,2=left,3=up
        for(int i=0;i<row;i++) for(int j=0;j<col;j++) maze[i][j]=WALL;

        srand(seed);

        int move;
        int r=0;int c=col/2;int steps=0;
        while(r<row-1)
        { 
            move=rand()%4;
            if (c==col-2&&move==1)continue; //turn left instead 
            else if (r==0&&move==3)continue; 
            else if (c==0&&move==2)continue; 
            if(move==0)r++; 
            else if(steps%2==0)
            {
            if(move==1)c++; 
            else if(move==2)c--;
            else if(move==3)r--;
            }
            if(move == 0)maze[r][c]=EMPTY;
            steps++;
        }

    }
    Maze(int r,int c):row{r},col{c}
    {
      maze=new Block*[row];
      for(int i=0;i<row;i++)maze[i]=new Block[col];
      randomGenerate();
    }
    void display()
    {
        for(int i=0;i<row;i++)
        {
            cout<<'+';
            for(int j=0;j<col;j++)
               {
                if(maze[i][j]==WALL)cout<<"|";
                else cout<<" ";
               }
            cout<<"+\n";
        }
    }

    ~Maze()
    {
        for(int i=0;i<row;i++)delete[] maze[i];
        delete[] maze;
    }
};

int main()
{
    Maze m(100,100);
    m.display();
    return 0;
}