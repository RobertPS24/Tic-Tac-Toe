#pragma once
#include <iostream>

#include "Player.h"
#include "Board.h"

using namespace std;

class Game {
private:
    int playerTurn;
    Player player1;
    Player player2;
    Board board;

public:
    Game() : player1('X'), player2('0'), board() { this->playerTurn = 1; };
    void startGame();
};


void Game::startGame() {
    this->board.showBoard();
    while (true) {
        int poz;
        if (this->playerTurn == 1) {
            cout << "Introduceti pozitia (Player 1 - X): ";
            cin >> poz;
            poz--;
            if (board.getElem(poz / 3, poz % 3) == 'X' || board.getElem(poz / 3, poz % 3) == '0') {
                continue;
            }
            this->board.makeMove(poz / 3, poz % 3, player1);
            this->playerTurn = 2;
        }
        else {
            cout << "Introduceti pozitia (Player 2 - 0): ";
            cin >> poz;
            poz--;
            if (board.getElem(poz / 3, poz % 3) == 'X' || board.getElem(poz / 3, poz % 3) == '0') {
                continue;
            }
            this->board.makeMove(poz / 3, poz % 3, player2);
            this->playerTurn = 1;
        }

        this->board.showBoard();

        if (this->board.checkWin()) {
            cout << "Playerul " << ((this->playerTurn == 1) ? 2 : 1) << " a castigat!";
            return;
        }

        if (this->board.checkDraw()) {
            cout << "Jocul s-a terminat la egalitate!";
            return;
        }

    }
}