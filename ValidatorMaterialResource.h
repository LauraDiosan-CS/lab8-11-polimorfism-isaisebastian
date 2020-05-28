#pragma once
#include "ValidatorResource.h"

class ValidatorMaterialResource : public ValidatorResource {
public:
	ValidatorMaterialResource();
	~ValidatorMaterialResource();
	void validate(EconomicResource* ec);
};