#pragma once
class Player {
private:
    char symbol;

public:
    Player(char sym);
    char getSymbol() const { return symbol; }

};

Player::Player(char sym) {
    this->symbol = sym;
}