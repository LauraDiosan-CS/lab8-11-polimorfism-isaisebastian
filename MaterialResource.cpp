#include "MaterialResource.h"
#include "Utilities.h"

MaterialResource::MaterialResource() : EconomicResource()
{
	this->lifetime = 0;
	this->pieces = 0;
}

MaterialResource::MaterialResource(string name, string date, double value, int lifetime, int pieces) : EconomicResource(name, date, value)
{
	this->lifetime = lifetime;
	this->pieces = pieces;
}

MaterialResource::MaterialResource(const MaterialResource& ec) : EconomicResource(ec)
{
	this->pieces = ec.pieces;
	this->lifetime = ec.lifetime;
}

MaterialResource::~MaterialResource()
{
}

int MaterialResource::getPieces()
{
	return this->pieces;
}

int MaterialResource::getLifeTime()
{
	return this->lifetime;
}

void MaterialResource::setPieces(int pieces)
{
	this->pieces = pieces;
}

void MaterialResource::setLifeTime(int lifetime)
{
	this->lifetime = lifetime;
}

MaterialResource& MaterialResource::operator=(const MaterialResource& ec)
{
	EconomicResource::operator=(ec);
	this->pieces = ec.pieces;
	this->lifetime = ec.lifetime;
	return *this;
}

bool MaterialResource::operator==(const MaterialResource& ec)
{
	return EconomicResource::operator==(ec) && this->pieces == ec.pieces && this->lifetime == ec.lifetime;
}

EconomicResource* MaterialResource::clone()
{
	return new MaterialResource(this->name, this->date, this->value, this->lifetime, this->pieces);
}

string MaterialResource::toString(string delim)
{
	return "MR" + delim + EconomicResource::toString(delim) + delim + convert_int_to_string(this->lifetime) + delim + convert_int_to_string(this->pieces);
}
