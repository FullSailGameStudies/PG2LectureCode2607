#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
    int val = Card::Value();
    if (face_ == "J" or face_ == "Q" or face_ == "K") val = 10;
    return val;
}
