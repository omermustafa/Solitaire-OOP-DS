#ifndef DECK_H
#define DECK_H
#include<iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.h"
#include "queue.cpp"
using namespace std;

class Deck
{
public:
    Deck();
    void buildDeck();
    void shuffleDeck();
    void printDeck();
    void popFront();
    Card newCard();
    Card deal();
    int getSize();

private:
    Queue deck;
};



#endif // DECK_H
