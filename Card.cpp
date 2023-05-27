#include "Card.h"

Card::Card(CardType type, const CardStats& stats) {
	this->m_effect = type;
	this->m_stats = stats;
}

void Card::applyEncounter(Player& player) const {
	bool result = false;
	switch (this->m_effect) {
	case CardType::Battle:
		result = (player.getAttackStrength() >= this->m_stats.force);
		if (result) { //if won battle
			player.levelUp();
			player.addCoins(this->m_stats.loot);
		}
		else { //lost - gets damage
			player.damage(this->m_stats.hpLossOnDefeat);
		}
		printBattleResult(result);
		break;
	case CardType::Buff:
		if (player.pay(this->m_stats.cost)) { //if has enough money
			player.buff(this->m_stats.buff);
		}
		break;
	case CardType::Heal:
		if (player.pay(this->m_stats.cost)) { //if has enough money
			player.heal(this->m_stats.heal);
		}
		break;
	case CardType::Treasure:
		player.addCoins(this->m_stats.loot); //looting
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
	}
}