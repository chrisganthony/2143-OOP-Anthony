//////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Chris Anthony
// Email:            chrisanthony97@hotmail.com
// Label:            H05
// Title:            Playing Card Class
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:      This program will create playing cards that can be
//                   implemented for any card game.The ostream operator
//                   along with other boolean operators will be overloaded
//                   to print the cards, as well as compare them to each other.
// 
//
// Usage: 
//     -This program will create playing cards for any card game.
// Files:            
//       PlayingCard.hpp    : Implements playing cards 
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
  ██████╗ █████╗ ██████╗ ██████╗
 ██╔════╝██╔══██╗██╔══██╗██╔══██╗
 ██║     ███████║██████╔╝██║  ██║
 ██║     ██╔══██║██╔══██╗██║  ██║
 ╚██████╗██║  ██║██║  ██║██████╔╝
  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝
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
 *                           Card(int);
 *      string               Repr();
 *      bool                 operator<(const Card &);
 *      bool                 operator>(const Card &);
 *      bool                 operator==(const Card &);
 *      bool                 operator!=(const Card &);
 *      bool                 operator()(const Card &);
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

const string spade = "♠";
const string diamond = "♦";
const string heart = "♥";
const string club = "♣";

const string suits[4] = {"♠", "♦", "♣", "♥"};

// Black background        blue ,  red , blue , red
const string colors2[4] = {"&60", "&20", "&60", "&20"};

// Colored background      blue  , red  , blue , red
const string colors[4] = {"&16", "&12", "&16", "&12"};

// Card labels
const string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
int suitNum;     // value 0-3 : num index of suit
int rank;        // 0-13      : num value of rank
int number;      // 1-52      : unique value determines card
int value;       // 1-14      : numeric value used for comparison
string suitChar; // "♠", "♦", "♣", "♥"
string rankChar; // Ace, 1 ,2 ,3 ... Q, K
string color;    // Spade=blue, Diamond=red, etc.

public:

friend ostream;

Card(int);
string Repr();
bool operator<(const Card &);
bool operator>(const Card &);
bool operator==(const Card &);
bool operator!=(const Card &);
bool operator()(const Card &);
};

/**
 * Public : Card
 *
 * Description:
 *      Represents a single card in a deck of cards to include a
 *      value along with rank and suit. We are assuming a standard
 *      card type in a deck of playing cards.
 *
 * Params:
 *      int :  value from 0 - 51 that represents a card in a deck.
 *
 * Returns:
 *      None
 */

// Overloaded Constructor
Card::Card(int num) {
    number = num;
    suitNum = number / 13;
    suitChar = suits[suitNum];
    color = colors[suitNum];
    rank = number % 13;
    rankChar = ranks[rank];
}

/**
 * Public : Repr
 *
 * Description:
 *      Returns a string representation of the card class with
 *      colors embedded.
 *
 * Params:
 *      None
 *
 * Returns:
 *      [string] - representation of card
 */
string Card::Repr() {
    string s = "";
    s += color + "┌────┐&00 \n";
    s += color + "│";
    if (rank != 9) {
        s += color + " ";
    }
    s += color + rankChar + " " + suitChar + "│&00 \n";
    s += color + "└────┘&00 ";
    return s;
}

/**
 * Public : operator <<
 *
 * Description:
 *      Overload ostream and send the string representation "Repr"
 *      of the card.
 *
 *      We don't need the scope resolution operator (Card::) since
 *      this is a "friend" of card.
 *
 * Params:
 *      [ostream&] : os
 *      [Card]     : obj
 *
 * Returns:
 *      [ostream&]
 */
ostream &operator<<(ostream &os, Card obj) {

    os << obj.Repr();

    return os;
}

/**
 * Public : operator <
 *
 * Description:
 *      Overloads the "<" operator to compare two cards and returns
 
 *      true if "this->rank" is less than rhs.rank.
 *
 * Params:
 *      const [Card&]     : rhs
 *
 * Returns:
 *      bool
 */

bool Card::operator<(const Card &rhs) {
    return this->rank < rhs.rank;
}

/**
 * Public : operator >
 *
 * Description:
 *      Overloads the ">" operator to compare two cards and returns
 *      true if "this->rank" is greater than rhs.rank.
 *
 * Params:
 *      const [Card&]     : rhs
 *
 * Returns:
 *      bool
 */
bool Card::operator>(const Card &rhs) {
    return this->rank > rhs.rank;
}

/**
 * Public : operator ==
 *
 * Description:
 *      Overloads the "==" operator to compare two cards and returns
 *      true if the cards' ranks are eqaul.
 *
 * Params:
 *      const [Card&]     : rhs
 *
 * Returns:
 *      bool
 */
bool Card::operator==(const Card &rhs) {
    return this->rank == rhs.rank;
}

/**
 * Public : operator !=
 *
 * Description:
 *      Overloads the "!=" operator to compare two cards and returns 
 *      true if the cards' ranks are not equal.
 *
 * Params:
 *      const [Card&]     : rhs
 *
 * Returns:
 *      bool
 */
bool Card::operator!=(const Card &rhs) {
    return this->rank != rhs.rank;
}

/**
 * Public : operator ()
 *
 * Description:
 *      Overloads the "()" operator to compare two Cards witout
 *      using the "<" operator. Returns true if "this->rank" is
 *      less than "rhs.rank".
 
 * 
 * Params:
 *      const [Card&]     : rhs
 *
 * Returns:
 *      bool
 */
bool Card::operator()(const Card &rhs) {
    return (this->rank < rhs.rank);
}
