//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus { Win, Loss, MidGame };

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);

    /*
    Copy c'tor of the game
    gets another mtmchkin game and does a deep copy of the values (copies values, array etc')
    output:none
    */
    Mtmchkin(const Mtmchkin& other);

    /*
    Function: overload of = operator, deep copies all values of other mtmchkin into this
    input: a mtmchkin game object
    output: refrence to this object 
    */
    Mtmchkin& operator=(const Mtmchkin& other);

    /*
    d'tor of the mtmchkin game
    frees all allocated memory in the mtmchkin object (the cards array)
    */
    ~Mtmchkin();

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;


private:
    /*
    Function: deep copies all values of other mtmchkin into this
    input: a mtmchkin game object
    output: refrence to this object
    */
    void copyValues(const Mtmchkin& other);

    /*
    * Function: creates an initializes an array of cards (based on the given one) in the given size
    * input: an array of cards, the size of the array
    * output: the array of cards we created (a copy of the given one)
    */
    Card* createNewArray(const Card* cards, int num);

    Player m_player;
    Card* m_cards;
    GameStatus m_gameStatus;
    int m_numOfCards;
    int m_currCard;
    const int WIN_LEVEL = 10;
};


#endif //EX2_GAME_H