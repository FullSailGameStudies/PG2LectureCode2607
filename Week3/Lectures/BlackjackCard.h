#pragma once
#include "Card.h"

// IS-A relationship
//   BlackjackCard IS-A Card

//
// Good programming practices:
//	  favor COMPOSITION (has-a) over INHERITANCE (is-a)
//    has-a is more flexible than is-a


class BlackjackCard : public Card
{
public:
	BlackjackCard(const std::string& face, const std::string& suit) :
		Card(face,suit)
	{

	}
	int Value() const;
};

