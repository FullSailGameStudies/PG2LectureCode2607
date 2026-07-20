#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	virtual ~Deck()
	{
		Cleanup();
	}
	const std::vector<Card*>& Cards() const
	{
		return cards_;
	}
	void Cards(const std::vector<Card*>& cards)
	{
		if (cards.size() == 52)
			cards_ = cards;
	}

	bool HasCards() const;
	virtual void MakeCards();
	Card* DealCard();
	void Shuffle();

protected:
	std::vector<Card*> cards_;

	void Cleanup();
};

