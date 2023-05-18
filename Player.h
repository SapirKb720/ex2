#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include <iostream>
#include "utilities.h"

class Player {
public:
	Player(const string name, const int maxHP, const int force);
	Player(const string name, const int maxHP);
	Player(const string name);
	Player(const Player& other);
	~Player() = default;
	Player& operator=(const Player& other);
	void printInfo()const;
	void levelUp();
	int getLevel()const;
	void buff(const int points);
	void heal(const int points);
	void damage(const int points);
	bool isKnockedOut()const;
	void addCoins(const int coins);
	bool pay(const int coins);
	int getAttackStrength()const;

private:
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