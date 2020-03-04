#pragma once

#include <string>

class Item
{
private:
	short nID;
	float fWeight;
	short nSize;
	std::string sName;

public:
	void SetID(short nID) { this->nID = nID; }
	void SetWeight(float fWeight) { this->fWeight = fWeight; }
	void SetSize(short nSize) { this->nSize = nSize; }
	void SetName(std::string sName) { this->sName = sName; }

	short getID() { return this->nID; }
	float getWeight() { return this->fWeight; }
	short getSize() { return this->nSize; }
	std::string getName() { return this->sName; }

	Item(short iID, float fWeight, short iSize, std::string sName);
	~Item();
};

