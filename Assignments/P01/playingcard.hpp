#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 
   ______    ______   _______   _______  
  /      \  /      \ /       \ /       \
 /$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$$  |
 $$ |  $$/ $$ |__$$ |$$ |__$$ |$$ |  $$ |
 $$ |      $$    $$ |$$    $$< $$ |  $$ |
 $$ |   __ $$$$$$$$ |$$$$$$$  |$$ |  $$ |
 $$ \__/  |$$ |  $$ |$$ |  $$ |$$ |__$$ |
 $$    $$/ $$ |  $$ |$$ |  $$ |$$    $$/
  $$$$$$/  $$/   $$/ $$/   $$/ $$$$$$$/  
                                                                                                               
*/

/**
 * Card
 *
 * Description:
 *      This class will create an actual representation of playing cards
 *      by doing arithmetic to calculate the suit and rank of each card,
 *      along with the giving each card its corresponding color to its suit.
 *      This class will also overload the "<<" and boolean operators to print
 *      and compare cards.
 *
 * Public Methods:
 *
 *      friend ostream;
 *      Card(int);
 *      string Repr();
 *      bool operator<(const Card &);
 *      bool operator>(const Card &);
 *      bool operator==(const Card &);
 *      bool operator!=(const Card &);
 *      bool operator()(const Card &);
 *      
 * Private:
 *
 *      const string         spade
 *      const string         diamond
 *      const string         heart    
 *      const string         club
 *      const string         suits[4]
 *      const string         colors[4]
 *      const string         ranks[13]
 *      int                  suitNum
 *      int                  rank
 *      int                  number
 *      int                  value
 *      string               suitChar
 *      string               rankChar
 *      string               color
 *          
 * Usage:
 *
 *      friend ostream      // Granted access to cards' private data members
 *                              // to print a card
 *
 *      Card(int)           // Overloaded constructor that initializes a card
 *                          Ex.) Card C1(5) is a 5 of Spades
 *                               Card C2(14) is a Ace of Diamonds
 *
 *      Repr()              // Returns a string representation of a card
 *      
 *      C1 < C2;             // Compares the cards' rank and results in true
 *      C1 > C2;             // Compares the cards' rank and results in false
 *      C1 == C2;            // Compares the cards' rank and results in false
 *      C1 != C2;            // Compares the cards' rank and results in true
 *
 */
class Card {
  private:
    // Card suits
    const string suits[4] = {"♠", "♦", "♣", "♥"};

    // Colored background      black  , red  , black , red
    const string colors[4] = {"&18", "&28", "&18", "&28"};

    // Card labels (could be "Iron Man" or "Charmander" or "Elf" ... anything)
    const string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
                           
    int suitNum;     // value 0-3 : num index of suit
    int rank;        // 0-13      : num value of rank
    int number;      // 1-52      : unique value determines card
    int value;       // 1-14      : numeric value used for comparison
    string suitChar; // "♠", "♦", "♣", "♥"
    string rankChar; // Ace, 1 ,2 ,3 ... Q, K
    string color;    // Spade=black, Diamond=red, etc.

  public:
    friend ostream;
    Card();
    Card(int);
    string Repr();
    string Repr2();
    int Rank();
    void SetForgroundColor(string color);
    bool operator<(Card *);
    bool operator==(Card *);
    bool operator!=(Card *);
    bool operator>(Card *);
    bool operator()(Card *);
};

/**
* Public : Constructor
*
* Description:
*      Represents a single card in a deck of cards including a
*      value, rank and suit. We are assuming a standard card 
*      type in a deck of playing cards.
*
* Params:  None
*
* Returns: None
*/

Card::Card(){
   int color;
   int rank;
   int number;
   int suitNum;
   int rankChar;
   int suitChar;
}

/**
* Overloaded Constructor
*
* Description:   Represents a single card in a deck of cards including a
*                value, rank and suit. A standard card type in a deck of
*                playing cards.
*
* Params:        int :  value from 0 - 51 that represents a card in a deck.
*
* Returns:       None
*/
Card::Card(int num){                              

    number = num;
    suitNum = number / 13;
    suitChar = suits[suitNum];
    color = colors[suitNum];
    rank = number % 13;
    rankChar = ranks[rank];
}

/**
* Rank
*
* Description: Returns a cards rank
*
* Params:      None
*
* Returns:     int :  a cards rank
*/

int Card::Rank(){
    return this->rank;
}

/**
* Public : Repr
*
* Description:  Returns a string representation of the card class with
*               colors embedded.
*
* Params:       None
*
* Returns:
*      [string] - representation of card
*/
string Card::Repr() {

    // string "s" acts as an accumulator to create an
    // image of a card

    string s = "";

    s += color + "┌────┐&00 \n";    // "&00" means the default color of a card
    s += color + "│";
    if (rank != 9) {
        s += color + " ";
    }
    s += color + rankChar + " " + suitChar + "│&00 \n";
    s += color + "└────┘&00 ";

    return s;   // return the card
}

string Card::Repr2() {      // Repr2()

    // string "s" acts as an accumulator to create an
    // image of a card

    string s = "";

    s += color + "┌────┐&85 \n";    // "&00" means the default color of a card

    s += color + "│    │&85 \n";

    s += color + "└────┘&85 \n";
   
    return s;               // return the card
}

/**
 * operator <<
 *
 * Description:   Overload ostream and send the string representation "Repr"
 *                of the card.The scope resolution operator is not necessary
 *                since this s is a "friend" of card.
 *
 * Params:       [ostream&] : os
 *               [Card]     : obj
 *
 * Returns:      [ostream&]
 */
ostream &operator<<(ostream &os, Card obj) {

    // An os object that contains the string
    // representation of a card.

    os << obj.Repr();

    return os;

}

/**
 * operator <
 *
 * Description:  Overloads the "<" operator to compare two cards and returns
 *               true if "this->rank" is less than rhs.rank.
 * 
 * Params:       const [Card*]     : rhs
 *
 * Returns:      bool
 */

bool Card::operator<(Card *rhs){

    return this->rank < rhs->rank;

}

/**
 * operator >
 *
 * Description:   Overloads the ">" operator to compare two cards and returns
 *                true if "this->rank" is greater than rhs.rank.
 *
 * Params:        const [Card*]     : rhs
 *
 * Returns:       bool
 */

bool Card::operator>(Card *rhs){

    return this->rank > rhs->rank;

}

/**
 * operator ==
 *
 * Description:   Overloads the "==" operator to compare two cards and returns
 *                true if the cards' ranks are eqaul.
 *
 * Params: *      const [Card*]: rhs
 *
 * Returns:       bool
 */

bool Card::operator==(Card *rhs){

    return this->rank == rhs->rank;
}

/**
 * operator !=
 *
 * Description:   Overloads the "!=" operator to compare two cards and returns
 *                true if the cards' ranks are not equal.
 *
 * Params:        const [Card*]: rhs
 *
 * Returns:       bool
 */

bool Card::operator!=(Card *rhs){

    return this->rank != rhs->rank;

}

/**
 * operator ()
 *
 * Description    Overloads the "()" operator to compare two Cards witout
 *                using the "<" operator. Returns true if "this->rank" is
 *                less than "rhs.rank".
 *
 * Params:       const [Card*]     : rhs
 *
 * Returns:      bool
 */

bool Card::operator()(Card *rhs){

    return (this->rank < rhs->rank);
}
