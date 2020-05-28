#include "ValidatorResource.h"
#include "ValidatorException.h"

ValidatorResource::ValidatorResource()
{
}

ValidatorResource::~ValidatorResource()
{
}

void ValidatorResource::validate(EconomicResource* ec)
{
	if (ec->getName().empty())
		throw ValidatorException("Numele resursei nu poate sa fie gol!");
	if (ec->getValue() <= 0.0)
		throw ValidatorException("Valoarea resursei nu poate sa fie un numar negativ!");
	if (ec->getDate().empty())
		throw ValidatorException("Data nu poate sa fie goala.");

}
