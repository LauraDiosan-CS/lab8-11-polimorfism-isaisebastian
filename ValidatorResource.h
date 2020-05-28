#pragma once
#include "EconomicResource.h"
#include <string>
using namespace std;

class ValidatorResource {
public:
	ValidatorResource();
	~ValidatorResource();
	virtual void validate(EconomicResource* ec);
};