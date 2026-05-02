#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessNumber(int secret, int currentPlayer)
{
    int guess;
    cout << "Player " << currentPlayer << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess < 1 || guess > 100)
    {
        cout << "Invalid input! Please guess a number between 1 and 100.\n";
        guessNumber(secret, currentPlayer);
        return;
    }

    if (guess == secret)
    {
        cout << "Player " << currentPlayer << " guessed the number correctly! You win!\n";
        return;
    }
    else if (guess < secret)
    {
        cout << "Too low!\n";
    }
    else
    {
        cout << "Too high!\n";
    }

    int nextPlayer = (currentPlayer == 1) ? 2 : 1;
    guessNumber(secret, nextPlayer);
}

int main()
{
    srand(time(0));
    int secret = rand() % 100 + 1;

    cout << "=== Number Guessing Game ===\n";
    cout << "Two players take turns guessing a number between 1 and 100.\n";
    cout << "Let's begin!\n\n";

    guessNumber(secret, 1);

    return 0;
}
