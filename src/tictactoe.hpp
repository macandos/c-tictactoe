#pragma once

#include <iostream>
#include <limits>

class Game {
public:
    bool p1 = false;
    bool p2 = false;

    bool gameOver = false;

    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Begins game
    void Play();

    // Basic Functionality
    void SwitchTurns();

    void PrintBoard();
    bool ChangeBoard(int opt, int change);

    bool IfWin(int change);
    bool IfTie();
};