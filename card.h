#ifndef CARD_H
#define CARD_H

#include <deque>
#include <ostream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

enum st { clubs, diamonds, hearts, spades };
enum clr { red, black };

class Card
{
public:
    Card();
    Card(int value, st suit, clr color);
    void setVal(int v);
    void setSuit(st s);
    void setColor(clr c);
    void setShow(bool s);
    void flipCard();
    int getVal();
    st getSuit();
    clr getColor();
    bool getShow();

private:
    int value;
    st suit;
    clr color;
    bool show;

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    friend bool operator==(const Card& card1, const Card& card2);

};

#endif
