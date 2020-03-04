#pragma once

#include <SFML/Graphics.hpp>

#include "Item.hpp"

class Weapon
	: public Item
{
private:
	//...

public:
	Weapon(short nID, float fWeight, short nSize, std::string sName) : Item(nID, fWeight, nSize, sName) {}
};

