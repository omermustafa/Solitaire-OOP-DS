#include "game.h"

Game::Game()
{
    setup();
}
void Game::setup()
{

    int columnSize = 0;
    int arrSize = 7;
    Card aCard;
    drawnCard = deck.deal();
    drawnCard.flipCard();
    for (int i = 0; i < arrSize; ++i)
    {
        ++columnSize;
        for (int j = 0; j < columnSize; ++j)
        {
            if (!tableau[i].isEmpty())
            {
                for (auto itr = tableau[i].getFront(); itr != tableau[i].getRear(); itr = itr->getNext())
                {
                    aCard = itr->getData();
                }
                while (drawnCard.getColor() == aCard.getColor())
                {
                    drawnCard = deck.newCard();
                }
                if (columnSize == (j + 1))
                {
                    drawnCard.flipCard();
                }
                tableau[i].push_back(drawnCard);
                deck.popFront();
                drawnCard = deck.newCard();
                ++tableauSize;
            }
            else if(tableau[i].isEmpty())
            {
                if (columnSize == (j + 1))
                {
                    drawnCard.flipCard();
                }
                tableau[i].push_back(drawnCard);
                deck.popFront();
                drawnCard = deck.newCard();
                ++tableauSize;
            }
        }
    }
}

void Game::run()
{
    bool finished = false;
    while (!finished)
    {
        printBoard();
        finished = handleInput();
        system("cls");
    }
}

void Game::printBoard()
{
    printDeckAndFoundation();
    printField();
    printMenu();



//    cout << "\nSize of the deck\n:" << deck.getSize();
//    cout << "\n\nSize of all the foundations" << endl;
//    for(short int i=0; i < 7; i++){
//        cout << i+1 << ": " << tableau[i].getSize() << endl;
//    }
//    cout << "Drawn Card: " << drawnCard;
//    cout << "\nPrinting all the cards in the deck: \n";
//    deck.printDeck();
//    for(int i=0; i<7; i++){
//        cout << "\nTableau # " << i+1 << ": ";
//        tableau[i].display();
//        cout << endl;
//    }

}

void Game::printMenu()
{
    cout << endl << "Options" << endl
        << "1. Draw another card" << endl
        << "2. Move from deck to tableau" << endl
        << "3. Move from deck to foundation" << endl
        << "4. Move from tableau to foundation" << endl
        << "5. Move from tableau to tableau" << endl
        << "6. Quit" << endl
        << "Selection: ";
}

void Game::printDeckAndFoundation()
{
    Card aCard;
    cout << left << setw(18) << "DECK" << "\tDISCARD "
        << setw(18) << "A"
        << setw(18) << "B"
        << setw(18) << "C"
        << setw(18) << "D"
        << endl;
    drawnCard.flipCard();
    cout << setw(18) << drawnCard << "\t\t";

    for (int i = 0; i < 4; i++)
    {
        if (foundation[i].isEmpty())
            cout << setw(18) << "Empty";
        else
        {
            //auto itr = discard[i].end();
            for (auto itr = foundation[i].getFront(); itr != foundation[i].getRear(); itr++)
            {
                aCard = itr->getData();

            }
            cout << setw(18) << aCard;
        }
    }

    cout << endl << endl;

}
void Game::printField()
{
    auto itr0 = tableau[0].getFront();
    auto itr1 = tableau[1].getFront();
    auto itr2 = tableau[2].getFront();
    auto itr3 = tableau[3].getFront();
    auto itr4 = tableau[4].getFront();
    auto itr5 = tableau[5].getFront();
    auto itr6 = tableau[6].getFront();

    int j0 = 0, j1 = 0, j2 = 0, j3 = 0,j4 = 0, j5 = 0, j6 = 0;

    cout << "TABLEAU" << endl
        << setw(18) << left << "1"
        << setw(18) << left << "2"
        << setw(18) << left << "3"
        << setw(18) << left << "4"
        << setw(18) << left << "5"
        << setw(18) << left << "6"
        << setw(18) << left << "7"
        << endl;

    Card showCheck;

    for (unsigned int i = 0; i < maxColumn; ++i)
    {
        if(j0 < tableau[0].getSize())
        {
            cout << setw(18) << left;
            cout << itr0->getData();
            itr0 = itr0->getNext();
            j0++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        if(j1 < tableau[1].getSize())
        {
            cout <<   setw(18) << left;
            cout << itr1->getData();
            itr1 = itr1->getNext();
            j1++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        if(j2 < tableau[2].getSize())
        {
            cout << setw(18) << left;
            cout << itr2->getData();
            itr2 = itr2->getNext();
            j2++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        if(j3 < tableau[3].getSize())
        {
            cout << setw(18) << left;
            cout << itr3->getData();
            itr3 = itr3->getNext();
            j3++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        if(j4 < tableau[4].getSize())
        {
            cout << setw(18) << left;
            cout << itr4->getData();
            itr4 = itr4->getNext();
            j4++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        if(j5 < tableau[5].getSize())
        {
            cout << setw(18) << left;
            cout << itr5->getData();
            itr5 = itr5->getNext();
            j5++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        if(j6 < tableau[6].getSize())
        {
            cout << setw(18) << left;
            cout << itr6->getData();
            itr6 = itr6->getNext();
            j6++;
        }
        else
            cout << setw(18) << setfill(' ') << "";

        cout << endl;
    }

}
bool Game::handleInput()
 {
    int select = 0;
    bool status = false;
    int i = 0;
    cin >> select;
    if (!cin)
    {
        cin.clear();
        cin.ignore();
        return false;
    }
    if (select < 0 || select > 6)
        return false;
    char src[5];
    char dst[5];
    char val[5];
    cin.ignore(8192, '\n');

    switch (select)
    {
        case 1: drawnCard = deck.newCard();
            return false;
            break;
        case 2: //deck to Tableau
            cout << "\nEnter Destination Column(1-7): ";
            cin.get(dst, 8192, '\n');
            cin.ignore(8192, '\n');
            status = deckToTableau(dst);
            return false;
            break;
        case 3: //deck to Foundation
            cout << "\nEnter Destination Column(A-D): ";
            cin.get(dst, 8192, '\n');
            cin.ignore(8192, '\n');
            i = 0;
            /*
            while (dst[i])
            {
                tolower(dst[i]);
                ++i;
            }
            */

            status = deckToFoundation(dst);
            return false;
            break;
        case 4: //field to Foundation
            cout << "Enter Source Column(1-7): ";
            cin.get(src, 8192, '\n');
            cin.ignore(8192, '\n');
            cout << "\nEnter Destination Column(A-D): ";
            cin.get(dst, 8192, '\n');
            cin.ignore(8192, '\n');
            i = 0;
            while (dst[i])
            {
                tolower(dst[i]);
                ++i;
            }
            status = tableauToFoundation(src, dst);
            if (!status)
            {
                cout << "Can't place that there" << endl;
            }
            return false;
            break;
        case 5: //tableau to tableau
            cout << "Enter Source Column(1-7): ";
            cin.get(src, 8192, '\n');
            cin.ignore(8192, '\n');
            cout << "Enter value to move: ";
            cin.get(val, 8192, '\n');
            cin.ignore(8192, '\n');
            cout << "Enter Destination Column(1-7): ";
            cin.get(dst, 8192, '\n');
            cin.ignore(8192, '\n');
            i = 0;
            while (val[i])
            {
                tolower(val[i]);
                ++i;
            }
            i = 0;
            while (dst[i])
            {
                tolower(dst[i]);
                ++i;
            }
            status = tableauToTableau(src, dst, val);
            return false;
            break;
        case 6: //quit
            return true;
            break;
        default:
            return false;
            break;

    }
 }

bool Game::deckToTableau(char* dst)
{
    Card srcCard = drawnCard;
    Card dstCard;
    int dest = atoi(dst) - 1;
    if (dest < 0 || dest > 6)
        return false;

    for (auto itr = tableau[dest].getFront(); itr != tableau[dest].getRear(); itr = itr->getNext())
    {
        dstCard = itr->getData();
    }

    if (dstCard.getColor() != srcCard.getColor() && srcCard.getVal() == (dstCard.getVal() - 1))
    {
        tableau[dest].push_back(srcCard);
        //deck.popFront();
        drawnCard = deck.deal();
        if (tableau[dest].getSize() > maxColumn)
            maxColumn = tableau[dest].getSize();

        return true;
    }
    //empty column and source card is a king
    else if (tableau[dest].isEmpty() && srcCard.getVal() == 13)
    {
        tableau[dest].push_back(srcCard);
        //deck.popFront();
        drawnCard = deck.deal();
        return true;
    }

    return false;
}

bool Game::deckToFoundation(char* dst)
{
    Card aCard = drawnCard;
    int dest = 0;
    if (strcmp(dst, "a") == 0 || strcmp(dst, "A") == 0)
        dest = 0;
    else if (strcmp(dst, "b") == 0 || strcmp(dst, "B") == 0)
        dest = 1;
    else if (strcmp(dst, "c") == 0 || strcmp(dst, "C") == 0)
        dest = 2;
    else if (strcmp(dst, "d") == 0 || strcmp(dst, "D") == 0)
        dest = 3;
    else
        return false;

    if (foundation[dest].isEmpty() && drawnCard.getVal() == 1)
    {
        foundation[dest].push_back(aCard);
        //deck.popFront();
        drawnCard = deck.deal();
        return true;
    }
    else if (!foundation[dest].isEmpty() && drawnCard.getVal() == (foundation[dest].getRearElement().getVal() + 1) && foundation[dest].getRearElement().getSuit() == aCard.getSuit())
    {
        foundation[dest].push_back(aCard);
        //deck.popFront();
        drawnCard = deck.deal();
        return true;
    }
    else
        return false;
}

bool Game::tableauToFoundation(char* src, char* dst)
{
    int source = atoi(src) - 1;
    if (source < 0 || source > 6)
        return false;
    int dest = 0;
    Card srcCard;
    Card dstCard;

    for (auto itr = tableau[source].getFront(); itr != tableau[source].getRear(); itr = itr->getNext() )
    {
        srcCard = itr->getData();
    }

    if (strcmp(dst, "a") == 0 || strcmp(dst, "A") == 0)
        dest = 0;
    else if (strcmp(dst, "b") == 0 || strcmp(dst, "B") == 0)
        dest = 1;
    else if (strcmp(dst, "c") == 0 || strcmp(dst, "C") == 0)
        dest = 2;
    else if (strcmp(dst, "d") == 0 || strcmp(dst, "D") == 0)
        dest = 3;
    else
        return false;

    if (foundation[dest].isEmpty() && srcCard.getVal() == 1)
    {
        foundation[dest].push_back(srcCard);
        tableau[source].pop_back();
        if (!tableau[source].isEmpty())
        {
            for (auto itr = tableau[source].getFront(); itr != tableau[source].getRear(); itr = itr->getNext())
            {
                srcCard = itr->getData();
            }
            srcCard.flipCard();
        }
        return true;
    }

    for (auto itr = foundation[dest].getFront(); itr != foundation[dest].getRear(); itr = itr->getNext())
    {
        dstCard = itr->getData();
    }

    if (srcCard.getSuit() == dstCard.getSuit() && srcCard.getVal() == (dstCard.getVal() + 1))
    {
        foundation[dest].push_back(srcCard);
        tableau[source].pop_back();
        if (!tableau[source].isEmpty())
        {
            for (auto itr = tableau[source].getFront(); itr != tableau[source].getRear(); itr = itr->getNext())
            {
                srcCard = itr->getData();
            }
            srcCard.flipCard();
        }
        return true;
    }


    return false;
}

bool Game::tableauToTableau(char* src, char* dst, char* num)
{
    int source = atoi(src) - 1;
    int dest = atoi(dst) - 1;
    int val = 0;
    if (strcmp(num, "k") == 0 || strcmp(num, "K") == 0)
        val = 13;
    else if (strcmp(num, "q") == 0 || strcmp(num, "Q") == 0)
        val = 12;
    else if (strcmp(num, "j") == 0 || strcmp(num, "J") == 0)
        val = 11;
    else if (strcmp(num, "ace") == 0)
        val = 1;
    else
        val = atoi(num);

    if (source < 0 || source > 6 || dest < 0 || source > 6 || val < 1 || val > 13)
        return false;

    Card srcCard;
    Card dstCard;
    if (!tableau[dest].isEmpty())
        dstCard = tableau[dest].getRearElement();
    auto itr = tableau[source].getFront();
    for (; itr != tableau[source].getRear() && srcCard.getVal() != val; itr = itr->getNext())
    {
        cout << "halooo";
            srcCard = itr->getData();
            if (srcCard.getVal() == val && srcCard.getShow() == false)
            {
                cout << "Hello world\n";
                itr = itr->getNext();
                srcCard = itr->getData();
            }
    }
    --itr;

//    //king to empty column
//    if (srcCard.getVal() == 13 && tableau[dest].isEmpty())
//    {
//        tableau[dest].splice(tableau[dest].getFront(), tableau[source], itr, tableau[source].getRear());
//        if (tableau[dest].getSize() > maxColumn)
//            maxColumn = tableau[dest].getSize() + 1;
//        return true;
//    }
//    else if (srcCard.getVal() == (dstCard.getVal() - 1) && srcCard.getSuit() != dstCard.getSuit())
//    {

//        tableau[dest].splice(tableau[dest].getRear(), tableau[source], itr, tableau[source].getRear());
//        if (tableau[dest].getSize() > maxColumn)
//            maxColumn = tableau[dest].getSize() + 1;
//        return true;
//    }

    return false;
}
