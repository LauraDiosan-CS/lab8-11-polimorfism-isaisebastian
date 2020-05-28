#include "ValidatorMaterialResource.h"
#include "ValidatorException.h"
#include "MaterialResource.h"

ValidatorMaterialResource::ValidatorMaterialResource()
{
}

ValidatorMaterialResource::~ValidatorMaterialResource()
{
}

void ValidatorMaterialResource::validate(EconomicResource* ec)
{
	ValidatorResource::validate(ec);
	MaterialResource* mr = (MaterialResource*)ec;
	if (mr->getPieces() < 0)
		throw ValidatorException("Numarul bucatilor nu poate sa fie negativ");
	if (mr->getLifeTime() < 0)
		throw ValidatorException("Durata de viata nu poate sa fie un numar negativ");
}
