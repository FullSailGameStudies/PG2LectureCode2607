#include "BlackjackDeck.h"
#include <BlackjackCard.h>

void BlackjackDeck::MakeCards()
{
	//a full override
    Cleanup();
    std::vector<std::string> faces
    { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    std::vector<std::string> suits{ "Hearts","Spades","Clubs","Diamonds" };

    //nested loops
    for (auto& suit : suits)
    {
        for (auto& face : faces)
        {
            //BlackjackCard card(face, suit);
            //create the card on the HEAP
            cards_.push_back(new BlackjackCard(face,suit));
        }
    }
}
