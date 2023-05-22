#include "Card.h"

Card::Card(CardType type, const CardStats& stats) {
	this->m_effect = type;
	this->m_stats = stats;
}

bool wonAgainstPlayer(Player& player, Card& card) {
	return (player.getAttackStrength() < card.m_stats.force);
}

void awardPlayer(Player& player, Card& card) {
	player.levelUp();
	player.addCoins(card.m_stats.loot);
}

void damagePlayer(Player& player, Card& card) {
	player.damage(card.m_stats.hpLossOnDefeat);
}

void buffPlayer(Player& player, Card& card) {
	if (player.pay(card.m_stats.cost)) {
		player.buff(card.m_stats.buff);
	}
}

void healPlayer(Player& player, Card& card) {
	if (player.pay(card.m_stats.cost)) {
		player.heal(card.m_stats.heal);
	}
}

void Card::applyEncounter(Player& player) const {
	switch (this->m_effect) {
	case CardType::Battle:
		if (wonAgainstPlayer(player, *this)) {
			awardPlayer(player, *this);
		}
		else {
			damagePlayer(player, *this);
		}
		break;

	case CardType::Buff:
		buffPlayer(player, *this);
		break;

	case CardType::Heal:
		healPlayer(player, *this);
		break;

	case CardType::Treasure:
		player.addCoins(this->m_stats.loot);
		break;

	case default:
		break;
	}
}

void Card::printInfo() const {
	switch (this->m_effect) {
	case CardType::Battle:
		printBattleCardInfo(this->m_stats);
		break;

	case CardType::Buff:
		printBuffCardInfo(this->m_stats);
		break;

	case CardType::Heal:
		printHealCardInfo(this->m_stats);
		break;

	case CardType::Treasure:
		printTreasureCardInfo(this->m_stats);
		break;

	case default:
		break;
	}
}