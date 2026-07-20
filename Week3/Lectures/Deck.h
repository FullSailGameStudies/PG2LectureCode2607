#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	Deck()
	{
		MakeCards();
	}
	const std::vector<Card>& Cards() const
	{
		return cards_;
	}
	void Cards(const std::vector<Card>& cards)
	{
		if (cards.size() == 52)
			cards_ = cards;
	}

	bool HasCards() const;
	void MakeCards();
	Card DealCard();
	void Shuffle();

private:
	std::vector<Card> cards_;
};

