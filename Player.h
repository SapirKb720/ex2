#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include <iostream>
#include "utilities.h"

class Player {
public:
	/*
* construcor
* gets name, maxHP, force
* intializing the player values according to default values and accepted values
*/
	Player(const string name, const int maxHP, const int force);


	/*
	* construcor
	* gets name, maxHP
	* intializing the player values according to default values and accepted values
	*/
	Player(const string name, const int maxHP);

	/*
	* construcor
	* gets name
	* intializing the player values according to default values and accepted values
	*/
	Player(const string name);


	/*
	* function: copy constructor
	* copies the other player values to the current player values
	* input: other player
	*/
	Player(const Player& other);

	/*
	* destructor
	* deletes this player
	*/
	~Player() = default;

	/*
	* function: puts the other player values in this player values
	* input: other player
	* output: this player
	*/
	Player& operator=(const Player& other);

	/*
	* function: prints this player info
	* input: none
	* output: none
	*/
	void printInfo()const;

	/*
	* function: promotes the player to next level until it gets to max level
	* input: none
	* output: none
	*/
	void levelUp();

	/*
	* function: returns this player level
	* input: none
	* output: this player laevel
	*/
	int getLevel()const;


	/*
	* function: adds this player force the amount of points we get
	* input: points to add
	* output: none
	*/
	void buff(const int points);

	/*
	* function: adds this player HP the amount of points we get until it gets to maxHP
	* if points is negetive, the function does nothing
	* input: points to add to HP
	* output: none
	*/
	void heal(const int points);

	/*
	* function: subtracts this player HP the amount of points we get until it gets to 0
	* input: the amount of points to subtract
	* if points is negetive, the function does nothing
	* output: none
	*/
	void damage(const int points);

	/*
	* function: returns if HP is zero
	* input: none
	* output: true if HP is zero, false otherwise.
	*/
	bool isKnockedOut()const;

	/*
	* function: adds coins to the coins bag
	* input: amount of coins to add
	* if coins is negetive, the function does nothing
	* output: none
	*/
	void addCoins(const int coins);

	/*
	* function: subtracts coins from the coins bag
	* if the amount of coins we get is bigger than the current amount of coins, the payment fails
	* input: amount of coins to subtract
	* output: true if payment worked, false otherwise.
	*/
	bool pay(const int coins);

	/*
	* function: calculates and returns the attack strength
	* input: none
	* output: the sum of the force and the level
	*/
	int getAttackStrength()const;

private:
	/*
	function: initializes the player's values
	if any of the values aren't valid, it gives them defalt values:
	for max hp - 100, for force - 5
	unput:
	output:
	*/
	void initPlayer(const string name, const int maxHP, const int force);
	void copyValues(const Player& other);
	const int DEFAULT_MAX_HP = 100;
	const int DEFAULT_FORCE = 5;
	const int MIN_LEVEL = 1;
	const int MAX_LEVEL = 10;
	string name;
	int level;
	int force;
	int maxHP;
	int HP;
	int coins;
};

#endif