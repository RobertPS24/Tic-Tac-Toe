#pragma once
#include <Windows.h>

using namespace std;

class Board {
private:
    char arry[3][3];

public:
    Board();
    void showBoard();
    void makeMove(int i, int j, Player p);
    bool checkWin();
    bool checkDraw();
    char getElem(int i, int j);
};
char Board::getElem(int i, int j) {
    return this->arry[i][j];
}
bool Board::checkDraw() {
    for (size_t i = 0; i < 9; i++) {
        if (this->arry[i / 3][i % 3] != 'X' && this->arry[i / 3][i % 3] != '0') {
            return false;
        }
    }
    return true;
}
bool Board::checkWin() {
    for (size_t i = 0; i < 3; i++) {
        if (arry[i][0] == arry[i][1] && arry[i][1] == arry[i][2]) {
            return true;
        }
        if (arry[0][i] == arry[1][i] && arry[i][i] == arry[2][i]) {
            return true;
        }
    }
    if (arry[0][0] == arry[1][1] && arry[1][1] == arry[2][2]) {
        return true;
    }
    if (arry[0][2] == arry[1][1] && arry[1][1] == arry[2][0]) {
        return true;
    }
    return false;
}
Board::Board() {
    for (size_t i = 0; i < 9 ; i++) {
        arry[i / 3][i % 3] = i + 1 + '0';
    }
}
void Board::makeMove(int i, int j, Player p) {
    arry[i][j] = p.getSymbol();
}
void Board::showBoard() {
    system("cls;");
    cout << " _______________________" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " << arry[0][0] << "   |   " << arry[0][1] << "   |   " << arry[0][2] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " << arry[1][0] << "   |   " << arry[1][1] << "   |   " << arry[1][2] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " << arry[2][0] << "   |   " << arry[2][1] << "   |   " << arry[2][2] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;
}