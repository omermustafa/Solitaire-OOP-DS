#include <iostream>
#include "card.h"
#include "queue.cpp"
#include "deck.h"
#include "game.h"
using namespace std;

int main()
{
//    int x=1, y=7;
//    swap(x,y);
//    cout << x;

//Checking card class
//    Card c(1, hearts, black);
//    cout << "Value: " << c.getVal() << endl;
//    cout << "Suit: " << c.getSuit() << endl;
//    cout << "Color: " << c.getColor() << endl;
//    c.flipCard();
//    cout << "Couting card object\n\n";
//    cout << c;

//Checking Queue
//    cout << "Couting insertion of Card using queue\n";
//    Card c, c2(1, spades, black);
//    c.flipCard();
//    Queue q;
//    q.push_back(c);
//    c2.flipCard();
//    q.push_back(c2);
//    q.display();

//    Deck d;
//    d.printDeck();

//    cout << "\n\nChecking out the deal card function:\n\n";
//    Queue q;
//    Card temp;

//    for(int i=1; i<=26; i++){
//        temp = d.deal();
//        q.push_back(temp);
//    }

//    cout << "\n\nDisplaying Queue: \n\n";
//    q.display();
//    cout << "Size of the queue:\n" << q.getSize();

//    cout << "\n\nDisplaying the deck\n\n";
//    d.printDeck();
//    cout << "\n\nSize of the deck\n\n" << d.getSize();


    Game g;
    g.run();






    return 0;
}
