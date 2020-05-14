
#include <iostream>
#include <deque>
#include "playingcard.hpp"
#include "termio.h"
#include <algorithm>

using namespace std;

/**
* Deck
*
* Description:      This class represents a deck of playing cards. Cards will be removed
*                   from the front of the deck and placed to the back.This class will 
*                   perform several operations such as determining if there are cards 
*                   present in the deck or not, resetting a deck, shuffling a deck,
*                   keeping track of the size of the deck along with printing out a 
*                   deck of cards.

* Public Methods:   Deck();
*                   void LoadCards(int);
*                   bool isEmpty();
*                   void Order();
*                   Card* Deal();
*                   void Reset();
*                   void ShuffleDeck();
*                   int Size();
*                   void Print(int, bool);

* Protected:        deque <Card*> Cards;
*                   Term::IO io;
*                   int cardCount;
*                   struct CompareCards();
*/

class Deck{
  protected:
    int cardCount;
    deque <Card*> Cards;
    Term::IO io;

struct CompareCards{
    
    bool operator()(Card *p, Card *q){
    return p < q;
    }
};

 public:
    Deck();
    void ShuffleDeck();
    int Size();
    void Reset();
    bool isEmpty();
    void LoadCards(int);
    void Print(int, bool);
    Card* Deal();
    void Order();

};

/**
* Constructor
*
* Description: Represents a deck of playing cards.
*
* Params:      None
*
* Returns:     None
*/
Deck::Deck(){
    cardCount = 0;
}

/**
* LoadCards
*
* Description:  Creates a deck of n number of playing cards
*
* Params:       int cardCount: the number of cards in deck
*
* Returns:      void
*/

void Deck::LoadCards(int cardCount){

    for (int i =0; i < cardCount; i++){
        Cards.push_back(new Card(i));  // memory allocation for a new card
    }
}
