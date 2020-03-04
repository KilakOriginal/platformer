#include "Item.hpp"

Item::Item(short nID, float fWeight, short nSize, std::string sName)
	: nID(nID), fWeight(fWeight), nSize(nSize), sName(sName)
{
}

Item::~Item()
{
}
