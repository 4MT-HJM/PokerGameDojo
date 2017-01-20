#include "hiker.hpp"
#include <algorithm>
#include <iostream>

Player::Player(vector<string> p1)
{
    transferToCard(p1);
    cardtype = calculateCardType(cardResult);
}

void Player::transferToCard(vector<string> p1)
{
    for(auto &i : p1)
    {
        Card tmpCard;
        tmpCard.value = cardNumValue[i[0]];
        tmpCard.suit = i[1];
        cardResult.push_back(tmpCard);
    }
    sort(cardResult.begin(), cardResult.end(), [](auto &i, auto &j){return i.value < j.value;});
}

bool Player::findOnePair(vector<Card> cardResult)
{
    auto cardIter = adjacent_find(cardResult.begin(), cardResult.end(),[](auto &i, auto &j){return i.value == j.value;});
    if (cardIter != cardResult.end())
    {
        return true;
    }
    return false;    
}

bool Player::findTwoPairs(vector<Card> cardResult)
{
    auto cardIter1 = adjacent_find(cardResult.begin(), cardResult.end(),[](auto &i, auto &j){return i.value == j.value;});
    if(cardIter1 <= cardResult.begin() + 1)
    {
        auto cardIter2 = adjacent_find(cardIter1 + 2, cardResult.end(),[](auto &i, auto &j){return i.value == j.value;});
        if (cardIter2 != cardResult.end())
        {
            return true;
        }
    }
    return false; 
}

bool Player::findThreeOfAKind(vector<Card> cardResult)
{
    if((cardResult[0].value == cardResult[2].value) ||
        (cardResult[1].value == cardResult[3].value) ||
        (cardResult[2].value == cardResult[4].value))
    {
        return true;
    }
    return false;
}

bool Player::findStraight(vector<Card> cardResult)
{
    if(!findOnePair(cardResult))
    {
       if(cardResult[0].value + 4 == cardResult[4].value) 
          return true;
    }
    return false;
}

bool Player::findFlush(vector<Card> cardResult)
{
    auto cardIter = find_if(cardResult.begin(), cardResult.end(), [&](auto &i){return i.suit != cardResult[0].suit;});
    if(cardIter == cardResult.end())
    {
        return true;
    }
    return false;
}

bool Player::findFullHouse(vector<Card> cardResult)
{
    if(findTwoPairs(cardResult) && findThreeOfAKind(cardResult))
    {
        return true;
    }
    return false;
}

bool Player::findFourOfAKind(vector<Card> cardResult)
{
    if (findFullHouse(cardResult))
    {
        if (cardResult[1].value == cardResult[3].value)
            return true;
    }
    return false;
}

bool Player::findStraightFlush(vector<Card> cardResult)
{
    if(findFlush(cardResult) && findStraight(cardResult))
        return true;
    return false;
}

bool Player::findRoyalFlush(vector<Card> cardResult)
{
    if(findStraightFlush(cardResult) && (cardResult[0].value == 10))
        return true;
    return false;
}

int Player::calculateCardType(vector<Card> cardResult)
{
    if(findRoyalFlush(cardResult))
        return 9;
    if(findStraightFlush(cardResult))
        return 8;
    if(findFourOfAKind(cardResult))
        return 7;
    if(findFullHouse(cardResult))
        return 6;
    if(findFlush(cardResult))
        return 5;
    if(findStraight(cardResult))
        return 4;
    if(findThreeOfAKind(cardResult))
        return 3;
    if(findTwoPairs(cardResult))
        return 2;
    if(findOnePair(cardResult))
        return 1;
    return 0;
}

int Player::getCardType()
{
    return cardtype;
}

vector<Card> Player::getCardResult()
{
    return cardResult;
}

int CardGame::Play(Player& playerOne, Player& playerTwo)
{
//    std::cout << "type1 = " << playerOne.getCardType() << endl;
//    std::cout << "type2 = " << playerTwo.getCardType() << endl;
    if(playerOne.getCardType() == playerTwo.getCardType()) 
    {
        switch(playerOne.getCardType())
        {
            case 8:
                return compareStraightFlush(playerOne,playerTwo);
            case 7:
            case 6:
                return compareFourOfAKindAndFullHouseAndThreeOfAKind(playerOne,playerTwo);
            case 5:
                return compareFlush(playerOne,playerTwo);
            default:
                return 0;
        }
    }
    
    return (playerOne.getCardType() > playerTwo.getCardType()) ? 1 : 2;
}

int CardGame::compareStraightFlush(Player& playerOne, Player& playerTwo)
{
    return (playerOne.getCardResult()[0].value > playerTwo.getCardResult()[0].value) ? 1:2;
}

int CardGame::compareFourOfAKindAndFullHouseAndThreeOfAKind(Player& playerOne, Player& playerTwo)
{
    return (playerOne.getCardResult()[2].value > playerTwo.getCardResult()[2].value) ? 1:2;
}

int CardGame::compareFlush(Player& playerOne, Player& playerTwo)
{
    for(auto i = 0; i < 5; i++)
    {
        if((playerOne.getCardResult()[i].value) == (playerTwo.getCardResult()[i].value))
        {
            continue;
        }
        return (playerOne.getCardResult()[i].value > playerTwo.getCardResult()[0].value) ? 1:2;
    }
    return 0;
}

