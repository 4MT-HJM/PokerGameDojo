#include "hiker.hpp"
#include <gmock/gmock.h>


using namespace ::testing;


namespace {

TEST(Hiker, OnePairBiggerThanHighCard)
{
    vector<string> cardForPlayerOne = {"5H","5C","6S","7S","KD"};
    vector<string> cardForPlayerTwo = {"2H","5C","6S","7S","KD"};
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
}

TEST(Hiker, TwoPairsBiggerThanOnePair)
{
    vector<string> cardForPlayerOne = {"5H","5C","6H","6S","KD"};
    vector<string> cardForPlayerTwo = {"5D","5S","6S","7S","KD"};
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
}

TEST(Hiker, ThreeOfKindBiggerThanTwoPair)
{
    vector<string> cardForPlayerOne = {"5H","5C","6H","6S","KD"};
    vector<string> cardForPlayerTwo = {"5D","5S","5S","7S","KD"};
    vector<string> cardForPlayerThree = {"6D","7S","5S","5S","5D"};
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    Player playerThree(cardForPlayerThree);

    ASSERT_EQ(2, CardGame::Play(playerOne, playerTwo));
    ASSERT_EQ(2, CardGame::Play(playerOne, playerThree));
}

TEST(Hiker, StraightBiggerThreeOfKind)
{
    vector<string> cardForPlayerOne = {"5H","5C","6H","6S","KD"};
    vector<string> cardForPlayerTwo = {"5D","6S","7S","8S","9D"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(2, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, FlushBiggerStraight)
{
    vector<string> cardForPlayerOne = {"3H","5H","6H","7H","KH"};
    vector<string> cardForPlayerTwo = {"5D","6S","7S","8S","9D"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, FullHouseBiggerFlush)
{
    vector<string> cardForPlayerOne = {"3H","3H","3H","5H","5H"};
    vector<string> cardForPlayerTwo = {"3H","5H","6H","7H","KH"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, FourOfAKindBiggerFullHouse)
{
    vector<string> cardForPlayerOne = {"6H","6H","6H","6H","5H"};
    vector<string> cardForPlayerTwo = {"3H","3H","3H","5H","5H"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, StraightFlushBiggerFourOfAKind)
{
    vector<string> cardForPlayerOne = {"7H","8H","9H","TH","JH"};
    vector<string> cardForPlayerTwo = {"6H","6H","6H","6H","5H"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, RoyalFlushBiggerStraightFlush)
{
    vector<string> cardForPlayerOne = {"TH","JH","QH","KH","AH"};
    vector<string> cardForPlayerTwo = {"7H","8H","9H","TH","JH"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, TwoStraightFlushPlayers)
{
    vector<string> cardForPlayerOne = {"3H","4H","5H","6H","7H"};
    vector<string> cardForPlayerTwo = {"5H","6H","7H","8H","9H"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);
    

    ASSERT_EQ(2, CardGame::Play(playerOne, playerTwo));
    
}

TEST(Hiker, TwoFourOfKindPlayers)
{
    vector<string> cardForPlayerOne = {"2H","5H","5H","5H","5H"};
    vector<string> cardForPlayerTwo = {"4H","3H","3H","3H","3H"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo)); 
}

TEST(Hiker, TwoFullHousePlayers)
{
    vector<string> cardForPlayerOne = {"2H","2S","5H","5S","5D"};
    vector<string> cardForPlayerTwo = {"4H","4S","3H","3S","3D"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);

    ASSERT_EQ(1, CardGame::Play(playerOne, playerTwo)); 
}

TEST(Hiker, TwoFlushPlayers)
{
    vector<string> cardForPlayerOne = {"2H","3H","5H","6H","8H"};
    vector<string> cardForPlayerTwo = {"4S","5S","8S","9S","TS"};
    
    Player playerOne(cardForPlayerOne);
    Player playerTwo(cardForPlayerTwo);

    ASSERT_EQ(2, CardGame::Play(playerOne, playerTwo)); 
}

}