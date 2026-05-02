#include <iostream>


void printSolution(int sol[5][5])
{
    for (int i = 0; i <5; i++)
    {
        for (int j = 0; j <5; j++)
        {
            std::cout << sol[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool solveMazeUtil(int maze[5][5], int x, int y, int sol[5][5])
{
    if (x ==5 - 1 && y ==5 - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (x >= 0 && x <5 && y >= 0 && y <5 && maze[x][y] == 1 && sol[x][y] == 0)
    {
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol))
        {
            return true;
        }
        
        if (solveMazeUtil(maze, x, y + 1, sol))
        {
            return true;
        }
        
        if (solveMazeUtil(maze, x - 1, y, sol))
        {
            return true;
        }

        if (solveMazeUtil(maze, x, y - 1, sol))
        {
            return true;
        }

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int maze[5][5])
{
    int sol[5][5] =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    if (solveMazeUtil(maze, 0, 0, sol) == false)
    {
        std::cout << "Solution doesn't exist" << std::endl;
    }
    else
    {
        std::cout << "Path found for the lion to reach the meat!" << std::endl;
        std::cout << "The path is marked with 1s:" << std::endl;
        printSolution(sol);
    }
}

int main()
{
    int maze[5][5] =
    {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    solveMaze(maze);
    return 0;
}