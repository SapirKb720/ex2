#include "Mtmchkin.h"

Card* Mtmchkin::createNewArray(const Card* cards, int num)
{
    Card* newCards = new Card[num];
    for (int i = 0; i < num; i++)
    {
        newCards[i] = Card(cards[i]);
    }
    return newCards;
}

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
    :m_player(playerName)
{
    this->m_cards = createNewArray(cardsArray, numOfCards);
    this->m_gameStatus = GameStatus::MidGame;
    this->m_numOfCards = numOfCards;
    this->m_currCard = 0;
}


void Mtmchkin::copyValues(const Mtmchkin &other)
{
    this->m_gameStatus = other.m_gameStatus;
    this->m_numOfCards = other.m_numOfCards;
    this->m_currCard = other.m_currCard;
    this->m_cards = createNewArray(other.m_cards, other.m_numOfCards);
}

Mtmchkin::Mtmchkin(const Mtmchkin &other)
    :m_player(other.m_player)
{
    copyValues(other);
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin &other)
{
    if (this == &other) {
        return *this;
    }
    
    delete[] this->m_cards;
    this->m_cards = NULL;
    this->m_player = other.m_player;
    copyValues(other);
    return *this;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
    this->m_cards = NULL;
}


void Mtmchkin::playNextCard()
{

    Card currCard = (this->m_cards)[this->m_currCard];
    currCard.printInfo();
    currCard.applyEncounter(this->m_player);
    (this->m_player).printInfo();

    //checking if got to level 10 and won the game
    if (this->m_player.getLevel() == WIN_LEVEL) {
        this->m_gameStatus = GameStatus::Win;
    }
    //checking if the player is knocked out and lost
    else if (this->m_player.isKnockedOut()) {
        this->m_gameStatus = GameStatus::Loss;
    }
    if (this->m_currCard == (this->m_numOfCards - 1))
        this->m_currCard = 0;
    else
        this->m_currCard++;

}

bool Mtmchkin::isOver() const
{
    return !(this->m_gameStatus == GameStatus::MidGame);
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_gameStatus;
}

