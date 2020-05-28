#pragma once
#include "EconomicResource.h"
class MaterialResource : public EconomicResource {
private:
	int pieces;
	int lifetime;
public:
	MaterialResource();
	MaterialResource(string name, string date, double value, int lifetime, int pieces);
	MaterialResource(const MaterialResource& ec);
	~MaterialResource();

	int getPieces();
	int getLifeTime();

	void setPieces(int pieces);
	void setLifeTime(int lifetime);

	MaterialResource& operator=(const MaterialResource& ec);
	bool operator==(const MaterialResource& ec);

	EconomicResource* clone();
	string toString(string delim);
};