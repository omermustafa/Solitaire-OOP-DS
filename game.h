#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "queue"
#include "windows.h"

class Game
{
public:
    Game(); //Done
    void setup();//Done
    void run();
    void printMenu(); //Done
    void printBoard();//Done
    void printField();//Done
    void printDeckAndFoundation();//Done
    bool handleInput();
    bool deckToTableau(char* dst); //Done
    bool deckToFoundation(char* dst); //Done
    bool tableauToFoundation(char* src, char* dst);//Done
    bool tableauToTableau(char* src, char* dst, char* num);

private:
    Queue tableau[7];
    Queue foundation[4];
    Deck deck;
    int tableauSize = 0;
    unsigned int maxColumn = 7;
    Card drawnCard;

};

#endif
