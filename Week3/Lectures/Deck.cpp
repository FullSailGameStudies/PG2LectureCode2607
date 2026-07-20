#include "Deck.h"

bool Deck::HasCards() const
{
    return not cards_.empty();
}

void Deck::MakeCards()
{
    cards_.clear();
    std::vector<std::string> faces
    { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    std::vector<std::string> suits{ "Hearts","Spades","Clubs","Diamonds" };

    //nested loops
    for (auto& suit : suits)
    {
        for (auto& face : faces)
        {
            Card card(face, suit);
            cards_.push_back(card);
        }
    }
}

Card Deck::DealCard()
{
    if (cards_.empty())
    {
        Shuffle();
    }
    //get the last card
    Card card = cards_.back();

    //erase the last card
    //cards_.erase(cards_.end() - 1);
    cards_.pop_back();

    return card;
}

void Deck::Shuffle()
{
    if (cards_.empty())
    {
        MakeCards();
    }

    int index1, index2;
    for (int i = 0; i < 156; i++)
    {
        index1 = rand() % 52;
        do
        {
            index2 = rand() % 52;
        } while (index1 == index2);
        std::swap(cards_[index1], cards_[index2]);
    }
}
