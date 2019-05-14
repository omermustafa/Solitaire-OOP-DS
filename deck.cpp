#include "deck.h"
using namespace std;

Deck::Deck()
{
    buildDeck();
    shuffleDeck();
}

void Deck::buildDeck()
{
    Card aCard;

    for (int i = 1; i <= 13; i++)
    {
        for (st suit = clubs; suit <= spades; suit = static_cast<st>(suit + 1))
        {
            if (suit == diamonds || suit == hearts)
                deck.push_back(Card(i, suit, red));
            else
                deck.push_back(Card(i, suit, black));
        }
    }
}
void Deck::popFront()
{
    deck.pop_front();
}
int Deck::getSize()
{
    return deck.getSize();
}

Card Deck::newCard()
{
    Node * aCard = deck.getFront();
    deck.push_back(aCard->getData());
    deck.pop_front();
    return aCard->getData();
}

void Deck::printDeck()
{
    Node * temp = deck.getFront();
    int counter=0;
    while(temp != NULL){
        cout << ++counter << ": ";
        temp->display();
        temp = temp->getNext();
        cout << "\n";
    }
}
Card Deck::deal()
{
    deck.pop_front();
    Node aCard = deck.getFrontElement();
    return aCard.getData();
}
void Deck::shuffleDeck(){
    Node *tempSimple = deck.getFront();
    Card temp;
    int random = 0;

    srand (time(NULL));
    for(int i=1; i <= 52 && tempSimple != NULL; i++){
        Node *tempRandom = deck.getFront();
        random = rand() % 52 + 1;
        for(int j=1; j < random && tempRandom != NULL; j++){
            tempRandom = tempRandom->getNext();
        }//Traversing breaks when it has been traversed random times
        temp = tempRandom->getData();
        tempRandom->setData(tempSimple->getData());
        tempSimple->setData(temp);

        //Moving tempSimple one step ahead
        tempSimple = tempSimple->getNext();
    }
}






