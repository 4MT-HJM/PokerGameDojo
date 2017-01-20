#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED

#include <vector>
#include <string>
#include <map>

using namespace std;



typedef struct card
{
    int value;
    char suit;
}Card;

class Player
{
public:
    Player(vector<string>);
    int getCardType();
    vector<Card> getCardResult();
private:
    void transferToCard(vector<string>);
    int calculateCardType(vector<Card>);
    bool findOnePair(vector<Card>);
    bool findTwoPairs(vector<Card>);
    bool findThreeOfAKind(vector<Card>);
    bool findStraight(vector<Card>);
    bool findFlush(vector<Card>);
    bool findFullHouse(vector<Card>);
    bool findFourOfAKind(vector<Card>);
    bool findStraightFlush(vector<Card>);
    bool findRoyalFlush(vector<Card>);
    
    vector<Card> cardResult;
    int cardtype;
    std::map<char, int> cardNumValue =
    {
        {'2', 2},        {'3', 3},        {'4', 4},
        {'5', 5},        {'6', 6},        {'7', 7},
        {'8', 8},        {'9', 9},        {'T', 10},
        {'J', 11},       {'Q', 12},       {'K', 13},
        {'A', 14}
    }; 
};

class CardGame
{
public:
    static int Play(Player&, Player&);
private:
    static int compareStraightFlush(Player&, Player&);
    static int compareFourOfAKindAndFullHouseAndThreeOfAKind(Player&, Player&);
    static int compareFlush(Player& playerOne, Player& playerTwo);
};

#endif
