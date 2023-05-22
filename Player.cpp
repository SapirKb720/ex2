#include "Player.h"



void Player::initPlayer(const string name, const int maxHP, const int force) {
	this->name = name;
	this->maxHP = maxHP;
	this->force = force;
	this->coins = 0;
	this->level = MIN_LEVEL;
	if (maxHP <= 0) { //if given maxHP is not positive - changing to default
		this->maxHP = DEFAULT_MAX_HP;
	}
	if (force < 0) { //if given maxHP is not negative - changing to default
		this->force = DEFAULT_FORCE;
	}
	this->HP = maxHP;
}

Player::Player(const string name, const int maxHP, const int force) {
	this->initPlayer(name, maxHP, force);
}


Player::Player(const string name, const int maxHP) {
	this->initPlayer(name, maxHP, DEFAULT_FORCE);
}


Player::Player(const string name) {
	this->initPlayer(name, DEFAULT_MAX_HP, DEFAULT_FORCE);
}


void Player::copyValues(const Player& other) {
	this->name = other.name;
	this->maxHP = other.maxHP;
	this->HP = other.HP;
	this->force = other.force;
	this->coins = other.coins;
	this->level = other.level;
}

Player::Player(const Player& other) {
	copyValues(other);
}


Player& Player::operator=(const Player& other) {
	if (this == &other) {
		return *this;
	}
	copyValues(other);
	return *this;
}


void Player::void printInfo()const {
	printPlayerInfo(this->name, this->level, this->force, this->HP, this->coins);
}


void Player::levelUp() {
	this->level++;
	if (this->level > MAX_LEVEL)
		this->level = MAX_LEVEL;
}


int Player::getLevel()const {
	return this->level;
}

void Player::buff(const int points) {
	this->force += points;
}


void Player::heal(const int points) {
	if (points > 0) {
		this->HP += points;
		if (this->HP > this->maxHP) {
			this->HP = this->maxHP;
		}
	}
}


void Player::damage(const int points) {
	if (points > 0) {
		this->HP -= points;
		if (this->HP < 0) {
			this->HP = 0;
		}
	}
}

bool Player::isKnockedOut()const {
	return (this->HP == 0);
}


void Player::addCoins(const int coins) {
	if (coins >= 0) {
		this->coins += coins;
	}
}

bool pay(const int coins) {
	if (coins >= 0 && this->coins >= coins) {
		this->coins -= coins;
		return true;
	}
	return false; //not enough coins to pay
}


int getAttackStrength()const {
	return this->force + this->level;
}