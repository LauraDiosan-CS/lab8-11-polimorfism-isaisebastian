#include "EconomicResource.h"
#include "Utilities.h"

EconomicResource::EconomicResource()
{
	this->value = 0.0;
}

EconomicResource::EconomicResource(string name, string date, double value)
{
	this->name = name;
	this->date = date;
	this->value = value;
}

EconomicResource::EconomicResource(const EconomicResource& ec)
{
	this->name = ec.name;
	this->date = ec.date;
	this->value = ec.value;
}

EconomicResource::~EconomicResource()
{
}

string EconomicResource::getName()
{
	return this->name;
}

string EconomicResource::getDate()
{
	return this->date;
}

double EconomicResource::getValue()
{
	return this->value;
}

void EconomicResource::setName(string name)
{
	this->name = name;
}

void EconomicResource::setDate(string date)
{
	this->date = date;
}

void EconomicResource::setValue(double value)
{
	this->value = value;
}

EconomicResource& EconomicResource::operator=(const EconomicResource& ec)
{
	this->name = ec.name;
	this->date = ec.date;
	this->value = ec.value;
	return *this;
}

bool EconomicResource::operator==(const EconomicResource& ec)
{
	return this->name == ec.name && this->date == ec.date && this->value == ec.value;
}

EconomicResource* EconomicResource::clone()
{
	return new EconomicResource(this->name, this->date, this->value);
}

string EconomicResource::toString(string delim)
{
	return this->name + delim + this->date + delim + convert_double_to_string(this->value);
}
