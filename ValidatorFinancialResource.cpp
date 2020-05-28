#include "ValidatorFinancialResource.h"
#include "FinancialResource.h"
#include "ValidatorException.h"

ValidatorFinancialResource::ValidatorFinancialResource()
{
}

ValidatorFinancialResource::~ValidatorFinancialResource()
{
}

void ValidatorFinancialResource::validate(EconomicResource* ec)
{
	ValidatorResource::validate(ec);
	FinancialResource* fr = (FinancialResource*)ec;
	if (fr->getCurrency().empty())
		throw ValidatorException("Valuta trebuie sa existe.");
	for (char c : fr->getCurrency())
		if (!isalpha(c))
			throw ValidatorException("Valuta nu poate contine caractere speciale.");
}
