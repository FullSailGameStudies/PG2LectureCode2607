#pragma once
#include "Weapon.h"
class Knife :
    public Weapon
{
public:

    Knife(int range, int damage, bool IsSerrated) :
        Weapon(range, damage),
        mIsSerrated(IsSerrated)
    {
    }
    void showMe() override;
    int calcDamage() override;
private:
    bool mIsSerrated;
};

