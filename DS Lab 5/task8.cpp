#include <iostream>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    for (j = 0; j < col; j++) {
        if (board[row][j]) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveUtil(int board[N][N], int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveUtil(board, col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if (solveUtil(board, 0) == false) {
        std::cout << "Solution does not exist" << std::endl;
    } else {
        std::cout << "Maximum flags that can be placed: " << N << std::endl;
        std::cout << "One possible arrangement (1s are flags):" << std::endl;
        printSolution(board);
    }

    return 0;
}