#pragma once
#include "ValidatorResource.h"

class ValidatorFinancialResource : public ValidatorResource {
public:
	ValidatorFinancialResource();
	~ValidatorFinancialResource();
	void validate(EconomicResource* ec);
};