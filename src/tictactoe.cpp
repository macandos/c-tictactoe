#include "tictactoe.hpp"

void Game::Play() {
    int opt;
    std::cout << "Welcome to TicTacToe!\n";
    // ----------- //
    p1 = true;

    while (!gameOver) {
        std::cout << "What will you do?: ";
        std::cin >> opt;
        
        if (p1) {
            if (!ChangeBoard(opt, 1)) { continue; }
            PrintBoard();
            if (IfWin(1)) { break; }
            if (IfTie()) { std::cout << "\n\nIt's a tie!\n"; break; }
            SwitchTurns();
        }
        else {
            if (!ChangeBoard(opt, 2)) { continue; };
            PrintBoard();
            if (IfWin(2)) { break; }
            if (IfTie()) { std::cout << "\n\nIt's a tie!\n"; break; }
            SwitchTurns();
        }
    }
}   

void Game::PrintBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j % 3 == 0) {
                std::cout << "\n";
            }
            if (board[i][j] == 0) {
                std::cout << "-";
            } 
            else if (board[i][j] == 1) {
                std::cout << "x";
            }
            else {
                std::cout << "o";
            }
        }
    }
}

void Game::SwitchTurns() {
    if (p2) {
        p1 = true;
        p2 = false;
        std::cout << "\n\nIt is Player 1's turn\n";
    }
    else if (p1) {
        p1 = false;
        p2 = true;
        std::cout << "\n\nIt is Player 2's turn\n";
    }
}

bool Game::ChangeBoard(int opt, int change) {
    switch (opt) {
        case 1:
            if (board[0][0] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[0][0] = change;
            return true;
        case 2:
            if (board[0][1] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[0][1] = change;
            return true;
        case 3:
            if (board[0][2] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[0][2] = change;
            return true;
        case 4:
            if (board[1][0] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[1][0] = change;
            return true;
        case 5:
            if (board[1][1] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[1][1] = change;
            return true;
        case 6:
            if (board[1][2] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[1][2] = change;
            return true;
        case 7:
            if (board[2][0] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[2][0] = change;
            return true;
        case 8:
            if (board[2][1] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[2][1] = change;
            return true;
        case 9:
            if (board[2][2] != 0) { std::cout << "That spot has already been chosen!\n"; return false;}
            board[2][2] = change;
            return true;
        default:
            // so the program doesnt loop when the user
            // inputs in a non-int
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option!\n\n";
            return false;
            break;

    }
}

bool Game::IfWin(int change) {
    if (board[0][0] == change && board[0][1] == change && board[0][2] == change) {
        /*
        xxx
        ---
        ---
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[1][0] == change && board[1][1] == change && board[1][2] == change) {
        /*
        ---
        xxx
        ---
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[2][0] == change && board[2][1] == change && board[2][2] == change) {
        /*
        ---
        ---
        xxx
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[0][0] == change && board[1][0] == change && board[2][0] == change) {
        /*
        xxx
        ---
        ---
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[0][0] == change && board[0][1] == change && board[0][2] == change) {
        /*
        x--
        x--
        x--
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[0][1] == change && board[1][1] == change && board[2][1] == change) {
        /*
        -x-
        -x-
        -x-
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[0][2] == change && board[1][2] == change && board[2][2] == change) {
        /*
        --x
        --x
        --x
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[0][0] == change && board[1][1] == change && board[2][2] == change) {
        /*
        x--
        -x-
        --x
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    if (board[0][2] == change && board[1][1] == change && board[2][0] == change) {
        /*
        --x
        -x-
        x--
        */
        std::cout << "\n\nYou did it!\n";
        return true;
    }
    return false;
}

 bool Game::IfTie() {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0) {
                count++;
            }
        }
    }
    if (count == 9) {
        return true;
    }
    return false;
}