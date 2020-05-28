#include "FinancialResource.h"

FinancialResource::FinancialResource() : EconomicResource()
{
}

FinancialResource::FinancialResource(string name, string date, double value, string currency) : EconomicResource(name, date, value)
{
	this->currency = currency;
}

FinancialResource::FinancialResource(const FinancialResource& ec) : EconomicResource(ec)
{
	this->currency = ec.currency;
}

FinancialResource::~FinancialResource()
{
}

string FinancialResource::getCurrency()
{
	return this->currency;
}

void FinancialResource::setCurrency(string currency)
{
	this->currency = currency;
}

bool FinancialResource::operator==(const FinancialResource& ec)
{
	return EconomicResource::operator==(ec) && this->currency == ec.currency;
}

FinancialResource& FinancialResource::operator=(const FinancialResource& ec)
{
	EconomicResource::operator=(ec);
	this->currency = ec.currency;
	return *this;
}

EconomicResource* FinancialResource::clone()
{
	return new FinancialResource(this->name, this->date, this->value, this->currency);
}

string FinancialResource::toString(string delim)
{
	return "FR" + delim + EconomicResource::toString(delim) + delim + this->currency;
}
