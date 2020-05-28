#pragma once
#include "EconomicResource.h"

class FinancialResource : public EconomicResource {
private:
	string currency;
public:
	FinancialResource();
	FinancialResource(string name, string date, double value, string currency);
	FinancialResource(const FinancialResource& ec);
	~FinancialResource();

	string getCurrency();
	void setCurrency(string currency);

	bool operator==(const FinancialResource& ec);
	FinancialResource& operator=(const FinancialResource& ec);
	 
	EconomicResource* clone();

	string toString(string delim);
};